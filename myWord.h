// -*-C++-*-
/*!
 * @file  myWord.h
 *
 */
#ifndef MYWORD_H
#define MYWORD_H

//using namespace Microsoft::Office::Interop::Word;
#define Word   Microsoft::Office::Interop::Word

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "MyObject.h"


/**
 * @class myWord
*@brief Word�𑀍삷��N���X
*/
ref class myWord
{
public:
	/**
	*@brief �R���X�g���N�^
	*/
	myWord();

	static myWord^ Obj; /**<�@@brief  */

	
	/**
	*@brief Word�t�@�C�����J���֐�
	* @param fn
	*/
	void Open(System::String^ fn);
	
	/**
	*@brief COM�I�u�W�F�N�g���������֐�
	*/
	void Close();

	
	/**
	*@brief ��������������ފ֐�
	* @param st
	* @param m_code
	*/
	void SetWord(std::string st, std::string m_code);
	
	/**
	*@brief �t�H���g�̃T�C�Y��ύX����֐�
	* @param fs
	*/
	void SetFontSize(float fs);
	
	/**
	*@brief �t�H���g�̎�ނ�ύX����֐�
	* @param fn
	*/
	void SetFontName(std::string fn);

	
	/**
	*@brief �I���ʒu��ύX����֐�
	* @param m_type
	* @param leng
	*/
	void MoveSelection(Word::WdUnits m_type, int leng);

	
	/**
	*@brief �I���ʒu�̕�������擾����֐�
	* @return 
	*/
	System::String^ GetSelWord();

	
	/**
	*@brief �����̐F��ύX����֐�
	* @param r
	* @param g
	* @param b
	*/
	void SetFontColor(int r, int g, int b);

	
	/**
	*@brief �w�i�F��ύX����֐�
	* @param r
	* @param g
	* @param b
	*/
	void SetBackColor(int r, int g, int b);

	/**
	*@brief �J�[�\���ʒu��X���W�擾(�P�ʂ�mm)
	* @return �J�[�\���ʒu��X���W
	*/
	float oCurrentCursorPositionX();
	/**
	*@brief �J�[�\���ʒu��Y���W�擾(�P�ʂ�mm)
	* @return �J�[�\���ʒu��X���W
	*/
	float oCurrentCursorPositionY();
	/**
	*@brief �J�[�\�����h�L�������g�擪�ֈړ�
	*/
	void gotoStart();
	/**
	*@brief �J�[�\�����h�L�������g�Ō���ֈړ�
	*/
	void gotoEnd();
	/**
	*@brief �J�[�\�����s�擪�ֈړ�
	*/
	void gotoStartOfLine();
	/**
	*@brief �J�[�\�����s�Ō���ֈړ�
	*/
	void gotoEndOfLine();


	System::String^ filename; /**<�@@brief  */
	Word::Application^ dcApplication; /**<�@@brief  */
	Word::Documents^ dcDocuments; /**<�@@brief  */
	Word::Document^ dcDocument; /**<�@@brief  */

	System::String^ FontName; /**<�@@brief  */
	float FontSize; /**<�@@brief  */

	int Char_Red, Char_Green, Char_Blue; /**<�@@brief  */

	bool MovementType; /**<�@@brief  */
	bool Italic; /**<�@@brief  */
	bool Bold; /**<�@@brief  */

	bool Underline; /**<�@@brief  */
	bool Shadow; /**<�@@brief  */
	bool Strikeout; /**<�@@brief  */
	bool Contoured; /**<�@@brief  */
	bool Emphasis; /**<�@@brief  */

	int Back_Red, Back_Green, Back_Blue; /**<�@@brief  */

	/**
	*@brief
	* @param pUtf8Str
	* @param nBytesOut
	* @return 
	*/
	static char* utf8_to_sjis(const char *pUtf8Str, int *nBytesOut);
	
	/**
	*@brief
	* @param pUcsStr
	* @param nBytesOut
	* @return 
	*/
	static char* utf16be_to_sjis(const wchar_t *pUcsStr, int *nBytesOut);

	/**
	*@brief
	* @param pUcs2
	* @param pUtf8
	* @param nUtf8Num
	* @param bCountOnly
	* @param bBigEndian
	* @return 
	*/
	static int utf8_to_utf16be_sub( wchar_t *pUcs2, const char *pUtf8, int nUtf8Num, BOOL bCountOnly, BOOL bBigEndian);

	/**
	*@brief
	* @param pUtf8Str
	* @param nNumOut
	* @param bBigEndian
	* @return 
	*/
	static wchar_t* utf8_to_utf16be(const char *pUtf8Str, int *nNumOut, BOOL bBigEndian);
	
};



#endif