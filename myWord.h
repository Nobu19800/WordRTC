#ifndef MYWORD_H
#define MYWORD_H

//using namespace Microsoft::Office::Interop::Word;
#define Word   Microsoft::Office::Interop::Word

#include <iostream>
#include <string>
#include <vector>

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
	void SetWord(std::string st);
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

	System::String^ filename;
	Word::Application^ dcApplication;
	Word::Documents^ dcDocuments;
	Word::Document^ dcDocument;

	System::String^ FontName;
	float FontSize;

	int Red, Green, Blue;

	bool MovementType;
	bool Italic;
	bool Bold;

	
};



#endif