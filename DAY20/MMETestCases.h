#ifndef MMETestCases_H
#define MMETestCases_H

#include "Tool.h"
//包含其他TTCN-3模块的头文件

#include "ControlTemplates.h"
#include "ENBFunctions.h"
#include "SGWFunctions.h"
#include "TestSystemConfig.h"

namespace	MMETestCases
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

	//测试例翻译类的声明
	class CLASS_MMETEST_NUES_ATTACH_TEST_001:public CTestCase
	{
	public:
		CLASS_MMETEST_NUES_ATTACH_TEST_001();
		~CLASS_MMETEST_NUES_ATTACH_TEST_001();
		void Body(CComponentReference &TTCN_self);
		void _Body(TestSystemConfig::TTCN_MTC &TTCN_self);
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
		TriPortIdList GetTestCaseTSI();
		TciParameterList GetTestCaseParameterList();
		CComponentReference *GetMtc();
		CComponentReference *GetSystem();
	};
	extern CLASS_MMETEST_NUES_ATTACH_TEST_001 TTCN_MMETEST_NUES_ATTACH_TEST_001;

	// 模块控制类的声明
	class CLASS_control : public CControl
	{
	public:
		CLASS_control();
		~CLASS_control();
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
		void Body(CComponentReference &TTCN_self);
	};
	extern CLASS_control *TTCN_control;

	// 模块类的声明
	class TTCN_MMETestCases : public CModule
	{
	public:
		TTCN_MMETestCases();
		~TTCN_MMETestCases();
		// 配置外部常量 
		TciExternalConstList GetExternalCst();
		// 配置模块参数 
		TciModuleParameterList GetTciModuleParameterList();
		// 该函数为可选的，如果没有control部分不需要翻译该函数 
		virtual const CBehavior * GetControlBehavior() const;
	};

	extern TTCN_MMETestCases *_g_pModule;

	void Init();

	void Release();

}
#endif
