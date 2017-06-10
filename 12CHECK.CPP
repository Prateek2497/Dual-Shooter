#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<iostream.h>
#include<stdio.h>

float y1[20],y11[20];
float y2[20],y22[20];
float x1[20],x11[20];
float x2[20],x22[20];
int hitlist1[20],hitlist11[20];
int hitlist2[20],hitlist22[20];
int hp1,hp2;

class game
 {
  int hp1;
  int hp2;
  char *hp11;
  char *hp22;

  public:

  /*game()           //Default Constructor
   {
    hp1=10;
    hp2=10;
   }*/

  inline void hit(int f,int m,int flags,int flagt)
   {
    int j=0;
    for(j=0;j<=9;j++)
     {
      if(flags==0 && flagt==0)
       {
	break;
       }

      if(flags==1 && f>=0 && ::hitlist1[j]==1)
       {
	for(int count=0;count<4;count++)
	 {
	  if(::y1[j]>86)
	   {
	    ::y1[j]=::y1[j]-1;
	    putpixel(::x1[j],::y1[j],WHITE);
	    if(j==9)
	     {
	      setcolor(CYAN);
	      outtextxy(10,350,"RELOAD");
	     }
	   }
	  else
	  {
	   ::hitlist1[j]=0;
	   ::hitlist11[j]=0;
	   if(j==9)
	    {
	     setcolor(BLACK);
	     outtextxy(10,350,"RELOAD");
	     outtextxy(50,330,"0");
	     setcolor(CYAN);
	     outtextxy(50,330,"10");
	    }
	  }
	 }

	f--;
	if(f<0)
	 {
	  flags=0;
	 }
	int check1=0;
	float ya=::y1[j];
	check1=getpixel(::x1[j],ya-1);
	if(check1==1)
	 {
	  ::hitlist1[j]=0;
	  ::hitlist11[j]=0;
	  clear(j);

	  setcolor(BLACK);
	  sprintf(hp22,"%d",::hp2);
	  outtextxy(620,100,hp22);
	  ::hp2--;
	  setcolor(CYAN);
	  sprintf(hp22,"%d",::hp2);
	  outtextxy(620,100,hp22);

	 }
       }

      if(flagt==1 && m>=0 && ::hitlist2[j]==1)
       {
	for(int count=0;count<4;count++)
	 {
	   if(::y2[j]<394)
	    {
	     ::y2[j]=::y2[j]+1;
	     putpixel(::x2[j],::y2[j],WHITE);
	     if(j==9)
	     {
	      setcolor(CYAN);
	      outtextxy(580,150,"RELOAD");
	     }
	    }
	   else
	    {
	     ::hitlist2[j]=0;
	     ::hitlist22[j]=0;
	     if(j==9)
	     {
	      setcolor(BLACK);
	      outtextxy(580,150,"RELOAD");
	      outtextxy(620,130,"0");
	      setcolor(CYAN);
	      outtextxy(620,130,"10");
	     }
	    }
	 }

	m--;
	if(m<0)
	 {
	  flagt=0;
	 }

	int check2=0;
	float yb=::y2[j];
	check2=getpixel(::x2[j],yb+1);
	if(check2==1)
	 {
	  ::hitlist2[j]=0;
	  ::hitlist22[j]=0;
	  clear1(j);

	  setcolor(BLACK);
	  sprintf(hp11,"%d",::hp1);
	  outtextxy(50,300,hp11);
	  ::hp1--;
	  setcolor(CYAN);
	  sprintf(hp11,"%d",::hp1);
	  outtextxy(50,300,hp11);
	 }
       }

    }

 }


 inline void clearhit(int f,int m,int flags,int flagt)
  {
   int j=0;
   for(j=0;j<=9;j++)
    {
     if(flags==0 && flagt==0)
      {
       break;
      }

     if(flags==1 && f>=0 && ::hitlist11[j]==1)
      {
       for(int count=0;count<4;count++)
	{
	  if(::y11[j]>86)
	   {
	    ::y11[j]=::y11[j]-1;
	    putpixel(::x11[j],::y11[j],BLACK);
	   }
	}
       f--;
       if(f<0)
	{
	 flags=0;
	}
      }

     if(flagt==1 && m>=0 && ::hitlist22[j]==1)
       {
	for(int count=0;count<4;count++)
	 {
	  if(::y22[j]<394)
	   {
	    ::y22[j]=::y22[j]+1;
	    putpixel(::x22[j],::y22[j],BLACK);
	   }
	 }
	m--;
	if(m<0)
	{
	 flagt=0;
	}
       }

    }

 }


 void clear(int j)
  {
    for(int i=0;i<4;i++)
    {
     putpixel(::x1[j],::y1[j],BLACK);
     ::y1[j]=::y1[j]+1;
     ::y11[j]=::y11[j]+1;
    }
  }

 void clear1(int j)
  {
   for(int i=0;i<4;i++)
    {
     putpixel(::x2[j],::y2[j],BLACK);
     ::y2[j]=::y2[j]-1;
     ::y22[j]=::y22[j]-1;
    }
  }

 inline int check()
  {
    hp1=::hp1;
    hp2=::hp2;
    if(hp1==0)
    return 1;
    else
    if(hp2==0)
    return 2;
  }

 /*void show()
  {

   setcolor(CYAN);
   sprintf(hp11,"%d",hp1);
   sprintf(hp22,"%d",hp2);
   outtextxy(50,300,hp11);
   outtextxy(620,100,hp22);

  }*/
};



void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 int S[]={300,390,340,390,320,370,300,390};
 int T[]={300,90,340,90,320,110,300,90};
 int i,flag1,flag2,flag3,flag4,a1,a2,first=1,first1=1;
 int stop,bull1,bull2;
 char c,*b1,*b2,*h1,*h2;
 ::hp1=10;
 ::hp2=10;
 stop=0;

 game g;

 bull1=10,bull2=10;
 flag1=flag2=a1=a2=0;
 flag3=flag4=0;

 setcolor(RED);
 outtextxy(10,300,"H.P.:");
 outtextxy(580,100,"H.P.:");
 outtextxy(10,330,"Ammo:");
 outtextxy(580,130,"Ammo:");

 setcolor(CYAN);
 sprintf(b1,"%d",bull1);
 sprintf(b2,"%d",bull2);
 outtextxy(50,330,b1);
 outtextxy(620,130,b2);
 sprintf(h1,"%d",::hp1);
 sprintf(h2,"%d",::hp2);
 outtextxy(50,300,h1);
 outtextxy(620,100,h2);


 setcolor(BLUE);
 drawpoly(4,S);
 drawpoly(4,T);

 setfillstyle(SOLID_FILL,BLUE);
 fillpoly(4,S);
 fillpoly(4,T);


 setfillstyle(SOLID_FILL,WHITE);

 bar(80,80,100,400);
 bar(80,60,560,80);
 bar(540,80,560,400);
 bar(80,400,560,420);

 //g.show();

 do
 {

   if(kbhit())
    {
     fflush(stdin);
     c=getch();
     if(c==27)
      {
       break;
      }
     else if(c=='W'|| c=='w')
      {
	if(S[5]>240)
	{
	 setcolor(BLACK);
	 drawpoly(4,S);
	 setfillstyle(SOLID_FILL,BLACK);
	 fillpoly(4,S);


	 i=5;
	 S[1]=S[1]-i;
	 S[7]=S[1];
	 S[3]=S[3]-i;
	 S[5]=S[5]-i;

	 setcolor(BLUE);
	 drawpoly(4,S);
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,S);

	}
      }
     else if(c=='K'|| c=='k')
      {
	if(T[5]<240)
	{
	 setcolor(BLACK);
	 drawpoly(4,T);
	 setfillstyle(SOLID_FILL,BLACK);
	 fillpoly(4,T);

	 i=5;
	 T[1]=T[1]+i;
	 T[7]=T[1];
	 T[3]=T[3]+i;
	 T[5]=T[5]+i;
	 setcolor(BLUE);
	 drawpoly(4,T);
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,T);

	}
      }

     else if(c=='S'|| c=='s')
      {
	if(S[1]<400)
	{
	 setcolor(BLACK);
	 drawpoly(4,S);
	 setfillstyle(SOLID_FILL,BLACK);
	 fillpoly(4,S);


	 i=5;
	 S[1]=S[1]+i;
	 S[7]=S[1];
	 S[3]=S[3]+i;
	 S[5]=S[5]+i;
	 setcolor(BLUE);
	 drawpoly(4,S);
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,S);


	}
      }

     else if(c=='I'|| c=='i')
      {
	if(T[1]>80)
	{
	 setcolor(BLACK);
	 drawpoly(4,T);
	 setfillstyle(SOLID_FILL,BLACK);
	 fillpoly(4,T);

	 i=5;
	 T[1]=T[1]-i;
	 T[7]=T[1];
	 T[3]=T[3]-i;
	 T[5]=T[5]-i;
	 setcolor(BLUE);
	 drawpoly(4,T);
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,T);

	}
      }

     else if(c=='A'|| c=='a')
      {
	if(S[0]>100)
	{
	 setcolor(BLACK);
	 drawpoly(4,S);
	 setfillstyle(SOLID_FILL,BLACK);
	 fillpoly(4,S);


	 i=8;
	 S[0]=S[0]-i;
	 S[6]=S[0];
	 S[2]=S[2]-i;
	 S[4]=S[4]-i;
	 setcolor(BLUE);
	 drawpoly(4,S);
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,S);


	}
      }
     else if(c=='J'|| c=='j')
      {
	if(T[0]>100)
	{
	 setcolor(BLACK);
	 drawpoly(4,T);
	 setfillstyle(SOLID_FILL,BLACK);
	 fillpoly(4,T);

	 i=8;
	 T[0]=T[0]-i;
	 T[6]=T[0];
	 T[2]=T[2]-i;
	 T[4]=T[4]-i;
	 setcolor(BLUE);
	 drawpoly(4,T);
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,T);

	}
      }
     else if(c=='D' || c=='d')
      {
	if(S[2]<540)
	{
	 setcolor(BLACK);
	 drawpoly(4,S);
	 setfillstyle(SOLID_FILL,BLACK);
	 fillpoly(4,S);


	 i=8;
	 S[0]=S[0]+i;
	 S[6]=S[0];
	 S[2]=S[2]+i;
	 S[4]=S[4]+i;
	 setcolor(BLUE);
	 drawpoly(4,S);
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,S);


	}
      }
     else if(c=='L'|| c=='l')
      {
	if(T[2]<540)
	{
	 setcolor(BLACK);
	 drawpoly(4,T);
	 setfillstyle(SOLID_FILL,BLACK);
	 fillpoly(4,T);

	 i=8;
	 T[0]=T[0]+i;
	 T[6]=T[0];
	 T[2]=T[2]+i;
	 T[4]=T[4]+i;
	 setcolor(BLUE);
	 drawpoly(4,T);
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,T);

	}
      }

     else if(c=='F' || c=='f')
      {
	flag1=1;
	first=0;
	if(flag3==1)
	 {
	   a1=a1+1;
	   if(a1>9)
	    {
	     int shoot=0;
	     for(int l=0;l<=9;l++)
	       {
		if(::hitlist1[l]==0)
		 {
		  shoot=shoot+1;
		  ::y1[l]=0;
		  ::y11[l]=0;
		  ::x1[l]=0;
		  ::x11[l]=0;
		 }
		if(shoot>9)
		 {
		    a1=0;
		    bull1=10;
		    setcolor(BLACK);
		    outtextxy(50,330,"10");
		 }
	       }

	    }

	   flag3=0;
	 }
       if(bull1>0)
       {
	setcolor(BLACK);
	outtextxy(50,330,b1);
	bull1--;
	setcolor(CYAN);
	sprintf(b1,"%d",bull1);
	outtextxy(50,330,b1);
       }
      }

     else if(c=='M' || c=='m')
      {
	flag2=1;
	first1=0;
	if(flag4==1)
	 {
	   a2=a2+1;
	   if(a2>9)
	    {
	     int shoot=0;
	     for(int l=0;l<=9;l++)
	       {
		if(::hitlist2[l]==0)
		 {
		  shoot=shoot+1;
		  ::y2[l]=0;
		  ::y22[l]=0;
		  ::x2[l]=0;
		  ::x22[l]=0;
		 }
		if(shoot>9)
		 {
		    a2=0;
		    bull2=10;
		    setcolor(BLACK);
		    outtextxy(620,130,"10");
		 }
	       }

	    }

	   flag4=0;
	 }
	if(bull2>0)
	{
	 setcolor(BLACK);
	 outtextxy(620,130,b2);
	 bull2--;
	 setcolor(CYAN);
	 sprintf(b2,"%d",bull2);
	 outtextxy(620,130,b2);
	}
      }

    }

  if(first==0 && flag3==0)
   {
     ::y1[a1]=S[5];
     ::y11[a1]=S[5];
     ::x1[a1]=S[4];
     ::x11[a1]=S[4];
     ::hitlist1[a1]=1;
     ::hitlist11[a1]=1;
     flag3=1;

   }


  if(first1==0 && flag4==0)
   {
     ::y2[a2]=T[5];
     ::y22[a2]=T[5];
     ::x2[a2]=T[4];
     ::x22[a2]=T[4];
     ::hitlist2[a2]=1;
     ::hitlist22[a2]=1;
     flag4=1;

   }


  if(flag1==1 || flag2==1)
   {
    g.hit(a1,a2,flag1,flag2);
   }



  setfillstyle(SOLID_FILL,WHITE);
  bar(80,80,100,400);
  bar(80,60,560,80);
  bar(540,80,560,400);
  bar(80,400,560,420);

  setfillstyle(SOLID_FILL,BLUE);
  fillpoly(4,S);
  fillpoly(4,T);
  delay(50);

  if(flag1==1 || flag2==1)
   {
    g.clearhit(a1,a2,flag1,flag2);
   }

  stop=g.check();
  if(stop==1 || stop==2)
   {
    break;
   }


 }while(1);

 if(stop==1)
  {
   settextstyle(4,HORIZ_DIR,5);
   outtextxy(280,10,"WIN");
   outtextxy(280,420,"LOOSE");
   setfillstyle(SOLID_FILL,BLACK);
   fillpoly(4,S);

  }
 else if(stop==2)
  {
   settextstyle(4,HORIZ_DIR,5);
   outtextxy(280,10,"LOOSE");
   outtextxy(280,420,"WIN");
   setfillstyle(SOLID_FILL,BLACK);
   fillpoly(4,T);
  }

 getch();
 getch();
 getch();
 getch();
 getch();
 getch();
 getch();
 closegraph();

}