// -*-C++-*-
/*!
 * @file  WriterSVC_impl.cpp
 * @brief Service implementation code of Writer.idl
 *
 */

#include "WriterSVC_impl.h"
#include "myWord.h"


mWriterSVC_impl::mWriterSVC_impl()
{

}


mWriterSVC_impl::~mWriterSVC_impl()
{

}



CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()
{
	return myWord::Obj->oCurrentCursorPositionX();

#ifndef WIN32
  #warning "Code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()>"
#endif
  
}



CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()
{
	return myWord::Obj->oCurrentCursorPositionY();

#ifndef WIN32
  #warning "Code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()>"
#endif
  
}


void mWriterSVC_impl::gotoStart(CORBA::Boolean sel)
{
	myWord::Obj->gotoStart();

#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoStart()>"
#endif
}


void mWriterSVC_impl::gotoEnd(CORBA::Boolean sel)
{
	myWord::Obj->gotoEnd();

#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoEnd()>"
#endif
}


void mWriterSVC_impl::gotoStartOfLine(CORBA::Boolean sel)
{
	myWord::Obj->gotoStartOfLine();

#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoStartOfLine()>"
#endif
}


void mWriterSVC_impl::gotoEndOfLine(CORBA::Boolean sel)
{
	myWord::Obj->gotoEndOfLine();

#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoEndOfLine()>"
#endif
}







