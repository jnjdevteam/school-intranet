//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"
#include "Unit3.h"
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
    char SendDate [100];       //보낼수있는 최대글자가 100글자이다.
    memset(SendDate,0x00,sizeof(SendDate));

    Form1->Edit3->Text = Form1->Edit3->Text.Insert("S",1);   //?
    Memo1->Text = Form1->Edit3->Text+":"+Memo1->Text;    //Memo1에 Edit3 텍스트 와 Memo1에 써있는 텍스트가 써진다.
    Form1->Edit3->Text = Form1->Edit3->Text.Delete(1,1); //?

    memcpy(SendDate,Memo1->Text.c_str(),strlen(Memo1->Lines->Text.c_str()));  //?
    Form1->ClientSocket1->Socket->SendBuf(SendDate,100);        //Form1 Client Socket 이 최대보낼수있는 글자수는 100글자이다.

    Memo1->Clear();  //Memo1이 깨끗해진다.
    Form4->Hide();                 //Form4가 가려진다.
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
    Memo1->Clear();                      //Memo1이 꺠끗해진다.
}
//---------------------------------------------------------------------------
