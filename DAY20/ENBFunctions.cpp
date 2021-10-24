#include "ENBFunctions.h"

namespace	ENBFunctions
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
		(CreateFunc)&InternalCreate, ANYTYPE_CLASS, "anytype", {TAG_UNIVERSAL, 17, TAG_IMPLICIT}, NULL, NULL, "", "", "ENBFunctions", NULL, &m_extraTypeInfo
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
	CLASS_ENBJob1 TTCN_ENBJob1;
	CLASS_ENBJob1::CLASS_ENBJob1() : CFunction("ENBJob1", "ENBFunctions")
	{
		SetLineNo(7);
	}
	CLASS_ENBJob1::~CLASS_ENBJob1()
	{

	}
	void CLASS_ENBJob1::Body(CComponentReference &TTCN_self)
	{

		EnterBehavior(TTCN_self);
		try
		{
			TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_ERROR_FUNCTION_INVOKE, TTCN_self.GetObjectName());
		}

		TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		_Body(PAR_self);
		ExitBehavior(TTCN_self);

	}
	void CLASS_ENBJob1::_Body(TestSystemConfig::TTCN_ENB &TTCN_self)
	{
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(9);
				if( PORTOP::Receive(TTCN_self.FIELD_PTCCP1(),false,&ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T1,NULL,NULL,NULL) )
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
		::SetLineNO(10);
		TTCN_F1_HO_REQ.Body(TTCN_self);
		::SetLineNO(11);
		PORTOP::Send(TTCN_self.FIELD_PTCCP1(),false,ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T1,NULL);
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(13);
				if( PORTOP::Receive(TTCN_self.FIELD_PTCCP1(),false,&ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T1,NULL,NULL,NULL) )
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
		::SetLineNO(14);
		TTCN_F2_SN_TRANSFER.Body(TTCN_self);
		::SetLineNO(15);
		PORTOP::Send(TTCN_self.FIELD_PTCCP1(),false,ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T1,NULL);
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(17);
				if( PORTOP::Receive(TTCN_self.FIELD_PTCCP1(),false,&ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T1,NULL,NULL,NULL) )
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
		::SetLineNO(18);
		TTCN_F3_UE_CON_REL.Body(TTCN_self);
		::SetLineNO(19);
		PORTOP::Send(TTCN_self.FIELD_PTCCP1(),false,ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T1,NULL);
	}
	void CLASS_ENBJob1::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
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
	CLASS_ENBJob2 TTCN_ENBJob2;
	CLASS_ENBJob2::CLASS_ENBJob2() : CFunction("ENBJob2", "ENBFunctions")
	{
		SetLineNo(21);
	}
	CLASS_ENBJob2::~CLASS_ENBJob2()
	{

	}
	void CLASS_ENBJob2::Body(CComponentReference &TTCN_self)
	{

		EnterBehavior(TTCN_self);
		try
		{
			TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_ERROR_FUNCTION_INVOKE, TTCN_self.GetObjectName());
		}

		TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		_Body(PAR_self);
		ExitBehavior(TTCN_self);

	}
	void CLASS_ENBJob2::_Body(TestSystemConfig::TTCN_ENB &TTCN_self)
	{
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(23);
				if( PORTOP::Receive(TTCN_self.FIELD_PTCCP1(),false,&ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T2,NULL,NULL,NULL) )
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
		::SetLineNO(24);
		TTCN_F1_PATH_SWI.Body(TTCN_self);
		::SetLineNO(25);
		PORTOP::Send(TTCN_self.FIELD_PTCCP1(),false,ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T2,NULL);
	}
	void CLASS_ENBJob2::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
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
	CLASS_F1_HO_REQ TTCN_F1_HO_REQ;
	CLASS_F1_HO_REQ::CLASS_F1_HO_REQ() : CFunction("F1_HO_REQ", "ENBFunctions")
	{
		SetLineNo(29);
	}
	CLASS_F1_HO_REQ::~CLASS_F1_HO_REQ()
	{

	}
	void CLASS_F1_HO_REQ::Body(CComponentReference &TTCN_self)
	{

		EnterBehavior(TTCN_self);
		try
		{
			TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_ERROR_FUNCTION_INVOKE, TTCN_self.GetObjectName());
		}

		TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		_Body(PAR_self);
		ExitBehavior(TTCN_self);

	}
	void CLASS_F1_HO_REQ::_Body(TestSystemConfig::TTCN_ENB &TTCN_self)
	{
		::SetLineNO(31);
		PORTOP::Send(TTCN_self.FIELD_X2APP(),false,X2APTemplates::TTCN_X2AP_PDU_ENB1_HANDOVER_REQUEST_S_T1,NULL);
		::SetLineNO(32);
		TIMEROP::Start(TTCN_self, TTCN_self.FIELD_X2APTimer());
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(35);
				if( PORTOP::Receive(TTCN_self.FIELD_X2APP(),false,&X2APTemplates::TTCN_X2AP_PDU_ENB1_HANDOVER_REQUEST_ACK_R_T1,NULL,NULL,NULL) )
				{
					TTCN_self.ExitAlt();
					{
						::SetLineNO(37);
						OTHEROP::SetVerdict(TTCN_self,CVerdict(TCI_VERDICT_PASS));
					}
					throw CAltBreak();
				}
				::SetLineNO(39);
				if( PORTOP::Receive(TTCN_self.FIELD_X2APP(),false,NULL,NULL,NULL,NULL) )
				{
					TTCN_self.ExitAlt();
					{
						::SetLineNO(41);
						OTHEROP::SetVerdict(TTCN_self,CVerdict(TCI_VERDICT_FAIL));
					}
					throw CAltBreak();
				}
				::SetLineNO(43);
				if( TIMEROP::TimeOut(TTCN_self, TTCN_self.FIELD_X2APTimer()) )
				{
					TTCN_self.ExitAlt();
					{
						::SetLineNO(45);
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
	void CLASS_F1_HO_REQ::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
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
	CLASS_F2_SN_TRANSFER TTCN_F2_SN_TRANSFER;
	CLASS_F2_SN_TRANSFER::CLASS_F2_SN_TRANSFER() : CFunction("F2_SN_TRANSFER", "ENBFunctions")
	{
		SetLineNo(50);
	}
	CLASS_F2_SN_TRANSFER::~CLASS_F2_SN_TRANSFER()
	{

	}
	void CLASS_F2_SN_TRANSFER::Body(CComponentReference &TTCN_self)
	{

		EnterBehavior(TTCN_self);
		try
		{
			TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_ERROR_FUNCTION_INVOKE, TTCN_self.GetObjectName());
		}

		TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		_Body(PAR_self);
		ExitBehavior(TTCN_self);

	}
	void CLASS_F2_SN_TRANSFER::_Body(TestSystemConfig::TTCN_ENB &TTCN_self)
	{
		::SetLineNO(52);
		PORTOP::Send(TTCN_self.FIELD_X2APP(),false,X2APTemplates::TTCN_X2AP_PDU_ENB1_SN_STATUS_TRANSFER_S_T1,NULL);
		::SetLineNO(53);
		OTHEROP::SetVerdict(TTCN_self,CVerdict(TCI_VERDICT_PASS));
	}
	void CLASS_F2_SN_TRANSFER::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
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
	CLASS_F3_UE_CON_REL TTCN_F3_UE_CON_REL;
	CLASS_F3_UE_CON_REL::CLASS_F3_UE_CON_REL() : CFunction("F3_UE_CON_REL", "ENBFunctions")
	{
		SetLineNo(59);
	}
	CLASS_F3_UE_CON_REL::~CLASS_F3_UE_CON_REL()
	{

	}
	void CLASS_F3_UE_CON_REL::Body(CComponentReference &TTCN_self)
	{

		EnterBehavior(TTCN_self);
		try
		{
			TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_ERROR_FUNCTION_INVOKE, TTCN_self.GetObjectName());
		}

		TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		_Body(PAR_self);
		ExitBehavior(TTCN_self);

	}
	void CLASS_F3_UE_CON_REL::_Body(TestSystemConfig::TTCN_ENB &TTCN_self)
	{
		::SetLineNO(61);
		TIMEROP::Start(TTCN_self, TTCN_self.FIELD_X2APTimer());
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(62);
				if( PORTOP::Receive(TTCN_self.FIELD_X2APP(),false,&X2APTemplates::TTCN_X2AP_PDU_ENB1_UE_CONTEXT_RELEASE_R_T1,NULL,NULL,NULL) )
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
		::SetLineNO(63);
		OTHEROP::SetVerdict(TTCN_self,CVerdict(TCI_VERDICT_PASS));
	}
	void CLASS_F3_UE_CON_REL::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
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
	CLASS_F1_PATH_SWI TTCN_F1_PATH_SWI;
	CLASS_F1_PATH_SWI::CLASS_F1_PATH_SWI() : CFunction("F1_PATH_SWI", "ENBFunctions")
	{
		SetLineNo(66);
	}
	CLASS_F1_PATH_SWI::~CLASS_F1_PATH_SWI()
	{

	}
	void CLASS_F1_PATH_SWI::Body(CComponentReference &TTCN_self)
	{

		EnterBehavior(TTCN_self);
		try
		{
			TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_ERROR_FUNCTION_INVOKE, TTCN_self.GetObjectName());
		}

		TestSystemConfig::TTCN_ENB &PAR_self = dynamic_cast<TestSystemConfig::TTCN_ENB &>(TTCN_self);
		_Body(PAR_self);
		ExitBehavior(TTCN_self);

	}
	void CLASS_F1_PATH_SWI::_Body(TestSystemConfig::TTCN_ENB &TTCN_self)
	{
		::SetLineNO(68);
		PORTOP::Send(TTCN_self.FIELD_X2APP(),false,X2APTemplates::TTCN_S1AP_PDU_ENB2_PATHSWITCH_REQUEST_S_T1,NULL);
		::SetLineNO(69);
		TIMEROP::Start(TTCN_self, TTCN_self.FIELD_X2APTimer());
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(72);
				if( PORTOP::Receive(TTCN_self.FIELD_X2APP(),false,&X2APTemplates::TTCN_S1AP_PDU_ENB2_PATHSWITCH_RESPONSE_R_T1,NULL,NULL,NULL) )
				{
					TTCN_self.ExitAlt();
					{
						::SetLineNO(74);
						OTHEROP::SetVerdict(TTCN_self,CVerdict(TCI_VERDICT_PASS));
					}
					throw CAltBreak();
				}
				::SetLineNO(76);
				if( PORTOP::Receive(TTCN_self.FIELD_X2APP(),false,NULL,NULL,NULL,NULL) )
				{
					TTCN_self.ExitAlt();
					{
						::SetLineNO(78);
						OTHEROP::SetVerdict(TTCN_self,CVerdict(TCI_VERDICT_FAIL));
					}
					throw CAltBreak();
				}
				::SetLineNO(80);
				if( TIMEROP::TimeOut(TTCN_self, TTCN_self.FIELD_X2APTimer()) )
				{
					TTCN_self.ExitAlt();
					{
						::SetLineNO(82);
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
	void CLASS_F1_PATH_SWI::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
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
	TTCN_ENBFunctions* _g_pModule= NULL;
	TTCN_ENBFunctions::TTCN_ENBFunctions():CModule("ENBFunctions")
	{
		AddCompInfo("ENB", &TestSystemConfig::TTCN_ENB::m_typeInfo);
		AddCompInfo("SGW", &TestSystemConfig::TTCN_SGW::m_typeInfo);
		AddCompInfo("MTC", &TestSystemConfig::TTCN_MTC::m_typeInfo);
		AddCompInfo("TSI", &TestSystemConfig::TTCN_TSI::m_typeInfo);
	}
	TTCN_ENBFunctions::~TTCN_ENBFunctions()
	{

	}
	TciModuleParameterList TTCN_ENBFunctions::GetTciModuleParameterList()
	{
		TciModuleParameterList ParList;
		return ParList;
	}
	TciExternalConstList TTCN_ENBFunctions::GetExternalCst()
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
			_g_pModule = new TTCN_ENBFunctions;
			te->GetModuleHolder().AddModule("ENBFunctions", _g_pModule, "C:\\kamal\\kamal personal\\TTCN3\\Learning\\DAY20\\ENBFunctions.3mp");
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
