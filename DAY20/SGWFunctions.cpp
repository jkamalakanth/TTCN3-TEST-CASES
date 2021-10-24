#include "SGWFunctions.h"

namespace	SGWFunctions
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
		(CreateFunc)&InternalCreate, ANYTYPE_CLASS, "anytype", {TAG_UNIVERSAL, 17, TAG_IMPLICIT}, NULL, NULL, "", "", "SGWFunctions", NULL, &m_extraTypeInfo
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

	// 函数翻译类的实现
	CLASS_SGWJob TTCN_SGWJob;
	CLASS_SGWJob::CLASS_SGWJob() : CFunction("SGWJob", "SGWFunctions")
	{
		SetLineNo(7);
	}
	CLASS_SGWJob::~CLASS_SGWJob()
	{

	}
	void CLASS_SGWJob::Body(CComponentReference &TTCN_self)
	{

		EnterBehavior(TTCN_self);
		try
		{
			TestSystemConfig::TTCN_SGW &PAR_self = dynamic_cast<TestSystemConfig::TTCN_SGW &>(TTCN_self);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_ERROR_FUNCTION_INVOKE, TTCN_self.GetObjectName());
		}

		TestSystemConfig::TTCN_SGW &PAR_self = dynamic_cast<TestSystemConfig::TTCN_SGW &>(TTCN_self);
		_Body(PAR_self);
		ExitBehavior(TTCN_self);

	}
	void CLASS_SGWJob::_Body(TestSystemConfig::TTCN_SGW &TTCN_self)
	{
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(10);
				if( PORTOP::Receive(TTCN_self.FIELD_PTCCP2(),false,&ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T1,NULL,NULL,NULL) )
				{
					TTCN_self.ExitAlt();
					{
					}
					throw CAltBreak();
				}
				TTCN_self.InvokeDefault();
			}
			catch(CAltBreak &)
			{
				break;
			}
			catch(CAltRepeat &)
			{
				continue;
			}
		}while(true);
		::SetLineNO(11);
		TTCN_F3_MBR_MBRs.Body(TTCN_self);
		::SetLineNO(12);
		PORTOP::Send(TTCN_self.FIELD_PTCCP2(),false,ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T1,NULL);
	}
	void CLASS_SGWJob::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
	{
		try
		{
			Body(TTCN_self);
		}
		catch(CTTCNException &ex)
		{
			TE_TciError(ex.GetLog());
			CTEImpl::Instance()->SetVerdict(TCI_VERDICT_ERROR);
			COMPONENTOP::Stop(TTCN_self, TTCN_self);
		}
		catch(CComponentEnd &ex)
		{
			throw ex;
		}
		catch(...)
		{
			TE_TciError("无法识别的异常");
			CTEImpl::Instance()->SetVerdict(TCI_VERDICT_ERROR);
			COMPONENTOP::Stop(TTCN_self, TTCN_self);
		}
		COMPONENTOP::Stop(TTCN_self, TTCN_self);
	}

	// 函数翻译类的实现
	CLASS_F3_MBR_MBRs TTCN_F3_MBR_MBRs;
	CLASS_F3_MBR_MBRs::CLASS_F3_MBR_MBRs() : CFunction("F3_MBR_MBRs", "SGWFunctions")
	{
		SetLineNo(15);
	}
	CLASS_F3_MBR_MBRs::~CLASS_F3_MBR_MBRs()
	{

	}
	void CLASS_F3_MBR_MBRs::Body(CComponentReference &TTCN_self)
	{

		EnterBehavior(TTCN_self);
		try
		{
			TestSystemConfig::TTCN_SGW &PAR_self = dynamic_cast<TestSystemConfig::TTCN_SGW &>(TTCN_self);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_ERROR_FUNCTION_INVOKE, TTCN_self.GetObjectName());
		}

		TestSystemConfig::TTCN_SGW &PAR_self = dynamic_cast<TestSystemConfig::TTCN_SGW &>(TTCN_self);
		_Body(PAR_self);
		ExitBehavior(TTCN_self);

	}
	void CLASS_F3_MBR_MBRs::_Body(TestSystemConfig::TTCN_SGW &TTCN_self)
	{
		::SetLineNO(17);
		TIMEROP::Start(TTCN_self, TTCN_self.FIELD_S11Timer());
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(20);
				if( PORTOP::Receive(TTCN_self.FIELD_S11P(),false,&S11Templates::TTCN_GTPC_MBR_R_T1,NULL,NULL,NULL) )
				{
					TTCN_self.ExitAlt();
					{
						::SetLineNO(22);
						PORTOP::Send(TTCN_self.FIELD_S11P(),false,S11Templates::TTCN_GTPC_MBRs_S_T1,NULL);
						::SetLineNO(23);
						OTHEROP::SetVerdict(TTCN_self,CVerdict(TCI_VERDICT_PASS));
					}
					throw CAltBreak();
				}
				::SetLineNO(25);
				if( PORTOP::Receive(TTCN_self.FIELD_S11P(),false,NULL,NULL,NULL,NULL) )
				{
					TTCN_self.ExitAlt();
					{
						::SetLineNO(27);
						OTHEROP::SetVerdict(TTCN_self,CVerdict(TCI_VERDICT_FAIL));
					}
					throw CAltBreak();
				}
				::SetLineNO(29);
				if( TIMEROP::TimeOut(TTCN_self, TTCN_self.FIELD_S11Timer()) )
				{
					TTCN_self.ExitAlt();
					{
						::SetLineNO(31);
						OTHEROP::SetVerdict(TTCN_self,CVerdict(TCI_VERDICT_FAIL));
					}
					throw CAltBreak();
				}
				TTCN_self.InvokeDefault();
			}
			catch(CAltBreak &)
			{
				break;
			}
			catch(CAltRepeat &)
			{
				continue;
			}
		}while(true);
	}
	void CLASS_F3_MBR_MBRs::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
	{
		try
		{
			Body(TTCN_self);
		}
		catch(CTTCNException &ex)
		{
			TE_TciError(ex.GetLog());
			CTEImpl::Instance()->SetVerdict(TCI_VERDICT_ERROR);
			COMPONENTOP::Stop(TTCN_self, TTCN_self);
		}
		catch(CComponentEnd &ex)
		{
			throw ex;
		}
		catch(...)
		{
			TE_TciError("无法识别的异常");
			CTEImpl::Instance()->SetVerdict(TCI_VERDICT_ERROR);
			COMPONENTOP::Stop(TTCN_self, TTCN_self);
		}
		COMPONENTOP::Stop(TTCN_self, TTCN_self);
	}

	// 模块类的实现
	TTCN_SGWFunctions* _g_pModule= NULL;
	TTCN_SGWFunctions::TTCN_SGWFunctions():CModule("SGWFunctions")
	{
		AddCompInfo("ENB", &TestSystemConfig::TTCN_ENB::m_typeInfo);
		AddCompInfo("SGW", &TestSystemConfig::TTCN_SGW::m_typeInfo);
		AddCompInfo("MTC", &TestSystemConfig::TTCN_MTC::m_typeInfo);
		AddCompInfo("TSI", &TestSystemConfig::TTCN_TSI::m_typeInfo);
	}
	TTCN_SGWFunctions::~TTCN_SGWFunctions()
	{

	}
	TciModuleParameterList TTCN_SGWFunctions::GetTciModuleParameterList()
	{
		TciModuleParameterList ParList;
		return ParList;
	}
	TciExternalConstList TTCN_SGWFunctions::GetExternalCst()
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
			_g_pModule = new TTCN_SGWFunctions;
			te->GetModuleHolder().AddModule("SGWFunctions", _g_pModule, "C:\\kamal\\kamal personal\\TTCN3\\Learning\\DAY20\\SGWFunctions.3mp");
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
