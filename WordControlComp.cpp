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
*@brief RTC������
* @param manager �}�l�[�W���I�u�W�F�N�g
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
*@brief ���C���֐�
* @param argc �R�}���h���C�������̐�
* @param argv �R�}���h���C������
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
