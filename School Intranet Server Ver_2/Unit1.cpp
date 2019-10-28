//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Memo1->Clear(); //Memo1 �� �ִ� �ؽ�Ʈ�� �����ش�.
    Edit1->Clear(); //Edit1 �� �ִ� �ؽ�Ʋ  �����ش�.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    char Buff[100]; // �ޱ����� �ҽ�, 100���ڼ�
    memset(Buff,0x00,100); //��Ȯ�ϰ� �𸣰ٴ� (�ʱ�ȭ)
    ServerSocket1->Socket->Connections[ListBox1->ItemIndex]->ReceiveBuf(Buff,100);//ServerSocket1 �� �������ϴ� ������ ip�� ������� 0,1�� ǥ���Ѵ�. ListBox1�� �ִ´� Item Index? �� ����  �޴� ���ڸ� 100�����̳��� �������մ�.
    //AnsiString Buff;
    //Buff = Socket->ReceiveText();
    //Memo1->Lines->Add(Buff);
    AnsiString A; // ?
    A  = Buff ;  //   ?

    if(A.SubString(1,1) == "M") //?
    {
        A.Delete(1,1);         //?
        Memo1->Lines->Add(A);  //?

    }
    else if(A.SubString(1,1)=="S") //?
    {
        Form3->Memo1->Clear(); //�� 3��  �޸� 1�� �����ϰ� �����.
        ShowMessage ("Message");   // ��޼����� �޼��� ��� ���.
        Form3->Show();             // �� 3 �����.
        A.Delete(1,1);             //?
        Form3->Memo1->Lines->Add(A);  //?

    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    char SendDate[100]; //100���ڼ��� ���� �ִ�.
    memset(SendDate,0x00,100);  //�̻��� ���ڵ��� �ʱ�ȭ
          if(!Radio1->Checked && !Radio2->Checked) // !->NOT , Radio1,Radio2�� üũ �����ʾ�����
          {
                ShowMessage("ä���� �������ּ��� ^_^");   //"ä���� �������ּ���" �����
                Edit1->Clear(); //Edit1���ִ� ���ڸ� �����ش�.
          }
          else if(Radio2->Checked)
          {
                ShowMessage("����� �����ڰ� �����ϴ� ");//"����� �����ڰ� ����"��� ���
                Edit1->Clear();  //Edit1���մ� ���ڸ� �����ش�.
          }
          else
          {
                Memo1->Lines->Add(Edit2->Text+":"+Edit1->Text);// Edit1,Edit2���� ���ڰ�  Memo1�� �߰��ȴ�.,Lines Add->�߰� �ҽ�

                Edit2->Text = Edit2->Text.Insert("M",1); // Edit2 �� ���մ� ���ڸ� ......
                Edit1->Text = Edit2->Text+":"+Edit1->Text; // Edit1��  Edit2 �ؽ�Ʈ�� �־�
                Edit2->Text = Edit2->Text.Delete(1,1);  //  ?

                memcpy(SendDate,Edit1->Text.c_str(),strlen(Edit1->Text.c_str()));//?
                ServerSocket1->Socket->Connections[ListBox1->ItemIndex]->SendBuf(SendDate,100);  //ListBox��  ����� Ip�ּҰ� �����µ� �� ��������� 0,1 �̼����� �ȴ�.!->-1 ������ ���Ѵ�.
                Edit1->Clear(); //Edit1->�� �մ� ���ڵ��� ��������.
          }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    ShowMessage("Ŭ���̾�Ʈ�� ����Ǿ����ϴ�");  //Ŭ���̾�Ʈ�� ����Ǿ��ٰ��� ���
    ListBox1->Items->Add(Socket->RemoteAddress);//Remote Address->?���� IP�ּ� EX)127.0.0.1

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if(Key==0xd)
      {
        if(ServerSocket1->Socket->Connected)  //���� ServerSocket1�� ������� �ʾ�����



        {
                char SendDate[100];   //�������ִ� ���ڼ� 100�����̴�.
                memset(SendDate,0x00,100);   //?
                Memo1->Lines->Add(Edit2->Text+":"+Edit1->Text); //�޸���ȿ� Edit2 �� ������ �ؽ�Ʈ�� Edit1�� ������ �ؽ�Ʈ�� ������ �޸����� ������.

                Edit2->Text = Edit2->Text.Insert("M",1); //?
                Edit1->Text = Edit2->Text+":"+Edit1->Text; //Edit1 �� Edit2 �� ������ �ؽ�Ʈ�� Edit1��  ������ �ؽ�Ʈ�� ������.
                Edit2->Text = Edit2->Text.Delete(1,1);  //?

                memcpy(SendDate,Edit1->Text.c_str(),strlen(Edit1->Text.c_str()));//?
                ServerSocket1->Socket->Connections[0]->SendText(SendDate);  //?
                Edit1->Clear();  // Edit1 �� Ŭ������.
        }
      }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
        Form2->Timer1->Enabled = false;  //Form2 Ÿ�̸Ӱ� �� �������� ������
        Form2->Timer1->Interval = 0;    //Form2 Ÿ�̸Ӱ� ?
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
        TreeView1->Items->Add(TreeView1->Selected,Edit3->Text);//Treeview1�� N1�� Ŭ���ɶ� Edit3�� ���ִ� �ؽ�Ʈ���Բ� �߰��ȴ�.
        TTreeNode *MyTreeNode1 = TreeView1->Items->Item[0]; //?
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    TreeView1->Items->Delete(TreeView1->Selected);   //Treeview���� N2�� Ŭ���ɶ� Ʈ����1���ִ� Ŭ���Ȱ��� �����ȴ�.
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    Form2->Close();    //Form2�� �ݴ´�.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Click(TObject *Sender)
{
    Edit3->Text="";     //Edit3�� Text�� ���.
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    if(ErrorCode == 10055 || ErrorCode == 10051 || ErrorCode == 10056 || ErrorCode == 10061)
        {
                 ErrorCode = 0 ;
                 ShowMessage("��� ������ Ȯ�����ּ���");  //�������ڵ尡 �㋚ ����������ش޶�� ���. �׷��鼭 Errocode�� 0���� ���ش�.
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
          StatusBar1->Panels->Items[1]->Text =Date();  //StatusBar1 ������ 1�� Date �� ��¥���Ѵ�.
          StatusBar1->Panels->Items[2]->Text =Time();  //StatusBar1 ������ 2�� Time ���� �Ѵ�.
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Form4->Memo1->Clear();   //Form4 �޸� �Ʋ������ش�.
    Form4->Show();          //Form4�� �����ش�.
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{

        AnsiString a = "http://search.naver.com/search.naver?where=nexearch&query="+Edit4->Text+"&frm=t1";
        ShellExecute(NULL,"open",a.c_str(),NULL,NULL,SW_SHOWNORMAL);    //?



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Click(TObject *Sender)
{
        Edit4->Text = "";     //Edit2��  Text�� �����ִ�.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Click(TObject *Sender)
{
        Edit2->Text = "";    //Edit2�� Text�� �����ִ�.
}
//---------------------------------------------------------------------------

