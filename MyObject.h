#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <vector>
#include <string>
#include <sstream>


//�Z���̔ԍ�(�A���t�@�x�b�g)�𐔒l�ɕϊ�����֐�
int convertStrToVal(std::string m_str);


//������u������֐�
std::string Replace( std::string String1, std::string String2, std::string String3 );


//RTC�̃f�[�^�|�[�g�̃c���[�̊e�I�u�W�F�N�g�N���X
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

//System::String��std::string�ɕϊ�����֐�
std::string MarshalString ( System::String ^ s);

//����������̕����ŕ�������֐�
std::vector<std::string> split(const std::string &str, const std::string &delim);

//������𐔒l�ɕϊ�����֐�
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