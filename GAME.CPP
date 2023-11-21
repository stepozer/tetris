#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define n 26
#define m 18
#define load 100
FILE *f;
int Time=181;
/*===========================Глобальные переменные=========================*/
int ozki=0;
struct nonpaBka
	  {
	    int ropu3,BepT;
	    int rop2,Bep2;
	    struct nonpaBka *left,*right;
	    int mas[4][4];
	  } *New, *Hazalo,*Temp,*Right;
struct inf
	  {
	    int mas[4][4];
	    int ropu3,BepT;
	    int rop2,Bep2;
	  } zzz;
int ropu3,BepT;
int rop2,Bep2;
char KEY[9];
int Telo[n][m],x1,x2,y1,y2,d;
int FFF[4][4],F1[4][4],F2[4][4],F3[4][4],F4[4][4],SAVE[4][4];
int           F5[4][4],F6[4][4],F7[4][4],F8[4][4];
int           F9[4][4],F10[4][4],F11[4][4],F12[4][4];
int           F13[4][4],F14[4][4],F15[4][4],F16[4][4];
int           F17[4][4],F18[4][4],F19[4][4],F20[4][4];
int           F21[4][4],F22[4][4],F23[4][4],F24[4][4];
int           F25[4][4],F26[4][4],F27[4][4],F28[4][4];
int G_O;
char CcC;
/*=============================Перечень функций============================*/

// 6) Меню
      game();
      L1();
#include "modul_2.txt"
#include "modul_1.txt"
#include "modul_3.txt"
#include "modul_4.txt"
#include "modul_5.txt"
/*=======================================================*/
main()
{

  struct menu
	 {
	    int Nomer;
	    struct menu *left,*right;
	 } *L, *N,*R,*T;
  int i=1;
  N=(struct menu *)malloc(sizeof(struct menu) );
  N->Nomer=i++;
  N->left=N->right=NULL;
  L=R=N;
  while(i<5)
   {
     N=(struct menu *)malloc(sizeof(struct menu) );
     N->Nomer=i;
     N->left=NULL;
     N->right=R;

     R->left=N;
     R=N;
     i++;
   }
  R->left=L;
  L->right=R;
  int Driver,Mode;
  int nuHkt;
  Driver=VGA;
  Mode=VGAHI;
  initgraph(&Driver,&Mode,"");
  int yyy1=165;
  int yyy2=185;
  T=L;

  L1();

  faf:

  cleardevice();
  setcolor(15);
  settextstyle(8,0,5);
  outtextxy(getmaxx()/2-80,100,"TetriS");
  settextstyle(0,0,1);
  outtextxy(getmaxx()/2-50,170,"NEW GAME");
  outtextxy(getmaxx()/2-50,190,"OPTIONS");
  outtextxy(getmaxx()/2-50,210,"HELP");
  outtextxy(getmaxx()/2-50,230,"EXIT");
  while (1)
  {
    if (yyy1>165+60) {
		       setcolor(0);
		       rectangle(getmaxx()/2-80,yyy1,getmaxx()/2+80,yyy2);
		       yyy1=165;
		       yyy2=185;
		     }
    else if (yyy1<165) {

			  setcolor(0);
			  rectangle(getmaxx()/2-80,yyy1,getmaxx()/2+80,yyy2);
			  yyy1=165+60;
			  yyy2=185+60;
			}

    setcolor(15);
    rectangle(getmaxx()/2-80,yyy1,getmaxx()/2+80,yyy2);
    nuHkt=getch();
    switch(nuHkt)
    {
      case 's': T=T->left;
		setcolor(0);
		rectangle(getmaxx()/2-80,yyy1,getmaxx()/2+80,yyy2);
		setcolor(15);
		rectangle(getmaxx()/2-80,yyy1+=20,getmaxx()/2+80,yyy2+=20);
		break;
      case 'w': T=T->right;
		setcolor(0);
		rectangle(getmaxx()/2-80,yyy1,getmaxx()/2+80,yyy2);
		setcolor(15);
		rectangle(getmaxx()/2-80,yyy1-=20,getmaxx()/2+80,yyy2-=20);
		break;
      case 13:
		switch(T->Nomer)
		{
		  case 1: cleardevice();game(); goto faf;
		  case 2: OPTIONS(); goto faf;
		  case 3: HELP(); goto faf;
		  case 4: return 0;
		}
		break;
    //  case 'q': return 0;
    }
  }
  //closegraph();
  //return 0;
}



/*================================Основная прога===========================*/
game()
{
  randomize();
  int i,j;
  Xo6oTaHue(0);
   for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    Telo[i][j]=0;


  DLL("F1_4.txt");
  copy(F1,Hazalo->mas);
  copy(F2,Hazalo->left->mas);
  copy(F3,Hazalo->left->left->mas);
  copy(F4,Hazalo->left->left->left->mas);
  NotDLL();

  DLL("F5_8.txt");
  copy(F5,Hazalo->mas);
  copy(F6,Hazalo->left->mas);
  copy(F7,Hazalo->left->left->mas);
  copy(F8,Hazalo->left->left->left->mas);
  NotDLL();

  DLL("F9_12.txt");
  copy(F9,Hazalo->mas);
  copy(F10,Hazalo->left->mas);
  copy(F11,Hazalo->left->left->mas);
  copy(F12,Hazalo->left->left->left->mas);
  NotDLL();

  DLL("F13_16.txt");
  copy(F13,Hazalo->mas);
  copy(F14,Hazalo->left->mas);
  copy(F15,Hazalo->left->left->mas);
  copy(F16,Hazalo->left->left->left->mas);
  NotDLL();

  DLL("F17_20.txt");
  copy(F17,Hazalo->mas);
  copy(F18,Hazalo->left->mas);
  copy(F19,Hazalo->left->left->mas);
  copy(F20,Hazalo->left->left->left->mas);
  NotDLL();

  DLL("F21_24.txt");
  copy(F21,Hazalo->mas);
  copy(F22,Hazalo->left->mas);
  copy(F23,Hazalo->left->left->mas);
  copy(F24,Hazalo->left->left->left->mas);
  NotDLL();

  DLL("F25_28.txt");
  copy(F25,Hazalo->mas);
  copy(F26,Hazalo->left->mas);
  copy(F27,Hazalo->left->left->mas);
  copy(F28,Hazalo->left->left->left->mas);
  NotDLL();

  rpaHuLLa (Telo);
  PucoBaHue(14,2);
  setfillstyle(1,0);
  bar(139,0,141,375);
  bar(370,0,381,375);
  bar(139,373,381,377);
  char c;
  HoBaa();
  KKK();

 // strcpy(KEY,"adwklpq");
 // printf("444444444444%s",KEY);
  while(1)
  {
     while(!kbhit())
      {
	if (OCTAHOBKA1()==0) BBB(Time);
	 else { KOHELL(); HABAHABA(); HoBaa(); if (G_O==1) {
							     Game_Over();
							     return 0;}}
      }
	if (OCTAHOBKA1()==1) { KOHELL();
			       HABAHABA();
			       HoBaa();
			       if (G_O==1) { Game_Over(); return 0;}
			     }
	else
	{
	CcC=getch();
	//switch (CcC)
	{
	  if (CcC==KEY[0]) {if(!OCTAHOBKA3()) LLL();if (OCTAHOBKA1()==0) BBB(Time);}
	  else if (CcC==KEY[1]) {if(!OCTAHOBKA2()) RRR();if (OCTAHOBKA1()==0) BBB(Time);}
	  else if (CcC==KEY[2]) YckopeHue();
	  else if (CcC==KEY[3]) nepeBoPoT('k');
	  else if (CcC==KEY[4]) nepeBoPoT('l');
	  else if (CcC==KEY[5]) Pause();
	  else if (CcC==KEY[6]) goto ee;
	}
       }
     }
  ee:
  cleardevice();
/*  for(i=0;i<n;i++)
   {
   for(j=0;j<m;j++)
    printf("%d",Telo[i][j]);
    printf("\n");
    getch();
   }
  /*printf("%d  %d",k,l);*/
  return 0;
}

/*=========================== Заставка 1 ==================================*/
L1()
{
  if((f=fopen("Load1.txt","r"))==NULL) return 0 ;
  char str[10];
  while((fscanf(f,"%s",&str)!=EOF)&&(!kbhit()))
  {
    cleardevice();
    settextstyle(1,0,5);
    outtextxy(230,200,str);
    delay(100);
  }
  if(kbhit()) { getch(); return 0; }
  delay(100);
  settextstyle(1,0,2);
  outtextxy(220,310,"V");
  delay(100);
  outtextxy(235,310,"e");
  delay(100);
  outtextxy(250,310,"r");
  delay(100);
  outtextxy(265,310,"s");
  delay(100);
  outtextxy(280,310,"i");
  delay(100);
  outtextxy(295,310,"o");
  delay(100);
  outtextxy(310,310,"N");
  delay(100);
  outtextxy(335,310,"1.1");
  getch();
  return 0;
}