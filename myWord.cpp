// -*-C++-*-
/*!
 * @file  myWord.cpp
 * @brief WordÇÃëÄçÏ
 *
 */

#include "myWord.h"


#include <locale.h>



myWord::myWord()
{
	dcApplication = nullptr;
	dcDocuments = nullptr;
	dcDocument = nullptr;

	FontSize = 10;
	FontName = "ÇlÇr ñæí©";
	filename = " ";

	Char_Red = 0;
	Char_Green = 0;
	Char_Blue = 0;

	MovementType = false;
	Italic = false;
	Bold = false;

	Underline = false;
	Shadow = false;
	Strikeout = false;
	Contoured = false;
	Emphasis = false;

	Back_Red = 255;
	Back_Green = 255;
	Back_Blue = 255;

	//Open("");
}

void myWord::SetFontColor(int r, int g, int b)
{
	Char_Red = r;
	Char_Green = g;
	Char_Blue = b;
}

void myWord::SetBackColor(int r, int g, int b)
{
	Back_Red = r;
	Back_Green = g;
	Back_Blue = b;
}

void myWord::SetFontSize(float fs)
{
	FontSize = fs;
}

void myWord::SetFontName(std::string fn)
{
	FontName = gcnew System::String(fn.c_str());
}

void myWord::SetWord(std::string st, std::string m_code)
{
	std::cout << dcDocument->Words->Count << std::endl;
	Word::Selection ^currentSelection = dcApplication->Selection;
	
	
		//Word::Range ^slc = dcDocument->Sentences[dcDocument->Sentences->Count];
		//Word::Selection^ slc = dcDocument->Select;
		//System::Object ^slc = dcDocument->Words[dcDocument->Words->Count]->End-1;
	System::Object ^slc = currentSelection->End;
		//System::Object ^slc = dcDocument->Words->Count;
	
	Word::Range ^tr = dcDocument->Range(slc,slc);
	
	if(m_code == "utf-8")
	{
		int str_size;
		tr->default = gcnew System::String(utf8_to_sjis(st.c_str(),&str_size));
	}
	else
		tr->default = gcnew System::String(st.c_str());

	tr->Font->Size = FontSize;
	tr->Font->Name = FontName;
	tr->Font->Bold = Bold;
	
	
	//tr->Font->Color = gcnew Microsoft::Office::Core::ChartColorFormat::RGB(255, 0, 0);

	System::String^ ts = gcnew System::String(st.c_str());
	
	
	
	currentSelection->MoveRight(static_cast<System::Object^>(Word::WdUnits::wdCharacter), static_cast<System::Object^>(ts->Length) , static_cast<System::Object^>(Word::WdMovementType::wdMove));
	

	
	//Word::Range ^tr = safe_cast<Word::Range^>(dcDocument);
	//tr->Text = "Ç†Ç†Ç†Ç†Ç†";
	
	
	
}

System::String^ myWord::GetSelWord()
{
	Word::Selection ^currentSelection = dcApplication->Selection;

	return currentSelection->default;
}


void myWord::MoveSelection(Word::WdUnits m_type, int leng)
{
	Word::Selection ^currentSelection = dcApplication->Selection;
	
	//if(leng > 0)
	if(!MovementType)
		currentSelection->MoveRight(static_cast<System::Object^>(m_type), static_cast<System::Object^>(leng) , static_cast<System::Object^>(Word::WdMovementType::wdMove));
	else
		currentSelection->MoveRight(static_cast<System::Object^>(m_type), static_cast<System::Object^>(leng) , static_cast<System::Object^>(Word::WdMovementType::wdExtend));
	//else
	//	currentSelection->MoveLeft(static_cast<System::Object^>(m_type), static_cast<System::Object^>(leng) , static_cast<System::Object^>(d_type));

}

void myWord::Open(System::String^ fn)
{
	if(filename == fn)
		return;
	filename = fn;

	Word::Application^ t_dcApplication;
	Word::Documents^ t_dcDocuments;
	Word::Document^ t_dcDocument;
	
	try {
		 try {
			System::Object^tObject = System::Runtime::InteropServices::Marshal::GetActiveObject("Word.Application");
			t_dcApplication = static_cast<Word::Application^>(tObject);
			}
		 catch(...){
				t_dcApplication = gcnew Word::Application();
			}
			t_dcApplication->Visible = true;
			
			try {
				t_dcDocuments = t_dcApplication->Documents;
				if(filename == "")
				{
					t_dcDocument = t_dcDocuments->Add(System::Reflection::Missing::Value,System::Reflection::Missing::Value,System::Reflection::Missing::Value,System::Reflection::Missing::Value);

				}
				else
				{
					t_dcDocument = t_dcDocuments->Open(filename, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value, System::Reflection::Missing::Value);
				}
				Close();
				dcApplication = t_dcApplication;
				dcDocuments = t_dcDocuments;
				dcDocument = t_dcDocument;
			}
			catch(...){

			}
	}
	catch(...){

	}
}

void myWord::Close()
{
	

	if (dcDocuments != nullptr) {
		System::Runtime::InteropServices::Marshal::ReleaseComObject(dcDocuments);
	}
	dcDocuments = nullptr;

	if (dcDocument != nullptr) {
		System::Runtime::InteropServices::Marshal::ReleaseComObject(dcDocument);
	}
	dcDocument = nullptr;
}

float myWord::oCurrentCursorPositionX()
{
	return 0;
}
float myWord::oCurrentCursorPositionY()
{
	return 0;
}
void myWord::gotoStart()
{

}
void myWord::gotoEnd()
{

}
void myWord::gotoStartOfLine()
{

}
void myWord::gotoEndOfLine()
{

}

char *myWord::utf8_to_sjis(const char *pUtf8Str, int *nBytesOut)
{
    int nNum, nBytes;

    wchar_t *pwcWork = utf8_to_utf16be( pUtf8Str, &nNum, TRUE);
    char *pcSjis = utf16be_to_sjis( pwcWork, &nBytes);
    free( pwcWork);

    *nBytesOut = nBytes;
    return pcSjis;
}
int myWord::utf8_to_utf16be_sub( wchar_t *pUcs2, const char *pUtf8, int nUtf8Num,
                          BOOL bCountOnly, BOOL bBigEndian)
{
    int nUtf8, nUcs2 = 0;
    char cHigh, cLow;

    for ( nUtf8=0; nUtf8 < nUtf8Num;) {
        if ( ( pUtf8[nUtf8] & 0x80) == 0x00) {
            if ( bCountOnly == FALSE) {
                pUcs2[nUcs2] = ( pUtf8[nUtf8] & 0x7f);
            }
            nUtf8 += 1;
        } else if ( ( pUtf8[nUtf8] & 0xe0) == 0xc0) {
            if ( bCountOnly == FALSE) {
                pUcs2[nUcs2] = ( pUtf8[nUtf8] & 0x1f) << 6;
                pUcs2[nUcs2] |= ( pUtf8[nUtf8+1] & 0x3f);
            }
            nUtf8 += 2;
        } else {
            if ( bCountOnly == FALSE) {
                pUcs2[nUcs2] = ( pUtf8[nUtf8] & 0x0f) << 12;
                pUcs2[nUcs2] |= ( pUtf8[nUtf8+1] & 0x3f) << 6;
                pUcs2[nUcs2] |= ( pUtf8[nUtf8+2] & 0x3f);
            }
            nUtf8 += 3;
        }

        if ( bCountOnly == FALSE) {
            if ( !bBigEndian) {
                
                cHigh = (pUcs2[nUcs2] & 0xff00) >> 8;
                cLow = (pUcs2[nUcs2] & 0x00ff);
                pUcs2[nUcs2] = (cLow << 8) | cHigh;
            }
        }

        nUcs2 += 1;
    }
    if ( bCountOnly == FALSE) {
        pUcs2[nUcs2] = L'\0';
    }

    return nUcs2;
}




char *myWord::utf16be_to_sjis(const wchar_t *pUcsStr, int *nBytesOut)
{
    char *pAnsiStr = NULL;
    int nLen;

    if (!pUcsStr) return NULL;

    setlocale(LC_ALL, "Japanese");

    nLen = wcslen( pUcsStr);

    if ( pUcsStr[0] == 0xfeff || pUcsStr[0] == 0xfffe) {
        pUcsStr++;
        nLen--;
    }

    pAnsiStr = (char *)calloc((nLen+1), sizeof(wchar_t));
    if (!pAnsiStr) return NULL;

    
    int nRet, i, nMbpos = 0;
    char *pcMbchar = new char[MB_CUR_MAX];

    for ( i=0; i < nLen; i++) {
        nRet = wctomb( pcMbchar, pUcsStr[i]);
        switch ( nRet) {
        case 1:
            pAnsiStr[nMbpos++] = pcMbchar[0];
            break;

        case 2:
            pAnsiStr[nMbpos++] = pcMbchar[0];
            pAnsiStr[nMbpos++] = pcMbchar[1];
            break;

        default:
            pAnsiStr[nMbpos++] = ' ';
            break;
        }
    }
    pAnsiStr[nMbpos] = '\0';

    delete [] pcMbchar;

    *nBytesOut = nMbpos;

    return pAnsiStr;
}

wchar_t *myWord::utf8_to_utf16be(const char *pUtf8Str, int *nNumOut, BOOL bBigEndian)
{
    int nUtf8Num;
    wchar_t *pUcsStr;

    nUtf8Num = strlen(pUtf8Str);
    *nNumOut = utf8_to_utf16be_sub( NULL, pUtf8Str, nUtf8Num, TRUE, bBigEndian);

    pUcsStr = (wchar_t *)calloc((*nNumOut + 1), sizeof(wchar_t));
    utf8_to_utf16be_sub( pUcsStr, pUtf8Str, nUtf8Num, FALSE, bBigEndian);

    return pUcsStr;
}