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


/*
 * 現在のカーソル位置X座標取得(単位はmm)
 */
CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()
{
	return myWord::Obj->oCurrentCursorPositionX();

#ifndef WIN32
  #warning "Code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()>"
#endif
  
}

/*
 * 現在のカーソル位置Y座標取得(単位はmm)
 */

CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()
{
	return myWord::Obj->oCurrentCursorPositionY();

#ifndef WIN32
  #warning "Code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()>"
#endif
  
}

/*
 * カーソルをドキュメント先頭に移動
 * sel：Trueなら移動範囲を選択
 */
void mWriterSVC_impl::gotoStart(CORBA::Boolean sel)
{
	myWord::Obj->gotoStart();

#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoStart()>"
#endif
}

/*
 * カーソルをドキュメント最後尾に移動
 * sel：Trueなら移動範囲を選択
 */
void mWriterSVC_impl::gotoEnd(CORBA::Boolean sel)
{
	myWord::Obj->gotoEnd();

#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoEnd()>"
#endif
}

/*
 * カーソルを行先頭に移動
 * sel：Trueなら移動範囲を選択
 */
void mWriterSVC_impl::gotoStartOfLine(CORBA::Boolean sel)
{
	myWord::Obj->gotoStartOfLine();

#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoStartOfLine()>"
#endif
}

/*
 * カーソルを行最後尾に移動
 * sel：Trueなら移動範囲を選択
 */
void mWriterSVC_impl::gotoEndOfLine(CORBA::Boolean sel)
{
	myWord::Obj->gotoEndOfLine();

#ifndef WIN32
  #warning "Code missing in function <void mWriterSVC_impl::gotoEndOfLine()>"
#endif
}







