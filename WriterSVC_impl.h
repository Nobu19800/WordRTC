// -*-C++-*-
/*!
 * @file  WriterSVC_impl.h
 * @brief Service implementation header of Writer.idl
 *
 */

#include "WriterSkel.h"

#ifndef WRITERSVC_IMPL_H
#define WRITERSVC_IMPL_H
 
/*!
 * @class mWriterSVC_impl
 * Example class implementing IDL interface Writer::mWriter
 */
class mWriterSVC_impl
 : public virtual POA_Writer::mWriter,
   public virtual PortableServer::RefCountServantBase
{
 private:
   

 public:
  /*!
   * @brief standard constructor
   */
   mWriterSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~mWriterSVC_impl();

   // attributes and operations
   /**
   *@brief ���݂̃J�[�\���ʒuX���W�擾(�P�ʂ�mm)
   * @return �J�[�\���ʒuX���W
   */
   
   CORBA::Float oCurrentCursorPositionX();
   /**
   *@brief ���݂̃J�[�\���ʒuY���W�擾(�P�ʂ�mm)
   * @return �J�[�\���ʒuY���W
   */
   CORBA::Float oCurrentCursorPositionY();
   /**
   *@brief �J�[�\�����h�L�������g�擪�Ɉړ�
   *@param sel True�Ȃ�ړ��͈͂�I��
   */
   void gotoStart(CORBA::Boolean sel);
   /**
   *@brief �J�[�\�����h�L�������g�Ō���Ɉړ�
   *@param sel True�Ȃ�ړ��͈͂�I��
   */
   
   void gotoEnd(CORBA::Boolean sel);
   /**
   *@brief �J�[�\�����s�擪�Ɉړ�
   *@param sel True�Ȃ�ړ��͈͂�I��
   */
   void gotoStartOfLine(CORBA::Boolean sel);
   /**
   *@brief �J�[�\�����s�Ō���Ɉړ�
   *@param sel True�Ȃ�ړ��͈͂�I��
   */
   void gotoEndOfLine(CORBA::Boolean sel);
   

};



#endif // WRITERSVC_IMPL_H


