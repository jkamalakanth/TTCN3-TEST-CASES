#ifndef ENBFunctions_H
#define ENBFunctions_H

#include "Tool.h"
//包含其他TTCN-3模块的头文件

#include "ControlTemplates.h"
#include "TestSystemConfig.h"
#include "X2APTemplates.h"

namespace	ENBFunctions
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

	// 函数翻译类的声明
	class CLASS_ENBJob1 : public CFunction
	{
	public:
		CLASS_ENBJob1();
		~CLASS_ENBJob1();
		void Body(CComponentReference &TTCN_self);
		void _Body(TestSystemConfig::TTCN_ENB &TTCN_self);
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
	};
	extern CLASS_ENBJob1 TTCN_ENBJob1;

	// 函数翻译类的声明
	class CLASS_ENBJob2 : public CFunction
	{
	public:
		CLASS_ENBJob2();
		~CLASS_ENBJob2();
		void Body(CComponentReference &TTCN_self);
		void _Body(TestSystemConfig::TTCN_ENB &TTCN_self);
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
	};
	extern CLASS_ENBJob2 TTCN_ENBJob2;

	// 函数翻译类的声明
	class CLASS_F1_HO_REQ : public CFunction
	{
	public:
		CLASS_F1_HO_REQ();
		~CLASS_F1_HO_REQ();
		void Body(CComponentReference &TTCN_self);
		void _Body(TestSystemConfig::TTCN_ENB &TTCN_self);
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
	};
	extern CLASS_F1_HO_REQ TTCN_F1_HO_REQ;

	// 函数翻译类的声明
	class CLASS_F2_SN_TRANSFER : public CFunction
	{
	public:
		CLASS_F2_SN_TRANSFER();
		~CLASS_F2_SN_TRANSFER();
		void Body(CComponentReference &TTCN_self);
		void _Body(TestSystemConfig::TTCN_ENB &TTCN_self);
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
	};
	extern CLASS_F2_SN_TRANSFER TTCN_F2_SN_TRANSFER;

	// 函数翻译类的声明
	class CLASS_F3_UE_CON_REL : public CFunction
	{
	public:
		CLASS_F3_UE_CON_REL();
		~CLASS_F3_UE_CON_REL();
		void Body(CComponentReference &TTCN_self);
		void _Body(TestSystemConfig::TTCN_ENB &TTCN_self);
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
	};
	extern CLASS_F3_UE_CON_REL TTCN_F3_UE_CON_REL;

	// 函数翻译类的声明
	class CLASS_F1_PATH_SWI : public CFunction
	{
	public:
		CLASS_F1_PATH_SWI();
		~CLASS_F1_PATH_SWI();
		void Body(CComponentReference &TTCN_self);
		void _Body(TestSystemConfig::TTCN_ENB &TTCN_self);
		void Execute(TciParameterList &ParList, CComponentReference &TTCN_self);
	};
	extern CLASS_F1_PATH_SWI TTCN_F1_PATH_SWI;

	// 模块类的声明
	class TTCN_ENBFunctions : public CModule
	{
	public:
		TTCN_ENBFunctions();
		~TTCN_ENBFunctions();
		// 配置外部常量 
		TciExternalConstList GetExternalCst();
		// 配置模块参数 
		TciModuleParameterList GetTciModuleParameterList();
	};

	extern TTCN_ENBFunctions *_g_pModule;

	void Init();

	void Release();

}
#endif
