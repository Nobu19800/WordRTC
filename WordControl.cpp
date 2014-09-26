// -*- C++ -*-
/*!
 * @file  WordControl.cpp
 * @brief WordControlComponent
 * @date $Date$
 *
 * $Id$
 */

#include "WordControl.h"
#include "MyObject.h"


// Module specification
// <rtc-template block="module_spec">
static const char* wordrtc_spec[] =
  {
    "implementation_id", "WordControl",
    "type_name",         "WordControl",
    "description",       "Word Control Component",
    "version",           "0.0.1",
    "vendor",            "Miyamoto Nobuhiko",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
	"conf.default.file_path", "NewFile",
	"conf.default.fontsize", "16",
	//"conf.default.fontname", "ＭＳ 明朝",
	"conf.default.Char_Red", "0",
	"conf.default.Char_Blue", "0",
	"conf.default.Char_Green", "0",
	"conf.default.Italic", "0",
	"conf.default.Bold", "0",
	"conf.default.Underline", "0",
    "conf.default.Shadow", "0",
    "conf.default.Strikeout", "0",
    "conf.default.Contoured", "0",
    "conf.default.Emphasis", "0",
    "conf.default.Back_Red", "255",
    "conf.default.Back_Blue", "255",
    "conf.default.Back_Green", "255",
	"conf.default.Code", "shift_jis",
	"conf.__widget__.file_path", "text",
	"conf.__widget__.fontsize", "spin",
	//"conf.__widget__.fontname", "radio",
	"conf.__widget__.Char_Red", "spin",
	"conf.__widget__.Char_Blue", "spin",
	"conf.__widget__.Char_Green", "spin",
	"conf.__widget__.Italic", "radio",
	"conf.__widget__.Bold", "radio",
	"conf.__widget__.Underline", "radio",
    "conf.__widget__.Shadow", "radio",
    "conf.__widget__.Strikeout", "radio",
    "conf.__widget__.Contoured", "radio",
    "conf.__widget__.Emphasis", "radio",
    "conf.__widget__.Back_Red", "spin",
    "conf.__widget__.Back_Blue", "spin",
    "conf.__widget__.Back_Green", "spin",
	"conf.__widget__.Code", "radio",
	"conf.__constraints__.fontsize", "1<=x<=72",
	//"conf.__constraints__.fontname", "(MS UI Gothic,MS ゴシック,MS Pゴシック,MS 明朝,MS P明朝,HG ゴシック E,HGP ゴシック E,HGS ゴシック E,HG ゴシック M,HGP ゴシック M,HGS ゴシック M,HG 正楷書体-PRO,HG 丸ゴシック M-PRO,HG 教科書体,HGP 教科書体,HGS 教科書体,HG 行書体,HGP 行書体,HGS 行書体,HG 創英プレゼンス EB,HGP 創英プレゼンス EB,HGS 創英プレゼンス EB,HG 創英角ゴシック UB,HGP 創英角ゴシック UB,HGS 創英角ゴシック UB,HG 創英角ポップ体,HGP 創英角ポップ体,HGS 創英角ポップ体,HG 明朝 B,HGP 明朝 B,HGS 明朝 B,HG 明朝 E,HGP 明朝 E,HGS 明朝 E,メイリオ)",
	"conf.__constraints__.Char_Red", "0<=x<=255",
	"conf.__constraints__.Char_Blue", "0<=x<=255",
	"conf.__constraints__.Char_Green", "0<=x<=255",
	"conf.__constraints__.Italic", "(0,1)",
	"conf.__constraints__.Bold", "(0,1)",
	"conf.__constraints__.Underline", "(0,1)",
    "conf.__constraints__.Shadow", "(0,1)",
    "conf.__constraints__.Strikeout", "(0,1)",
    "conf.__constraints__.Contoured", "(0,1)",
    "conf.__constraints__.Emphasis", "(0,1)",
    "conf.__constraints__.Back_Red", "0<=x<=255",
    "conf.__constraints__.Back_Blue", "0<=x<=255",
    "conf.__constraints__.Back_Green", "0<=x<=255",
	"conf.__constraints__.Code", "(utf-8, shift_jis)",
    ""
  };

//コンフィギュレーションパラメータが更新されたときのコールバック
class MyConfigUpdateParam
    : public RTC::ConfigurationSetListener
{
public:
    MyConfigUpdateParam(WordControl *e_rtc)
    {
		m_rtc = e_rtc;
    }
    void operator()(const coil::Properties& config_set)
	{
		
		m_rtc->ConfigUpdate();
		
    }
	WordControl *m_rtc;

};

// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
WordControl::WordControl(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_wordIn("word", m_word),
    m_fontSizeIn("fontSize", m_fontSize),
	m_fontNameIn("fontName", m_fontName),
	m_wsCharacterIn("wsCharacter", m_wsCharacter),
    m_wsWordIn("wsWord", m_wsWord),
    m_wsLineIn("wsLine", m_wsLine),
    m_wsParagraphIn("wsParagraph", m_wsParagraph),
    m_wsWindowIn("wsWindow", m_wsWindow),
    m_wsScreenIn("wsScreen", m_wsScreen),
    m_Char_colorIn("Char_color", m_Char_color),
	m_MovementTypeIn("MovementType", m_MovementType),
	m_ItalicIn("Italic", m_Italic),
	m_BoldIn("Bold", m_Bold),
	m_UnderlineIn("Underline", m_Underline),
	m_ShadowIn("Shadow", m_Shadow),
	m_StrikeoutIn("Strikeout", m_Strikeout),
	m_ContouredIn("Contoured", m_Contoured),
	m_EmphasisIn("Emphasis", m_Emphasis),
	m_Back_colorIn("Back_color", m_Back_color),
    m_selWordOut("selWord", m_selWord),
    m_copyWordOut("copyWord", m_copyWord),
	m_WriterPort("Writer")

    // </rtc-template>
{
	wt = new WordTask();
	wt->activate();
}

/*!
 * @brief destructor
 */
WordControl::~WordControl()
{
}





RTC::ReturnCode_t WordControl::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("word", m_wordIn);
  addInPort("fontSize", m_fontSizeIn);
  addInPort("fontName", m_fontNameIn);
  addInPort("wsCharacter", m_wsCharacterIn);
  addInPort("wsWord", m_wsWordIn);
  addInPort("wsLine", m_wsLineIn);
  addInPort("wsParagraph", m_wsParagraphIn);
  addInPort("wsWindow", m_wsWindowIn);
  addInPort("wsScreen", m_wsScreenIn);
  addInPort("Char_color", m_Char_colorIn);
  addInPort("MovementType", m_MovementTypeIn);
  addInPort("Italic", m_ItalicIn);
  addInPort("Bold", m_BoldIn);
  addInPort("Underline", m_UnderlineIn);
  addInPort("Shadow", m_ShadowIn);
  addInPort("Strikeout", m_StrikeoutIn);
  addInPort("Contoured", m_ContouredIn);
  addInPort("Emphasis", m_EmphasisIn);
  addInPort("Bold", m_BoldIn);
  addInPort("Back_color", m_Back_colorIn);

  
  // Set OutPort buffer
  addOutPort("selWord", m_selWordOut);
  addOutPort("copyWord", m_copyWordOut);

  // Set service provider to Ports
  m_WriterPort.registerProvider("writer", "Writer::mWriter", m_writer);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_WriterPort);


  
  

  

  
  bindParameter("file_path", file_path, "NewFile");
  
  bindParameter("fontsize", fontsize, "16");
  //bindParameter("fontname", fontname, "ＭＳ 明朝");
  bindParameter("Char_Red", Char_Red, "0");
  bindParameter("Char_Green", Char_Green, "0");
  bindParameter("Char_Blue", Char_Blue, "0");
  bindParameter("Italic", Italic, "0");
  bindParameter("Bold", Bold, "0");
  bindParameter("Code", Code, "shift_jis");

  bindParameter("Underline", Underline, "0");
  bindParameter("Shadow", Shadow, "0");
  bindParameter("Strikeout", Strikeout, "0");
  bindParameter("Contoured", Contoured, "0");
  bindParameter("Emphasis", Emphasis, "0");
  bindParameter("Back_Red", Back_Red, "255");
  bindParameter("Back_Green", Back_Green, "255");
  bindParameter("Back_Blue", Back_Blue, "255");

  std::string filePath = "";
  coil::Properties& prop(::RTC::Manager::instance().getConfig());
  getProperty(prop, "excel.filename", filePath);
  SetFilePath(filePath);


  this->addConfigurationSetListener(ON_SET_CONFIG_SET, new MyConfigUpdateParam(this));
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>


  
  return RTC::RTC_OK;
}



void WordControl::SetFilePath(std::string FP)
{

	coil::Properties file_confSet("default");
	file_confSet.setProperty("file_path", FP.c_str());
	this->m_configsets.setConfigurationSetValues(file_confSet);
	this->m_configsets.activateConfigurationSet("default");
	


	this->m_configsets.update("default", "file_path");
	
}


void WordControl::ConfigUpdate()
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


RTC::ReturnCode_t WordControl::onFinalize()
{
  myWord::Obj->Close();
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t WordControl::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordControl::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t WordControl::onActivated(RTC::UniqueId ec_id)
{
	myWord::Obj->SetFontSize(fontsize);
	myWord::Obj->SetFontName(fontname);
	myWord::Obj->SetFontColor(Char_Red, Char_Green, Char_Blue);
	if(Italic == 0)
		myWord::Obj->Italic = false;
	else
		myWord::Obj->Italic = true;
	if(Bold == 0)
		myWord::Obj->Bold = false;
	else
		myWord::Obj->Bold = true;

	if(Underline == 0)
		myWord::Obj->Underline = false;
	else
		myWord::Obj->Underline = true;

	if(Shadow == 0)
		myWord::Obj->Shadow = false;
	else
		myWord::Obj->Shadow = true;

	if(Strikeout == 0)
		myWord::Obj->Strikeout = false;
	else
		myWord::Obj->Strikeout = true;

	if(Contoured == 0)
		myWord::Obj->Contoured = false;
	else
		myWord::Obj->Contoured = true;

	if(Emphasis == 0)
		myWord::Obj->Emphasis = false;
	else
		myWord::Obj->Emphasis = true;

	myWord::Obj->SetBackColor(Back_Red, Back_Green, Back_Blue);

	

	myWord::Obj->MovementType = false;

	//ofs.open("test.txt");

  return RTC::RTC_OK;
}


RTC::ReturnCode_t WordControl::onDeactivated(RTC::UniqueId ec_id)
{
	//ofs.close();
  return RTC::RTC_OK;
}



RTC::ReturnCode_t WordControl::onExecute(RTC::UniqueId ec_id)
{
	

	if(m_fontSizeIn.isNew())
	{
		m_fontSizeIn.read();
		myWord::Obj->SetFontSize(m_fontSize.data);
	}

	if(m_MovementTypeIn.isNew())
	{
		m_MovementTypeIn.read();
		myWord::Obj->MovementType = m_MovementType.data;
	}


	if(m_fontNameIn.isNew())
	{
		m_fontNameIn.read();
		myWord::Obj->SetFontName((const char*)m_fontName.data);
	}
	if(m_wsCharacterIn.isNew())
	{
		m_wsCharacterIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdCharacter, m_wsCharacter.data);
	}
	if(m_wsWordIn.isNew())
	{
		m_wsWordIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdWord, m_wsWord.data);
	}
	if(m_wsLineIn.isNew())
	{
		m_wsLineIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdLine, m_wsLine.data);
	}
	if(m_wsParagraphIn.isNew())
	{
		m_wsParagraphIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdParagraph, m_wsParagraph.data);
	}
	if(m_wsWindowIn.isNew())
	{
		m_wsWindowIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdWindow, m_wsWindow.data);
	}
	if(m_wsScreenIn.isNew())
	{
		m_wsScreenIn.read();
		myWord::Obj->MoveSelection(Word::WdUnits::wdScreen, m_wsScreen.data);
	}
	if(m_Char_colorIn.isNew())
	{
		m_Char_colorIn.read();
		myWord::Obj->SetFontColor(m_Char_color.data.r*255,m_Char_color.data.g*255,m_Char_color.data.b*255);
	}

	if(m_ItalicIn.isNew())
	{
		m_ItalicIn.read();
		myWord::Obj->Italic = m_Italic.data;
	}
	if(m_BoldIn.isNew())
	{
		m_BoldIn.read();
		myWord::Obj->Bold = m_Bold.data;
	}

	if(m_UnderlineIn.isNew())
	{
		m_UnderlineIn.read();
		myWord::Obj->Underline = m_Underline.data;
	}

	if(m_ShadowIn.isNew())
	{
		m_ShadowIn.read();
		myWord::Obj->Shadow = m_Shadow.data;
	}

	if(m_StrikeoutIn.isNew())
	{
		m_StrikeoutIn.read();
		myWord::Obj->Strikeout = m_Strikeout.data;
	}

	if(m_ContouredIn.isNew())
	{
		m_ContouredIn.read();
		myWord::Obj->Contoured = m_Contoured.data;
	}

	if(m_EmphasisIn.isNew())
	{
		m_EmphasisIn.read();
		myWord::Obj->Emphasis = m_Emphasis.data;
	}

	if(m_Back_colorIn.isNew())
	{
		m_Back_colorIn.read();
		myWord::Obj->SetBackColor(m_Back_color.data.r*255,m_Back_color.data.g*255,m_Back_color.data.b*255);
	}

	
	

	if(m_wordIn.isNew())
	{
		m_wordIn.read();
		const char *tmp = m_word.data;
		coil::TimeValue t1(coil::gettimeofday());
		myWord::Obj->SetWord(tmp, Code);
		coil::TimeValue t2(coil::gettimeofday());
		//ofs << t2 - t1 << std::endl;
	}

	m_selWord.data = MarshalString(myWord::Obj->GetSelWord()).c_str();
	m_selWordOut.write();

	

	


  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t WordControl::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordControl::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordControl::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordControl::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t WordControl::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void WordControlInit(RTC::Manager* manager)
  {
    coil::Properties profile(wordrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<WordControl>,
                             RTC::Delete<WordControl>);
  }
  
};


