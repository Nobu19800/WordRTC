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

	//Word�t�@�C�����J���֐�
	void Open(System::String^ fn);
	//COM�I�u�W�F�N�g���������֐�
	void Close();

	//��������������ފ֐�
	void SetWord(std::string st, std::string m_code);
	//�t�H���g�̃T�C�Y��ύX����֐�
	void SetFontSize(float fs);
	//�t�H���g�̎�ނ�ύX����֐�
	void SetFontName(std::string fn);

	//�I���ʒu��ύX����֐�
	void MoveSelection(Word::WdUnits m_type, int leng);

	//�I���ʒu�̕�������擾����֐�
	System::String^ GetSelWord();

	//�����̐F��ύX����֐�
	void SetFontColor(int r, int g, int b);

	//�w�i�F��ύX����֐�
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