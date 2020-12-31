object Form1: TForm1
  Left = 160
  Top = 245
  Width = 794
  Height = 490
  Caption = 's'
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Trebuchet MS'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 24
  object Label1: TLabel
    Left = 16
    Top = 56
    Width = 33
    Height = 24
    Caption = 'SNP'
  end
  object Label2: TLabel
    Left = 16
    Top = 96
    Width = 124
    Height = 24
    Caption = 'Year of Birdth:'
  end
  object Edit3: TLabel
    Left = 16
    Top = 136
    Width = 128
    Height = 24
    Caption = 'Group number:'
  end
  object Label3: TLabel
    Left = 8
    Top = 8
    Width = 66
    Height = 24
    Caption = 'Grades:'
  end
  object Memo1: TMemo
    Left = 288
    Top = 8
    Width = 473
    Height = 393
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object SNP: TEdit
    Left = 64
    Top = 48
    Width = 201
    Height = 32
    TabOrder = 1
    Text = 'Surname_N_P'
  end
  object yearOfBirdth: TEdit
    Left = 144
    Top = 88
    Width = 57
    Height = 32
    TabOrder = 2
    Text = '1995'
  end
  object groupNumber: TEdit
    Left = 160
    Top = 128
    Width = 33
    Height = 32
    TabOrder = 3
    Text = '3'
  end
  object chemistry: TEdit
    Left = 216
    Top = 8
    Width = 33
    Height = 32
    TabOrder = 4
    Text = '9'
  end
  object physics: TEdit
    Left = 88
    Top = 8
    Width = 33
    Height = 32
    TabOrder = 5
    Text = '9'
  end
  object CS: TEdit
    Left = 168
    Top = 8
    Width = 33
    Height = 32
    TabOrder = 6
    Text = '9'
  end
  object math: TEdit
    Left = 128
    Top = 8
    Width = 33
    Height = 32
    TabOrder = 7
    Text = '9'
  end
  object createFile: TButton
    Left = 288
    Top = 408
    Width = 233
    Height = 33
    Caption = 'Create file'
    TabOrder = 8
    OnClick = createFileClick
  end
  object openFile: TButton
    Left = 544
    Top = 408
    Width = 217
    Height = 33
    Caption = 'Open File'
    TabOrder = 9
    OnClick = openFileClick
  end
  object add: TButton
    Left = 16
    Top = 176
    Width = 249
    Height = 33
    Caption = 'add Element'
    TabOrder = 10
    OnClick = addClick
  end
  object showExellentStudents: TButton
    Left = 16
    Top = 408
    Width = 249
    Height = 33
    Caption = 'show Exellent Students'
    TabOrder = 11
    OnClick = showExellentStudentsClick
  end
  object editData: TButton
    Left = 16
    Top = 368
    Width = 201
    Height = 33
    Caption = 'Edit element'
    TabOrder = 12
    OnClick = editDataClick
  end
  object Edit1: TEdit
    Left = 232
    Top = 368
    Width = 33
    Height = 32
    TabOrder = 13
    Text = '0'
  end
  object OpenDialog1: TOpenDialog
    Filter = 'text files|*.txt|all files|*.*'
    Left = 240
    Top = 128
  end
  object SaveDialog1: TSaveDialog
    Filter = 'text files|*.txt|all files|*.*'
    Left = 240
    Top = 96
  end
end
