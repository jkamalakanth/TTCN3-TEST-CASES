#include "ControlMessages.h"

namespace	ControlMessages
{

	// Anytype �ṹ�������ʵ��
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

	// �����ͷ������ʵ��

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

	// �����ͷ������ʵ��

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

	// ģ�����ʵ��
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

		// ��ʼ��ASN.1����
		InitAsnType();

		// ��ʼ��ȫ�ֳ���
		InitConst();

		// ��ʼ��ȫ��ģ��
		InitTemplate();

		// ��ʼ��ģ�����
		InitModuleParameter();
	}

	void Release()
	{
		delete _g_pModule;
	}

}
