// -*- C++ -*-
/*!
 * @file  WordTask.h
 *
 * $Id$
 */


#ifndef WORDTASK_H
#define WORDTASK_H

#include <rtm/RTC.h>



#include <rtm/Manager.h>
#include <rtm/PeriodicExecutionContext.h>



/*!
 * @class WordTask
 * @brief 
 *
 */
class WordTask : public virtual coil::Task
{
public:
		/**
		*@brief コンストラクタ
		* @param manager
		*/
		WordTask();
		/**
		*@brief 
		*/
		virtual int svc();
		


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