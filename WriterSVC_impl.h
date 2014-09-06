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
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~mWriterSVC_impl();

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
   CORBA::Float oCurrentCursorPositionX();
   CORBA::Float oCurrentCursorPositionY();
   void gotoStart(CORBA::Boolean sel);
   void gotoEnd(CORBA::Boolean sel);
   void gotoStartOfLine(CORBA::Boolean sel);
   void gotoEndOfLine(CORBA::Boolean sel);

};



#endif // WRITERSVC_IMPL_H


