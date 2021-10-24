#include "S11Templates.h"

namespace	S11Templates
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
		(CreateFunc)&InternalCreate, ANYTYPE_CLASS, "anytype", {TAG_UNIVERSAL, 17, TAG_IMPLICIT}, NULL, NULL, "", "", "S11Templates", NULL, &m_extraTypeInfo
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

	S11Messages::TTCN_GTPC_MBR TTCN_GTPC_MBR_R_T1;
	void FUNC_GTPC_MBR_R_T1()
	{
		TTCN_GTPC_MBR_R_T1.SetTemplate(true);
		TTCN_GTPC_MBR_R_T1.SetObjectName("GTPC_MBR_R_T1");
		TTCN_GTPC_MBR_R_T1.SetData( CCharString("TEID:SGW C TEID+ENB U TEID "));
	}

	S11Messages::TTCN_GTPC_MBRs TTCN_GTPC_MBRs_S_T1;
	void FUNC_GTPC_MBRs_S_T1()
	{
		TTCN_GTPC_MBRs_S_T1.SetTemplate(true);
		TTCN_GTPC_MBRs_S_T1.SetObjectName("GTPC_MBRs_S_T1");
		TTCN_GTPC_MBRs_S_T1.SetData( CCharString("TEID:MME S11 TEID+ GTPC CAUSE:ACCEPTED"));
	}

	// 模块类的实现
	TTCN_S11Templates* _g_pModule= NULL;
	TTCN_S11Templates::TTCN_S11Templates():CModule("S11Templates")
	{
	}
	TTCN_S11Templates::~TTCN_S11Templates()
	{

	}
	TciModuleParameterList TTCN_S11Templates::GetTciModuleParameterList()
	{
		TciModuleParameterList ParList;
		return ParList;
	}
	TciExternalConstList TTCN_S11Templates::GetExternalCst()
	{
		TciExternalConstList  CstList;
		return CstList;
	}
	void InitConst()
	{
	}
	void InitTemplate()
	{
		FUNC_GTPC_MBR_R_T1();
		FUNC_GTPC_MBRs_S_T1();
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
			_g_pModule = new TTCN_S11Templates;
			te->GetModuleHolder().AddModule("S11Templates", _g_pModule, "C:\\kamal\\kamal personal\\TTCN3\\Learning\\DAY20\\S11Templates.3mp");
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
