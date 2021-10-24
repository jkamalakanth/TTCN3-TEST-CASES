#ifndef X2APMessages_H
#define X2APMessages_H

#include "Tool.h"

namespace	X2APMessages
{

	class TTCN_X2AP_PDU;
	class TTCN_S1AP_PDU;

	// Anytype 翻译类的声明
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

	//子类型翻译类的声明
	class TTCN_X2AP_PDU:public CCharString
	{
	public:
		explicit TTCN_X2AP_PDU(ValueOrTemplate vort = DATA_VALUE): CCharString(&m_typeInfo, vort) {}
		TTCN_X2AP_PDU(const TypeInfo *m_typeInfo, ValueOrTemplate vort = DATA_VALUE): CCharString(m_typeInfo, vort) {}
		TTCN_X2AP_PDU(const CCharString &data, const TypeInfo *m_typeInfo = NULL):CCharString(data, m_typeInfo){}
		~TTCN_X2AP_PDU() {}
		TTCN_X2AP_PDU(const CCharString &data):CCharString(data, &m_typeInfo) {}
		TTCN_X2AP_PDU &operator=(const CData &data);
		static TTCN_X2AP_PDU *InternalCreate();
		static TypeInfo m_typeInfo;
	};

	//子类型翻译类的声明
	class TTCN_S1AP_PDU:public CCharString
	{
	public:
		explicit TTCN_S1AP_PDU(ValueOrTemplate vort = DATA_VALUE): CCharString(&m_typeInfo, vort) {}
		TTCN_S1AP_PDU(const TypeInfo *m_typeInfo, ValueOrTemplate vort = DATA_VALUE): CCharString(m_typeInfo, vort) {}
		TTCN_S1AP_PDU(const CCharString &data, const TypeInfo *m_typeInfo = NULL):CCharString(data, m_typeInfo){}
		~TTCN_S1AP_PDU() {}
		TTCN_S1AP_PDU(const CCharString &data):CCharString(data, &m_typeInfo) {}
		TTCN_S1AP_PDU &operator=(const CData &data);
		static TTCN_S1AP_PDU *InternalCreate();
		static TypeInfo m_typeInfo;
	};

	// 模块类的声明
	class TTCN_X2APMessages : public CModule
	{
	public:
		TTCN_X2APMessages();
		~TTCN_X2APMessages();
		// 配置外部常量 
		TciExternalConstList GetExternalCst();
		// 配置模块参数 
		TciModuleParameterList GetTciModuleParameterList();
	};

	extern TTCN_X2APMessages *_g_pModule;

	void Init();

	void Release();

}
#endif
