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
		*@brief �R���X�g���N�^
		* @param manager
		*/
		WordTask();
		/**
		*@brief 
		*/
		virtual int svc();
		


};


#endif