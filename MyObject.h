// -*-C++-*-
/*!
 * @file  MyObject.h
 *
 */
#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <vector>
#include <string>
#include <sstream>



/**
*@brief �Z���̔ԍ�(�A���t�@�x�b�g)�𐔒l�ɕϊ�����֐�
*/
int convertStrToVal(std::string m_str);



/**
*@brief ������u������֐�
*/
std::string Replace( std::string String1, std::string String2, std::string String3 );



/**
*@brief RTC�̃f�[�^�|�[�g�̃c���[�̊e�I�u�W�F�N�g�N���X
*/
class TreeObject
{
public:
	TreeObject(std::string n)
	{
		name = n;
	};
	std::string name;
	std::vector<TreeObject*> to;
};


/**
*@brief System::String��std::string�ɕϊ�����֐�
*/
std::string MarshalString ( System::String ^ s);


/**
*@brief ����������̕����ŕ�������֐�
*/
std::vector<std::string> split(const std::string &str, const std::string &delim);


/**
*@brief ������𐔒l�ɕϊ�����֐�
*/
template<typename T>
T string2binary(const std::string& text, int base) {
    
    std::istringstream is(text);
    T value;
    switch (base) {
    case 8:
        is >> std::oct >> value;
        break;
    case 10:
        is >> value;
        break;
    case 16:
        is >> std::hex >> value;
        break;
    default:
        ;
    }

    return value;
}

#endif