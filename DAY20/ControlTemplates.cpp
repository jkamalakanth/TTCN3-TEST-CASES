#include "ControlTemplates.h"

namespace	ControlTemplates
{

	// Anytype 结构翻译类的实现
	FieldInfo CAnyType::m_fieldInfo[8] =
	{
		{(TypeInfo *)&CInteger::m_typeInfo, "integer", {TAG_UNIVERSAL, -1, TAG_IMPLICIT}, NULL, NULL, "", "", false, true, 1},

		{(TypeInfo *)&CFloat::m_typeInfo, "float", {TAG_UNIVERSAL, -1, TAG_IMPLICIT}, NULL, NULL, "", "", false, true, 1},

		{(TypeInfo *)&CBoolean::m_typeInfo, "boolean", {TAG_UNIVERSAL, -1, TAG_IMPLICIT}, NULL, NULL, "", "", false, true, 1},

		{(TypeInfo *)&CVerdict::m_typeInfo, "verdicttype", {TAG_UNIVERSAL, -1, TAG_IMPLICIT}, NULL, NULL, "", "", false, true, 1},

		{(TypeInfo *)&CBitString::m_typeInfo, "bitstring", {TAG_UNIVERSAL, -1, TAG_IMPLICIT}, NULL, NULL, "", "", false, true, 1},

		{(TypeInfo *)&COctetString::m_typeInfo, "octetstring", {TAG_UNIVERSAL, -1, TAG_IMPLICIT}, NULL, NULL, "", "", false, true, 1},

		{(TypeInfo *)&CHexString::m_typeInfo, "hexstring", {TAG_UNIVERSAL, -1, TAG_IMPLICIT}, NULL, NULL, "", "", false, true, 1},

		{(TypeInfo *)&CCharString::m_typeInfo, "charstring", {TAG_UNIVERSAL, -1, TAG_IMPLICIT}, NULL, NULL, "", "", false, true, 1},

	};

	UnionExtraInfo CAnyType::m_extraTypeInfo = {8, m_fieldInfo, m_valueIndex, std::make_pair(-1, -1)};

	TypeInfo CAnyType::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, ANYTYPE_CLASS, "anytype", {TAG_UNIVERSAL, 17, TAG_IMPLICIT}, NULL, NULL, "", "", "ControlTemplates", NULL, &m_extraTypeInfo
	};
	TTCN_UINT32 CAnyType::m_valueIndex[8] = {-1};

	CAnyType &CAnyType::operator=(const CData &data)
	{
		CUnion::operator=(data);
		return *this;
	}

	CAnyType *CAnyType::InternalCreate()
	{
		return new CAnyType;
	}

	CInteger &CAnyType::FIELD_integer()
	{
		return *static_cast<CInteger *>(GetSafeData(0));
	}
	CFloat &CAnyType::FIELD_float()
	{
		return *static_cast<CFloat *>(GetSafeData(1));
	}
	CBoolean &CAnyType::FIELD_boolean()
	{
		return *static_cast<CBoolean *>(GetSafeData(2));
	}
	CVerdict &CAnyType::FIELD_verdicttype()
	{
		return *static_cast<CVerdict *>(GetSafeData(3));
	}
	CBitString &CAnyType::FIELD_bitstring()
	{
		return *static_cast<CBitString *>(GetSafeData(4));
	}
	COctetString &CAnyType::FIELD_octetstring()
	{
		return *static_cast<COctetString *>(GetSafeData(5));
	}
	CHexString &CAnyType::FIELD_hexstring()
	{
		return *static_cast<CHexString *>(GetSafeData(6));
	}
	CCharString &CAnyType::FIELD_charstring()
	{
		return *static_cast<CCharString *>(GetSafeData(7));
	}

	ControlMessages::TTCN_MTC_TO_PTC_COMMAND TTCN_MTC_TO_PTC_COMMAND_T1;
	void FUNC_MTC_TO_PTC_COMMAND_T1()
	{
		TTCN_MTC_TO_PTC_COMMAND_T1.SetTemplate(true);
		TTCN_MTC_TO_PTC_COMMAND_T1.SetObjectName("MTC_TO_PTC_COMMAND_T1");
		TTCN_MTC_TO_PTC_COMMAND_T1.SetData( CCharString("Start Your Work and Execute One Sub-Function"));
	}

	ControlMessages::TTCN_MTC_TO_PTC_COMMAND TTCN_MTC_TO_PTC_COMMAND_T2;
	void FUNC_MTC_TO_PTC_COMMAND_T2()
	{
		TTCN_MTC_TO_PTC_COMMAND_T2.SetTemplate(true);
		TTCN_MTC_TO_PTC_COMMAND_T2.SetObjectName("MTC_TO_PTC_COMMAND_T2");
		TTCN_MTC_TO_PTC_COMMAND_T2.SetData( CCharString("Start Your Work and Execute One Sub-Function"));
	}

	ControlMessages::TTCN_PTC_TO_MTC_REPORT TTCN_PTC_TO_MTC_REPORT_T1;
	void FUNC_PTC_TO_MTC_REPORT_T1()
	{
		TTCN_PTC_TO_MTC_REPORT_T1.SetTemplate(true);
		TTCN_PTC_TO_MTC_REPORT_T1.SetObjectName("PTC_TO_MTC_REPORT_T1");
		TTCN_PTC_TO_MTC_REPORT_T1.SetData( CCharString("I've completed my Work, one Sub-Function succesfully executed"));
	}

	ControlMessages::TTCN_PTC_TO_MTC_REPORT TTCN_PTC_TO_MTC_REPORT_T2;
	void FUNC_PTC_TO_MTC_REPORT_T2()
	{
		TTCN_PTC_TO_MTC_REPORT_T2.SetTemplate(true);
		TTCN_PTC_TO_MTC_REPORT_T2.SetObjectName("PTC_TO_MTC_REPORT_T2");
		TTCN_PTC_TO_MTC_REPORT_T2.SetData( CCharString("I've completed my Work, one Sub-Function succesfully executed"));
	}

	// 模块类的实现
	TTCN_ControlTemplates* _g_pModule= NULL;
	TTCN_ControlTemplates::TTCN_ControlTemplates():CModule("ControlTemplates")
	{
	}
	TTCN_ControlTemplates::~TTCN_ControlTemplates()
	{

	}
	TciModuleParameterList TTCN_ControlTemplates::GetTciModuleParameterList()
	{
		TciModuleParameterList ParList;
		return ParList;
	}
	TciExternalConstList TTCN_ControlTemplates::GetExternalCst()
	{
		TciExternalConstList  CstList;
		return CstList;
	}
	void InitConst()
	{
	}
	void InitTemplate()
	{
		FUNC_MTC_TO_PTC_COMMAND_T1();
		FUNC_MTC_TO_PTC_COMMAND_T2();
		FUNC_PTC_TO_MTC_REPORT_T1();
		FUNC_PTC_TO_MTC_REPORT_T2();
	}
	void InitAsnType()
	{
	}
	void InitModuleParameter()
	{
	}

	void Init()
	{
		CTEImpl* te = CTEImpl::Instance();
		CTciTMRequiredImpl* tmr = dynamic_cast<CTciTMRequiredImpl *>(te->GetTciTMRequired());
		if(tmr != NULL)
		{
			_g_pModule = new TTCN_ControlTemplates;
			te->GetModuleHolder().AddModule("ControlTemplates", _g_pModule, "C:\\kamal\\kamal personal\\TTCN3\\Learning\\DAY20\\ControlTemplates.3mp");
			//tmr->TciRootModule(_g_pModule->GetModuleId());
		}

		// 初始化ASN.1类型
		InitAsnType();

		// 初始化全局常量
		InitConst();

		// 初始化全局模板
		InitTemplate();

		// 初始化模板参数
		InitModuleParameter();
	}

	void Release()
	{
		delete _g_pModule;
	}

}
