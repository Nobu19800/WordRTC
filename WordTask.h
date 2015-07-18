// -*- C++ -*-
/*!
 * @file  WordTask.h
 * @brief Word�̋N���ACOM�̎Q�Ƃ�����X���b�h
 * $Id$
 */


#ifndef WORDTASK_H
#define WORDTASK_H

#include <rtm/RTC.h>



#include <rtm/Manager.h>
#include <rtm/PeriodicExecutionContext.h>

#include "WordControl.h"

class WordControl;

/*!
 * @class WordTask
 * @brief Word�̋N���ACOM�̎Q�Ƃ�����X���b�h
 *
 */
class WordTask : public virtual coil::Task
{
public:
		/**
		*@brief �R���X�g���N�^
		*/
		WordTask(WordControl *mrtc);
		/**
		*@brief �X���b�h�����s
		*/
		virtual int svc();
		WordControl *mrtc;
		


};

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


#endif