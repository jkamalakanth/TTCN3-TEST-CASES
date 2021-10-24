#include "MMETestCases.h"

namespace	MMETestCases
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
		(CreateFunc)&InternalCreate, ANYTYPE_CLASS, "anytype", {TAG_UNIVERSAL, 17, TAG_IMPLICIT}, NULL, NULL, "", "", "MMETestCases", NULL, &m_extraTypeInfo
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

	// 测试例翻译类的实现
	CLASS_MMETEST_NUES_ATTACH_TEST_001 TTCN_MMETEST_NUES_ATTACH_TEST_001;
	CLASS_MMETEST_NUES_ATTACH_TEST_001::CLASS_MMETEST_NUES_ATTACH_TEST_001() : CTestCase("MMETEST_NUES_ATTACH_TEST_001", "MMETestCases")
	{
		SetLineNo(8);
	}
	CLASS_MMETEST_NUES_ATTACH_TEST_001::~CLASS_MMETEST_NUES_ATTACH_TEST_001()
	{

	}
	void CLASS_MMETEST_NUES_ATTACH_TEST_001::Body(CComponentReference &TTCN_self)
	{

		EnterBehavior(TTCN_self);
		try
		{
			TestSystemConfig::TTCN_MTC &PAR_self = dynamic_cast<TestSystemConfig::TTCN_MTC &>(TTCN_self);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_ERROR_FUNCTION_INVOKE, TTCN_self.GetObjectName());
		}

		TestSystemConfig::TTCN_MTC &PAR_self = dynamic_cast<TestSystemConfig::TTCN_MTC &>(TTCN_self);
		_Body(PAR_self);
		ExitBehavior(TTCN_self);

	}
	void CLASS_MMETEST_NUES_ATTACH_TEST_001::_Body(TestSystemConfig::TTCN_MTC &TTCN_self)
	{
		TestSystemConfig::TTCN_ENB TTCN_ENB1;
		TTCN_ENB1.SetObjectName("ENB1");
		TestSystemConfig::TTCN_ENB TTCN_ENB2;
		TTCN_ENB2.SetObjectName("ENB2");
		TestSystemConfig::TTCN_SGW TTCN_SGW1;
		TTCN_SGW1.SetObjectName("SGW1");
		::SetLineNO(11);
		TTCN_ENB1 = COMPONENTOP::Create(TTCN_self, TestSystemConfig::TTCN_ENB(),false);
		::SetLineNO(12);
		TTCN_ENB2 = COMPONENTOP::Create(TTCN_self, TestSystemConfig::TTCN_ENB(),false);
		::SetLineNO(13);
		TTCN_SGW1 = COMPONENTOP::Create(TTCN_self, TestSystemConfig::TTCN_SGW(),false);
		::SetLineNO(16);
		CONFIGOP::Map(TTCN_ENB1,"X2APP",COMPONENTOP::System(TTCN_self),"X2APT");
		::SetLineNO(17);
		CONFIGOP::Map(TTCN_ENB2,"X2APP",COMPONENTOP::System(TTCN_self),"X2APT");
		::SetLineNO(18);
		CONFIGOP::Map(TTCN_SGW1,"S11P",COMPONENTOP::System(TTCN_self),"S11T");
		::SetLineNO(21);
		CONFIGOP::Connect(COMPONENTOP::Self(TTCN_self),"MTCCP1",TTCN_ENB1,"PTCCP1");
		::SetLineNO(22);
		CONFIGOP::Connect(COMPONENTOP::Self(TTCN_self),"MTCCP1",TTCN_ENB2,"PTCCP1");
		::SetLineNO(23);
		CONFIGOP::Connect(COMPONENTOP::Self(TTCN_self),"MTCCP2",TTCN_SGW1,"PTCCP2");
		::SetLineNO(27);
		COMPONENTOP::Start(TTCN_self, TTCN_ENB1,ENBFunctions::TTCN_ENBJob1,NULL);
		::SetLineNO(28);
		COMPONENTOP::Start(TTCN_self, TTCN_ENB2,ENBFunctions::TTCN_ENBJob2,NULL);
		::SetLineNO(29);
		COMPONENTOP::Start(TTCN_self, TTCN_SGW1,SGWFunctions::TTCN_SGWJob,NULL);
		::SetLineNO(37);
		PORTOP::Send(TTCN_self.FIELD_MTCCP1(),false,ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T1,NULL);
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(38);
				if( PORTOP::Receive(TTCN_self.FIELD_MTCCP1(),false,&ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T1,NULL,NULL,NULL) )
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
		::SetLineNO(40);
		PORTOP::Send(TTCN_self.FIELD_MTCCP1(),false,ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T1,NULL);
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(41);
				if( PORTOP::Receive(TTCN_self.FIELD_MTCCP1(),false,&ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T1,NULL,NULL,NULL) )
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
		::SetLineNO(43);
		PORTOP::Send(TTCN_self.FIELD_MTCCP1(),false,ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T2,NULL);
		::SetLineNO(44);
		PORTOP::Send(TTCN_self.FIELD_MTCCP1(),false,ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T1,NULL);
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(45);
				if( PORTOP::Receive(TTCN_self.FIELD_MTCCP1(),false,&ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T1,NULL,NULL,NULL) )
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
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(46);
				if( PORTOP::Receive(TTCN_self.FIELD_MTCCP1(),false,&ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T2,NULL,NULL,NULL) )
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
		::SetLineNO(48);
		PORTOP::Send(TTCN_self.FIELD_MTCCP1(),false,ControlTemplates::TTCN_MTC_TO_PTC_COMMAND_T1,NULL);
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(49);
				if( PORTOP::Receive(TTCN_self.FIELD_MTCCP1(),false,&ControlTemplates::TTCN_PTC_TO_MTC_REPORT_T1,NULL,NULL,NULL) )
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
		do
		{
			TTCN_self.SnapShot();
			try
			{
				::SetLineNO(54);
				if( ALLCOMPONENTOP::Done(TTCN_self) )
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
		::SetLineNO(57);
		{
			PortTimerIndexType vLeftIndex;
			PortTimerIndexType vRightIndex;
			CONFIGOP::DisConnect(COMPONENTOP::Self(TTCN_self),"MTCCP1",vLeftIndex,TTCN_ENB1,"PTCCP1",vRightIndex);
		};
		::SetLineNO(58);
		{
			PortTimerIndexType vLeftIndex;
			PortTimerIndexType vRightIndex;
			CONFIGOP::DisConnect(COMPONENTOP::Self(TTCN_self),"MTCCP1",vLeftIndex,TTCN_ENB2,"PTCCP1",vRightIndex);
		};
		::SetLineNO(59);
		{
			PortTimerIndexType vLeftIndex;
			PortTimerIndexType vRightIndex;
			CONFIGOP::DisConnect(COMPONENTOP::Self(TTCN_self),"MTCCP2",vLeftIndex,TTCN_SGW1,"PTCCP2",vRightIndex);
		};
		::SetLineNO(62);
		CONFIGOP::Map(TTCN_ENB1,"X2APP",COMPONENTOP::System(TTCN_self),"X2APT");
		::SetLineNO(63);
		CONFIGOP::Map(TTCN_ENB2,"X2APP",COMPONENTOP::System(TTCN_self),"X2APT");
		::SetLineNO(64);
		CONFIGOP::Map(TTCN_SGW1,"S11P",COMPONENTOP::System(TTCN_self),"S11T");
		::SetLineNO(68);
		COMPONENTOP::Stop(TTCN_self, TTCN_self);
	}
	void CLASS_MMETEST_NUES_ATTACH_TEST_001::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
	{
		Body(TTCN_self);
		COMPONENTOP::Stop(TTCN_self, TTCN_self);
	}
	TciParameterList CLASS_MMETEST_NUES_ATTACH_TEST_001::GetTestCaseParameterList()
	{
		TciParameterList ParList;
		return ParList;
	}
	CComponentReference *CLASS_MMETEST_NUES_ATTACH_TEST_001::GetMtc()
	{
		return new TestSystemConfig::TTCN_MTC;
	}
	CComponentReference *CLASS_MMETEST_NUES_ATTACH_TEST_001::GetSystem()
	{
		return new TestSystemConfig::TTCN_TSI;
	}

	// 模块控制类的实现
	CLASS_control *TTCN_control = NULL;
	CLASS_control::CLASS_control():CControl("MMETestCases")
	{
		SetLineNo(71);
	}
	CLASS_control::~CLASS_control()
	{

	}
	void CLASS_control::Body( CComponentReference &TTCN_self)
	{
		::SetLineNO(73);
		OTHEROP::Execute(TTCN_self,TTCN_MMETEST_NUES_ATTACH_TEST_001,CFloat(TTCN3_FLOAT_MAX),NULL);
	}
	void CLASS_control::Execute(TciParameterList &ParList, CComponentReference &TTCN_self)
	{
		try
		{
			EnterBehavior(TTCN_self);
			Body(TTCN_self);
			ExitBehavior(TTCN_self);
		}
		catch(CTTCNException &ex)
		{
			TE_TciError(ex.GetLog());
			COMPONENTOP::Stop(TTCN_self, TTCN_self);
		}
		catch(CComponentEnd &ex)
		{
			throw ex;
		}
		catch(...)
		{
			TE_TciError("无法识别的异常");
			COMPONENTOP::Stop(TTCN_self, TTCN_self);
		}
		COMPONENTOP::Stop(TTCN_self, TTCN_self);
	}

	// 模块类的实现
	TTCN_MMETestCases* _g_pModule= NULL;
	TTCN_MMETestCases::TTCN_MMETestCases():CModule("MMETestCases")
	{
		AddTestCase("MMETEST_NUES_ATTACH_TEST_001", &TTCN_MMETEST_NUES_ATTACH_TEST_001);
		AddCompInfo("ENB", &TestSystemConfig::TTCN_ENB::m_typeInfo);
		AddCompInfo("SGW", &TestSystemConfig::TTCN_SGW::m_typeInfo);
		AddCompInfo("MTC", &TestSystemConfig::TTCN_MTC::m_typeInfo);
		AddCompInfo("TSI", &TestSystemConfig::TTCN_TSI::m_typeInfo);
	}
	TTCN_MMETestCases::~TTCN_MMETestCases()
	{

	}
	TciModuleParameterList TTCN_MMETestCases::GetTciModuleParameterList()
	{
		TciModuleParameterList ParList;
		return ParList;
	}
	TciExternalConstList TTCN_MMETestCases::GetExternalCst()
	{
		TciExternalConstList  CstList;
		return CstList;
	}
	const CBehavior * TTCN_MMETestCases::GetControlBehavior() const
	{
		return TTCN_control;
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
			_g_pModule = new TTCN_MMETestCases;
			te->GetModuleHolder().AddModule("MMETestCases", _g_pModule, "C:\\kamal\\kamal personal\\TTCN3\\Learning\\DAY20\\MMETestCases.3mp");
			//tmr->TciRootModule(_g_pModule->GetModuleId());
			TTCN_control = new CLASS_control;
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
		delete TTCN_control;
		delete _g_pModule;
	}

}
