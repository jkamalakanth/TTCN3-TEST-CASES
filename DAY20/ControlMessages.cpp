#include "ControlMessages.h"

namespace	ControlMessages
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
		(CreateFunc)&InternalCreate, ANYTYPE_CLASS, "anytype", {TAG_UNIVERSAL, 17, TAG_IMPLICIT}, NULL, NULL, "", "", "ControlMessages", NULL, &m_extraTypeInfo
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

	// 子类型翻译类的实现

	TypeInfo TTCN_MTC_TO_PTC_COMMAND::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, CHARSTRING_CLASS, "MTC_TO_PTC_COMMAND", {TAG_UNIVERSAL, 18, TAG_IMPLICIT}, NULL, (PTypeInfo)&CCharString::m_typeInfo, "", "", "ControlMessages", NULL, CCharString::m_typeInfo.pExtraInfo
	};
	TTCN_MTC_TO_PTC_COMMAND &TTCN_MTC_TO_PTC_COMMAND::operator=(const CData &data)
	{
		CCharString::operator=(data);
		return *this;
	}
	TTCN_MTC_TO_PTC_COMMAND *TTCN_MTC_TO_PTC_COMMAND::InternalCreate()
	{
		return new TTCN_MTC_TO_PTC_COMMAND();
	}

	// 子类型翻译类的实现

	TypeInfo TTCN_PTC_TO_MTC_REPORT::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, CHARSTRING_CLASS, "PTC_TO_MTC_REPORT", {TAG_UNIVERSAL, 18, TAG_IMPLICIT}, NULL, (PTypeInfo)&CCharString::m_typeInfo, "", "", "ControlMessages", NULL, CCharString::m_typeInfo.pExtraInfo
	};
	TTCN_PTC_TO_MTC_REPORT &TTCN_PTC_TO_MTC_REPORT::operator=(const CData &data)
	{
		CCharString::operator=(data);
		return *this;
	}
	TTCN_PTC_TO_MTC_REPORT *TTCN_PTC_TO_MTC_REPORT::InternalCreate()
	{
		return new TTCN_PTC_TO_MTC_REPORT();
	}

	// 模块类的实现
	TTCN_ControlMessages* _g_pModule= NULL;
	TTCN_ControlMessages::TTCN_ControlMessages():CModule("ControlMessages")
	{
	}
	TTCN_ControlMessages::~TTCN_ControlMessages()
	{

	}
	TciModuleParameterList TTCN_ControlMessages::GetTciModuleParameterList()
	{
		TciModuleParameterList ParList;
		return ParList;
	}
	TciExternalConstList TTCN_ControlMessages::GetExternalCst()
	{
		TciExternalConstList  CstList;
		return CstList;
	}
	void InitConst()
	{
	}
	void InitTemplate()
	{
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
			_g_pModule = new TTCN_ControlMessages;
			te->GetModuleHolder().AddModule("ControlMessages", _g_pModule, "C:\\kamal\\kamal personal\\TTCN3\\Learning\\DAY20\\ControlMessages.3mp");
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
