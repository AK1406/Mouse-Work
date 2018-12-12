#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
union REGS in,out;

void callmouse()
 {
     in.x.ax=1;
     int86(51,&in,&out);
  }

 void mousepos(int &xpos,int &ypos,int &click)
  {
       in.x.ax=3;
       int86(51,&in,&out);
       click=out.x.bx;
       xpos=out.x.cx;
       ypos=out.x.dx;
       if(click==1)
       {
	  clrscr();
     int grd,grm;

     int bgcolor,midx,midy,color,j;
     char str[]="I Love you Coding         U & I always together (Proof see Keyboard)";
     detectgraph(&grd,&grm);
     initgraph(&grd,&grm,"//Turboc3//bgi//");
     bgcolor=RED;
     setbkcolor(bgcolor);
     midx=getmaxx();
     midy=getmaxy();
     setcolor(WHITE);
     rectangle(0,0,midx,midy);
     settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
     color=GREEN;
      int i,n=10;
      for(i=n/2;i<=n;i+=2)
     {
	for(j=1;j<n-i;j+=2)
	 {
	   cout<<" ";
	  }
	for(j=1;j<=i;j++)
	 {
	    cout<<"*";
	 }

	for(j=1;j<=n-i;j++)
	 {
	   cout<<" ";
	  }
	  for(j=1;j<=i;j++)
	 {
	    cout<<"*";
	 }
	printf("\n");
    }

    for(i=n;i>=1;i--)
     {
       for(j=1;j<=n-i;j++)
	 {
	     cout<<" ";
	  }
       for(j=1;j<=(i*2)-1;j++)
	 {
	     cout<<"*";

	  }
      cout<<"\n";
   }
  getch();
     for(j=0;j<=10;j++)
     {
       if((j%2)==0)
	{
	  setcolor(color++);
	  outtextxy(20,220,str);
	  delay(1000);
	  if(color>WHITE)
	     color=GREEN;
	 }
       else
	 {
	   setcolor(bgcolor);
	   outtextxy(20,220,str);
	   delay(500);
	}
     }
     getch();
     closegraph();

  }
}

void mousehide()
 {
    in.x.ax=2;
    int86(51,&in,&out);
 }

 void setposi(int &xpos, int &ypos)
  {
       in.x.ax=4;
       in.x.cx=xpos;
       in.x.dx=ypos;
       int86(51,&in,&out);
  }

void restrictmouseptr(int x1,int y1, int x2,int y2)
 {
    in.x.ax=7;
    in.x.cx=x1;
    in.x.dx=x2;
    int86(51,&in,&out);
    in.x.ax=8;
    in.x.cx=y1;
    in.x.dx=y2;
    int86(51,&in,&out);
 }




 void main()
  {
    int x,y,cl,a,b;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:/turboc3/bgi");
    a=100;
    b=400;
    setposi(a,b);
    callmouse();
    restrictmouseptr(5,8,650,500);
    getch();
    do
      {
	 mousepos(x,y,cl);
	 gotoxy(10,2);
	 cout<<"\n\tMouse position is:"<<x<<","<<y;
	 cout<<"\n\tClick:"<<cl;
	 cout<<"\n\n\tclick left button of your mouse to get message";

	 cout<<"\n\tPress any key to hide the mouse";
      }while(!kbhit());
      getch();
      mousehide();
      printf("\n\n\tPress any key to Exit");
      getch();
   }
