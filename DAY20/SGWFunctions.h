#ifndef SGWFunctions_H
#define SGWFunctions_H

#include "Tool.h"
//��������TTCN-3ģ���ͷ�ļ�

#include "ControlTemplates.h"
#include "S11Templates.h"
#include "TestSystemConfig.h"

namespace	SGWFunctions
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

	// ���������������
	class CLASS_SGWJob : public CFunction
	{
	public:
		CLASS_SGWJob();
		~CLASS_SGWJob();
		void Body(CComponentReference &TTCN_self);
		void _Body(TestSystemConfig::TTCN_SGW &TTCN_self);
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
	};
	extern CLASS_SGWJob TTCN_SGWJob;

	// ���������������
	class CLASS_F3_MBR_MBRs : public CFunction
	{
	public:
		CLASS_F3_MBR_MBRs();
		~CLASS_F3_MBR_MBRs();
		void Body(CComponentReference &TTCN_self);
		void _Body(TestSystemConfig::TTCN_SGW &TTCN_self);
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
	};
	extern CLASS_F3_MBR_MBRs TTCN_F3_MBR_MBRs;

	// ģ���������
	class TTCN_SGWFunctions : public CModule
	{
	public:
		TTCN_SGWFunctions();
		~TTCN_SGWFunctions();
		// �����ⲿ���� 
		TciExternalConstList GetExternalCst();
		// ����ģ����� 
		TciModuleParameterList GetTciModuleParameterList();
	};

	extern TTCN_SGWFunctions *_g_pModule;

	void Init();

	void Release();

}
#endif
