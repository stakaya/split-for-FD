Attribute VB_Name = "filecntl"
Option Explicit

Public Declare Function FD_File_Cntl Lib "FD_FILE32" _
(ByVal a As String, ByVal b As String) As Long

Sub main()
    FileMake.Show
End Sub

