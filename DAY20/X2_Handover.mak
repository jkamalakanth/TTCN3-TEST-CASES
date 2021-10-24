all:ControlMessages.obj ControlTemplates.obj ENBFunctions.obj MMETestCases.obj S11Messages.obj S11Templates.obj SGWFunctions.obj TestSystemConfig.obj X2APMessages.obj X2APTemplates.obj Tool.obj X2_Handover.dll
.cpp.obj:
	cl /nologo /c /EHsc /bigobj /MD /GR $*.cpp
X2_Handover.dll : ControlMessages.obj ControlTemplates.obj ENBFunctions.obj MMETestCases.obj S11Messages.obj S11Templates.obj SGWFunctions.obj TestSystemConfig.obj X2APMessages.obj X2APTemplates.obj Tool.obj 
	link /nologo /OUT:"X2_Handover.dll" /DLL te.lib ControlMessages.obj ControlTemplates.obj ENBFunctions.obj MMETestCases.obj S11Messages.obj S11Templates.obj SGWFunctions.obj TestSystemConfig.obj X2APMessages.obj X2APTemplates.obj Tool.obj 
