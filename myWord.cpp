

#include "myWord.h"
#include "UnicodeF.h"


myWord::myWord()
{
	dcApplication = nullptr;
	dcDocument = nullptr;

	FontSize = 10;
	FontName = "ＭＳ 明朝";
	filename = " ";

	Char_Red = 0;
	Char_Green = 0;
	Char_Blue = 0;

	MovementType = false;
	Italic = false;
	Bold = false;

	Underline = false;
	Shadow = false;
	Strikeout = false;
	Contoured = false;
	Emphasis = false;

	Back_Red = 255;
	Back_Green = 255;
	Back_Blue = 255;

	//Open("");
}

void myWord::SetFontColor(int r, int g, int b)
{
	Char_Red = r;
	Char_Green = g;
	Char_Blue = b;
}

void myWord::SetBackColor(int r, int g, int b)
{
	Back_Red = r;
	Back_Green = g;
	Back_Blue = b;
}

void myWord::SetFontSize(float fs)
{
	FontSize = fs;
}

void myWord::SetFontName(std::string fn)
{
	FontName = gcnew System::String(fn.c_str());
}

void myWord::SetWord(std::string st, std::string m_code)
{
	std::cout << dcDocument->Words->Count << std::endl;
	Word::Selection ^currentSelection = dcApplication->Selection;
	
	
		//Word::Range ^slc = dcDocument->Sentences[dcDocument->Sentences->Count];
		//Word::Selection^ slc = dcDocument->Select;
		//System::Object ^slc = dcDocument->Words[dcDocument->Words->Count]->End-1;
	System::Object ^slc = currentSelection->End;
		//System::Object ^slc = dcDocument->Words->Count;
	
	Word::Range ^tr = dcDocument->Range(slc,slc);
	
	if(m_code == "utf-8")
	{
		int str_size;
		tr->default = gcnew System::String(CUnicodeF::utf8_to_sjis(st.c_str(),&str_size));
	}
	else
		tr->default = gcnew System::String(st.c_str());

	tr->Font->Size = FontSize;
	tr->Font->Name = FontName;
	tr->Font->Bold = Bold;
	
	
	//tr->Font->Color = gcnew Microsoft::Office::Core::ChartColorFormat::RGB(255, 0, 0);

	System::String^ ts = gcnew System::String(st.c_str());
	
	
	
	currentSelection->MoveRight(static_cast<System::Object^>(Word::WdUnits::wdCharacter), static_cast<System::Object^>(ts->Length) , static_cast<System::Object^>(Word::WdMovementType::wdMove));
	

	
	//Word::Range ^tr = safe_cast<Word::Range^>(dcDocument);
	//tr->Text = "あああああ";
	
	
	
}

System::String^ myWord::GetSelWord()
{
	Word::Selection ^currentSelection = dcApplication->Selection;

	return currentSelection->default;
}


void myWord::MoveSelection(Word::WdUnits m_type, int leng)
{
	Word::Selection ^currentSelection = dcApplication->Selection;
	
	//if(leng > 0)
	if(!MovementType)
		currentSelection->MoveRight(static_cast<System::Object^>(m_type), static_cast<System::Object^>(leng) , static_cast<System::Object^>(Word::WdMovementType::wdMove));
	else
		currentSelection->MoveRight(static_cast<System::Object^>(m_type), static_cast<System::Object^>(leng) , static_cast<System::Object^>(Word::WdMovementType::wdExtend));
	//else
	//	currentSelection->MoveLeft(static_cast<System::Object^>(m_type), static_cast<System::Object^>(leng) , static_cast<System::Object^>(d_type));

}

void myWord::Open(System::String^ fn)
{
	if(filename == fn)
		return;
	filename = fn;

	Word::Application^ t_dcApplication;
	Word::Documents^ t_dcDocuments;
	Word::Document^ t_dcDocument;
	
	try {
		 try {
			System::Object^tObject = System::Runtime::InteropServices::Marshal::GetActiveObject("Word.Application");
			t_dcApplication = static_cast<Word::Application^>(tObject);
			}
		 catch(...){
				t_dcApplication = gcnew Word::Application();
			}
			t_dcApplication->Visible = true;
			
			try {
				t_dcDocuments = t_dcApplication->Documents;
				if(filename == "")
				{
					t_dcDocument = t_dcDocuments->Add(System::Reflection::Missing::Value,System::Reflection::Missing::Value,System::Reflection::Missing::Value,System::Reflection::Missing::Value);

				}
				else
				{
					t_dcDocument = t_dcDocuments->Open(filename, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value);
				}
				Close();
				dcApplication = t_dcApplication;
				dcDocuments = t_dcDocuments;
				dcDocument = t_dcDocument;
			}
			catch(...){

			}
	}
	catch(...){

	}
}

void myWord::Close()
{

}

float myWord::oCurrentCursorPositionX()
{
	return 0;
}
float myWord::oCurrentCursorPositionY()
{
	return 0;
}
void myWord::gotoStart()
{

}
void myWord::gotoEnd()
{

}
void myWord::gotoStartOfLine()
{

}
void myWord::gotoEndOfLine()
{

}