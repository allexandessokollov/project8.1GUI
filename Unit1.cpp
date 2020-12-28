//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

const int ARR_SIZE = 4;
const int MAX_NAME_SIZE = 128;
const int STUDENT_ARRAY_SIZE = 128;

struct student
{
    char name[MAX_NAME_SIZE];
    int yearOfBirdth;
    int group;
    int grades[ARR_SIZE]; // 0 - physics, 1 - math, 2 - Comp Sience, 3 - chemistry
    double avgGrade;
};

FILE *myFile;
AnsiString fileName;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    Memo1->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::createFileClick(TObject *Sender)
{
   OpenDialog1->Title="Create new file";

    if(OpenDialog1->Execute())
    {

        fileName = OpenDialog1->FileName;
        if ((myFile = fopen(fileName.c_str(), "w")) == NULL)
        {
                ShowMessage("\nCannot create file.\n");
                return;
        }
    }
    
    Memo1->Lines->Add("file " + AnsiString(fileName) + " created!");

    fclose(myFile);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::openFileClick(TObject *Sender)
{
    OpenDialog1->Title = "Open file";
    student st;

    if(OpenDialog1->Execute())
    {
        fileName = OpenDialog1->FileName;
        if((myFile = fopen(fileName.c_str(), "r")) == NULL)
        {
            ShowMessage("Cannot open file");
            return;
        }

        Memo1->Lines->Add("--------all data--------");
        while((fscanf(myFile, "%s %d %d %d %d %d %d %lf\n", &st.name,
             &st.yearOfBirdth, &st.group,
             &st.grades[0], &st.grades[1], &st.grades[2],
             &st.grades[3], &st.avgGrade))!= EOF)
        {


           Memo1->Lines->Add(AnsiString(st.name) + "    " + FloatToStr(st.avgGrade));
        }

    }

     fclose(myFile);
}
//---------------------------------------------------------------------------


float TForm1::avgGrade(int arr[])
{
    double temp = 0;

    for(int i = 0; i < ARR_SIZE; i++)
    {
        temp += arr[i];
    }

    return temp / ARR_SIZE;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::addClick(TObject *Sender)
{
    student temp;

    if ((myFile = fopen(fileName.c_str(), "a+")) == NULL)
    {
        ShowMessage("\nERROR\n");
    }
    else if(checkEdits() == false)
    {
    }
    else
    {
        AnsiString tempr =  SNP->Text;
        strcpy(temp.name, tempr.c_str());
        temp.yearOfBirdth = StrToInt(yearOfBirdth->Text);
        temp.group = StrToInt(groupNumber->Text);
        temp.grades[0] = StrToInt(physics->Text);
        temp.grades[1] = StrToInt(math->Text);
        temp.grades[2] = StrToInt(CS->Text);
        temp.grades[3] = StrToInt(chemistry->Text);
        temp.avgGrade = avgGrade(temp.grades);

        Memo1->Lines->Add("----ELEMENT ADDED----\n");
        Memo1->Lines->Add(AnsiString(temp.name) + "    " + FloatToStr(temp.avgGrade));

        fprintf(myFile, "%s %d %d %d %d %d %d %f\n", temp.name, temp.yearOfBirdth,
                 temp.group, temp.grades[0], temp.grades[1],
                 temp.grades[2], temp.grades[3], temp.avgGrade);
    }

    fclose(myFile);
}
//---------------------------------------------------------------------------


bool TForm1::checkEdits()
{
    bool ret = true;

    if(SNP->Text == "")
    {
        ShowMessage("fill SNP");
        ret = false;
    }
    else if(yearOfBirdth->Text == "")
    {
        ShowMessage("fill year Of Birdth");
        ret = false;
    }
    else if(groupNumber->Text == "")
    {
        ShowMessage("fill group Number");
        ret = false;
    }
    else if(physics->Text == "")
    {
         ShowMessage("fill physics");
         ret = false;
    }
    else if(math->Text == "")
    {
         ShowMessage("fill math");
         ret = false;
    }
    else if(CS->Text == "")
    {
         ShowMessage("fill CS");
         ret = false;
    }
    else if(chemistry->Text == "")
    {
         ShowMessage("fill chemistry");
         ret = false;
    }

    return ret;
}
void __fastcall TForm1::showExellentStudentsClick(TObject *Sender)
{
        student st;
        student stArr[STUDENT_ARRAY_SIZE];
        
        fileName = OpenDialog1->FileName;
        if((myFile = fopen(fileName.c_str(), "r+")) == NULL)
        {
            ShowMessage("Cannot open file");
            return;
        }
        int counter = 0;

        Memo1->Lines->Add("--------Exellent Students--------\n");
        while((fscanf(myFile, "%s %d %d %d %d %d %d %lf\n", &st.name,
             &st.yearOfBirdth, &st.group,
             &st.grades[0], &st.grades[1], &st.grades[2],
             &st.grades[3], &st.avgGrade))!= EOF)
        {

           if(st.avgGrade == 8 || st.avgGrade == 9 || st.avgGrade == 10)
           {
               stArr[counter++] = st;
               Memo1->Lines->Add(AnsiString(st.name) + "    " + FloatToStr(st.avgGrade));

           }
        }

    fclose(myFile);

    if ((myFile = fopen(fileName.c_str(), "a+")) == NULL){
    }
    else
    {
         fprintf(myFile, "\n------Exellent students----------\n");
         for(int j = 0; j < counter; j++)
         {
             fprintf(myFile, "\n%s %d %d %d %d %d %d %lf\n", stArr[j].name, stArr[j].yearOfBirdth,
             stArr[j].group, stArr[j].grades[0], stArr[j].grades[1], stArr[j].grades[2],
             stArr[j].grades[3], stArr[j].avgGrade);
         }
    }

    fclose(myFile);
}
//---------------------------------------------------------------------------
/*if ((myFile = fopen(fileName.c_str(), "a+")) == NULL){
               }
               else
               {
                 fprintf(myFile, "\n------Exellent students----------\n");
                 printf("\n%s %d %d %d %d %d %d %lf\n", st.name, st.yearOfBirdth, st.group,
                 st.grades[0], st.grades[1], st.grades[2], st.grades[3], st.avgGrade);
               }
               */