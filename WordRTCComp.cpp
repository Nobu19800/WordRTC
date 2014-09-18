// -*- C++ -*-
/*!
 * @file WordRTCComp.cpp
 * @brief Standalone component
 * @date $Date$
 *
 * $Id$
 */

#include <rtm/Manager.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "WordRTC.h"





void MyModuleInit(RTC::Manager* manager)
{
  WordRTCInit(manager);
  RTC::RtcBase* comp;

  // Create a component
  comp = manager->createComponent("WordControl");

  if (comp==NULL)
  {
    std::cerr << "Component create failed." << std::endl;
    abort();
  }

  

  return;
}

template <class T>
void getProperty(coil::Properties& prop, const char* key, T& value)
{
if (prop.findNode(key) != 0)
  {
    T tmp;
    if (coil::stringTo(tmp, prop[key].c_str()))
      {
        value = tmp;
      }
  }
}

int main (int argc, char** argv)
{
	

  RTC::Manager* manager;
  manager = RTC::Manager::init(argc, argv);


  



  // Initialize manager
  manager->init(argc, argv);

  // Set module initialization proceduer
  // This procedure will be invoked in activateManager() function.
  manager->setModuleInitProc(MyModuleInit);

  // Activate manager and register to naming service
  manager->activateManager();

  // run the manager in blocking mode
  // runManager(false) is the default.

  myWord::Obj = gcnew myWord();
  std::string filePath = "";
  coil::Properties& prop(::RTC::Manager::instance().getConfig());
  getProperty(prop, "word.filename", filePath);
  myWord::Obj->Open(gcnew System::String(filePath.c_str()));
  myWord::Obj->filename = "";

  manager->runManager();

  // If you want to run the manager in non-blocking mode, do like this
  // manager->runManager(true);

  return 0;
}
