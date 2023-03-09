#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#define stopper 50

void ReverseArray(int testData2[], int start, int end)
{
  int temp;
    while (start < end)
    {
        temp = testData2[start];
        testData2[start] = testData2[end];
        testData2[end] = temp;
        start++;
        end--;
    }
}
void Merge(int testData1[], int testData2[], int ResultData[], int length1, int length2, int length3)
{
    printf("\nMerged\n");
    for(int i = 0; i<length1; i++)
    {
        ResultData[i] = testData1[i];
    }
    for(int i = 0; i<length2; i++)
    {
        ResultData[i+length1] = testData2[i];
    }
    for(int i = 0; i<length3; i++)
    {
        printf("%d ", ResultData[i]);
    }

}
void DrawLine(int XLine, int YLine, int heightLine, int lineColor)
{
  setcolor(lineColor);
  line(XLine, YLine, XLine, YLine - heightLine);
}
void DrawTomographyLine(int x1, int y1, int x2,int y2)
{
    line(x1,y1,x2,y2);
}
void DrawPlate(int ResultData[], int length3)
{

    int max = ResultData[0];
    int min = ResultData[0];
    for(int i = 0; i<length3; i++)
    {
        if(ResultData[i]>max)
        {
            max = ResultData[i];
        }
    }
    for(int i = 0; i<length3; i++)
    {
        if(ResultData[i]<min)
        {
            min = ResultData[i];
        }
    }
    setcolor(BLACK);
    line(100,300,900,300);
    line(100,300,100,min);
    setcolor(WHITE);
    outtextxy(90,301,"0");
    outtextxy(95,min,"1");
    outtextxy(900, 301, "256");
}
void DrawDefault(int length3, int ResultData[])
{
    for(int i=0; i<length3; i++)
    {
        DrawLine(100+1*i,300, ResultData[i],2);
    }
}
int MathColorLine(int height){
  /*
  BLACK	0
BLUE	1
GREEN	2
CYAN	3
RED	4
MAGENTA	5
BROWN	6
LIGHTGRAY	7
DARKGRAY	8
LIGHTBLUE	9
LIGHTGREEN	10
LIGHTCYAN	11
LIGHTRED	12
LIGHTMAGENTA	13
YELLOW	14
WHITE	15

  */

  int finalColor = 0;

  if (height ==0){
    finalColor = 9;
  }
   else if (height < 15){
    finalColor = 1;
  }
  else if (height < 20 * 2){
    finalColor = 7;
  }
  else if (height < 35 * 3){
    finalColor = 14;
  }
  else if (height < 35 * 4){
    finalColor = 6;
  }
  else if (height < 35 * 5){
    finalColor = 12;
  }
  else if (height < 35 * 6){
    finalColor = 4;
  }
  else if (height > 35 * 6){
    finalColor = 15;
  }

  return finalColor;
}
void TomographyStatic(int ResultData[], int length3){
  for(int i = 0; i < length3; i++){
    int fColor = MathColorLine(ResultData[i]);
    setcolor(WHITE);
    outtextxy(50,400,"Profil1");
    DrawLine(100 + i, 500, 50, fColor);
  }
}
void TomographyDynamic(int ResultData[], int length3)
{
  for(int i = 0; i < length3; i++)
 {
    int fColor = MathColorLine(ResultData[i]/2);
    setcolor(WHITE);
    outtextxy(50,570,"Profil2");
    setcolor(fColor);
    DrawLine(100 + i, 650, 50, fColor);
    delay(stopper);
 }
}
int main()
{
  initwindow(1000,1000);
  int testData1[100] = {};
  int testData2[100]  ={};
  int ResultData[200]= {};
  int length1 = sizeof testData1/ sizeof testData1[0];
  int length2 = sizeof testData2/ sizeof testData2[0];
  int length3 = sizeof ResultData/ sizeof ResultData[0];
  for(int i = 0; i < length1; i++)
  {
    testData1[i] = rand()%256;
  }
  for(int i = 0 ; i<length1; i++)
  {
    for(int j =0; j<length1-1; j++)
    {
      if(testData1[j]>testData1[i])
      {
        int temp = testData1[j];
        testData1[j]=testData1[i];
        testData1[i] = temp;
      }
    }
  }
  printf("\nSorted First\n");
    for(int i = 0; i< length1; i++)
  {
    printf("%d ", testData1[i]);
  }
  for(int i = 0 ; i < length1; i++)
  {
    testData2[i] = testData1[i];
  }
  printf("\n");
  ReverseArray(testData2,0,length2-1);
  for(int i = 0 ; i<length2; i++)
  {
    for(int j =0; j<length2-1; j++)
    {
      if(testData2[j]>testData2[i])
      {
        int temp = testData2[j];
        testData2[j]=testData2[i];
        testData2[i] = temp;
      }
    }
  }
  ReverseArray(testData2, 0, length2-1);
  printf("\nReversed + sorted Second Array\n");
  for(int i = 0; i<length2; i++)
  {
    printf("%d ", testData2[i]);
  }
  Merge(testData1, testData2, ResultData, length1, length2, length3);
  bar(0, 0, 1000, 350);
  DrawPlate(ResultData,length3);
  DrawDefault(length3, ResultData);
  TomographyStatic(ResultData, length3);
  for(int x = 200; x<=700; x =x+10)
  {
       bar(0, 0, 1000, 350);
       DrawPlate(ResultData,length3);
       DrawDefault(length3, ResultData);
       for(int i =0; i<length3; i++)
      {
          DrawLine(x+1*i,300,ResultData[i]/2,2);
          continue;
      }

  }
  TomographyDynamic(ResultData,length3);
  getch();
  closegraph();
  }





