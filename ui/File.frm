VERSION 5.00
Begin VB.Form FileMake 
   BackColor       =   &H00000000&
   Caption         =   "FD�t�@�C�������E�g��"
   ClientHeight    =   1560
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5550
   Icon            =   "File.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   1560
   ScaleWidth      =   5550
   StartUpPosition =   3  'Windows �̊���l
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   270
      TabIndex        =   4
      Top             =   150
      Width           =   5145
   End
   Begin VB.CommandButton Command2 
      Caption         =   "�L�����Z��"
      Height          =   315
      Left            =   4050
      TabIndex        =   3
      Top             =   900
      Width           =   1365
   End
   Begin VB.CommandButton Command1 
      Caption         =   "�n�j"
      Height          =   315
      Left            =   2700
      TabIndex        =   2
      Top             =   900
      Width           =   1230
   End
   Begin VB.OptionButton Option1 
      Caption         =   "̧�ّg��"
      Height          =   180
      Index           =   1
      Left            =   270
      TabIndex        =   1
      Top             =   1050
      Width           =   2040
   End
   Begin VB.OptionButton Option1 
      Caption         =   "̧�ٕ���"
      Height          =   180
      Index           =   0
      Left            =   270
      TabIndex        =   0
      Top             =   750
      Width           =   2040
   End
End
Attribute VB_Name = "FileMake"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
    Dim RET             As Long
    Dim REC             As String
    Dim FILE            As String
    Dim E_FILE          As String
    Dim Cnt             As Integer

Private Sub Command1_Click()
    If Option1(0).Value = True Then
        REC = "C"
    Else
        REC = "M"
    End If
    E_FILE = Text1.Text
    For Cnt = 1 To 256
        If Mid(E_FILE, Cnt, 1) = "\" Then
            FILE = FILE & "\"
        End If
    FILE = FILE & Mid(E_FILE, Cnt, 1)
    Next Cnt
    RET = FD_File_Cntl(REC, FILE)
    If RET = -1 Then
        MsgBox ("̧�ٖ��𐳂����w�肵�Ă�������")
    Else
        MsgBox ("����")
    End If
End Sub

Private Sub Command2_Click()
    End
End Sub



