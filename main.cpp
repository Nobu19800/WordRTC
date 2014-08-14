#include<windows.h>
#include<stdio.h>
#include<iostream>

#include "MyObject.h"
#include "myWord.h"
 
using namespace std;

 
int main()
{
	myWord^ mw = gcnew myWord();
	mw->Open("");
	
	mw->SetWord("‚ ‚ ‚ ‚ ‚ ‚ ");
	mw->SetFontSize(20.5);
	mw->SetFontName("Arial");
	mw->MoveSelection(Word::WdUnits::wdCharacter,-4,Word::WdMovementType::wdMove);
	//mw->MoveSelection(Word::WdUnits::wdCharacter,4,Word::WdMovementType::wdMove);
	mw->SetWord("‚¢‚¢‚¢‚¢‚¢‚¢");
 
	return 0;
}