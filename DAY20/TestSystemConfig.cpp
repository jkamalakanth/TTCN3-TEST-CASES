#include "TestSystemConfig.h"

namespace	TestSystemConfig
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
		(CreateFunc)&InternalCreate, ANYTYPE_CLASS, "anytype", {TAG_UNIVERSAL, 17, TAG_IMPLICIT}, NULL, NULL, "", "", "TestSystemConfig", NULL, &m_extraTypeInfo
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

	// 端口翻译类的实现
	TypeInfo TTCN_X2APPort::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, PORT_CLASS, "X2APPort", {TAG_UNIVERSAL, 0, TAG_IMPLICIT}, NULL, NULL, NULL, NULL, "TestSystemConfig", NULL, NULL
	};
	TTCN_X2APPort::TTCN_X2APPort() : CPort(&m_typeInfo, DIRECTION_EITHER)
	{
		AddInTypeInfo(&X2APMessages::TTCN_X2AP_PDU::m_typeInfo);
		AddInTypeInfo(&X2APMessages::TTCN_S1AP_PDU::m_typeInfo);
		AddOutTypeInfo(&X2APMessages::TTCN_X2AP_PDU::m_typeInfo);
		AddOutTypeInfo(&X2APMessages::TTCN_S1AP_PDU::m_typeInfo);
	}
	TTCN_X2APPort::~TTCN_X2APPort()
	{

	}

	// 端口翻译类的实现
	TypeInfo TTCN_S11Port::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, PORT_CLASS, "S11Port", {TAG_UNIVERSAL, 0, TAG_IMPLICIT}, NULL, NULL, NULL, NULL, "TestSystemConfig", NULL, NULL
	};
	TTCN_S11Port::TTCN_S11Port() : CPort(&m_typeInfo, DIRECTION_EITHER)
	{
		AddInTypeInfo(&S11Messages::TTCN_GTPC_MBR::m_typeInfo);
		AddOutTypeInfo(&S11Messages::TTCN_GTPC_MBRs::m_typeInfo);
	}
	TTCN_S11Port::~TTCN_S11Port()
	{

	}

	// 端口翻译类的实现
	TypeInfo TTCN_MTCControlPort::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, PORT_CLASS, "MTCControlPort", {TAG_UNIVERSAL, 0, TAG_IMPLICIT}, NULL, NULL, NULL, NULL, "TestSystemConfig", NULL, NULL
	};
	TTCN_MTCControlPort::TTCN_MTCControlPort() : CPort(&m_typeInfo, DIRECTION_EITHER)
	{
		AddInTypeInfo(&ControlMessages::TTCN_PTC_TO_MTC_REPORT::m_typeInfo);
		AddOutTypeInfo(&ControlMessages::TTCN_MTC_TO_PTC_COMMAND::m_typeInfo);
	}
	TTCN_MTCControlPort::~TTCN_MTCControlPort()
	{

	}

	// 端口翻译类的实现
	TypeInfo TTCN_PTCControlPort::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, PORT_CLASS, "PTCControlPort", {TAG_UNIVERSAL, 0, TAG_IMPLICIT}, NULL, NULL, NULL, NULL, "TestSystemConfig", NULL, NULL
	};
	TTCN_PTCControlPort::TTCN_PTCControlPort() : CPort(&m_typeInfo, DIRECTION_EITHER)
	{
		AddInTypeInfo(&ControlMessages::TTCN_MTC_TO_PTC_COMMAND::m_typeInfo);
		AddOutTypeInfo(&ControlMessages::TTCN_PTC_TO_MTC_REPORT::m_typeInfo);
	}
	TTCN_PTCControlPort::~TTCN_PTCControlPort()
	{

	}

	// 组件类型翻译类的实现
	ComponentExtraInfo TTCN_ENB::m_extraTypeInfo = {std::string("127.0.0.1"), 80};
	TypeInfo TTCN_ENB::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, COMPONENT_CLASS, "ENB", {TAG_UNIVERSAL, 0, TAG_IMPLICIT}, NULL, NULL, NULL, NULL, "TestSystemConfig", NULL, &m_extraTypeInfo
	};
	TTCN_ENB::TTCN_ENB():CComponentReference(&m_typeInfo)
	{

	}
	TTCN_ENB::~TTCN_ENB()
	{

	}
	TTCN_ENB::TTCN_ENB(const TTCN_ENB &rhs) : CComponentReference(rhs)
	{
		_X2APTimer = rhs._X2APTimer;
		_PTCCP1 = rhs._PTCCP1;
		_X2APP = rhs._X2APP;
	}
	TTCN_ENB &TTCN_ENB::operator=(const CComponentReference &rhs)
	{
		try
		{
			const TTCN_ENB &rhsTemp = dynamic_cast<const TTCN_ENB &>(rhs);
			_X2APTimer = rhsTemp._X2APTimer;
			_PTCCP1 = rhsTemp._PTCCP1;
			_X2APP = rhsTemp._X2APP;
			CComponentReference::operator =(rhsTemp);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_COMPONENT_BOT_COMPATIBLE, rhs.GetObjectName());
		}
		return *this;
	}
	TriPortIdList TTCN_ENB::GetTriPortIdList()
	{
		TriPortIdList portIdList;
		{
			TriPortId portId;
			portId.compInst.compType.objectName = "TTCN_ENB";
			portId.portName = "PTCCP1";
			portId.portIndex = -1;
			portId.portType.objectName = "TTCN_PTCControlPort";
			portIdList.push_back(portId);
		}
		{
			TriPortId portId;
			portId.compInst.compType.objectName = "TTCN_ENB";
			portId.portName = "X2APP";
			portId.portIndex = -1;
			portId.portType.objectName = "TTCN_X2APPort";
			portIdList.push_back(portId);
		}
		return portIdList;
	}
	CComponentReference *TTCN_ENB::Clone() const
	{
		return new TTCN_ENB(*this);
	}

	CTimer& TTCN_ENB::FIELD_X2APTimer()
	{
		IsCompAvailable();
		return *_X2APTimer;
	}

	TTCN_PTCControlPort& TTCN_ENB::FIELD_PTCCP1()
	{
		IsCompAvailable();
		return *_PTCCP1;
	}

	TTCN_X2APPort& TTCN_ENB::FIELD_X2APP()
	{
		IsCompAvailable();
		return *_X2APP;
	}
	void TTCN_ENB::Init()
	{
		_X2APTimer = new CTimer(true);
		_X2APTimer->SetObjectName("X2APTimer");
		_X2APTimer->SetDefaultDuration(CFloat(10));
		InsertTimer(_X2APTimer);

		_PTCCP1 = new TTCN_PTCControlPort();
		_PTCCP1->SetObjectName("PTCCP1");
		InsertPort(_PTCCP1);

		_X2APP = new TTCN_X2APPort();
		_X2APP->SetObjectName("X2APP");
		InsertPort(_X2APP);

		CComponentReference::Init();
	}

	// 组件类型翻译类的实现
	ComponentExtraInfo TTCN_SGW::m_extraTypeInfo = {std::string("127.0.0.1"), 80};
	TypeInfo TTCN_SGW::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, COMPONENT_CLASS, "SGW", {TAG_UNIVERSAL, 0, TAG_IMPLICIT}, NULL, NULL, NULL, NULL, "TestSystemConfig", NULL, &m_extraTypeInfo
	};
	TTCN_SGW::TTCN_SGW():CComponentReference(&m_typeInfo)
	{

	}
	TTCN_SGW::~TTCN_SGW()
	{

	}
	TTCN_SGW::TTCN_SGW(const TTCN_SGW &rhs) : CComponentReference(rhs)
	{
		_S11Timer = rhs._S11Timer;
		_PTCCP2 = rhs._PTCCP2;
		_S11P = rhs._S11P;
	}
	TTCN_SGW &TTCN_SGW::operator=(const CComponentReference &rhs)
	{
		try
		{
			const TTCN_SGW &rhsTemp = dynamic_cast<const TTCN_SGW &>(rhs);
			_S11Timer = rhsTemp._S11Timer;
			_PTCCP2 = rhsTemp._PTCCP2;
			_S11P = rhsTemp._S11P;
			CComponentReference::operator =(rhsTemp);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_COMPONENT_BOT_COMPATIBLE, rhs.GetObjectName());
		}
		return *this;
	}
	TriPortIdList TTCN_SGW::GetTriPortIdList()
	{
		TriPortIdList portIdList;
		{
			TriPortId portId;
			portId.compInst.compType.objectName = "TTCN_SGW";
			portId.portName = "PTCCP2";
			portId.portIndex = -1;
			portId.portType.objectName = "TTCN_PTCControlPort";
			portIdList.push_back(portId);
		}
		{
			TriPortId portId;
			portId.compInst.compType.objectName = "TTCN_SGW";
			portId.portName = "S11P";
			portId.portIndex = -1;
			portId.portType.objectName = "TTCN_S11Port";
			portIdList.push_back(portId);
		}
		return portIdList;
	}
	CComponentReference *TTCN_SGW::Clone() const
	{
		return new TTCN_SGW(*this);
	}

	CTimer& TTCN_SGW::FIELD_S11Timer()
	{
		IsCompAvailable();
		return *_S11Timer;
	}

	TTCN_PTCControlPort& TTCN_SGW::FIELD_PTCCP2()
	{
		IsCompAvailable();
		return *_PTCCP2;
	}

	TTCN_S11Port& TTCN_SGW::FIELD_S11P()
	{
		IsCompAvailable();
		return *_S11P;
	}
	void TTCN_SGW::Init()
	{
		_S11Timer = new CTimer(true);
		_S11Timer->SetObjectName("S11Timer");
		_S11Timer->SetDefaultDuration(CFloat(10));
		InsertTimer(_S11Timer);

		_PTCCP2 = new TTCN_PTCControlPort();
		_PTCCP2->SetObjectName("PTCCP2");
		InsertPort(_PTCCP2);

		_S11P = new TTCN_S11Port();
		_S11P->SetObjectName("S11P");
		InsertPort(_S11P);

		CComponentReference::Init();
	}

	// 组件类型翻译类的实现
	ComponentExtraInfo TTCN_MTC::m_extraTypeInfo = {std::string("127.0.0.1"), 80};
	TypeInfo TTCN_MTC::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, COMPONENT_CLASS, "MTC", {TAG_UNIVERSAL, 0, TAG_IMPLICIT}, NULL, NULL, NULL, NULL, "TestSystemConfig", NULL, &m_extraTypeInfo
	};
	TTCN_MTC::TTCN_MTC():CComponentReference(&m_typeInfo)
	{

	}
	TTCN_MTC::~TTCN_MTC()
	{

	}
	TTCN_MTC::TTCN_MTC(const TTCN_MTC &rhs) : CComponentReference(rhs)
	{
		_MTCCP1 = rhs._MTCCP1;
		_MTCCP2 = rhs._MTCCP2;
	}
	TTCN_MTC &TTCN_MTC::operator=(const CComponentReference &rhs)
	{
		try
		{
			const TTCN_MTC &rhsTemp = dynamic_cast<const TTCN_MTC &>(rhs);
			_MTCCP1 = rhsTemp._MTCCP1;
			_MTCCP2 = rhsTemp._MTCCP2;
			CComponentReference::operator =(rhsTemp);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_COMPONENT_BOT_COMPATIBLE, rhs.GetObjectName());
		}
		return *this;
	}
	TriPortIdList TTCN_MTC::GetTriPortIdList()
	{
		TriPortIdList portIdList;
		{
			TriPortId portId;
			portId.compInst.compType.objectName = "TTCN_MTC";
			portId.portName = "MTCCP1";
			portId.portIndex = -1;
			portId.portType.objectName = "TTCN_MTCControlPort";
			portIdList.push_back(portId);
		}
		{
			TriPortId portId;
			portId.compInst.compType.objectName = "TTCN_MTC";
			portId.portName = "MTCCP2";
			portId.portIndex = -1;
			portId.portType.objectName = "TTCN_MTCControlPort";
			portIdList.push_back(portId);
		}
		return portIdList;
	}
	CComponentReference *TTCN_MTC::Clone() const
	{
		return new TTCN_MTC(*this);
	}

	TTCN_MTCControlPort& TTCN_MTC::FIELD_MTCCP1()
	{
		IsCompAvailable();
		return *_MTCCP1;
	}

	TTCN_MTCControlPort& TTCN_MTC::FIELD_MTCCP2()
	{
		IsCompAvailable();
		return *_MTCCP2;
	}
	void TTCN_MTC::Init()
	{
		_MTCCP1 = new TTCN_MTCControlPort();
		_MTCCP1->SetObjectName("MTCCP1");
		InsertPort(_MTCCP1);

		_MTCCP2 = new TTCN_MTCControlPort();
		_MTCCP2->SetObjectName("MTCCP2");
		InsertPort(_MTCCP2);

		CComponentReference::Init();
	}

	// 组件类型翻译类的实现
	ComponentExtraInfo TTCN_TSI::m_extraTypeInfo = {std::string("127.0.0.1"), 80};
	TypeInfo TTCN_TSI::m_typeInfo =
	{
		(CreateFunc)&InternalCreate, COMPONENT_CLASS, "TSI", {TAG_UNIVERSAL, 0, TAG_IMPLICIT}, NULL, NULL, NULL, NULL, "TestSystemConfig", NULL, &m_extraTypeInfo
	};
	TTCN_TSI::TTCN_TSI():CComponentReference(&m_typeInfo)
	{

	}
	TTCN_TSI::~TTCN_TSI()
	{

	}
	TTCN_TSI::TTCN_TSI(const TTCN_TSI &rhs) : CComponentReference(rhs)
	{
		_S11T = rhs._S11T;
		_X2APT = rhs._X2APT;
	}
	TTCN_TSI &TTCN_TSI::operator=(const CComponentReference &rhs)
	{
		try
		{
			const TTCN_TSI &rhsTemp = dynamic_cast<const TTCN_TSI &>(rhs);
			_S11T = rhsTemp._S11T;
			_X2APT = rhsTemp._X2APT;
			CComponentReference::operator =(rhsTemp);
		}
		catch(std::bad_cast &)
		{
			throw CTTCNException(RUNTIME_COMPONENT_BOT_COMPATIBLE, rhs.GetObjectName());
		}
		return *this;
	}
	TriPortIdList TTCN_TSI::GetTriPortIdList()
	{
		TriPortIdList portIdList;
		{
			TriPortId portId;
			portId.compInst.compType.objectName = "TTCN_TSI";
			portId.portName = "S11T";
			portId.portIndex = -1;
			portId.portType.objectName = "TTCN_S11Port";
			portIdList.push_back(portId);
		}
		{
			TriPortId portId;
			portId.compInst.compType.objectName = "TTCN_TSI";
			portId.portName = "X2APT";
			portId.portIndex = -1;
			portId.portType.objectName = "TTCN_X2APPort";
			portIdList.push_back(portId);
		}
		return portIdList;
	}
	CComponentReference *TTCN_TSI::Clone() const
	{
		return new TTCN_TSI(*this);
	}

	TTCN_S11Port& TTCN_TSI::FIELD_S11T()
	{
		IsCompAvailable();
		return *_S11T;
	}

	TTCN_X2APPort& TTCN_TSI::FIELD_X2APT()
	{
		IsCompAvailable();
		return *_X2APT;
	}
	void TTCN_TSI::Init()
	{
		_S11T = new TTCN_S11Port();
		_S11T->SetObjectName("S11T");
		InsertPort(_S11T);

		_X2APT = new TTCN_X2APPort();
		_X2APT->SetObjectName("X2APT");
		InsertPort(_X2APT);

		CComponentReference::Init();
	}

	// 模块类的实现
	TTCN_TestSystemConfig* _g_pModule= NULL;
	TTCN_TestSystemConfig::TTCN_TestSystemConfig():CModule("TestSystemConfig")
	{
		AddCompInfo("ENB", &TestSystemConfig::TTCN_ENB::m_typeInfo);
		AddCompInfo("SGW", &TestSystemConfig::TTCN_SGW::m_typeInfo);
		AddCompInfo("MTC", &TestSystemConfig::TTCN_MTC::m_typeInfo);
		AddCompInfo("TSI", &TestSystemConfig::TTCN_TSI::m_typeInfo);
	}
	TTCN_TestSystemConfig::~TTCN_TestSystemConfig()
	{

	}
	TciModuleParameterList TTCN_TestSystemConfig::GetTciModuleParameterList()
	{
		TciModuleParameterList ParList;
		return ParList;
	}
	TciExternalConstList TTCN_TestSystemConfig::GetExternalCst()
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
			_g_pModule = new TTCN_TestSystemConfig;
			te->GetModuleHolder().AddModule("TestSystemConfig", _g_pModule, "C:\\kamal\\kamal personal\\TTCN3\\Learning\\DAY20\\TestSystemConfig.3mp");
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
