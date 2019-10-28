//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
    char SendDate [100];    //보낼수있는 글자수가 100글자이내이다.
    memset(SendDate,0x00,sizeof(SendDate));      //?

    Form1->Edit2->Text = Form1->Edit2->Text.Insert("S",1);
    Memo1->Text = Form1->Edit2->Text+":"+Memo1->Text;     //Memo1에  Form1에 Edit2 에쓰여진 텍스트와 Memo1에 쓰여진 텍스트가 합쳐져 써진다.
    Form1->Edit2->Text = Form1->Edit2->Text.Delete(1,1);

    memcpy(SendDate,Memo1->Text.c_str(),strlen(Memo1->Lines->Text.c_str()));
    Form1->ServerSocket1->Socket->Connections[Form1->ListBox1->ItemIndex]->SendBuf(SendDate,100);

    Memo1->Clear();      //Memo1은 깨끗해진다.

    Form4->Hide();      //Form4는 가려진다.
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
    Memo1->Clear();     //Memo1은 깨끗해진다.
}
//---------------------------------------------------------------------------
