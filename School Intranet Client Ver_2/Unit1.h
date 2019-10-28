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
    TGroupBox *GroupBox7;
    TGroupBox *GroupBox6;
    TGroupBox *GroupBox1;
    TMemo *Memo1;
    TEdit *Edit1;
    TGroupBox *GroupBox2;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TMemo *Memo2;
    TTreeView *TreeView1;
    TGroupBox *GroupBox3;
    TEdit *Edit2;
    TGroupBox *GroupBox4;
    TGroupBox *GroupBox5;
    TButton *Button1;
    TStatusBar *StatusBar1;
    TButton *Button4;
    TButton *Button5;
    TClientSocket *ClientSocket1;
    TPopupMenu *PopupMenu1;
    TMenuItem *Y1;
    TMenuItem *N1;
    TImageList *ImageList1;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    TTimer *Timer1;
        TEdit *Edit3;
        TGroupBox *GroupBox8;
        TEdit *Edit4;
        TButton *Button2;
    TGroupBox *GroupBox10;
    TEdit *Edit5;
    void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
    void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall RadioButton1Click(TObject *Sender);
    void __fastcall RadioButton2Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall Y1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall Button2Click(TObject *Sender);
    void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit1Click(TObject *Sender);
        void __fastcall Edit4Click(TObject *Sender);
        void __fastcall Edit3Click(TObject *Sender);
        void __fastcall Edit2Click(TObject *Sender);
        void __fastcall TreeView1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
