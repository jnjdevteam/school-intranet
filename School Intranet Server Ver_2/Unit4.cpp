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
    char SendDate [100];    //�������ִ� ���ڼ��� 100�����̳��̴�.
    memset(SendDate,0x00,sizeof(SendDate));      //?

    Form1->Edit2->Text = Form1->Edit2->Text.Insert("S",1);
    Memo1->Text = Form1->Edit2->Text+":"+Memo1->Text;     //Memo1��  Form1�� Edit2 �������� �ؽ�Ʈ�� Memo1�� ������ �ؽ�Ʈ�� ������ ������.
    Form1->Edit2->Text = Form1->Edit2->Text.Delete(1,1);

    memcpy(SendDate,Memo1->Text.c_str(),strlen(Memo1->Lines->Text.c_str()));
    Form1->ServerSocket1->Socket->Connections[Form1->ListBox1->ItemIndex]->SendBuf(SendDate,100);

    Memo1->Clear();      //Memo1�� ����������.

    Form4->Hide();      //Form4�� ��������.
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
    Memo1->Clear();     //Memo1�� ����������.
}
//---------------------------------------------------------------------------
