#ifndef MYWORD_H
#define MYWORD_H

//using namespace Microsoft::Office::Interop::Word;
#define Word   Microsoft::Office::Interop::Word

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "MyObject.h"



ref class myWord
{
public:
	myWord();

	static myWord^ Obj;

	//Wordファイルを開く関数
	void Open(System::String^ fn);
	//COMオブジェクトを解放する関数
	void Close();

	//文字列を書き込む関数
	void SetWord(std::string st, std::string m_code);
	//フォントのサイズを変更する関数
	void SetFontSize(float fs);
	//フォントの種類を変更する関数
	void SetFontName(std::string fn);

	//選択位置を変更する関数
	void MoveSelection(Word::WdUnits m_type, int leng);

	//選択位置の文字列を取得する関数
	System::String^ GetSelWord();

	//文字の色を変更する関数
	void SetFontColor(int r, int g, int b);

	//背景色を変更する関数
	void SetBackColor(int r, int g, int b);

	float oCurrentCursorPositionX();
	float oCurrentCursorPositionY();
	void gotoStart();
	void gotoEnd();
	void gotoStartOfLine();
	void gotoEndOfLine();


	System::String^ filename;
	Word::Application^ dcApplication;
	Word::Documents^ dcDocuments;
	Word::Document^ dcDocument;

	System::String^ FontName;
	float FontSize;

	int Char_Red, Char_Green, Char_Blue;

	bool MovementType;
	bool Italic;
	bool Bold;

	bool Underline;
	bool Shadow;
	bool Strikeout;
	bool Contoured;
	bool Emphasis;

	int Back_Red, Back_Green, Back_Blue;

	static char* utf8_to_sjis(const char *pUtf8Str, int *nBytesOut);
	
	static char* utf16be_to_sjis(const wchar_t *pUcsStr, int *nBytesOut);
	static int utf8_to_utf16be_sub( wchar_t *pUcs2, const char *pUtf8, int nUtf8Num, BOOL bCountOnly, BOOL bBigEndian);
	static wchar_t* utf8_to_utf16be(const char *pUtf8Str, int *nNumOut, BOOL bBigEndian);
	
};



#endif