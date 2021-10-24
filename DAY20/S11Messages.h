#ifndef S11Messages_H
#define S11Messages_H

#include "Tool.h"

namespace	S11Messages
{

	class TTCN_GTPC_MBR;
	class TTCN_GTPC_MBRs;

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
	class TTCN_GTPC_MBR:public CCharString
	{
	public:
		explicit TTCN_GTPC_MBR(ValueOrTemplate vort = DATA_VALUE): CCharString(&m_typeInfo, vort) {}
		TTCN_GTPC_MBR(const TypeInfo *m_typeInfo, ValueOrTemplate vort = DATA_VALUE): CCharString(m_typeInfo, vort) {}
		TTCN_GTPC_MBR(const CCharString &data, const TypeInfo *m_typeInfo = NULL):CCharString(data, m_typeInfo){}
		~TTCN_GTPC_MBR() {}
		TTCN_GTPC_MBR(const CCharString &data):CCharString(data, &m_typeInfo) {}
		TTCN_GTPC_MBR &operator=(const CData &data);
		static TTCN_GTPC_MBR *InternalCreate();
		static TypeInfo m_typeInfo;
	};

	//子类型翻译类的声明
	class TTCN_GTPC_MBRs:public CCharString
	{
	public:
		explicit TTCN_GTPC_MBRs(ValueOrTemplate vort = DATA_VALUE): CCharString(&m_typeInfo, vort) {}
		TTCN_GTPC_MBRs(const TypeInfo *m_typeInfo, ValueOrTemplate vort = DATA_VALUE): CCharString(m_typeInfo, vort) {}
		TTCN_GTPC_MBRs(const CCharString &data, const TypeInfo *m_typeInfo = NULL):CCharString(data, m_typeInfo){}
		~TTCN_GTPC_MBRs() {}
		TTCN_GTPC_MBRs(const CCharString &data):CCharString(data, &m_typeInfo) {}
		TTCN_GTPC_MBRs &operator=(const CData &data);
		static TTCN_GTPC_MBRs *InternalCreate();
		static TypeInfo m_typeInfo;
	};

	// 模块类的声明
	class TTCN_S11Messages : public CModule
	{
	public:
		TTCN_S11Messages();
		~TTCN_S11Messages();
		// 配置外部常量 
		TciExternalConstList GetExternalCst();
		// 配置模块参数 
		TciModuleParameterList GetTciModuleParameterList();
	};

	extern TTCN_S11Messages *_g_pModule;

	void Init();

	void Release();

}
#endif
