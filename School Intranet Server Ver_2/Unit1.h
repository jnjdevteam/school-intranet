//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox4;
    TGroupBox *IP;
    TGroupBox *GroupBox3;
    TGroupBox *GroupBox2;
    TGroupBox *GroupBox1;
    TMemo *Memo1;
    TEdit *Edit1;
    TButton *Button1;
    TListBox *ListBox1;
    TRadioButton *Radio1;
    TRadioButton *Radio2;
    TEdit *Edit2;
    TButton *Button2;
    TEdit *Edit3;
    TButton *Button3;
    TStatusBar *StatusBar1;
    TTreeView *TreeView1;
    TServerSocket *ServerSocket1;
    TImageList *ImageList1;
    TPopupMenu *PopupMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TTimer *Timer1;
    TImageList *ImageList2;
        TGroupBox *GroupBox5;
        TButton *Button4;
        TEdit *Edit4;
    void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Edit3Click(TObject *Sender);
    void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Edit4Click(TObject *Sender);
        void __fastcall Edit2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
