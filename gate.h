// Gate.h: Definition of the Gate class
//
//////////////////////////////////////////////////////////////////////
#pragma once
#if !defined(AFX_GATE_H__EDC63CB2_226F_4606_99A9_0C2DB8FE1E3B__INCLUDED_)
#define AFX_GATE_H__EDC63CB2_226F_4606_99A9_0C2DB8FE1E3B__INCLUDED_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Gate

class GateData
	{
public:
	Vertex2D m_vCenter;
	float m_length;
	float m_height;
	float m_rotation;
    char m_szMaterial[32];
	TimerDataRoot m_tdr;
	float m_elasticity;
	float m_friction;
	float m_scatter;
	char m_szSurface[MAXTOKEN];
	char m_szImageFront[MAXTOKEN];
	char m_szImageBack[MAXTOKEN];
	float m_angleMin;
	float m_angleMax;
	bool m_fShowBracket;
	bool m_fCollidable;
	bool m_fVisible;
	bool m_fEnableLighting;
	};

class Gate :
	public IDispatchImpl<IGate, &IID_IGate, &LIBID_VPinballLib>,
	//public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<Gate,&CLSID_Gate>,
	public EventProxy<Gate, &DIID_IGateEvents>,
	public IConnectionPointContainerImpl<Gate>,
	public IProvideClassInfo2Impl<&CLSID_Gate, &DIID_IGateEvents, &LIBID_VPinballLib>,
	public ISelect,
	public IEditable,
	public Hitable,
	public IScriptable,
	public IFireEvents,
	public IPerPropertyBrowsing // Ability to fill in dropdown in property browser
{
public:
	Gate();
	~Gate();

BEGIN_COM_MAP(Gate)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IGate)
	//COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IPerPropertyBrowsing)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(Light)
// Remove the comment from the line above if you don't want your object to
// support aggregation.

BEGIN_CONNECTION_POINT_MAP(Gate)
	CONNECTION_POINT_ENTRY(DIID_IGateEvents)
END_CONNECTION_POINT_MAP()

STANDARD_EDITABLE_DECLARES(Gate, eItemGate, GATE, 1)

//DECLARE_NOT_AGGREGATABLE(Gate)
// Remove the comment from the line above if you don't want your object to
// support aggregation.

DECLARE_REGISTRY_RESOURCEID(IDR_GATE)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

	virtual void GetDialogPanes(Vector<PropertyPane> *pvproppane);

	virtual void MoveOffset(const float dx, const float dy);
	virtual void SetObjectPos();
	// Multi-object manipulation
	virtual void GetCenter(Vertex2D * const pv) const;
	virtual void PutCenter(const Vertex2D * const pv);
   void PrepareStatic(RenderDevice* pd3dDevice);
   void PrepareMovers(RenderDevice* pd3dDevice );

	virtual void RenderBlueprint(Sur *psur);

    int angleToFrame(float angle) const;

	void WriteRegDefaults();
    void UpdateWire( RenderDevice *pd3dDevice );
    void RenderObject( RenderDevice* pd3dDevice);

	PinTable *m_ptable;

	GateData m_d;

private:
	LineSeg *m_plineseg;
	HitGate *m_phitgate;

   float m_posZ;        // z coordinate for rendering

   VertexBuffer *wireVertexBuffer;
   IndexBuffer *wireIndexBuffer;
   VertexBuffer *bracketVertexBuffer;
   IndexBuffer *bracketIndexBuffer;
   Vertex3D_NoTex2 *wireVertices;
   float baseHeight;
// IGate
public:
	STDMETHOD(get_Elasticity)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_Elasticity)(/*[in]*/ float newVal);
	STDMETHOD(get_Open)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	//STDMETHOD(put_Open)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(put_Open)(/*[in]*/ VARIANT_BOOL newVal);

	STDMETHOD(get_Surface)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Surface)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Y)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_Y)(/*[in]*/ float newVal);
	STDMETHOD(get_X)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_X)(/*[in]*/ float newVal);
	STDMETHOD(get_Rotation)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_Rotation)(/*[in]*/ float newVal);
	STDMETHOD(get_Length)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_Length)(/*[in]*/ float newVal);
	STDMETHOD(get_Material)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Material)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Height)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_Height)(/*[in]*/ float newVal);
	STDMETHOD(get_ShowBracket)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ShowBracket)(/*[in]*/ VARIANT_BOOL newVal);

	STDMETHOD(get_CloseAngle)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_CloseAngle)(/*[in]*/ float newVal);
	STDMETHOD(get_OpenAngle)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_OpenAngle)(/*[in]*/ float newVal);
	STDMETHOD(get_Collidable)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Collidable)(/*[in]*/ VARIANT_BOOL newVal);

	STDMETHOD(Move)(int dir, float speed, float angle);

	STDMETHOD(get_Friction)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_Friction)(/*[in]*/ float newVal);
	STDMETHOD(get_Visible)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Visible)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_EnableLighting)(/*[out, retval]*/ VARIANT_BOOL *pVal);
    STDMETHOD(put_EnableLighting)(/*[in]*/ VARIANT_BOOL newVal);
    STDMETHOD(get_CurrentAngle)(/*[out, retval]*/ float *pVal);
};

#endif // !defined(AFX_GATE_H__EDC63CB2_226F_4606_99A9_0C2DB8FE1E3B__INCLUDED_)
