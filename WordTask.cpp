// -*-C++-*-
/*!
 * @file  WordTask.cpp
 * @brief
 *
 */



#include "WordTask.h"
#include "myWord.h"


WordTask::WordTask()
{
	
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


int WordTask::svc()
{
	
	myWord::Obj = gcnew myWord();
	std::string filePath = "";
	coil::Properties& prop(::RTC::Manager::instance().getConfig());
	getProperty(prop, "word.filename", filePath);
	myWord::Obj->Open(gcnew System::String(filePath.c_str()));
	myWord::Obj->filename = "";
	return 0;
}


