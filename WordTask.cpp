// -*-C++-*-
/*!
 * @file  WordTask.cpp
 * @brief Wordの起動、COMの参照をするスレッド
 *
 */



#include "WordTask.h"
#include "myWord.h"


WordTask::WordTask()
{
	
}





int WordTask::svc()
{
	
	myWord::Obj = gcnew myWord();
	std::string filePath = "";
	coil::Properties& prop(::RTC::Manager::instance().getConfig());
	getProperty(prop, "word.filename", filePath);
	//filePath = Replace(filePath, "/", "\\");

	myWord::Obj->Open(gcnew System::String(filePath.c_str()));
	
	return 0;
}


