// -*-C++-*-
/*!
 * @file  WordTask.cpp
 * @brief Word�̋N���ACOM�̎Q�Ƃ�����X���b�h
 *
 */



#include "WordTask.h"
#include "WordObject.h"


WordTask::WordTask(WordControl *m_rtc)
{
	mrtc = m_rtc;
}





int WordTask::svc()
{
	
	WordObject::Obj = gcnew WordObject();
	std::string filePath = mrtc->getFileName();
	if(filePath == "NewFile")
	{
		filePath = "";
	}
	//coil::Properties& prop(::RTC::Manager::instance().getConfig());
	//getProperty(prop, "word.filename", filePath);
	//System::Console::WriteLine(gcnew System::String(filePath.c_str()));
	coil::replaceString(filePath, "/", "\\");
	
	WordObject::Obj->Open(gcnew System::String(filePath.c_str()));
	
	return 0;
}


