//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{

    Memo1->Clear();  //Memo1이 깨끗해진다.
    Form4->Memo1->Clear();   //Form4 Memo1은 깨끗해진다.
    Form3->Hide();            //Form3는 가려진다.
    Form4->Show();                  //Form4는 보여진다.
}
//---------------------------------------------------------------------------
