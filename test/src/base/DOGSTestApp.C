//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DOGSTestApp.h"
#include "DOGSApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
DOGSTestApp::validParams()
{
  InputParameters params = DOGSApp::validParams();
  return params;
}

DOGSTestApp::DOGSTestApp(InputParameters parameters) : MooseApp(parameters)
{
  DOGSTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

DOGSTestApp::~DOGSTestApp() {}

void
DOGSTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  DOGSApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"DOGSTestApp"});
    Registry::registerActionsTo(af, {"DOGSTestApp"});
  }
}

void
DOGSTestApp::registerApps()
{
  registerApp(DOGSApp);
  registerApp(DOGSTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
DOGSTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DOGSTestApp::registerAll(f, af, s);
}
extern "C" void
DOGSTestApp__registerApps()
{
  DOGSTestApp::registerApps();
}
