// -*-C++-*-
/*!
 * @file  WriterSVC_impl.cpp
 * @brief Service implementation code of Writer.idl
 *
 */

#include "WriterSVC_impl.h"
#include "WordObject.h"

/*!
* @brief ワードを操作するためのインターフェースのコンストラクタ
*/
mWriterSVC_impl::mWriterSVC_impl()
{

}

/*!
* @brief ワードを操作するためのインターフェースのデストラクタ
*/
mWriterSVC_impl::~mWriterSVC_impl()
{

}


/**
*@brief 現在のカーソル位置X座標取得(単位はmm)
* @return カーソル位置X座標
*/
CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()
{
	return WordObject::Obj->oCurrentCursorPositionX();

#ifndef WIN32
  #warning "code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionX()>"
#endif
  
}


/**
*@brief 現在のカーソル位置Y座標取得(単位はmm)
* @return カーソル位置Y座標
*/
CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()
{
	return WordObject::Obj->oCurrentCursorPositionY();

#ifndef WIN32
  #warning "code missing in function <CORBA::Float mWriterSVC_impl::oCurrentCursorPositionY()>"
#endif
  
}

/**
*@brief カーソルをドキュメント先頭に移動
*@param sel Trueなら移動範囲を選択
*/
void mWriterSVC_impl::gotoStart(CORBA::Boolean sel)
{
	WordObject::Obj->gotoStart();

#ifndef WIN32
  #warning "code missing in function <void mWriterSVC_impl::gotoStart()>"
#endif
}

/**
*@brief カーソルをドキュメント最後尾に移動
*@param sel Trueなら移動範囲を選択
*/
void mWriterSVC_impl::gotoEnd(CORBA::Boolean sel)
{
	WordObject::Obj->gotoEnd();

#ifndef WIN32
  #warning "code missing in function <void mWriterSVC_impl::gotoEnd()>"
#endif
}

/**
*@brief カーソルを行先頭に移動
*@param sel Trueなら移動範囲を選択
*/
void mWriterSVC_impl::gotoStartOfLine(CORBA::Boolean sel)
{
	WordObject::Obj->gotoStartOfLine();

#ifndef WIN32
  #warning "code missing in function <void mWriterSVC_impl::gotoStartOfLine()>"
#endif
}

/**
*@brief カーソルを行最後尾に移動
*@param sel Trueなら移動範囲を選択
*/
void mWriterSVC_impl::gotoEndOfLine(CORBA::Boolean sel)
{
	WordObject::Obj->gotoEndOfLine();

#ifndef WIN32
  #warning "code missing in function <void mWriterSVC_impl::gotoEndOfLine()>"
#endif
}







