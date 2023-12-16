#include <graphics.h>
#include <iostream>
using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

class Point
{
	public:
	    int x, y;
};

int computeCode(int ptx, int pty, int x_min, int y_min, int x_max, int y_max)
{
    int code = INSIDE;
    if (ptx < x_min)
        code |= LEFT;
    else if (ptx > x_max)
        code |= RIGHT;
    if (pty < y_min)
        code |= BOTTOM;
    else if (pty > y_max)
        code |= TOP;
    return code;
}

void cohenSutherland(int lineStartx, int lineStarty, int lineEndx, int lineEndy, int x_min, int y_min, int x_max, int y_max)
{
    int code1 = computeCode(lineStartx, lineStarty, x_min, y_min, x_max, y_max);
    int code2 = computeCode(lineEndx, lineEndy, x_min, y_min, x_max, y_max);
    bool accept = false;
    
    while (true)
	{
        if ((code1 == 0) && (code2 == 0))
		{
            accept = true;
            break;
        }
		else if (code1 & code2)
            break;
        else
		{
            int code_out;
            Point intersection;
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
                
            if (code_out & TOP)
			{
                intersection.x = lineStartx + (lineEndx - lineStartx) * (y_max - lineStarty) / (lineEndy - lineStarty);
                intersection.y = y_max;
            }
			else if (code_out & BOTTOM)
			{
                intersection.x = lineStartx + (lineEndx - lineStartx) * (y_min - lineStarty) / (lineEndy - lineStarty);
                intersection.y = y_min;
            }
			else if (code_out & RIGHT)
			{
                intersection.y = lineStarty + (lineEndy - lineStarty) * (x_max - lineStartx) / (lineEndx - lineStartx);
                intersection.x = x_max;
            }
			else if (code_out & LEFT)
			{
                intersection.y = lineStarty + (lineEndy - lineStarty) * (x_min - lineStartx) / (lineEndx - lineStartx);
                intersection.x = x_min;
            }
            if (code_out == code1)
			{
                lineStartx = intersection.x;
                lineStarty = intersection.y;
                code1 = computeCode(lineStartx, lineStarty, x_min, y_min, x_max, y_max);
            }
			else
			{
                lineEndx = intersection.x;
                lineEndy = intersection.y;
                code2 = computeCode(lineEndx, lineEndy, x_min, y_min, x_max, y_max);
            }
        }
    }
    
    if (accept)
        line(lineStartx, lineStarty, lineEndx, lineEndy);
}

void seedFill(int x, int y, int fillColor, int borderColor)
{
    if (getpixel(x, y) != borderColor && getpixel(x, y) != fillColor)
    {
        putpixel(x, y, fillColor);
        seedFill(x + 1, y, fillColor, borderColor);
        seedFill(x - 1, y, fillColor, borderColor);
        seedFill(x, y + 1, fillColor, borderColor);
        seedFill(x, y - 1, fillColor, borderColor);
    }
}

void DrawShip()
{
	circle(400, 480, 30);
	circle(400, 480, 20);
	circle(500, 480, 30);
	circle(500, 480, 20);
	circle(740, 400, 20);
	
	circle(965,215,20);
	circle(950,165,30);
	circle(895,240,20);
	circle(895,240,20);
	circle(870,190,30);
	circle(895,240,20);
	circle(895,115,40);
	circle(895,240,20);
	circle(900, 400, 20);
	circle(820, 400, 20);

	line(300, 600, 1000, 600);
	line(290, 580, 1003, 580);
	line(285, 560, 1005, 560);
	line(300, 600, 220, 400);
	line(1000, 600, 1020, 450);
	line(220, 400, 1020, 450);	
	line(230, 400, 230, 370);
	line(225, 400, 225, 365);
	line(230, 370, 430, 385);
	line(225, 365, 435, 380);
	line(430, 385, 430, 415);
	line(435, 380, 435, 415);
	line(410, 415, 410, 315);
	line(410, 315, 1000, 374);
	line(1000, 374, 1000, 450);
	line(880, 363, 880, 280);
	line(880, 280, 910, 280);
	line(910, 280, 910, 365);
	line(950, 369, 950, 255);
	line(950, 255, 980, 255);
	line(980, 255, 980, 374);
	line(0, 600, 1300, 600);

	setlinestyle(DASHED_LINE, 0, 1);
	setcolor(BLUE);
	
	line(0, 630, 1300, 630);
	line(0, 660, 1300, 660);
	line(0, 690, 1300, 690);
	line(0, 720, 1300, 720);
	line(0, 750, 1300, 750);
	line(0, 780, 1300, 780);
}

void fillColors()
{
	seedFill(431, 386,YELLOW , WHITE);
	seedFill(425, 386,DARKGRAY, WHITE);
	seedFill(230, 369, YELLOW, WHITE);
	seedFill(898,118,WHITE,WHITE);
	seedFill(968,218,WHITE,WHITE);
	seedFill(952,168,WHITE,WHITE);
	seedFill(898,243,WHITE,WHITE);
	seedFill(872,193,WHITE,WHITE);
	seedFill(295, 584, RED, WHITE);
	seedFill(288, 562, DARKGRAY, WHITE);
	seedFill(250, 420, RED,WHITE);
	seedFill(375, 480, WHITE,BLACK);
	seedFill(475, 480, WHITE,BLACK);
	seedFill(383, 484, BROWN,WHITE);
	seedFill(483, 484, BROWN,WHITE);
    seedFill(950, 390, DARKGRAY,WHITE);
	seedFill(810, 400, WHITE,WHITE);
	seedFill(890, 400, WHITE,WHITE);
	seedFill(730, 400, WHITE,WHITE);
	seedFill(978, 258, LIGHTRED, WHITE);
	seedFill(900, 284, LIGHTRED, WHITE);
}

void Clipp()
{
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
	
	circle(400, 480, 30);
	circle(400, 480, 20);
	circle(500, 480, 30);
	circle(500, 480, 20);
	circle(740, 400, 20);
	
	// Clipping Window
	rectangle(350,300,780,675);
	
	cohenSutherland(0,600,1300,600,350,300,780,675);
	cohenSutherland(300, 600, 1000, 600,350,300,780,675);
	cohenSutherland(290, 580, 1003, 580,350,300,780,675);
	cohenSutherland(285, 560, 1005, 560,350,300,780,675);
	cohenSutherland(300, 600, 220, 400,350,300,780,675);
	cohenSutherland(1000, 600, 1020, 450,350,300,780,675);
	cohenSutherland(220, 400, 1020, 450,350,300,780,675);
	cohenSutherland(230, 400, 230, 370,350,300,780,675);
	cohenSutherland(225, 400, 225, 365,350,300,780,675);
	cohenSutherland(230, 370, 430, 385,350,300,780,675);
	cohenSutherland(225, 365, 435, 380,350,300,780,675);
	cohenSutherland(430, 385, 430, 415,350,300,780,675);
	cohenSutherland(435, 380, 435, 415,350,300,780,675);
	cohenSutherland(410, 415, 410, 315,350,300,780,675);
	cohenSutherland(410, 315, 1000, 374,350,300,780,675);
	cohenSutherland(1000, 374, 1000, 450,350,300,780,675);
	cohenSutherland(880, 363, 880, 280,350,300,780,675);
	cohenSutherland(880, 280, 910, 280,350,300,780,675);
	cohenSutherland(910, 280, 910, 365,350,300,780,675);
	cohenSutherland(950, 369, 950, 255,350,300,780,675);
	cohenSutherland(950, 255, 980, 255,350,300,780,675);
	cohenSutherland(980, 255, 980, 374,350,300,780,675);
	
	seedFill(431, 386,YELLOW , WHITE);
	seedFill(425, 386,DARKGRAY, WHITE);
	seedFill(450, 386,DARKGRAY, WHITE);
	seedFill(383, 380, YELLOW, WHITE);
	seedFill(360, 584, RED, WHITE);
	seedFill(360, 550, RED, WHITE);
	seedFill(360, 562, DARKGRAY, WHITE);
	seedFill(383, 484, BROWN,WHITE);
	seedFill(483, 484, BROWN,WHITE);
	seedFill(730, 400, WHITE,WHITE);
	
	setlinestyle(DASHED_LINE, 0, 1);
	setcolor(BLUE);
	
	cohenSutherland(0, 630, 1300, 630,350,300,780,675);
	cohenSutherland(0, 660, 1300, 660,350,300,780,675);
	cohenSutherland(0, 690, 1300, 690,350,300,780,675);
	cohenSutherland(0, 720, 1300, 720,350,300,780,675);
	cohenSutherland(0, 750, 1300, 750,350,300,780,675);
	cohenSutherland(0, 780, 1300, 780,350,300,780,675);
}

int main()
{
	initwindow(1300,800);
	
	DrawShip();
	
	char key;
	
	cout<<"Press any key to color the window"<<endl;
	cin>>key;
	delay(10);
	
	fillColors();
	
	cout<<"Press any key to clip the window"<<endl;
	cin>>key;
	
	cleardevice();
	
	Clipp();
	
	getch();
	closegraph();
}
