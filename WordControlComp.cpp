// -*- C++ -*-
/*!
 * @file WordControlComp.cpp
 * @brief Standalone component
 * @date $Date$
 *
 * $Id$
 */

#include <rtm/Manager.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "WordControl.h"




/**
*@brief RTC初期化
* @param manager マネージャオブジェクト
*/
void MyModuleInit(RTC::Manager* manager)
{
  WordControlInit(manager);
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


/**
*@brief メイン関数
* @param argc コマンドライン引数の数
* @param argv コマンドライン引数
* @return 0
*/
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

  

  manager->runManager();

  // If you want to run the manager in non-blocking mode, do like this
  // manager->runManager(true);

  return 0;
}
