/*** Autogenerated by WIDL 8.21 from ../inc/ultradmd/UltraDMD.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __ultradmd_i_h__
#define __ultradmd_i_h__

#ifndef __WIDL_INLINE
#if defined(__cplusplus) || defined(_MSC_VER)
#define __WIDL_INLINE inline
#elif defined(__GNUC__)
#define __WIDL_INLINE __inline__
#endif
#endif

/* Forward declarations */

#ifndef __IDMDObject_FWD_DEFINED__
#define __IDMDObject_FWD_DEFINED__
typedef interface IDMDObject IDMDObject;
#ifdef __cplusplus
interface IDMDObject;
#endif /* __cplusplus */
#endif

#ifndef __DMDObject_FWD_DEFINED__
#define __DMDObject_FWD_DEFINED__
#ifdef __cplusplus
typedef class DMDObject DMDObject;
#else
typedef struct DMDObject DMDObject;
#endif /* defined __cplusplus */
#endif /* defined __DMDObject_FWD_DEFINED__ */

#ifndef __IDMDObjectEvents_FWD_DEFINED__
#define __IDMDObjectEvents_FWD_DEFINED__
typedef interface IDMDObjectEvents IDMDObjectEvents;
#ifdef __cplusplus
interface IDMDObjectEvents;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <oaidl.h>
#include <ocidl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef float single;
#ifndef __UltraDMD_LIBRARY_DEFINED__
#define __UltraDMD_LIBRARY_DEFINED__

DEFINE_GUID(LIBID_UltraDMD, 0x30b5ccd9, 0x5104, 0x41a8, 0xa6,0x97, 0x2a,0x9e,0x86,0x1f,0xbc,0x2a);

#ifndef __IDMDObject_FWD_DEFINED__
#define __IDMDObject_FWD_DEFINED__
typedef interface IDMDObject IDMDObject;
#ifdef __cplusplus
interface IDMDObject;
#endif /* __cplusplus */
#endif

#ifndef __IDMDObjectEvents_FWD_DEFINED__
#define __IDMDObjectEvents_FWD_DEFINED__
typedef interface IDMDObjectEvents IDMDObjectEvents;
#ifdef __cplusplus
interface IDMDObjectEvents;
#endif /* __cplusplus */
#endif

/*****************************************************************************
 * IDMDObject interface
 */
#ifndef __IDMDObject_INTERFACE_DEFINED__
#define __IDMDObject_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDMDObject, 0xf7e68187, 0x251f, 0x4dfb, 0xaf,0x79, 0xf1,0xd4,0xd6,0x9e,0xe1,0x88);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("f7e68187-251f-4dfb-af79-f1d4d69ee188")
IDMDObject : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE get_FloatProperty(
        single *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE put_FloatProperty(
        single pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE Init(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Uninit(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetMajorVersion(
        LONG *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetMinorVersion(
        LONG *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetBuildNumber(
        LONG *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetVisibleVirtualDMD(
        VARIANT_BOOL bHide,
        VARIANT_BOOL *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetFlipY(
        VARIANT_BOOL flipY,
        VARIANT_BOOL *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE IsRendering(
        VARIANT_BOOL *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE CancelRendering(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CancelRenderingWithId(
        BSTR sceneId) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clear(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetProjectFolder(
        BSTR basePath) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetVideoStretchMode(
        LONG mode) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetScoreboardBackgroundImage(
        BSTR filename,
        LONG selectedBrightness,
        LONG unselectedBrightness) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateAnimationFromImages(
        LONG fps,
        VARIANT_BOOL loop,
        BSTR imagelist,
        LONG *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterVideo(
        LONG videoStretchMode,
        VARIANT_BOOL loop,
        BSTR videoFilename,
        LONG *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterFont(
        BSTR file,
        LONG *pRetVal) = 0;

    virtual HRESULT STDMETHODCALLTYPE UnregisterFont(
        LONG registeredFont) = 0;

    virtual HRESULT STDMETHODCALLTYPE DisplayVersionInfo(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DisplayScoreboard(
        LONG cPlayers,
        LONG highlightedPlayer,
        LONG score1,
        LONG score2,
        LONG score3,
        LONG score4,
        BSTR lowerLeft,
        BSTR lowerRight) = 0;

    virtual HRESULT STDMETHODCALLTYPE DisplayScoreboard00(
        LONG cPlayers,
        LONG highlightedPlayer,
        LONG score1,
        LONG score2,
        LONG score3,
        LONG score4,
        BSTR lowerLeft,
        BSTR lowerRight) = 0;

    virtual HRESULT STDMETHODCALLTYPE DisplayScene00(
        BSTR background,
        BSTR toptext,
        LONG topBrightness,
        BSTR bottomtext,
        LONG bottomBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut) = 0;

    virtual HRESULT STDMETHODCALLTYPE DisplayScene00Ex(
        BSTR background,
        BSTR toptext,
        LONG topBrightness,
        LONG topOutlineBrightness,
        BSTR bottomtext,
        LONG bottomBrightness,
        LONG bottomOutlineBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut) = 0;

    virtual HRESULT STDMETHODCALLTYPE DisplayScene00ExWithId(
        BSTR sceneId,
        VARIANT_BOOL cancelPrevious,
        BSTR background,
        BSTR toptext,
        LONG topBrightness,
        LONG topOutlineBrightness,
        BSTR bottomtext,
        LONG bottomBrightness,
        LONG bottomOutlineBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut) = 0;

    virtual HRESULT STDMETHODCALLTYPE ModifyScene00(
        BSTR id,
        BSTR toptext,
        BSTR bottomtext) = 0;

    virtual HRESULT STDMETHODCALLTYPE ModifyScene00Ex(
        BSTR id,
        BSTR toptext,
        BSTR bottomtext,
        LONG pauseTime) = 0;

    virtual HRESULT STDMETHODCALLTYPE DisplayScene01(
        BSTR sceneId,
        BSTR background,
        BSTR text,
        LONG textBrightness,
        LONG textOutlineBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut) = 0;

    virtual HRESULT STDMETHODCALLTYPE DisplayText(
        BSTR text,
        LONG textBrightness,
        LONG textOutlineBrightness) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScrollingCredits(
        BSTR background,
        BSTR text,
        LONG textBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDMDObject, 0xf7e68187, 0x251f, 0x4dfb, 0xaf,0x79, 0xf1,0xd4,0xd6,0x9e,0xe1,0x88)
#endif
#else
typedef struct IDMDObjectVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDMDObject *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDMDObject *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDMDObject *This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        IDMDObject *This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        IDMDObject *This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        IDMDObject *This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        IDMDObject *This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    /*** IDMDObject methods ***/
    HRESULT (STDMETHODCALLTYPE *get_FloatProperty)(
        IDMDObject *This,
        single *pRetVal);

    HRESULT (STDMETHODCALLTYPE *put_FloatProperty)(
        IDMDObject *This,
        single pRetVal);

    HRESULT (STDMETHODCALLTYPE *Init)(
        IDMDObject *This);

    HRESULT (STDMETHODCALLTYPE *Uninit)(
        IDMDObject *This);

    HRESULT (STDMETHODCALLTYPE *GetMajorVersion)(
        IDMDObject *This,
        LONG *pRetVal);

    HRESULT (STDMETHODCALLTYPE *GetMinorVersion)(
        IDMDObject *This,
        LONG *pRetVal);

    HRESULT (STDMETHODCALLTYPE *GetBuildNumber)(
        IDMDObject *This,
        LONG *pRetVal);

    HRESULT (STDMETHODCALLTYPE *SetVisibleVirtualDMD)(
        IDMDObject *This,
        VARIANT_BOOL bHide,
        VARIANT_BOOL *pRetVal);

    HRESULT (STDMETHODCALLTYPE *SetFlipY)(
        IDMDObject *This,
        VARIANT_BOOL flipY,
        VARIANT_BOOL *pRetVal);

    HRESULT (STDMETHODCALLTYPE *IsRendering)(
        IDMDObject *This,
        VARIANT_BOOL *pRetVal);

    HRESULT (STDMETHODCALLTYPE *CancelRendering)(
        IDMDObject *This);

    HRESULT (STDMETHODCALLTYPE *CancelRenderingWithId)(
        IDMDObject *This,
        BSTR sceneId);

    HRESULT (STDMETHODCALLTYPE *Clear)(
        IDMDObject *This);

    HRESULT (STDMETHODCALLTYPE *SetProjectFolder)(
        IDMDObject *This,
        BSTR basePath);

    HRESULT (STDMETHODCALLTYPE *SetVideoStretchMode)(
        IDMDObject *This,
        LONG mode);

    HRESULT (STDMETHODCALLTYPE *SetScoreboardBackgroundImage)(
        IDMDObject *This,
        BSTR filename,
        LONG selectedBrightness,
        LONG unselectedBrightness);

    HRESULT (STDMETHODCALLTYPE *CreateAnimationFromImages)(
        IDMDObject *This,
        LONG fps,
        VARIANT_BOOL loop,
        BSTR imagelist,
        LONG *pRetVal);

    HRESULT (STDMETHODCALLTYPE *RegisterVideo)(
        IDMDObject *This,
        LONG videoStretchMode,
        VARIANT_BOOL loop,
        BSTR videoFilename,
        LONG *pRetVal);

    HRESULT (STDMETHODCALLTYPE *RegisterFont)(
        IDMDObject *This,
        BSTR file,
        LONG *pRetVal);

    HRESULT (STDMETHODCALLTYPE *UnregisterFont)(
        IDMDObject *This,
        LONG registeredFont);

    HRESULT (STDMETHODCALLTYPE *DisplayVersionInfo)(
        IDMDObject *This);

    HRESULT (STDMETHODCALLTYPE *DisplayScoreboard)(
        IDMDObject *This,
        LONG cPlayers,
        LONG highlightedPlayer,
        LONG score1,
        LONG score2,
        LONG score3,
        LONG score4,
        BSTR lowerLeft,
        BSTR lowerRight);

    HRESULT (STDMETHODCALLTYPE *DisplayScoreboard00)(
        IDMDObject *This,
        LONG cPlayers,
        LONG highlightedPlayer,
        LONG score1,
        LONG score2,
        LONG score3,
        LONG score4,
        BSTR lowerLeft,
        BSTR lowerRight);

    HRESULT (STDMETHODCALLTYPE *DisplayScene00)(
        IDMDObject *This,
        BSTR background,
        BSTR toptext,
        LONG topBrightness,
        BSTR bottomtext,
        LONG bottomBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut);

    HRESULT (STDMETHODCALLTYPE *DisplayScene00Ex)(
        IDMDObject *This,
        BSTR background,
        BSTR toptext,
        LONG topBrightness,
        LONG topOutlineBrightness,
        BSTR bottomtext,
        LONG bottomBrightness,
        LONG bottomOutlineBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut);

    HRESULT (STDMETHODCALLTYPE *DisplayScene00ExWithId)(
        IDMDObject *This,
        BSTR sceneId,
        VARIANT_BOOL cancelPrevious,
        BSTR background,
        BSTR toptext,
        LONG topBrightness,
        LONG topOutlineBrightness,
        BSTR bottomtext,
        LONG bottomBrightness,
        LONG bottomOutlineBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut);

    HRESULT (STDMETHODCALLTYPE *ModifyScene00)(
        IDMDObject *This,
        BSTR id,
        BSTR toptext,
        BSTR bottomtext);

    HRESULT (STDMETHODCALLTYPE *ModifyScene00Ex)(
        IDMDObject *This,
        BSTR id,
        BSTR toptext,
        BSTR bottomtext,
        LONG pauseTime);

    HRESULT (STDMETHODCALLTYPE *DisplayScene01)(
        IDMDObject *This,
        BSTR sceneId,
        BSTR background,
        BSTR text,
        LONG textBrightness,
        LONG textOutlineBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut);

    HRESULT (STDMETHODCALLTYPE *DisplayText)(
        IDMDObject *This,
        BSTR text,
        LONG textBrightness,
        LONG textOutlineBrightness);

    HRESULT (STDMETHODCALLTYPE *ScrollingCredits)(
        IDMDObject *This,
        BSTR background,
        BSTR text,
        LONG textBrightness,
        LONG animateIn,
        LONG pauseTime,
        LONG animateOut);

    END_INTERFACE
} IDMDObjectVtbl;

interface IDMDObject {
    CONST_VTBL IDMDObjectVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDMDObject_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDMDObject_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDMDObject_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define IDMDObject_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IDMDObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDMDObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDMDObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
/*** IDMDObject methods ***/
#define IDMDObject_get_FloatProperty(This,pRetVal) (This)->lpVtbl->get_FloatProperty(This,pRetVal)
#define IDMDObject_put_FloatProperty(This,pRetVal) (This)->lpVtbl->put_FloatProperty(This,pRetVal)
#define IDMDObject_Init(This) (This)->lpVtbl->Init(This)
#define IDMDObject_Uninit(This) (This)->lpVtbl->Uninit(This)
#define IDMDObject_GetMajorVersion(This,pRetVal) (This)->lpVtbl->GetMajorVersion(This,pRetVal)
#define IDMDObject_GetMinorVersion(This,pRetVal) (This)->lpVtbl->GetMinorVersion(This,pRetVal)
#define IDMDObject_GetBuildNumber(This,pRetVal) (This)->lpVtbl->GetBuildNumber(This,pRetVal)
#define IDMDObject_SetVisibleVirtualDMD(This,bHide,pRetVal) (This)->lpVtbl->SetVisibleVirtualDMD(This,bHide,pRetVal)
#define IDMDObject_SetFlipY(This,flipY,pRetVal) (This)->lpVtbl->SetFlipY(This,flipY,pRetVal)
#define IDMDObject_IsRendering(This,pRetVal) (This)->lpVtbl->IsRendering(This,pRetVal)
#define IDMDObject_CancelRendering(This) (This)->lpVtbl->CancelRendering(This)
#define IDMDObject_CancelRenderingWithId(This,sceneId) (This)->lpVtbl->CancelRenderingWithId(This,sceneId)
#define IDMDObject_Clear(This) (This)->lpVtbl->Clear(This)
#define IDMDObject_SetProjectFolder(This,basePath) (This)->lpVtbl->SetProjectFolder(This,basePath)
#define IDMDObject_SetVideoStretchMode(This,mode) (This)->lpVtbl->SetVideoStretchMode(This,mode)
#define IDMDObject_SetScoreboardBackgroundImage(This,filename,selectedBrightness,unselectedBrightness) (This)->lpVtbl->SetScoreboardBackgroundImage(This,filename,selectedBrightness,unselectedBrightness)
#define IDMDObject_CreateAnimationFromImages(This,fps,loop,imagelist,pRetVal) (This)->lpVtbl->CreateAnimationFromImages(This,fps,loop,imagelist,pRetVal)
#define IDMDObject_RegisterVideo(This,videoStretchMode,loop,videoFilename,pRetVal) (This)->lpVtbl->RegisterVideo(This,videoStretchMode,loop,videoFilename,pRetVal)
#define IDMDObject_RegisterFont(This,file,pRetVal) (This)->lpVtbl->RegisterFont(This,file,pRetVal)
#define IDMDObject_UnregisterFont(This,registeredFont) (This)->lpVtbl->UnregisterFont(This,registeredFont)
#define IDMDObject_DisplayVersionInfo(This) (This)->lpVtbl->DisplayVersionInfo(This)
#define IDMDObject_DisplayScoreboard(This,cPlayers,highlightedPlayer,score1,score2,score3,score4,lowerLeft,lowerRight) (This)->lpVtbl->DisplayScoreboard(This,cPlayers,highlightedPlayer,score1,score2,score3,score4,lowerLeft,lowerRight)
#define IDMDObject_DisplayScoreboard00(This,cPlayers,highlightedPlayer,score1,score2,score3,score4,lowerLeft,lowerRight) (This)->lpVtbl->DisplayScoreboard00(This,cPlayers,highlightedPlayer,score1,score2,score3,score4,lowerLeft,lowerRight)
#define IDMDObject_DisplayScene00(This,background,toptext,topBrightness,bottomtext,bottomBrightness,animateIn,pauseTime,animateOut) (This)->lpVtbl->DisplayScene00(This,background,toptext,topBrightness,bottomtext,bottomBrightness,animateIn,pauseTime,animateOut)
#define IDMDObject_DisplayScene00Ex(This,background,toptext,topBrightness,topOutlineBrightness,bottomtext,bottomBrightness,bottomOutlineBrightness,animateIn,pauseTime,animateOut) (This)->lpVtbl->DisplayScene00Ex(This,background,toptext,topBrightness,topOutlineBrightness,bottomtext,bottomBrightness,bottomOutlineBrightness,animateIn,pauseTime,animateOut)
#define IDMDObject_DisplayScene00ExWithId(This,sceneId,cancelPrevious,background,toptext,topBrightness,topOutlineBrightness,bottomtext,bottomBrightness,bottomOutlineBrightness,animateIn,pauseTime,animateOut) (This)->lpVtbl->DisplayScene00ExWithId(This,sceneId,cancelPrevious,background,toptext,topBrightness,topOutlineBrightness,bottomtext,bottomBrightness,bottomOutlineBrightness,animateIn,pauseTime,animateOut)
#define IDMDObject_ModifyScene00(This,id,toptext,bottomtext) (This)->lpVtbl->ModifyScene00(This,id,toptext,bottomtext)
#define IDMDObject_ModifyScene00Ex(This,id,toptext,bottomtext,pauseTime) (This)->lpVtbl->ModifyScene00Ex(This,id,toptext,bottomtext,pauseTime)
#define IDMDObject_DisplayScene01(This,sceneId,background,text,textBrightness,textOutlineBrightness,animateIn,pauseTime,animateOut) (This)->lpVtbl->DisplayScene01(This,sceneId,background,text,textBrightness,textOutlineBrightness,animateIn,pauseTime,animateOut)
#define IDMDObject_DisplayText(This,text,textBrightness,textOutlineBrightness) (This)->lpVtbl->DisplayText(This,text,textBrightness,textOutlineBrightness)
#define IDMDObject_ScrollingCredits(This,background,text,textBrightness,animateIn,pauseTime,animateOut) (This)->lpVtbl->ScrollingCredits(This,background,text,textBrightness,animateIn,pauseTime,animateOut)
#else
/*** IUnknown methods ***/
static __WIDL_INLINE HRESULT IDMDObject_QueryInterface(IDMDObject* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static __WIDL_INLINE ULONG IDMDObject_AddRef(IDMDObject* This) {
    return This->lpVtbl->AddRef(This);
}
static __WIDL_INLINE ULONG IDMDObject_Release(IDMDObject* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
static __WIDL_INLINE HRESULT IDMDObject_GetTypeInfoCount(IDMDObject* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
static __WIDL_INLINE HRESULT IDMDObject_GetTypeInfo(IDMDObject* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
static __WIDL_INLINE HRESULT IDMDObject_GetIDsOfNames(IDMDObject* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
static __WIDL_INLINE HRESULT IDMDObject_Invoke(IDMDObject* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
/*** IDMDObject methods ***/
static __WIDL_INLINE HRESULT IDMDObject_get_FloatProperty(IDMDObject* This,single *pRetVal) {
    return This->lpVtbl->get_FloatProperty(This,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_put_FloatProperty(IDMDObject* This,single pRetVal) {
    return This->lpVtbl->put_FloatProperty(This,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_Init(IDMDObject* This) {
    return This->lpVtbl->Init(This);
}
static __WIDL_INLINE HRESULT IDMDObject_Uninit(IDMDObject* This) {
    return This->lpVtbl->Uninit(This);
}
static __WIDL_INLINE HRESULT IDMDObject_GetMajorVersion(IDMDObject* This,LONG *pRetVal) {
    return This->lpVtbl->GetMajorVersion(This,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_GetMinorVersion(IDMDObject* This,LONG *pRetVal) {
    return This->lpVtbl->GetMinorVersion(This,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_GetBuildNumber(IDMDObject* This,LONG *pRetVal) {
    return This->lpVtbl->GetBuildNumber(This,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_SetVisibleVirtualDMD(IDMDObject* This,VARIANT_BOOL bHide,VARIANT_BOOL *pRetVal) {
    return This->lpVtbl->SetVisibleVirtualDMD(This,bHide,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_SetFlipY(IDMDObject* This,VARIANT_BOOL flipY,VARIANT_BOOL *pRetVal) {
    return This->lpVtbl->SetFlipY(This,flipY,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_IsRendering(IDMDObject* This,VARIANT_BOOL *pRetVal) {
    return This->lpVtbl->IsRendering(This,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_CancelRendering(IDMDObject* This) {
    return This->lpVtbl->CancelRendering(This);
}
static __WIDL_INLINE HRESULT IDMDObject_CancelRenderingWithId(IDMDObject* This,BSTR sceneId) {
    return This->lpVtbl->CancelRenderingWithId(This,sceneId);
}
static __WIDL_INLINE HRESULT IDMDObject_Clear(IDMDObject* This) {
    return This->lpVtbl->Clear(This);
}
static __WIDL_INLINE HRESULT IDMDObject_SetProjectFolder(IDMDObject* This,BSTR basePath) {
    return This->lpVtbl->SetProjectFolder(This,basePath);
}
static __WIDL_INLINE HRESULT IDMDObject_SetVideoStretchMode(IDMDObject* This,LONG mode) {
    return This->lpVtbl->SetVideoStretchMode(This,mode);
}
static __WIDL_INLINE HRESULT IDMDObject_SetScoreboardBackgroundImage(IDMDObject* This,BSTR filename,LONG selectedBrightness,LONG unselectedBrightness) {
    return This->lpVtbl->SetScoreboardBackgroundImage(This,filename,selectedBrightness,unselectedBrightness);
}
static __WIDL_INLINE HRESULT IDMDObject_CreateAnimationFromImages(IDMDObject* This,LONG fps,VARIANT_BOOL loop,BSTR imagelist,LONG *pRetVal) {
    return This->lpVtbl->CreateAnimationFromImages(This,fps,loop,imagelist,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_RegisterVideo(IDMDObject* This,LONG videoStretchMode,VARIANT_BOOL loop,BSTR videoFilename,LONG *pRetVal) {
    return This->lpVtbl->RegisterVideo(This,videoStretchMode,loop,videoFilename,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_RegisterFont(IDMDObject* This,BSTR file,LONG *pRetVal) {
    return This->lpVtbl->RegisterFont(This,file,pRetVal);
}
static __WIDL_INLINE HRESULT IDMDObject_UnregisterFont(IDMDObject* This,LONG registeredFont) {
    return This->lpVtbl->UnregisterFont(This,registeredFont);
}
static __WIDL_INLINE HRESULT IDMDObject_DisplayVersionInfo(IDMDObject* This) {
    return This->lpVtbl->DisplayVersionInfo(This);
}
static __WIDL_INLINE HRESULT IDMDObject_DisplayScoreboard(IDMDObject* This,LONG cPlayers,LONG highlightedPlayer,LONG score1,LONG score2,LONG score3,LONG score4,BSTR lowerLeft,BSTR lowerRight) {
    return This->lpVtbl->DisplayScoreboard(This,cPlayers,highlightedPlayer,score1,score2,score3,score4,lowerLeft,lowerRight);
}
static __WIDL_INLINE HRESULT IDMDObject_DisplayScoreboard00(IDMDObject* This,LONG cPlayers,LONG highlightedPlayer,LONG score1,LONG score2,LONG score3,LONG score4,BSTR lowerLeft,BSTR lowerRight) {
    return This->lpVtbl->DisplayScoreboard00(This,cPlayers,highlightedPlayer,score1,score2,score3,score4,lowerLeft,lowerRight);
}
static __WIDL_INLINE HRESULT IDMDObject_DisplayScene00(IDMDObject* This,BSTR background,BSTR toptext,LONG topBrightness,BSTR bottomtext,LONG bottomBrightness,LONG animateIn,LONG pauseTime,LONG animateOut) {
    return This->lpVtbl->DisplayScene00(This,background,toptext,topBrightness,bottomtext,bottomBrightness,animateIn,pauseTime,animateOut);
}
static __WIDL_INLINE HRESULT IDMDObject_DisplayScene00Ex(IDMDObject* This,BSTR background,BSTR toptext,LONG topBrightness,LONG topOutlineBrightness,BSTR bottomtext,LONG bottomBrightness,LONG bottomOutlineBrightness,LONG animateIn,LONG pauseTime,LONG animateOut) {
    return This->lpVtbl->DisplayScene00Ex(This,background,toptext,topBrightness,topOutlineBrightness,bottomtext,bottomBrightness,bottomOutlineBrightness,animateIn,pauseTime,animateOut);
}
static __WIDL_INLINE HRESULT IDMDObject_DisplayScene00ExWithId(IDMDObject* This,BSTR sceneId,VARIANT_BOOL cancelPrevious,BSTR background,BSTR toptext,LONG topBrightness,LONG topOutlineBrightness,BSTR bottomtext,LONG bottomBrightness,LONG bottomOutlineBrightness,LONG animateIn,LONG pauseTime,LONG animateOut) {
    return This->lpVtbl->DisplayScene00ExWithId(This,sceneId,cancelPrevious,background,toptext,topBrightness,topOutlineBrightness,bottomtext,bottomBrightness,bottomOutlineBrightness,animateIn,pauseTime,animateOut);
}
static __WIDL_INLINE HRESULT IDMDObject_ModifyScene00(IDMDObject* This,BSTR id,BSTR toptext,BSTR bottomtext) {
    return This->lpVtbl->ModifyScene00(This,id,toptext,bottomtext);
}
static __WIDL_INLINE HRESULT IDMDObject_ModifyScene00Ex(IDMDObject* This,BSTR id,BSTR toptext,BSTR bottomtext,LONG pauseTime) {
    return This->lpVtbl->ModifyScene00Ex(This,id,toptext,bottomtext,pauseTime);
}
static __WIDL_INLINE HRESULT IDMDObject_DisplayScene01(IDMDObject* This,BSTR sceneId,BSTR background,BSTR text,LONG textBrightness,LONG textOutlineBrightness,LONG animateIn,LONG pauseTime,LONG animateOut) {
    return This->lpVtbl->DisplayScene01(This,sceneId,background,text,textBrightness,textOutlineBrightness,animateIn,pauseTime,animateOut);
}
static __WIDL_INLINE HRESULT IDMDObject_DisplayText(IDMDObject* This,BSTR text,LONG textBrightness,LONG textOutlineBrightness) {
    return This->lpVtbl->DisplayText(This,text,textBrightness,textOutlineBrightness);
}
static __WIDL_INLINE HRESULT IDMDObject_ScrollingCredits(IDMDObject* This,BSTR background,BSTR text,LONG textBrightness,LONG animateIn,LONG pauseTime,LONG animateOut) {
    return This->lpVtbl->ScrollingCredits(This,background,text,textBrightness,animateIn,pauseTime,animateOut);
}
#endif
#endif

#endif


#endif  /* __IDMDObject_INTERFACE_DEFINED__ */

/*****************************************************************************
 * DMDObject coclass
 */

DEFINE_GUID(CLSID_DMDObject, 0xe1612654, 0x304a, 0x4e07, 0xa2,0x36, 0xeb,0x64,0xd6,0xd4,0xf5,0x11);

#ifdef __cplusplus
class DECLSPEC_UUID("e1612654-304a-4e07-a236-eb64d6d4f511") DMDObject;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(DMDObject, 0xe1612654, 0x304a, 0x4e07, 0xa2,0x36, 0xeb,0x64,0xd6,0xd4,0xf5,0x11)
#endif
#endif

/*****************************************************************************
 * IDMDObjectEvents dispinterface
 */
#ifndef __IDMDObjectEvents_DISPINTERFACE_DEFINED__
#define __IDMDObjectEvents_DISPINTERFACE_DEFINED__

DEFINE_GUID(DIID_IDMDObjectEvents, 0x0decff48, 0x5492, 0x43e7, 0xab,0x6c, 0xbf,0xd9,0x24,0x5f,0x2e,0xad);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("0decff48-5492-43e7-ab6c-bfd9245f2ead")
IDMDObjectEvents : public IDispatch
{
};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDMDObjectEvents, 0x0decff48, 0x5492, 0x43e7, 0xab,0x6c, 0xbf,0xd9,0x24,0x5f,0x2e,0xad)
#endif
#else
typedef struct IDMDObjectEventsVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDMDObjectEvents *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDMDObjectEvents *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDMDObjectEvents *This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        IDMDObjectEvents *This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        IDMDObjectEvents *This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        IDMDObjectEvents *This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        IDMDObjectEvents *This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    END_INTERFACE
} IDMDObjectEventsVtbl;

interface IDMDObjectEvents {
    CONST_VTBL IDMDObjectEventsVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDMDObjectEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDMDObjectEvents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDMDObjectEvents_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define IDMDObjectEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IDMDObjectEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDMDObjectEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDMDObjectEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#else
/*** IUnknown methods ***/
static __WIDL_INLINE HRESULT IDMDObjectEvents_QueryInterface(IDMDObjectEvents* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static __WIDL_INLINE ULONG IDMDObjectEvents_AddRef(IDMDObjectEvents* This) {
    return This->lpVtbl->AddRef(This);
}
static __WIDL_INLINE ULONG IDMDObjectEvents_Release(IDMDObjectEvents* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
static __WIDL_INLINE HRESULT IDMDObjectEvents_GetTypeInfoCount(IDMDObjectEvents* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
static __WIDL_INLINE HRESULT IDMDObjectEvents_GetTypeInfo(IDMDObjectEvents* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
static __WIDL_INLINE HRESULT IDMDObjectEvents_GetIDsOfNames(IDMDObjectEvents* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
static __WIDL_INLINE HRESULT IDMDObjectEvents_Invoke(IDMDObjectEvents* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
#endif
#endif

#endif

#endif  /* __IDMDObjectEvents_DISPINTERFACE_DEFINED__ */

#endif /* __UltraDMD_LIBRARY_DEFINED__ */
/* Begin additional prototypes for all interfaces */

ULONG           __RPC_USER BSTR_UserSize     (ULONG *, ULONG, BSTR *);
unsigned char * __RPC_USER BSTR_UserMarshal  (ULONG *, unsigned char *, BSTR *);
unsigned char * __RPC_USER BSTR_UserUnmarshal(ULONG *, unsigned char *, BSTR *);
void            __RPC_USER BSTR_UserFree     (ULONG *, BSTR *);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __ultradmd_i_h__ */
