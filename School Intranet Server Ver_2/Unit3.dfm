object Form3: TForm3
  Left = 551
  Top = 135
  BorderStyle = bsDialog
  Caption = 'School Intranet Message'
  ClientHeight = 384
  ClientWidth = 359
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 353
    Height = 329
    ImeName = 'Microsoft Office IME 2007'
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 48
    Top = 352
    Width = 265
    Height = 25
    Caption = 'To Send The Message'
    TabOrder = 1
    OnClick = Button1Click
  end
end
