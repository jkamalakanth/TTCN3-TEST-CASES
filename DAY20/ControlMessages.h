#ifndef ControlMessages_H
#define ControlMessages_H

#include "Tool.h"

namespace	ControlMessages
{

	class TTCN_MTC_TO_PTC_COMMAND;
	class TTCN_PTC_TO_MTC_REPORT;

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
	class TTCN_MTC_TO_PTC_COMMAND:public CCharString
	{
	public:
		explicit TTCN_MTC_TO_PTC_COMMAND(ValueOrTemplate vort = DATA_VALUE): CCharString(&m_typeInfo, vort) {}
		TTCN_MTC_TO_PTC_COMMAND(const TypeInfo *m_typeInfo, ValueOrTemplate vort = DATA_VALUE): CCharString(m_typeInfo, vort) {}
		TTCN_MTC_TO_PTC_COMMAND(const CCharString &data, const TypeInfo *m_typeInfo = NULL):CCharString(data, m_typeInfo){}
		~TTCN_MTC_TO_PTC_COMMAND() {}
		TTCN_MTC_TO_PTC_COMMAND(const CCharString &data):CCharString(data, &m_typeInfo) {}
		TTCN_MTC_TO_PTC_COMMAND &operator=(const CData &data);
		static TTCN_MTC_TO_PTC_COMMAND *InternalCreate();
		static TypeInfo m_typeInfo;
	};

	//子类型翻译类的声明
	class TTCN_PTC_TO_MTC_REPORT:public CCharString
	{
	public:
		explicit TTCN_PTC_TO_MTC_REPORT(ValueOrTemplate vort = DATA_VALUE): CCharString(&m_typeInfo, vort) {}
		TTCN_PTC_TO_MTC_REPORT(const TypeInfo *m_typeInfo, ValueOrTemplate vort = DATA_VALUE): CCharString(m_typeInfo, vort) {}
		TTCN_PTC_TO_MTC_REPORT(const CCharString &data, const TypeInfo *m_typeInfo = NULL):CCharString(data, m_typeInfo){}
		~TTCN_PTC_TO_MTC_REPORT() {}
		TTCN_PTC_TO_MTC_REPORT(const CCharString &data):CCharString(data, &m_typeInfo) {}
		TTCN_PTC_TO_MTC_REPORT &operator=(const CData &data);
		static TTCN_PTC_TO_MTC_REPORT *InternalCreate();
		static TypeInfo m_typeInfo;
	};

	// 模块类的声明
	class TTCN_ControlMessages : public CModule
	{
	public:
		TTCN_ControlMessages();
		~TTCN_ControlMessages();
		// 配置外部常量 
		TciExternalConstList GetExternalCst();
		// 配置模块参数 
		TciModuleParameterList GetTciModuleParameterList();
	};

	extern TTCN_ControlMessages *_g_pModule;

	void Init();

	void Release();

}
#endif
