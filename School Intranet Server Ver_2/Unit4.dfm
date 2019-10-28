object Form4: TForm4
  Left = 986
  Top = 156
  BorderStyle = bsDialog
  Caption = 'School Intranet Message'
  ClientHeight = 327
  ClientWidth = 360
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
    Height = 273
    ImeName = 'Microsoft Office IME 2007'
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 8
    Top = 288
    Width = 145
    Height = 25
    Caption = 'Send To Message'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 208
    Top = 288
    Width = 131
    Height = 25
    Caption = 'Retry Write the Message'
    TabOrder = 2
    OnClick = Button2Click
  end
end
