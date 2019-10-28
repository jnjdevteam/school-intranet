//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Memo1->Clear();   //Memo1�� ����������.

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //������ �޴� �κ�
    char Buff[100];      //�������ִ� �ִ���ڼ��� 100����
    memset(Buff,0x00,100);     //?
    ClientSocket1->Socket->ReceiveBuf(Buff,100); //Client Sokcet�� ���� ���ִ� �ִ� ���ڼ��� 100����
    //Memo1->Lines->Add(Buff);

    AnsiString A;  //?
    A  = Buff ;    //?

    if(A.SubString(1,1) == "M")  //?
    {
        A.Delete(1,1);          //?
        Memo1->Lines->Add(A);   //?

    }
    else if(A.SubString(1,1)=="S") //?
    {
        Form3->Memo1->Clear();     //Form3�� Memo1�� ����������.
        ShowMessage("Message");     //ShowMessage�� Message���  ���.

        Form3->Show();           //Form3�� ��������.
        A.Delete(1,1);
        Form3->Memo1->Lines->Add(A);
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     OpenDialog1->Execute();       // OpenDialog 1 ?
     Memo2->Lines->LoadFromFile(OpenDialog1->FileName); // Memo2�� OpenDilog1�� FileName �� �ҷ��´�.

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if(Key==0xd)
    {
        if(!ClientSocket1->Socket->Connected) //  ClientSocket�� ������� �ʾ�����
        {
            ShowMessage("������ ����Ǿ������ʽ��ϴ�"); //ShowMessage�� �����Ϳ���Ǿ����� �ʽ��ϴ� �����.
        }
        else
        {
           char SendDate[100];  //�ִ뺸�����ִ� ���ڼ��� 100���ڼ��̴�.
            memset(SendDate,0x00,100);           //?
            Memo1->Lines->Add(Edit3->Text+":"+Edit1->Text);  // Memo1 �� Edit3 �����մ� Text�� Edit1�� �ؽ�Ʈ�� Memo1�� ���δ�.

            Edit3->Text = Edit3->Text.Insert("M",1);
            Edit1->Text = Edit3->Text+":"+Edit1->Text; //Edit1 Text�� Edit3�� ���ִ� Text �� Edit1 �� ���ִ� Text �� ������.
            Edit3->Text = Edit3->Text.Delete(1,1); //  ?

            memcpy(SendDate,Edit1->Text.c_str(),strlen(Edit1->Text.c_str()));//?
            ClientSocket1->Socket->SendBuf(SendDate,100);  //ClientSocket1 �� �ִ� 100���� �� �������ִ�.
            Edit1->Clear();  //Edit1�� ����������.
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    if(ErrorCode==10061)
    {
    ErrorCode=0;
    ShowMessage("������ �����ֽ��ϴ�");
    }
    if(ErrorCode==10053){
    ErrorCode=0;
    ShowMessage("Ŭ���̾�Ʈ�� ������ �ֽ��ϴ�.");
    }
    ClientSocket1->Active = false;
    //211.245.19.102
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    if(RadioButton1->Checked == true)  // RadioButton1�� Check �Ǿ����� �۵����Ѵ�. (��)
        {
            ClientSocket1->Active = true;      //ClientSocket1�� �۵��Ѵ�.
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
    if(RadioButton2->Checked == true)  //RadioButton1�� Check �Ǿ����� �۵����Ѵ�
        {
            ClientSocket1->Active = false;      //ClientSocket�� �۵����� �ʴ´�
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
          StatusBar1->Panels->Items[1]->Text =Date();  //StarusBar Item1�� ��¥�� �Ѵ�
          StatusBar1->Panels->Items[2]->Text =Time();  //StatusBar Item2�� �ð����Ѵ�
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        SaveDialog1->Execute();  //SaveDialog�� �����Ѵ�.
         // Memo2->Lines->LoadFromFile(OpenDialog1->FileName);
         Memo2->Lines->SaveToFile(SaveDialog1->FileName+".txt"); //Memo2 SaveDialog�� ���� FileName txt���Ϸ� ����ȴ�.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    Form4->Memo1->Clear();   // Form4 Memo1�� ����������.
    Form4->Show();     //Form4�� ���.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        Form2->Close();  //Form2 �� ������.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
        TreeView1->Items->Delete(TreeView1->Selected);//Treeview1��  N1�� Ŭ��������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Y1Click(TObject *Sender)
{
             TreeView1->Items->Add(TreeView1->Selected,Edit2->Text); //?
             TTreeNode *MyTreeNode1 = TreeView1->Items->Item[0];   //?
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
    Form2->Timer1->Enabled = false ;   // Form2 Timer1 �� �۵����� �ʴ´�.
    Form2->Timer1->Interval= 0;   //?
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    ShowMessage("������ ����Ǿ����ϴ�"); //ShowMessage�� ������ ����Ǿ����ϴ� ��� â�̶��.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        AnsiString a = "http://search.naver.com/search.naver?where=nexearch&query="+Edit4->Text+"&frm=t1";  //Naver �� ���� �Ѵ�. (Ansistring ?)
        ShellExecute(NULL,"open",a.c_str(),NULL,NULL,SW_SHOWNORMAL);    //?
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit5KeyPress(TObject *Sender, char &Key)
{
    if (Key == 0xd)   //?
    {
        ClientSocket1->Address = Edit5->Text; //ClientSocket1 ��  �ּҰ� Edit5 �ؽ�Ʈ�� ģ��.
        //Form3->NMUDP1->RemoteHost = Edit5->Text;
       ClientSocket1->Active = true;   //ClientSocket �� Ȱ���� �Ѵ�.
        ShowMessage("Server IP ���� �Ǿ����ϴ�.");       //ShowMessage �� Server Ip �� ����Ǿ��� ��� â�� ���.
    }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Click(TObject *Sender)
{
        Edit1->Text = "";      //Edit1 �� �ؽ�Ʈ�� �������Ѵ�.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Click(TObject *Sender)
{
        Edit4->Text = "";   //Edit4  �� �ؽ�Ʈ�� �������Ѵ�.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Click(TObject *Sender)
{
        Edit3->Text = "";    //Edit3�� �ؽ�Ʈ�� �������Ѵ�.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Click(TObject *Sender)
{
        Edit2->Text = "";     //Edit2�� �ؽ�Ź �������Ѵ�.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView1Click(TObject *Sender)
{
        Edit3->Text=TreeView1->Selected->Text;   /// ?
}
//---------------------------------------------------------------------------

