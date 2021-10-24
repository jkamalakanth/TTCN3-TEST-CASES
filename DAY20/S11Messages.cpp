#include "S11Messages.h"

namespace	S11Messages
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
		(CreateFunc)&InternalCreate, ANYTYPE_CLASS, "anytype", {TAG_UNIVERSAL, 17, TAG_IMPLICIT}, NULL, NULL, "", "", "S11Messages", NULL, &m_extraTypeInfo
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

	TypeInfo TTCN_GTPC_MBR::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, CHARSTRING_CLASS, "GTPC_MBR", {TAG_UNIVERSAL, 18, TAG_IMPLICIT}, NULL, (PTypeInfo)&CCharString::m_typeInfo, "", "", "S11Messages", NULL, CCharString::m_typeInfo.pExtraInfo
	};
	TTCN_GTPC_MBR &TTCN_GTPC_MBR::operator=(const CData &data)
	{
		CCharString::operator=(data);
		return *this;
	}
	TTCN_GTPC_MBR *TTCN_GTPC_MBR::InternalCreate()
	{
		return new TTCN_GTPC_MBR();
	}

	// 子类型翻译类的实现

	TypeInfo TTCN_GTPC_MBRs::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, CHARSTRING_CLASS, "GTPC_MBRs", {TAG_UNIVERSAL, 18, TAG_IMPLICIT}, NULL, (PTypeInfo)&CCharString::m_typeInfo, "", "", "S11Messages", NULL, CCharString::m_typeInfo.pExtraInfo
	};
	TTCN_GTPC_MBRs &TTCN_GTPC_MBRs::operator=(const CData &data)
	{
		CCharString::operator=(data);
		return *this;
	}
	TTCN_GTPC_MBRs *TTCN_GTPC_MBRs::InternalCreate()
	{
		return new TTCN_GTPC_MBRs();
	}

	// 模块类的实现
	TTCN_S11Messages* _g_pModule= NULL;
	TTCN_S11Messages::TTCN_S11Messages():CModule("S11Messages")
	{
	}
	TTCN_S11Messages::~TTCN_S11Messages()
	{

	}
	TciModuleParameterList TTCN_S11Messages::GetTciModuleParameterList()
	{
		TciModuleParameterList ParList;
		return ParList;
	}
	TciExternalConstList TTCN_S11Messages::GetExternalCst()
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
			_g_pModule = new TTCN_S11Messages;
			te->GetModuleHolder().AddModule("S11Messages", _g_pModule, "C:\\kamal\\kamal personal\\TTCN3\\Learning\\DAY20\\S11Messages.3mp");
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
