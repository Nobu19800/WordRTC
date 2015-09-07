// -*-C++-*-
/*!
 * @file  WordObject.h
 * @brief Word�̑���
 */
#ifndef WordObject_H
#define WordObject_H

//using namespace Microsoft::Office::Interop::Word;
#define Word   Microsoft::Office::Interop::Word

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "SubFunction.h"
#include "UnicodeF.h"


/**
 * @class WordObject
*@brief Word�𑀍삷��N���X
*/
ref class WordObject
{
public:
	/**
	*@brief �R���X�g���N�^
	*/
	WordObject();

	static WordObject^ Obj; /**<�@@brief  */

	
	/**
	*@brief Word�t�@�C�����J���֐�
	* @param fn �t�@�C���p�X
	*/
	void Open(System::String^ fn);
	
	/**
	*@brief COM�I�u�W�F�N�g���������֐�
	*/
	void Close();

	
	/**
	*@brief ��������������ފ֐�
	* @param st �������ޕ�����
	* @param m_code �����R�[�h
	*/
	void setWord(std::string st, std::string m_code);
	
	/**
	*@brief �t�H���g�̃T�C�Y��ύX����֐�
	* @param fs �t�H���g�T�C�Y
	*/
	void setFontSize(float fs);
	
	/**
	*@brief �t�H���g�̎�ނ�ύX����֐�
	* @param fn �t�H���g�̎��
	*/
	void setFontName(std::string fn);

	
	/**
	*@brief �I���ʒu��ύX����֐�
	* @param m_type �ړ��̃^�C�v
	* @param leng �ړ���
	*/
	void moveSelection(Word::WdUnits m_type, int leng);

	
	/**
	*@brief �I���ʒu�̕�������擾����֐�
	* @return �擾����������
	*/
	System::String^ getSelWord();

	
	/**
	*@brief �����̐F��ύX����֐�
	* @param r �����̐F(R)
	* @param g �����̐F(G)
	* @param b �����̐F(B)
	*/
	void setFontColor(int r, int g, int b);

	
	/**
	*@brief �w�i�F��ύX����֐�
	* @param r �����̐F(R)
	* @param g �����̐F(G)
	* @param b �����̐F(B)
	*/
	void setBackColor(int r, int g, int b);

	/**
	*@brief �J�[�\���ʒu��X���W�擾(�P�ʂ�mm)��������
	* @return �J�[�\���ʒu��X���W
	*/
	float oCurrentCursorPositionX();
	/**
	*@brief �J�[�\���ʒu��Y���W�擾(�P�ʂ�mm)��������
	* @return �J�[�\���ʒu��X���W
	*/
	float oCurrentCursorPositionY();
	/**
	*@brief �J�[�\�����h�L�������g�擪�ֈړ���������
	*/
	void gotoStart();
	/**
	*@brief �J�[�\�����h�L�������g�Ō���ֈړ���������
	*/
	void gotoEnd();
	/**
	*@brief �J�[�\�����s�擪�ֈړ���������
	*/
	void gotoStartOfLine();
	/**
	*@brief �J�[�\�����s�Ō���ֈړ���������
	*/
	void gotoEndOfLine();


	System::String^ filename; /**<�@@brief  */
	Word::Application^ dcApplication; /**<�@@brief  */
	Word::Documents^ dcDocuments; /**<�@@brief  */
	Word::Document^ dcDocument; /**<�@@brief  */

	System::String^ fontName; /**<�@@brief  */
	float fontSize; /**<�@@brief  */

	int char_Red, char_Green, char_Blue; /**<�@@brief  */

	bool movementType; /**<�@@brief  */
	bool italic; /**<�@@brief  */
	bool bold; /**<�@@brief  */

	bool underline; /**<�@@brief  */
	bool shadow; /**<�@@brief  */
	bool strikeout; /**<�@@brief  */
	bool contoured; /**<�@@brief  */
	bool emphasis; /**<�@@brief  */

	int back_Red, back_Green, back_Blue; /**<�@@brief  */

	
};



#endif