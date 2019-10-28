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
    Memo1->Clear();   //Memo1이 깨끗해진다.

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //데이터 받는 부분
    char Buff[100];      //보낼수있는 최대글자수는 100글자
    memset(Buff,0x00,100);     //?
    ClientSocket1->Socket->ReceiveBuf(Buff,100); //Client Sokcet이 받을 수있는 최대 글자수는 100글자
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
        Form3->Memo1->Clear();     //Form3에 Memo1은 깨끗해진다.
        ShowMessage("Message");     //ShowMessage로 Message라고  뜬다.

        Form3->Show();           //Form3가 보여진다.
        A.Delete(1,1);
        Form3->Memo1->Lines->Add(A);
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     OpenDialog1->Execute();       // OpenDialog 1 ?
     Memo2->Lines->LoadFromFile(OpenDialog1->FileName); // Memo2에 OpenDilog1이 FileName 을 불러온다.

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if(Key==0xd)
    {
        if(!ClientSocket1->Socket->Connected) //  ClientSocket이 연결되지 않았을때
        {
            ShowMessage("서버와 연결되어있지않습니다"); //ShowMessage로 서버와연결되어있지 않습니다 라고뜬다.
        }
        else
        {
           char SendDate[100];  //최대보낼수있는 글자수가 100글자수이다.
            memset(SendDate,0x00,100);           //?
            Memo1->Lines->Add(Edit3->Text+":"+Edit1->Text);  // Memo1 에 Edit3 에써잇는 Text와 Edit1의 텍스트가 Memo1에 쓰인다.

            Edit3->Text = Edit3->Text.Insert("M",1);
            Edit1->Text = Edit3->Text+":"+Edit1->Text; //Edit1 Text는 Edit3에 써있는 Text 와 Edit1 에 써있는 Text 가 써진다.
            Edit3->Text = Edit3->Text.Delete(1,1); //  ?

            memcpy(SendDate,Edit1->Text.c_str(),strlen(Edit1->Text.c_str()));//?
            ClientSocket1->Socket->SendBuf(SendDate,100);  //ClientSocket1 은 최대 100글자 만 보낼수있다.
            Edit1->Clear();  //Edit1은 깨끗해지다.
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
    ShowMessage("서버가 닫혀있습니다");
    }
    if(ErrorCode==10053){
    ErrorCode=0;
    ShowMessage("클라이언트에 오류가 있습니다.");
    }
    ClientSocket1->Active = false;
    //211.245.19.102
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    if(RadioButton1->Checked == true)  // RadioButton1이 Check 되었을떄 작동이한다. (▲)
        {
            ClientSocket1->Active = true;      //ClientSocket1이 작동한다.
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
    if(RadioButton2->Checked == true)  //RadioButton1이 Check 되었을떄 작동이한다
        {
            ClientSocket1->Active = false;      //ClientSocket이 작동하지 않는다
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
          StatusBar1->Panels->Items[1]->Text =Date();  //StarusBar Item1은 날짜를 한다
          StatusBar1->Panels->Items[2]->Text =Time();  //StatusBar Item2는 시간을한다
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        SaveDialog1->Execute();  //SaveDialog을 실행한다.
         // Memo2->Lines->LoadFromFile(OpenDialog1->FileName);
         Memo2->Lines->SaveToFile(SaveDialog1->FileName+".txt"); //Memo2 SaveDialog을 통해 FileName txt파일로 저장된다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    Form4->Memo1->Clear();   // Form4 Memo1이 깨끗해지다.
    Form4->Show();     //Form4가 뜬다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        Form2->Close();  //Form2 가 꺼진다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
        TreeView1->Items->Delete(TreeView1->Selected);//Treeview1에  N1을 클릭했을때
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
    Form2->Timer1->Enabled = false ;   // Form2 Timer1 은 작동하지 않는다.
    Form2->Timer1->Interval= 0;   //?
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    ShowMessage("서버와 연결되었습니다"); //ShowMessage로 서버와 연결되었습니다 라고 창이뜬다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        AnsiString a = "http://search.naver.com/search.naver?where=nexearch&query="+Edit4->Text+"&frm=t1";  //Naver 와 연결 한다. (Ansistring ?)
        ShellExecute(NULL,"open",a.c_str(),NULL,NULL,SW_SHOWNORMAL);    //?
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit5KeyPress(TObject *Sender, char &Key)
{
    if (Key == 0xd)   //?
    {
        ClientSocket1->Address = Edit5->Text; //ClientSocket1 의  주소가 Edit5 텍스트에 친다.
        //Form3->NMUDP1->RemoteHost = Edit5->Text;
       ClientSocket1->Active = true;   //ClientSocket 이 활동을 한다.
        ShowMessage("Server IP 변경 되었습니다.");       //ShowMessage 로 Server Ip 가 변경되었다 라고 창이 뜬다.
    }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Click(TObject *Sender)
{
        Edit1->Text = "";      //Edit1 에 텍스트가 써지게한다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Click(TObject *Sender)
{
        Edit4->Text = "";   //Edit4  에 텍스트가 써지게한다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Click(TObject *Sender)
{
        Edit3->Text = "";    //Edit3에 텍스트가 써지게한다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Click(TObject *Sender)
{
        Edit2->Text = "";     //Edit2에 텍스탁 써지게한다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView1Click(TObject *Sender)
{
        Edit3->Text=TreeView1->Selected->Text;   /// ?
}
//---------------------------------------------------------------------------

