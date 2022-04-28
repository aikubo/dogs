#include "DOGSApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
DOGSApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

DOGSApp::DOGSApp(InputParameters parameters) : MooseApp(parameters)
{
  DOGSApp::registerAll(_factory, _action_factory, _syntax);
}

DOGSApp::~DOGSApp() {}

void
DOGSApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"DOGSApp"});
  Registry::registerActionsTo(af, {"DOGSApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
DOGSApp::registerApps()
{
  registerApp(DOGSApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DOGSApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DOGSApp::registerAll(f, af, s);
}
extern "C" void
DOGSApp__registerApps()
{
  DOGSApp::registerApps();
}
