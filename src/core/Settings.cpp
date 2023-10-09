#include "stdafx.h"
#include "Settings.h"

#include <stdio.h>

#define VP_REGKEY_GENERAL "Software\\Visual Pinball\\"
#define VP_REGKEY "Software\\Visual Pinball\\VP10\\"

static const string regKey[Settings::Count] =
   {
      "Controller"s, "Editor"s, "Player"s, "PlayerVR"s, "RecentDir"s, "Version"s, "CVEdit"s,
      "DefaultProps\\Bumper"s, "DefaultProps\\Decal"s, "DefaultProps\\EMReel"s, "DefaultProps\\Flasher"s, "DefaultProps\\Flipper"s,
      "DefaultProps\\Gate"s, "DefaultProps\\HitTarget"s, "DefaultProps\\Kicker"s, "DefaultProps\\Light"s, "DefaultProps\\LightSequence"s,
      "DefaultProps\\Plunger"s, "DefaultProps\\Primitive"s, "DefaultProps\\Ramp"s, "DefaultProps\\Rubber"s, "DefaultProps\\Spinner"s,
      "DefaultProps\\Wall"s, "DefaultProps\\Target"s, "DefaultProps\\TextBox"s, "DefaultProps\\Timer"s, "DefaultProps\\Trigger"s,
      "Defaults\\Camera"s
   };

Settings::Section Settings::GetSection(const string& name)
{
   for (int i = 0; i < Settings::Count; i++)
   {
      if (regKey[i] == name)
         return (Settings::Section) i;
   }
   return Count;
}

Settings::Settings(const Settings* parent)
   : m_parent(parent)
{
}

bool Settings::LoadFromFile(const string& path, const bool createDefault)
{
   m_iniPath = path;
   mINI::INIFile file(path);
   if (file.read(m_ini))
   {
      PLOGI << "Settings file was loaded from '" << path << "'";
      return true;
   }
   else if (createDefault)
   {
      PLOGI << "Settings file was not found at '" << path << "' creating a default one";
#ifdef _WIN32
      // Load failed: initialize from a default setting file
      HMODULE handle = ::GetModuleHandle(NULL);
      HRSRC rc = ::FindResource(handle, MAKEINTRESOURCE(IDR_DEFAULT_INI), MAKEINTRESOURCE(INI_FILE));
      HGLOBAL rcData = ::LoadResource(handle, rc);
      DWORD size = ::SizeofResource(handle, rc);
      const char *data = static_cast<const char *>(::LockResource(rcData));
      std::ofstream defaultFile(path);
      defaultFile << data;
      defaultFile.close();
      if (!file.read(m_ini))
      {
         PLOGE << "Loading of default settings file failed";
      }

      // Get default values from windows registry
      for (unsigned int j = 0; j < Section::Count; j++)
      {
         // We do not save version of played tables in the ini file
         if (j == Section::Version)
            continue;

         string regpath(j == 0 ? VP_REGKEY_GENERAL : VP_REGKEY);
         regpath += regKey[j];

         HKEY hk;
         LSTATUS res = RegOpenKeyEx(HKEY_CURRENT_USER, regpath.c_str(), 0, KEY_READ, &hk);
         if (res != ERROR_SUCCESS)
            return false;

         for (DWORD Index = 0;; ++Index)
         {
            DWORD dwSize = MAX_PATH;
            TCHAR szName[MAX_PATH];
            res = RegEnumValue(hk, Index, szName, &dwSize, nullptr, nullptr, nullptr, nullptr);
            if (res != ERROR_SUCCESS)
               break;

            if (dwSize == 0 || szName[0] == '\0')
               continue;
            // detect whitespace and skip, as no whitespace allowed in XML tags
            bool whitespace = false;
            unsigned int i = 0;
            while (szName[i])
               if (isspace(szName[i]))
               {
                  whitespace = true;
                  break;
               }
               else
                  ++i;
            if (whitespace)
               continue;

            dwSize = MAXSTRING;
            BYTE pvalue[MAXSTRING];
            DWORD type = REG_NONE;
            res = RegQueryValueEx(hk, szName, nullptr, &type, pvalue, &dwSize);
            if (res != ERROR_SUCCESS)
               continue;

            // old Win32xx and Win32xx 9+ docker keys
            if (strcmp((char *)pvalue, "Dock Windows") == 0) // should not happen, as a folder, not value.. BUT also should save these somehow and restore for Win32++, or not ?
               continue;
            if (strcmp((char *)pvalue, "Dock Settings") == 0) // should not happen, as a folder, not value.. BUT also should save these somehow and restore for Win32++, or not ?
               continue;

            char *copy;
            if (type == REG_SZ)
            {
               const size_t size = strlen((char *)pvalue);
               copy = new char[size + 1];
               memcpy(copy, pvalue, size);
               copy[size] = '\0';
            }
            else if (type == REG_DWORD)
            {
               const string tmp = std::to_string(*(DWORD *)pvalue);
               const size_t len = tmp.length() + 1;
               copy = new char[len];
               strcpy_s(copy, len, tmp.c_str());
            }
            else
            {
               copy = nullptr;
               assert(!"Bad RegKey");
            }

            m_ini[regKey[j]][szName] = copy;
         }
         RegCloseKey(hk);
      }
#endif
      return true;
   }
   else
   {
      PLOGI << "Settings file was not found at '" << path << "'";
      return false;
   }
}

void Settings::SaveToFile(const string &path)
{
   m_iniPath = path;
   int size = 0;
   for (auto section : m_ini)
      size += section.second.size();
   if (size > 0)
   {
      mINI::INIFile file(path);
      file.write(m_ini, true);
   }
   else if (FileExists(path))
   {
      // Remove empty settings file
      remove(path.c_str());
   }
}

void Settings::Save()
{
   SaveToFile(m_iniPath);
}

bool Settings::LoadValue(const Section &section, const string &key, string &buffer) const
{
   DataType type = DT_SZ;
   char szbuffer[MAXSTRING];
   szbuffer[0] = '\0';
   const bool success = LoadValue(section, key, type, szbuffer, MAXSTRING);
   buffer = szbuffer;
   return success && (type == DT_SZ);
}

bool Settings::LoadValue(const Section &section, const string &key, void *const szbuffer, const DWORD size) const
{
   if (size > 0) // clear string in case of reg value being set, but being null string which results in szbuffer being kept as-is
      ((char *)szbuffer)[0] = '\0';
   DataType type = DT_SZ;
   const bool success = LoadValue(section, key, type, szbuffer, size);
   return success && (type == DT_SZ);
}

bool Settings::LoadValue(const Section &section, const string &key, float &pfloat) const
{
   DataType type = DT_SZ;
   char szbuffer[16];
   const bool success = LoadValue(section, key, type, szbuffer, 16);
   if (!success || (type != DT_SZ))
      return false;
   const int len = lstrlen(szbuffer);
   if (len == 0)
      return false;
   char *const fo = strchr(szbuffer, ',');
   if (fo != nullptr)
      *fo = '.';
   if (szbuffer[0] == '-')
   {
      if (len < 2)
         return false;
      pfloat = (float)atof(&szbuffer[1]);
      pfloat = -pfloat;
   }
   else
      pfloat = (float)atof(szbuffer);
   return true;
}

bool Settings::LoadValue(const Section &section, const string &key, int &pint) const
{
   DataType type = DT_DWORD;
   const bool success = LoadValue(section, key, type, (void *)&pint, 4);
   return success && (type == DT_DWORD);
}

bool Settings::LoadValue(const Section &section, const string &key, unsigned int &pint) const
{
   DataType type = DT_DWORD;
   const bool success = LoadValue(section, key, type, (void *)&pint, 4);
   return success && (type == DT_DWORD);
}

bool Settings::LoadValue(const Section &section, const string &key, DataType &type, void *pvalue, DWORD size) const
{
   if (size == 0)
   {
      type = DT_ERROR;
      return false;
   }
   bool hasInIni = m_ini.has(regKey[section]) && m_ini.get(regKey[section]).has(key);
   if (hasInIni)
   {
      string value = m_ini.get(regKey[section]).get(key);
      if (value.length() > 0)
      {
         // Value is empty (just a marker for text formatting), consider it as undefined
         if (type == DT_SZ)
         {
            const DWORD len = (DWORD)value.length() + 1;
            const DWORD len_min = min(len, size) - 1;
            memcpy(pvalue, value.c_str(), len_min);
            ((char *)pvalue)[len_min] = '\0';
            return true;
         }
         else if (type == DT_DWORD)
         {
            *((DWORD *)pvalue) = (DWORD)atoll(value.c_str());
            return true;
         }
         else
         {
            assert(!"Bad Type");
            type = DT_ERROR;
            return false;
         }
      }
   }

   if (m_parent != nullptr)
      return m_parent->LoadValue(section, key, type, pvalue, size);

   type = DT_ERROR;
   return false;
}

int Settings::LoadValueWithDefault(const Section &section, const string &key, const int def) const
{
   int val;
   return LoadValue(section, key, val) ? val : def;
}

float Settings::LoadValueWithDefault(const Section &section, const string &key, const float def) const
{
   float val;
   return LoadValue(section, key, val) ? val : def;
}

bool Settings::LoadValueWithDefault(const Section &section, const string &key, const bool def) const
{
   return LoadValueWithDefault(section, key, (int)def) != 0;
}

string Settings::LoadValueWithDefault(const Section &section, const string &key, const string &def) const
{
   string val;
   return LoadValue(section, key, val) ? val : def;
}

bool Settings::SaveValue(const Section &section, const string &key, const DataType type, const void *pvalue, const DWORD size)
{
   if (key.empty() || size == 0)
      return false;

   char *copy;
   if (type == DT_SZ)
   {
      copy = new char[size + 1];
      memcpy(copy, pvalue, size);
      copy[size] = '\0';
   }
   else if (type == DT_DWORD)
   {
      const string tmp = std::to_string(*(DWORD *)pvalue);
      const size_t len = tmp.length() + 1;
      copy = new char[len];
      strcpy_s(copy, len, tmp.c_str());
   }
   else
   {
      assert(!"Bad RegKey");
      return false;
   }
   m_ini[regKey[section]][key] = copy;
   delete[] copy;
   return true;
}

bool Settings::SaveValue(const Section &section, const string &key, const bool val)
{
   const DWORD dwval = val ? 1 : 0;
   return SaveValue(section, key, DT_DWORD, &dwval, sizeof(DWORD));
}

bool Settings::SaveValue(const Section &section, const string &key, const int val)
{
   return SaveValue(section, key, DT_DWORD, &val, sizeof(DWORD));
}

bool Settings::SaveValue(const Section &section, const string &key, const float val)
{
   char buf[16];
   sprintf_s(buf, sizeof(buf), "%f", val);
   return SaveValue(section, key, DT_SZ, buf, lstrlen(buf));
}

bool Settings::SaveValue(const Section &section, const string &key, const char *val)
{
   return SaveValue(section, key, DT_SZ, val, lstrlen(val));
}

bool Settings::SaveValue(const Section &section, const string &key, const string &val)
{
   return SaveValue(section, key, DT_SZ, val.c_str(), (DWORD)val.length());
}

bool Settings::DeleteValue(const Section &section, const string &key, const bool &deleteFromParent)
{
   bool success = true;
   if (m_parent && deleteFromParent)
      success &= DeleteValue(section, key, deleteFromParent);
   if (m_ini.has(regKey[section]) && m_ini.get(regKey[section]).has(key))
      success &= m_ini[regKey[section]].remove(key);
   return success;
}

bool Settings::DeleteSubKey(const Section &section, const bool &deleteFromParent)
{
   bool success = true;
   if (m_parent && deleteFromParent)
      success &= DeleteSubKey(section, deleteFromParent);
   if (m_ini.has(regKey[section]))
      success &= m_ini.remove(regKey[section]);
   return success;
}