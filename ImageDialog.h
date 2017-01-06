#ifndef H_IMAGE_DIALOG
#define H_IMAGE_DIALOG

class ImageDialog : public CDialog
{
public:
   ImageDialog();
   virtual ~ImageDialog();

protected:
   virtual void OnDestroy();
   virtual void OnClose();
   virtual BOOL OnInitDialog();
   virtual INT_PTR DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
   virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
   virtual void OnOK();
   virtual void OnCancel();

private:
   void Import();
   void Export();
   void DeleteImage();
   void Reimport();
   void UpdateAll();
   void ReimportFrom();
   void LoadPosition();
   void SavePosition();
};
#endif // !H_IMAGE_DIALOG
