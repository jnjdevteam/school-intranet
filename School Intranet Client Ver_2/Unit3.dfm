object Form3: TForm3
  Left = 681
  Top = 142
  BorderStyle = bsDialog
  Caption = 'School Intranet Message'
  ClientHeight = 242
  ClientWidth = 307
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
    Width = 305
    Height = 185
    ImeName = 'Microsoft Office IME 2007'
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 56
    Top = 200
    Width = 185
    Height = 25
    Caption = 'To Send Message'
    TabOrder = 1
    OnClick = Button1Click
  end
end
