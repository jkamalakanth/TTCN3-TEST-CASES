#ifndef TestSystemConfig_H
#define TestSystemConfig_H

#include "Tool.h"
//��������TTCN-3ģ���ͷ�ļ�

#include "ControlMessages.h"
#include "S11Messages.h"
#include "X2APMessages.h"

namespace	TestSystemConfig
{

	class TTCN_X2APPort;
	class TTCN_S11Port;
	class TTCN_MTCControlPort;
	class TTCN_PTCControlPort;
	class TTCN_ENB;
	class TTCN_SGW;
	class TTCN_MTC;
	class TTCN_TSI;

	// Anytype �����������
	class CAnyType:public CUnion
	{
	public:

		explicit CAnyType(ValueOrTemplate vort = DATA_VALUE, const TypeInfo *info = &m_typeInfo): CUnion(info, vort) {}
		CAnyType(const TypeInfo *info, ValueOrTemplate vort): CUnion(info, vort) {}

		~CAnyType() { }

		CAnyType( const CAnyType &data, const TypeInfo *info = &m_typeInfo): CUnion(data, info) {}

		CAnyType &operator=(const CData &data);

		static CAnyType *InternalCreate();

		CInteger &FIELD_integer();
		CFloat &FIELD_float();
		CBoolean &FIELD_boolean();
		CVerdict &FIELD_verdicttype();
		CBitString &FIELD_bitstring();
		COctetString &FIELD_octetstring();
		CHexString &FIELD_hexstring();
		CCharString &FIELD_charstring();

		static UnionExtraInfo m_extraTypeInfo;
		static TTCN_UINT32 m_valueIndex[8];
		static FieldInfo m_fieldInfo[8];
		static TypeInfo m_typeInfo;
	};

	// �˿ڷ����������
	class TTCN_X2APPort : public CPort
	{
	public:
		TTCN_X2APPort();
		~TTCN_X2APPort();
		static CData*InternalCreate() {return new TTCN_X2APPort();};
		static TypeInfo m_typeInfo;
	};

	// �˿ڷ����������
	class TTCN_S11Port : public CPort
	{
	public:
		TTCN_S11Port();
		~TTCN_S11Port();
		static CData*InternalCreate() {return new TTCN_S11Port();};
		static TypeInfo m_typeInfo;
	};

	// �˿ڷ����������
	class TTCN_MTCControlPort : public CPort
	{
	public:
		TTCN_MTCControlPort();
		~TTCN_MTCControlPort();
		static CData*InternalCreate() {return new TTCN_MTCControlPort();};
		static TypeInfo m_typeInfo;
	};

	// �˿ڷ����������
	class TTCN_PTCControlPort : public CPort
	{
	public:
		TTCN_PTCControlPort();
		~TTCN_PTCControlPort();
		static CData*InternalCreate() {return new TTCN_PTCControlPort();};
		static TypeInfo m_typeInfo;
	};

	//��������������
	class TTCN_ENB:virtual public CComponentReference
	{
	public:
		TTCN_ENB();
		~TTCN_ENB();
		TTCN_ENB(const TTCN_ENB &);
		TTCN_ENB& operator=(const CComponentReference&);
		TTCN_ENB& operator=(const CNull &rNull){SetNull(); return *this;};
		TriPortIdList GetTriPortIdList();
		CComponentReference *Clone() const;

		CTimer &FIELD_X2APTimer();

		TTCN_PTCControlPort &FIELD_PTCCP1();
		TTCN_X2APPort &FIELD_X2APP();
		void Init();
		static ComponentExtraInfo m_extraTypeInfo;
		static TypeInfo m_typeInfo;
		static CData *InternalCreate(){CData *pData = new TTCN_ENB();return pData;};
	private:


		CTimer *_X2APTimer;

		TTCN_PTCControlPort *_PTCCP1;
		TTCN_X2APPort *_X2APP;
	};

	//��������������
	class TTCN_SGW:virtual public CComponentReference
	{
	public:
		TTCN_SGW();
		~TTCN_SGW();
		TTCN_SGW(const TTCN_SGW &);
		TTCN_SGW& operator=(const CComponentReference&);
		TTCN_SGW& operator=(const CNull &rNull){SetNull(); return *this;};
		TriPortIdList GetTriPortIdList();
		CComponentReference *Clone() const;

		CTimer &FIELD_S11Timer();

		TTCN_PTCControlPort &FIELD_PTCCP2();
		TTCN_S11Port &FIELD_S11P();
		void Init();
		static ComponentExtraInfo m_extraTypeInfo;
		static TypeInfo m_typeInfo;
		static CData *InternalCreate(){CData *pData = new TTCN_SGW();return pData;};
	private:


		CTimer *_S11Timer;

		TTCN_PTCControlPort *_PTCCP2;
		TTCN_S11Port *_S11P;
	};

	//��������������
	class TTCN_MTC:virtual public CComponentReference
	{
	public:
		TTCN_MTC();
		~TTCN_MTC();
		TTCN_MTC(const TTCN_MTC &);
		TTCN_MTC& operator=(const CComponentReference&);
		TTCN_MTC& operator=(const CNull &rNull){SetNull(); return *this;};
		TriPortIdList GetTriPortIdList();
		CComponentReference *Clone() const;

		TTCN_MTCControlPort &FIELD_MTCCP1();
		TTCN_MTCControlPort &FIELD_MTCCP2();
		void Init();
		static ComponentExtraInfo m_extraTypeInfo;
		static TypeInfo m_typeInfo;
		static CData *InternalCreate(){CData *pData = new TTCN_MTC();return pData;};
	private:


		TTCN_MTCControlPort *_MTCCP1;
		TTCN_MTCControlPort *_MTCCP2;
	};

	//��������������
	class TTCN_TSI:virtual public CComponentReference
	{
	public:
		TTCN_TSI();
		~TTCN_TSI();
		TTCN_TSI(const TTCN_TSI &);
		TTCN_TSI& operator=(const CComponentReference&);
		TTCN_TSI& operator=(const CNull &rNull){SetNull(); return *this;};
		TriPortIdList GetTriPortIdList();
		CComponentReference *Clone() const;

		TTCN_S11Port &FIELD_S11T();
		TTCN_X2APPort &FIELD_X2APT();
		void Init();
		static ComponentExtraInfo m_extraTypeInfo;
		static TypeInfo m_typeInfo;
		static CData *InternalCreate(){CData *pData = new TTCN_TSI();return pData;};
	private:


		TTCN_S11Port *_S11T;
		TTCN_X2APPort *_X2APT;
	};

	// ģ���������
	class TTCN_TestSystemConfig : public CModule
	{
	public:
		TTCN_TestSystemConfig();
		~TTCN_TestSystemConfig();
		// �����ⲿ���� 
		TciExternalConstList GetExternalCst();
		// ����ģ����� 
		TciModuleParameterList GetTciModuleParameterList();
	};

	extern TTCN_TestSystemConfig *_g_pModule;

	void Init();

	void Release();

}
#endif
