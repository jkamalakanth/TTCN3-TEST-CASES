#include "ControlMessages.h"
#include "ControlTemplates.h"
#include "S11Messages.h"
#include "S11Templates.h"
#include "X2APMessages.h"
#include "X2APTemplates.h"
#include "TestSystemConfig.h"
#include "ENB1Functions.h"
#include "ENBFunctions.h"
#include "SGWFunctions.h"

void InitializeTE()
{
	try
	{
		ControlMessages::Init();
		ControlTemplates::Init();
		S11Messages::Init();
		S11Templates::Init();
		X2APMessages::Init();
		X2APTemplates::Init();
		TestSystemConfig::Init();
		ENB1Functions::Init();
		ENBFunctions::Init();
		SGWFunctions::Init();
	}
	catch(CTTCNException &ex)
	{
		TE_RDebug(ex.GetLog().c_str());
	}
	catch(...)
	{
		TE_RDebug("²¶»ñÎ´ÖªÒì³£");
	}
}

void TerminateTE()
{
	ControlMessages::Release();
	ControlTemplates::Release();
	S11Messages::Release();
	S11Templates::Release();
	X2APMessages::Release();
	X2APTemplates::Release();
	TestSystemConfig::Release();
	ENB1Functions::Release();
	ENBFunctions::Release();
	SGWFunctions::Release();
	delete CTEImpl::Instance();
}

extern "C" BOOL APIENTRY DllMain(HANDLE hMoudle, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch(ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		::InitializeTE();
		break;
	case DLL_THREAD_ATTACH:
			break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		::TerminateTE();
		break;
	}
	return true;
}

extern "C"
{
	__declspec(dllexport) CTE* CreateTE()
	{
		CTEImpl* te = CTEImpl::Instance();
		return te;
	}

	__declspec(dllexport) void DeleteTE(CTE* pTE)
	{

	}
};
