// -*-C++-*-
/*!
 * @file  WordObject.cpp
 * @brief Wordの操作
 *
 */

#include "WordObject.h"


#include <locale.h>


/**
*@brief Wordを操作するクラスのコンストラクタ
*/
WordObject::WordObject()
{
	dcApplication = nullptr;
	dcDocuments = nullptr;
	dcDocument = nullptr;

	fontSize = 10;
	fontName = "ＭＳ 明朝";
	filename = " ";

	char_Red = 0;
	char_Green = 0;
	char_Blue = 0;

	movementType = false;
	italic = false;
	bold = false;

	underline = false;
	shadow = false;
	strikeout = false;
	contoured = false;
	emphasis = false;

	back_Red = 255;
	back_Green = 255;
	back_Blue = 255;

	//Open("");
}

/**
*@brief 文字の色を変更する関数
* @param r 文字の色(R)
* @param g 文字の色(G)
* @param b 文字の色(B)
*/
void WordObject::setFontColor(int r, int g, int b)
{
	char_Red = r;
	char_Green = g;
	char_Blue = b;
}

/**
*@brief 背景色を変更する関数
* @param r 文字の色(R)
* @param g 文字の色(G)
* @param b 文字の色(B)
*/
void WordObject::setBackColor(int r, int g, int b)
{
	back_Red = r;
	back_Green = g;
	back_Blue = b;
}

/**
*@brief フォントのサイズを変更する関数
* @param fs フォントサイズ
*/
void WordObject::setFontSize(float fs)
{
	fontSize = fs;
}

/**
*@brief フォントの種類を変更する関数
* @param fn フォントの種類
*/
void WordObject::setFontName(std::string fn)
{
	fontName = gcnew System::String(fn.c_str());
}

/**
*@brief 文字列を書き込む関数
* @param st 書き込む文字列
* @param m_code 文字コード
*/
void WordObject::setWord(std::string st, std::string m_code)
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
		tr->default = gcnew System::String(CUnicodeF::utf8_to_sjis(st.c_str(), &str_size));
	}
	else
		tr->default = gcnew System::String(st.c_str());

	tr->Font->Size = fontSize;
	tr->Font->Name = fontName;
	tr->Font->Bold = bold;
	
	
	//tr->Font->Color = gcnew Microsoft::Office::Core::ChartColorFormat::RGB(255, 0, 0);

	System::String^ ts = gcnew System::String(st.c_str());
	
	
	
	currentSelection->MoveRight(static_cast<System::Object^>(Word::WdUnits::wdCharacter), static_cast<System::Object^>(ts->Length) , static_cast<System::Object^>(Word::WdMovementType::wdMove));
	

	
	//Word::Range ^tr = safe_cast<Word::Range^>(dcDocument);
	//tr->Text = "あああああ";
	
	
	
}

/**
*@brief 選択位置の文字列を取得する関数
* @return 取得した文字列
*/
System::String^ WordObject::getSelWord()
{
	Word::Selection ^currentSelection = dcApplication->Selection;

	return currentSelection->default;
}

/**
*@brief 選択位置を変更する関数
* @param m_type 移動のタイプ
* @param leng 移動量
*/
void WordObject::moveSelection(Word::WdUnits m_type, int leng)
{
	Word::Selection ^currentSelection = dcApplication->Selection;
	
	//if(leng > 0)
	if(!movementType)
		currentSelection->MoveRight(static_cast<System::Object^>(m_type), static_cast<System::Object^>(leng) , static_cast<System::Object^>(Word::WdMovementType::wdMove));
	else
		currentSelection->MoveRight(static_cast<System::Object^>(m_type), static_cast<System::Object^>(leng) , static_cast<System::Object^>(Word::WdMovementType::wdExtend));
	//else
	//	currentSelection->MoveLeft(static_cast<System::Object^>(m_type), static_cast<System::Object^>(leng) , static_cast<System::Object^>(d_type));

}

/**
*@brief Wordファイルを開く関数
* @param fn ファイルパス
*/
void WordObject::Open(System::String^ fn)
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

/**
*@brief COMオブジェクトを解放する関数
*/
void WordObject::Close()
{
	

	if (dcDocuments != nullptr) {
		System::Runtime::InteropServices::Marshal::ReleaseComObject(dcDocuments);
	}
	dcDocuments = nullptr;

	if (dcDocument != nullptr) {
		System::Runtime::InteropServices::Marshal::ReleaseComObject(dcDocument);
	}
	dcDocument = nullptr;
}

/**
*@brief カーソル位置のX座標取得(単位はmm)※未実装
* @return カーソル位置のX座標
*/
float WordObject::oCurrentCursorPositionX()
{
	return 0;
}

/**
*@brief カーソル位置のY座標取得(単位はmm)※未実装
* @return カーソル位置のX座標
*/
float WordObject::oCurrentCursorPositionY()
{
	return 0;
}

/**
*@brief カーソルをドキュメント先頭へ移動※未実装
*/
void WordObject::gotoStart()
{

}

/**
*@brief カーソルをドキュメント最後尾へ移動※未実装
*/
void WordObject::gotoEnd()
{

}

/**
*@brief カーソルを行先頭へ移動※未実装
*/
void WordObject::gotoStartOfLine()
{

}

/**
*@brief カーソルを行最後尾へ移動※未実装
*/
void WordObject::gotoEndOfLine()
{

}


