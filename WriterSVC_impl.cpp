// -*-C++-*-
/*!
 * @file  WriterSVC_impl.cpp
 * @brief Service implementation code of Writer.idl
 *
 */

#include "WriterSVC_impl.h"
#include "WordObject.h"

/*!
* @brief ���[�h�𑀍삷�邽�߂̃C���^�[�t�F�[�X�̃R���X�g���N�^
*/
mWriterSVC_impl::mWriterSVC_impl()
{

}

/*!
* @brief ���[�h�𑀍삷�邽�߂̃C���^�[�t�F�[�X�̃f�X�g���N�^
*/
mWriterSVC_impl::~mWriterSVC_impl()
{

}


/**
*@brief ���݂̃J�[�\���ʒuX���W�擾(�P�ʂ�mm)
* @return �J�[�\���ʒuX���W
*/
CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()
{
	return WordObject::Obj->oCurrentCursorPositionX();

#ifndef WIN32
  #warning "code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()>"
#endif
  
}


/**
*@brief ���݂̃J�[�\���ʒuY���W�擾(�P�ʂ�mm)
* @return �J�[�\���ʒuY���W
*/
CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()
{
	return WordObject::Obj->oCurrentCursorPositionY();

#ifndef WIN32
  #warning "code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()>"
#endif
  
}

/**
*@brief �J�[�\�����h�L�������g�擪�Ɉړ�
*@param sel True�Ȃ�ړ��͈͂�I��
*/
void mWriterSVC_impl::gotoStart(CORBA::Boolean sel)
{
	WordObject::Obj->gotoStart();

#ifndef WIN32
  #warning "code missing in function <void mWriterSVC_impl::gotoStart()>"
#endif
}

/**
*@brief �J�[�\�����h�L�������g�Ō���Ɉړ�
*@param sel True�Ȃ�ړ��͈͂�I��
*/
void mWriterSVC_impl::gotoEnd(CORBA::Boolean sel)
{
	WordObject::Obj->gotoEnd();

#ifndef WIN32
  #warning "code missing in function <void mWriterSVC_impl::gotoEnd()>"
#endif
}

/**
*@brief �J�[�\�����s�擪�Ɉړ�
*@param sel True�Ȃ�ړ��͈͂�I��
*/
void mWriterSVC_impl::gotoStartOfLine(CORBA::Boolean sel)
{
	WordObject::Obj->gotoStartOfLine();

#ifndef WIN32
  #warning "code missing in function <void mWriterSVC_impl::gotoStartOfLine()>"
#endif
}

/**
*@brief �J�[�\�����s�Ō���Ɉړ�
*@param sel True�Ȃ�ړ��͈͂�I��
*/
void mWriterSVC_impl::gotoEndOfLine(CORBA::Boolean sel)
{
	WordObject::Obj->gotoEndOfLine();

#ifndef WIN32
  #warning "code missing in function <void mWriterSVC_impl::gotoEndOfLine()>"
#endif
}







