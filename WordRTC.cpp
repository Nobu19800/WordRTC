// -*- C++ -*-
/*!
 * @file  WordRTC.cpp
 * @brief WordRTComponent
 * @date $Date$
 *
 * $Id$
 */

#include "WordRTC.h"
#include "MyObject.h"

// Module specification
// <rtc-template block="module_spec">
static const char* wordrtc_spec[] =
  {
    "implementation_id", "WordRTC",
    "type_name",         "WordRTC",
    "description",       "WordRTComponent",
    "version",           "0.0.1",
    "vendor",            "Miyamoto Nobuhiko",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
	"conf.default.file_path", "NewFile",
	"conf.__widget__.file_path", "text",
    ""
  };

//コンフィギュレーションパラメータが更新されたときのコールバック
class MyConfigUpdateParam
    : public RTC::ConfigurationSetListener
{
public:
    MyConfigUpdateParam(WordRTC *e_rtc)
    {
		m_rtc = e_rtc;
    }
    void operator()(const coil::Properties& config_set)
	{
		
		m_rtc->ConfigUpdate();
		
    }
	WordRTC *m_rtc;

};

// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
WordRTC::WordRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_wordIn("word", m_word),
    m_fontSizeIn("fontSize", m_fontSize),
	m_wsCharacterIn("wsCharacter", m_wsCharacter),
    m_wsWordIn("wsWord", m_wsWord),
    m_wsLineIn("wsLine", m_wsLine),
    m_wsParagraphIn("wsParagraph", m_wsParagraph),
    m_wsWindowIn("wsWindow", m_wsWindow),
    m_wsScreenIn("wsScreen", m_wsScreen),
    m_colorIn("color", m_color),
    m_selWordOut("selWord", m_selWord),
    m_copyWordOut("copyWord", m_copyWord)

    // </rtc-template>
{
	myWord::Obj = gcnew myWord();
}

/*!
 * @brief destructor
 */
WordRTC::~WordRTC()
{
}



RTC::ReturnCode_t WordRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("word", m_wordIn);
  addInPort("fontSize", m_fontSizeIn);
  addInPort("wsCharacter", m_wsCharacterIn);
  addInPort("wsWord", m_wsWordIn);
  addInPort("wsLine", m_wsLineIn);
  addInPort("wsParagraph", m_wsParagraphIn);
  addInPort("wsWindow", m_wsWindowIn);
  addInPort("wsScreen", m_wsScreenIn);
  addInPort("color", m_colorIn);
  
  // Set OutPort buffer
  addOutPort("selWord", m_selWordOut);
  addOutPort("copyWord", m_copyWordOut);


  
  

  this->addConfigurationSetListener(ON_SET_CONFIG_SET, new MyConfigUpdateParam(this));

  
  bindParameter("file_path", file_path, "NewFile");
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}


void WordRTC::ConfigUpdate()
{
	this->m_configsets.update("default","file_path");
	std::string sfn = Replace(file_path, "/", "\\");
	System::String ^tfn = gcnew System::String(sfn.c_str());
	//System::Console::WriteLine(tfn);
	
	if(sfn ==  "NewFile")
	{
		myWord::Obj->Open("");
	}
	else if(myWord::Obj->filename != tfn)
	{
		
		myWord::Obj->Open(tfn);
		 
		
	}
	
}

/*
RTC::ReturnCode_t WordRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t WordRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t WordRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t WordRTC::onExecute(RTC::UniqueId ec_id)
{
	if(m_wordIn.isNew())
	{
		m_wordIn.read();
		const char *tmp = m_word.data;
		myWord::Obj->SetWord(tmp);
	}
	if(m_fontSizeIn.isNew())
	{
		m_fontSizeIn.read();
		myWord::Obj->SetFontSize(m_fontSize.data);
	}
	if(m_wsCharacterIn.isNew())
	{
		m_wsCharacterIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdCharacter, m_wsCharacter.data, Word::WdMovementType::wdMove);
	}
	if(m_wsWordIn.isNew())
	{
		m_wsWordIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdWord, m_wsWord.data, Word::WdMovementType::wdMove);
	}
	if(m_wsLineIn.isNew())
	{
		m_wsLineIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdLine, m_wsLine.data, Word::WdMovementType::wdMove);
	}
	if(m_wsParagraphIn.isNew())
	{
		m_wsParagraphIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdParagraph, m_wsParagraph.data, Word::WdMovementType::wdMove);
	}
	if(m_wsWindowIn.isNew())
	{
		m_wsWindowIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdWindow, m_wsWindow.data, Word::WdMovementType::wdMove);
	}
	if(m_wsScreenIn.isNew())
	{
		m_wsScreenIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdScreen, m_wsScreen.data, Word::WdMovementType::wdMove);
	}

	m_selWord.data = MarshalString(myWord::Obj->GetSelWord()).c_str();
	m_selWordOut.write();


  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t WordRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void WordRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(wordrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<WordRTC>,
                             RTC::Delete<WordRTC>);
  }
  
};


