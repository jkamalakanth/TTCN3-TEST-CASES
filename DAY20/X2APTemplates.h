#ifndef X2APTemplates_H
#define X2APTemplates_H

#include "Tool.h"
//包含其他TTCN-3模块的头文件

#include "X2APMessages.h"

namespace	X2APTemplates
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

	extern X2APMessages::TTCN_X2AP_PDU TTCN_X2AP_PDU_ENB1_HANDOVER_REQUEST_S_T1;

	extern X2APMessages::TTCN_X2AP_PDU TTCN_X2AP_PDU_ENB1_HANDOVER_REQUEST_ACK_R_T1;

	extern X2APMessages::TTCN_X2AP_PDU TTCN_X2AP_PDU_ENB1_SN_STATUS_TRANSFER_S_T1;

	extern X2APMessages::TTCN_X2AP_PDU TTCN_X2AP_PDU_ENB1_UE_CONTEXT_RELEASE_R_T1;

	extern X2APMessages::TTCN_S1AP_PDU TTCN_S1AP_PDU_ENB2_PATHSWITCH_REQUEST_S_T1;

	extern X2APMessages::TTCN_S1AP_PDU TTCN_S1AP_PDU_ENB2_PATHSWITCH_RESPONSE_R_T1;

	// 模块类的声明
	class TTCN_X2APTemplates : public CModule
	{
	public:
		TTCN_X2APTemplates();
		~TTCN_X2APTemplates();
		// 配置外部常量 
		TciExternalConstList GetExternalCst();
		// 配置模块参数 
		TciModuleParameterList GetTciModuleParameterList();
	};

	extern TTCN_X2APTemplates *_g_pModule;

	void Init();

	void Release();

}
#endif
