// -*-C++-*-
/*!
 * @file  WriterSVC_impl.cpp
 * @brief Service implementation code of Writer.idl
 *
 */

#include "WriterSVC_impl.h"
#include "myWord.h"

/*
 * Example implementational code for IDL interface Writer::mWriter
 */
mWriterSVC_impl::mWriterSVC_impl()
{
  // Please add extra constructor code here.
}


mWriterSVC_impl::~mWriterSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()
{
	return myWord::Obj->oCurrentCursorPositionX();
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()>"
#endif
  
}

CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()
{
	return myWord::Obj->oCurrentCursorPositionY();
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()>"
#endif
  
}

void mWriterSVC_impl::gotoStart(CORBA::Boolean sel)
{
	myWord::Obj->gotoStart();
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoStart()>"
#endif
}

void mWriterSVC_impl::gotoEnd(CORBA::Boolean sel)
{
	myWord::Obj->gotoEnd();
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoEnd()>"
#endif
}

void mWriterSVC_impl::gotoStartOfLine(CORBA::Boolean sel)
{
	myWord::Obj->gotoStartOfLine();
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoStartOfLine()>"
#endif
}

void mWriterSVC_impl::gotoEndOfLine(CORBA::Boolean sel)
{
	myWord::Obj->gotoEndOfLine();
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoEndOfLine()>"
#endif
}



// End of example implementational code



