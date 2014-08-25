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

	//Word�t�@�C�����J���֐�
	void Open(System::String^ fn);
	//COM�I�u�W�F�N�g���������֐�
	void Close();

	//��������������ފ֐�
	void SetWord(std::string st);
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