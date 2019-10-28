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
    Memo1->Clear(); //Memo1 에 있는 텍스트를 없애준다.
    Edit1->Clear(); //Edit1 에 있는 텍스틀  없애준다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    char Buff[100]; // 받기위한 소스, 100글자수
    memset(Buff,0x00,100); //정확하게 모르겟다 (초기화)
    ServerSocket1->Socket->Connections[ListBox1->ItemIndex]->ReceiveBuf(Buff,100);//ServerSocket1 이 연결을하는 들어오는 ip를 순서대로 0,1로 표현한다. ListBox1에 넣는다 Item Index? 가 머지  받는 글자를 100글자이내로 받을수잇다.
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
        Form3->Memo1->Clear(); //폼 3에  메모 1을 깨끗하게 지운다.
        ShowMessage ("Message");   // 쇼메세지로 메세지 라고 뜬다.
        Form3->Show();             // 폼 3 가뜬다.
        A.Delete(1,1);             //?
        Form3->Memo1->Lines->Add(A);  //?

    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    char SendDate[100]; //100글자수를 쓸수 있다.
    memset(SendDate,0x00,100);  //이상한 문자들이 초기화
          if(!Radio1->Checked && !Radio2->Checked) // !->NOT , Radio1,Radio2가 체크 되지않았을때
          {
                ShowMessage("채팅을 선택해주세요 ^_^");   //"채팅을 선택해주세요" 가뜬다
                Edit1->Clear(); //Edit1에있는 글자를 없애준다.
          }
          else if(Radio2->Checked)
          {
                ShowMessage("연결된 접속자가 없습니다 ");//"연결된 접속자가 없다"라고 뜬다
                Edit1->Clear();  //Edit1에잇는 글자를 없애준다.
          }
          else
          {
                Memo1->Lines->Add(Edit2->Text+":"+Edit1->Text);// Edit1,Edit2에쓴 문자가  Memo1에 추가된다.,Lines Add->추가 소스

                Edit2->Text = Edit2->Text.Insert("M",1); // Edit2 에 써잇는 글자를 ......
                Edit1->Text = Edit2->Text+":"+Edit1->Text; // Edit1에  Edit2 텍스트를 넣어
                Edit2->Text = Edit2->Text.Delete(1,1);  //  ?

                memcpy(SendDate,Edit1->Text.c_str(),strlen(Edit1->Text.c_str()));//?
                ServerSocket1->Socket->Connections[ListBox1->ItemIndex]->SendBuf(SendDate,100);  //ListBox에  사람이 Ip주소가 들어오는데 그 사람수마다 0,1 이순서로 된다.!->-1 정수로 변한다.
                Edit1->Clear(); //Edit1->에 잇던 글자들이 없어진다.
          }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    ShowMessage("클라이언트와 연결되었습니다");  //클라이언트와 연결되엇다고라고 뜬다
    ListBox1->Items->Add(Socket->RemoteAddress);//Remote Address->?상대방 IP주소 EX)127.0.0.1

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if(Key==0xd)
      {
        if(ServerSocket1->Socket->Connected)  //만약 ServerSocket1이 연결되지 않았을떄



        {
                char SendDate[100];   //보낼수있는 글자수 100글자이다.
                memset(SendDate,0x00,100);   //?
                Memo1->Lines->Add(Edit2->Text+":"+Edit1->Text); //메모장안에 Edit2 에 쓰여진 텍스트와 Edit1에 쓰여진 텍스트가 합쳐져 메모라인즈에 써진다.

                Edit2->Text = Edit2->Text.Insert("M",1); //?
                Edit1->Text = Edit2->Text+":"+Edit1->Text; //Edit1 에 Edit2 의 쓰여진 텍스트와 Edit1에  쓰여진 텍스트가 써진다.
                Edit2->Text = Edit2->Text.Delete(1,1);  //?

                memcpy(SendDate,Edit1->Text.c_str(),strlen(Edit1->Text.c_str()));//?
                ServerSocket1->Socket->Connections[0]->SendText(SendDate);  //?
                Edit1->Clear();  // Edit1 이 클리어댄다.
        }
      }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
        Form2->Timer1->Enabled = false;  //Form2 타이머가 가 동작하지 않을때
        Form2->Timer1->Interval = 0;    //Form2 타이머가 ?
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
        TreeView1->Items->Add(TreeView1->Selected,Edit3->Text);//Treeview1에 N1이 클릭될때 Edit3에 써있는 텍스트와함께 추가된다.
        TTreeNode *MyTreeNode1 = TreeView1->Items->Item[0]; //?
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    TreeView1->Items->Delete(TreeView1->Selected);   //Treeview에서 N2가 클릭될때 트리뷰1에있는 클릭된것이 삭제된다.
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    Form2->Close();    //Form2를 닫는다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Click(TObject *Sender)
{
    Edit3->Text="";     //Edit3에 Text가 뜬다.
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    if(ErrorCode == 10055 || ErrorCode == 10051 || ErrorCode == 10056 || ErrorCode == 10061)
        {
                 ErrorCode = 0 ;
                 ShowMessage("통신 설정을 확인해주세요");  //위에러코드가 뜰떄 통신을설정해달라고 뜬다. 그러면서 Errocode를 0으로 해준다.
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
          StatusBar1->Panels->Items[1]->Text =Date();  //StatusBar1 아이템 1을 Date 즉 날짜로한다.
          StatusBar1->Panels->Items[2]->Text =Time();  //StatusBar1 아이템 2를 Time 으로 한다.
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Form4->Memo1->Clear();   //Form4 메모를 꺠끗이해준다.
    Form4->Show();          //Form4를 보여준다.
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
        Edit4->Text = "";     //Edit2에  Text를 쓸수있다.
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Click(TObject *Sender)
{
        Edit2->Text = "";    //Edit2에 Text를 쓸수있다.
}
//---------------------------------------------------------------------------

