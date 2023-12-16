#include<graphics.h>
#include <windows.h>
#include<time.h>

int raisehand=0;
int handY=230;

void cloud1(int x,int y)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    ellipse(x+2,y+5,0,180,40,25);
    ellipse(x-40,y+30,80,320,50,30);
    ellipse(x,y+40,180,360,30,20);
    ellipse(x+60,y+30,210,120,40,30);
    floodfill(x+10,y+30,WHITE);
}

void sky()
{
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    rectangle(0,0,700,300);
    floodfill(1,1,LIGHTBLUE);
}

void sea()
{
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(0,300,700,600);
    floodfill(2,301,BLUE);
}

void tree()
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BROWN);
    ellipse(150,300,350,120,20,80);
    ellipse(130,300,350,50,20,90);
    line(150,313,170,313);
    // line(139,232,152,221);
    floodfill(152,310,BLACK);

    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    // Leaves
    ellipse(145,262,0,360,7,30);    
    floodfill(145,262,GREEN);
    ellipse(120,235,45,44,30,7);
    floodfill(120,235,GREEN);

    arc(140,280,85,160,40);
    arc(105,225,265,340,40);
    // putpixel(130,250,WHITE);
    floodfill(130,250,GREEN);

    arc(140,280,85,160,40);
    arc(105,225,265,340,40);
}

void island()
{
    setcolor(BROWN);
    setfillstyle(SOLID_FILL,BROWN);
    ellipse(300,370,30,150,200,100);
    line(127,320,475,320);
    floodfill(150,310,BROWN);

    // tree();

}

void man()
{
    setcolor(WHITE);
    circle(300,227,13);
    circle(295,224,3);
    circle(305,224,3);
    arc(300,237,45,135,7);

    line(300,240,300,270);

    line(280,245,320,245);
    if(raisehand==2)
    {
        if(handY==230)
        {
            handY=260;
        }
        else
        {
            handY=230;
            setbkcolor(LIGHTBLUE);
            settextstyle(8,0,2);
            setcolor(WHITE);
            outtextxy(350,210,(char *)". . . Help");
        }
        raisehand=0;
    }
    else
    {
        raisehand++;
    }
    line(280,245,270,handY);//handY+30
    line(320,245,330,handY);//handY+30

    line(300,270,280,285);
    line(300,270,320,285);
}

void boat(int x, int y)//x=100,y=400
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BROWN);
    line(x,y,x+200,y);
    line(x,y,x+50,y+50);
    line(x+200,y,x+150,y+50);
    line(x+50,y+50,x+150,y+50);
    // putpixel(x+20,y+10,BROWN);
    floodfill(x+20,y+10,BLACK);
}



int main()
{
    
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    int x=150,y=50;
    int boatX=600,boatY=420;
    while(1)
    {
        // Upper Sky
            sky();    

        // Moving Cloud
        if(x>650)
            x=0;
        else
            x+=10;
        cloud1(x,y);

            
            sea();
            island();

            man();
            if(boatX<-100)
            {
                boatX=600;
            }
            else
            {
                boatX-=30;
            }
            boat(boatX,boatY);

            
            

        delay(200);
        cleardevice();
    }


    
    



    getch();
    closegraph();
    return 0;
}