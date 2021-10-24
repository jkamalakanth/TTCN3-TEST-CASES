#ifndef ControlTemplates_H
#define ControlTemplates_H

#include "Tool.h"
//��������TTCN-3ģ���ͷ�ļ�

#include "ControlMessages.h"

namespace	ControlTemplates
{

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

	extern ControlMessages::TTCN_MTC_TO_PTC_COMMAND TTCN_MTC_TO_PTC_COMMAND_T1;

	extern ControlMessages::TTCN_MTC_TO_PTC_COMMAND TTCN_MTC_TO_PTC_COMMAND_T2;

	extern ControlMessages::TTCN_PTC_TO_MTC_REPORT TTCN_PTC_TO_MTC_REPORT_T1;

	extern ControlMessages::TTCN_PTC_TO_MTC_REPORT TTCN_PTC_TO_MTC_REPORT_T2;

	// ģ���������
	class TTCN_ControlTemplates : public CModule
	{
	public:
		TTCN_ControlTemplates();
		~TTCN_ControlTemplates();
		// �����ⲿ���� 
		TciExternalConstList GetExternalCst();
		// ����ģ����� 
		TciModuleParameterList GetTciModuleParameterList();
	};

	extern TTCN_ControlTemplates *_g_pModule;

	void Init();

	void Release();

}
#endif
