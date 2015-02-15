// -*-C++-*-
/*!
 * @file  WordTask.cpp
 * @brief Wordの起動、COMの参照をするスレッド
 *
 */



#include "WordTask.h"
#include "WordObject.h"


WordTask::WordTask()
{
	
}





int WordTask::svc()
{
	
	WordObject::Obj = gcnew WordObject();
	std::string filePath = "";
	coil::Properties& prop(::RTC::Manager::instance().getConfig());
	getProperty(prop, "word.filename", filePath);
	//System::Console::WriteLine(gcnew System::String(filePath.c_str()));
	//filePath = Replace(filePath, "/", "\\");

	WordObject::Obj->Open(gcnew System::String(filePath.c_str()));
	
	return 0;
}


