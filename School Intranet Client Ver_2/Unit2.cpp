//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int i=0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
    Form2->Hide();     //Form2�� ��������.
    Form1->Show();     //Form1�� ��������.
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
    Form1->Hide();   //Form1�� ��������.
    Form1->Memo1->Clear(); //Form1 Memo1�� ����������.
    Form1->Memo2->Clear();      //  Form1 Memo2�� ����������.
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormHide(TObject *Sender)
{
    Form2->Hide();       //Form2�°�������.
}
//---------------------------------------------------------------------------

