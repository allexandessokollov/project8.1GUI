//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TLabel *Label1;
        TEdit *SNP;
        TLabel *Label2;
        TEdit *yearOfBirdth;
        TLabel *Edit3;
        TEdit *groupNumber;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *chemistry;
        TEdit *physics;
        TEdit *CS;
        TEdit *math;
        TOpenDialog *OpenDialog1;
        TButton *createFile;
        TSaveDialog *SaveDialog1;
        TButton *openFile;
        TButton *add;
        TButton *showExellentStudents;
        TButton *editData;
        TEdit *Edit1;
        void __fastcall createFileClick(TObject *Sender);
        void __fastcall openFileClick(TObject *Sender);
        void __fastcall addClick(TObject *Sender);
        void __fastcall showExellentStudentsClick(TObject *Sender);
        void __fastcall editDataClick(TObject *Sender);
private:
        float avgGrade(int arr[]);
        bool checkEdits();	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
