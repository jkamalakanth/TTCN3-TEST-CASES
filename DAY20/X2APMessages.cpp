#include "X2APMessages.h"

namespace	X2APMessages
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
		(CreateFunc)&InternalCreate, ANYTYPE_CLASS, "anytype", {TAG_UNIVERSAL, 17, TAG_IMPLICIT}, NULL, NULL, "", "", "X2APMessages", NULL, &m_extraTypeInfo
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

	TypeInfo TTCN_X2AP_PDU::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, CHARSTRING_CLASS, "X2AP_PDU", {TAG_UNIVERSAL, 18, TAG_IMPLICIT}, NULL, (PTypeInfo)&CCharString::m_typeInfo, "", "", "X2APMessages", NULL, CCharString::m_typeInfo.pExtraInfo
	};
	TTCN_X2AP_PDU &TTCN_X2AP_PDU::operator=(const CData &data)
	{
		CCharString::operator=(data);
		return *this;
	}
	TTCN_X2AP_PDU *TTCN_X2AP_PDU::InternalCreate()
	{
		return new TTCN_X2AP_PDU();
	}

	// 子类型翻译类的实现

	TypeInfo TTCN_S1AP_PDU::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, CHARSTRING_CLASS, "S1AP_PDU", {TAG_UNIVERSAL, 18, TAG_IMPLICIT}, NULL, (PTypeInfo)&CCharString::m_typeInfo, "", "", "X2APMessages", NULL, CCharString::m_typeInfo.pExtraInfo
	};
	TTCN_S1AP_PDU &TTCN_S1AP_PDU::operator=(const CData &data)
	{
		CCharString::operator=(data);
		return *this;
	}
	TTCN_S1AP_PDU *TTCN_S1AP_PDU::InternalCreate()
	{
		return new TTCN_S1AP_PDU();
	}

	// 模块类的实现
	TTCN_X2APMessages* _g_pModule= NULL;
	TTCN_X2APMessages::TTCN_X2APMessages():CModule("X2APMessages")
	{
	}
	TTCN_X2APMessages::~TTCN_X2APMessages()
	{

	}
	TciModuleParameterList TTCN_X2APMessages::GetTciModuleParameterList()
	{
		TciModuleParameterList ParList;
		return ParList;
	}
	TciExternalConstList TTCN_X2APMessages::GetExternalCst()
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
			_g_pModule = new TTCN_X2APMessages;
			te->GetModuleHolder().AddModule("X2APMessages", _g_pModule, "C:\\kamal\\kamal personal\\TTCN3\\Learning\\DAY20\\X2APMessages.3mp");
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
