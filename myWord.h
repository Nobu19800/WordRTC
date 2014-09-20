// -*-C++-*-
/*!
 * @file  myWord.h
 *
 */
#ifndef MYWORD_H
#define MYWORD_H

//using namespace Microsoft::Office::Interop::Word;
#define Word   Microsoft::Office::Interop::Word

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "MyObject.h"


/**
 * @class myWord
*@brief Wordを操作するクラス
*/
ref class myWord
{
public:
	/**
	*@brief コンストラクタ
	*/
	myWord();

	static myWord^ Obj; /**<　@brief  */

	
	/**
	*@brief Wordファイルを開く関数
	* @param fn
	*/
	void Open(System::String^ fn);
	
	/**
	*@brief COMオブジェクトを解放する関数
	*/
	void Close();

	
	/**
	*@brief 文字列を書き込む関数
	* @param st
	* @param m_code
	*/
	void SetWord(std::string st, std::string m_code);
	
	/**
	*@brief フォントのサイズを変更する関数
	* @param fs
	*/
	void SetFontSize(float fs);
	
	/**
	*@brief フォントの種類を変更する関数
	* @param fn
	*/
	void SetFontName(std::string fn);

	
	/**
	*@brief 選択位置を変更する関数
	* @param m_type
	* @param leng
	*/
	void MoveSelection(Word::WdUnits m_type, int leng);

	
	/**
	*@brief 選択位置の文字列を取得する関数
	* @return 
	*/
	System::String^ GetSelWord();

	
	/**
	*@brief 文字の色を変更する関数
	* @param r
	* @param g
	* @param b
	*/
	void SetFontColor(int r, int g, int b);

	
	/**
	*@brief 背景色を変更する関数
	* @param r
	* @param g
	* @param b
	*/
	void SetBackColor(int r, int g, int b);

	/**
	*@brief カーソル位置のX座標取得(単位はmm)
	* @return カーソル位置のX座標
	*/
	float oCurrentCursorPositionX();
	/**
	*@brief カーソル位置のY座標取得(単位はmm)
	* @return カーソル位置のX座標
	*/
	float oCurrentCursorPositionY();
	/**
	*@brief カーソルをドキュメント先頭へ移動
	*/
	void gotoStart();
	/**
	*@brief カーソルをドキュメント最後尾へ移動
	*/
	void gotoEnd();
	/**
	*@brief カーソルを行先頭へ移動
	*/
	void gotoStartOfLine();
	/**
	*@brief カーソルを行最後尾へ移動
	*/
	void gotoEndOfLine();


	System::String^ filename; /**<　@brief  */
	Word::Application^ dcApplication; /**<　@brief  */
	Word::Documents^ dcDocuments; /**<　@brief  */
	Word::Document^ dcDocument; /**<　@brief  */

	System::String^ FontName; /**<　@brief  */
	float FontSize; /**<　@brief  */

	int Char_Red, Char_Green, Char_Blue; /**<　@brief  */

	bool MovementType; /**<　@brief  */
	bool Italic; /**<　@brief  */
	bool Bold; /**<　@brief  */

	bool Underline; /**<　@brief  */
	bool Shadow; /**<　@brief  */
	bool Strikeout; /**<　@brief  */
	bool Contoured; /**<　@brief  */
	bool Emphasis; /**<　@brief  */

	int Back_Red, Back_Green, Back_Blue; /**<　@brief  */

	/**
	*@brief
	* @param pUtf8Str
	* @param nBytesOut
	* @return 
	*/
	static char* utf8_to_sjis(const char *pUtf8Str, int *nBytesOut);
	
	/**
	*@brief
	* @param pUcsStr
	* @param nBytesOut
	* @return 
	*/
	static char* utf16be_to_sjis(const wchar_t *pUcsStr, int *nBytesOut);

	/**
	*@brief
	* @param pUcs2
	* @param pUtf8
	* @param nUtf8Num
	* @param bCountOnly
	* @param bBigEndian
	* @return 
	*/
	static int utf8_to_utf16be_sub( wchar_t *pUcs2, const char *pUtf8, int nUtf8Num, BOOL bCountOnly, BOOL bBigEndian);

	/**
	*@brief
	* @param pUtf8Str
	* @param nNumOut
	* @param bBigEndian
	* @return 
	*/
	static wchar_t* utf8_to_utf16be(const char *pUtf8Str, int *nNumOut, BOOL bBigEndian);
	
};



#endif