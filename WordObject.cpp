// -*-C++-*-
/*!
 * @file  WordObject.cpp
 * @brief Word�̑���
 *
 */

#include "WordObject.h"


#include <locale.h>


/**
*@brief Word�𑀍삷��N���X�̃R���X�g���N�^
*/
WordObject::WordObject()
{
	dcApplication = nullptr;
	dcDocuments = nullptr;
	dcDocument = nullptr;

	fontSize = 10;
	fontName = "�l�r ����";
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
*@brief �����̐F��ύX����֐�
* @param r �����̐F(R)
* @param g �����̐F(G)
* @param b �����̐F(B)
*/
void WordObject::setFontColor(int r, int g, int b)
{
	char_Red = r;
	char_Green = g;
	char_Blue = b;
}

/**
*@brief �w�i�F��ύX����֐�
* @param r �����̐F(R)
* @param g �����̐F(G)
* @param b �����̐F(B)
*/
void WordObject::setBackColor(int r, int g, int b)
{
	back_Red = r;
	back_Green = g;
	back_Blue = b;
}

/**
*@brief �t�H���g�̃T�C�Y��ύX����֐�
* @param fs �t�H���g�T�C�Y
*/
void WordObject::setFontSize(float fs)
{
	fontSize = fs;
}

/**
*@brief �t�H���g�̎�ނ�ύX����֐�
* @param fn �t�H���g�̎��
*/
void WordObject::setFontName(std::string fn)
{
	fontName = gcnew System::String(fn.c_str());
}

/**
*@brief ��������������ފ֐�
* @param st �������ޕ�����
* @param m_code �����R�[�h
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
	//tr->Text = "����������";
	
	
	
}

/**
*@brief �I���ʒu�̕�������擾����֐�
* @return �擾����������
*/
System::String^ WordObject::getSelWord()
{
	Word::Selection ^currentSelection = dcApplication->Selection;

	return currentSelection->default;
}

/**
*@brief �I���ʒu��ύX����֐�
* @param m_type �ړ��̃^�C�v
* @param leng �ړ���
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
*@brief Word�t�@�C�����J���֐�
* @param fn �t�@�C���p�X
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
*@brief COM�I�u�W�F�N�g���������֐�
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
*@brief �J�[�\���ʒu��X���W�擾(�P�ʂ�mm)��������
* @return �J�[�\���ʒu��X���W
*/
float WordObject::oCurrentCursorPositionX()
{
	return 0;
}

/**
*@brief �J�[�\���ʒu��Y���W�擾(�P�ʂ�mm)��������
* @return �J�[�\���ʒu��X���W
*/
float WordObject::oCurrentCursorPositionY()
{
	return 0;
}

/**
*@brief �J�[�\�����h�L�������g�擪�ֈړ���������
*/
void WordObject::gotoStart()
{

}

/**
*@brief �J�[�\�����h�L�������g�Ō���ֈړ���������
*/
void WordObject::gotoEnd()
{

}

/**
*@brief �J�[�\�����s�擪�ֈړ���������
*/
void WordObject::gotoStartOfLine()
{

}

/**
*@brief �J�[�\�����s�Ō���ֈړ���������
*/
void WordObject::gotoEndOfLine()
{

}


