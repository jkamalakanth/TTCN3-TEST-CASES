#ifndef S11Templates_H
#define S11Templates_H

#include "Tool.h"
//包含其他TTCN-3模块的头文件

#include "S11Messages.h"

namespace	S11Templates
{

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

	extern S11Messages::TTCN_GTPC_MBR TTCN_GTPC_MBR_R_T1;

	extern S11Messages::TTCN_GTPC_MBRs TTCN_GTPC_MBRs_S_T1;

	// 模块类的声明
	class TTCN_S11Templates : public CModule
	{
	public:
		TTCN_S11Templates();
		~TTCN_S11Templates();
		// 配置外部常量 
		TciExternalConstList GetExternalCst();
		// 配置模块参数 
		TciModuleParameterList GetTciModuleParameterList();
	};

	extern TTCN_S11Templates *_g_pModule;

	void Init();

	void Release();

}
#endif
