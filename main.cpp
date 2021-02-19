# include "iGraphics.h"
#include<math.h>

double x[1015], y[1015],x2[1015], y2[1015],x3[1015], y3[1015],x4[1015],y4[1015],x5[1015],y5[1015];
double a1=100,b1=2,f1=0,a2=150,b2=3,f2=0,a3=100,b3=2,f3=-150,a4=150,b4=3,f4=-150,mini1=700,maxi1=0,mini2=700,maxi2=0,mini3=700,maxi3=0,mini4=700,maxi4=0;
int i,mood=1,bl1=1,bl2=1,bl3=1,bl4=1,bl5=1,it=2,moved=1,t=5,as,de,help=1;

void change();
void calculate()
{
    ///sin-curve 1
    x[0]=1000;
    y[0]=350;
    x[1]=-15;
    y[1]=350;
    for(i=2;i<=1009;i++)
    {
        x[i]=i-2;
        y[i]=350+a1*sin(b1*(i-2)*(3.1416/180)+(3.1416*f1/180));
        if(mini1>y[i])
            mini1=y[i];
        if(maxi1<y[i])
            maxi1=y[i];
    }
    ///cos-curve2
    x2[0]=1000;
    y2[0]=350;
    x2[1]=-15;
    y2[1]=350;
    for(i=2;i<=1009;i++)
    {
        x2[i]=i-2;
        y2[i]=350+a2*cos(b2*(i-2)*(3.1416/180)+(3.1416*f2/180));
        if(mini2>y[i])
            mini2=y[i];
        if(maxi2<y[i])
            maxi2=y[i];
    }
    ///sin-curve 3
    x3[0]=1000;
    y3[0]=350;
    x3[1]=-15;
    y3[1]=350;
    for(i=2;i<=1009;i++)
    {
        x3[i]=i-2;
        y3[i]=350+a3*sin(b3*(i-2)*(3.1416/180)+(3.1416*f3/180));
        if(mini3>y[i])
            mini3=y[i];
        if(maxi3<y[i])
            maxi3=y[i];
    }
    ///cos-curve 4
    x4[0]=1000;
    y4[0]=350;
    x4[1]=-15;
    y4[1]=350;
    for(i=2;i<=1009;i++)
    {
        x4[i]=i-2;
        y4[i]=350+a4*cos(b4*(i-2)*(3.1416/180)+(3.1416*f4/180));
        if(mini4>y[i])
            mini4=y[i];
        if(maxi4<y[i])
            maxi4=y[i];
    }
    ///sum of 1,2,3,4 curve 5
    x5[0]=1000;
    y5[0]=350;
    x5[1]=-15;
    y5[1]=350;
    for(i=2;i<=1009;i++)
    {
        x5[i]=i-2;
        y5[i]=350+(a4*cos(b4*(i-2)*(3.1416/180)+(3.1416*f4/180))+a3*sin(b3*(i-2)*(3.1416/180)+(3.1416*f3/180))+a2*cos(b2*(i-2)*(3.1416/180)+(3.1416*f2/180))+a1*sin(b1*(i-2)*(3.1416/180)+(3.1416*f1/180)));
    }
}

void change()
{
    if(moved==1)
    {
        if(it>=1005)
        {
            as=0;
            de=1;
        }
        else if(it<=2)
        {
            as=1;
            de=0;
        }
        if(as==1)
            it+=t;
        else if(de==1)
            it-=t;
    }
}
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
    //place your drawing codes here
    iClear();
    if(help==0)
    {
        iSetColor(255,255,255);
        if(mood==1)
        {
            iPolygon(x,y,1010);
            iPolygon(x2,y2,1010);
            iPolygon(x3,y3,1010);
            iPolygon(x4,y4,1010);
            iPolygon(x5,y5,1010);
        }
        if(bl1==1)
        {
            iSetColor(255,0,0);
            iFilledCircle(x[it],y[it],5);
        }
        if(bl2==1)
        {
            iSetColor(0,255,0);
            iFilledCircle(x2[it],y2[it],5);
        }
        if(bl3==1)
        {
            iSetColor(0,0,255);
            iFilledCircle(x3[it],y3[it],5);
        }
        if(bl4==1)
        {
            iSetColor(255,255,0);
            iFilledCircle(x4[it],y4[it],5);
        }
        if(bl5==1)
        {
            iSetColor(255,0,255);
            iFilledCircle(x5[it],y5[it],5);
        }
        iText(15,15,"Press P/p for pause,R/r for resume,End for exit");
    }
    else
    {
        iShowBMP(0,0,"help.bmp");
        iSetColor(0,0,0);
        iText(385,660,"INSTRUCTIONS");
        iText(53,635,"Toggle Help / Main page : F1");
        iText(53,610,"Toggle curve show / hide  : s / S");
        iText(53,585,"Toggle tracer show / hide : <curve_no>");
        iText(53,560,"Pause Animation  : p / P");
        iText(53,535,"Resume Animation : r / R");
        iText(53,510,"Increase amplitude : a");
        iText(53,485,"Decrease amplitude : A");
        iText(53,460,"Increase frequency : f");
        iText(53,435,"Decrease frequency : F");
        iText(53,410,"Increase speed : +");
        iText(53,385,"Decrease speed : -");
        iText(53,360,"Left shift  : Left_arrow");
        iText(53,335,"Right shift : Right_arrow");
        iText(53,310,"Exit      : End");

    }
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    ///printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'a')
    {
        if(mini1>=0&&maxi1<=700)
             a1+=20;
        else
        {
            mini1=700;
            maxi1=0;
        }
        if(mini2>=0&&maxi2<=700)
            a2+=20;
        else
        {
            mini2=700;
            maxi2=0;
        }
        if(mini3>=0&&maxi3<=700)
            a3+=20;
        else
        {
            mini3=700;
            maxi3=0;
        }
        if(mini4>=0&&maxi4<=700)
            a4+=20;
        else
        {
            mini4=700;
            maxi4=0;
        }
    }
    if(key == 'A')
    {
        if(a1>=20)
            a1-=20;
        if(a2>=20)
            a2-=20;
        if(a3>=20)
            a3-=20;
        if(a4>=20)
            a4-=20;
    }
    if(key == 'F')
    {
        if(b1>=0.5)
            b1-=0.5;
        if(b2>=0.5)
            b2-=0.5;
        if(b3>=0.5)
            b3-=0.5;
        if(b4>=0.5)
            b4-=0.5;
    }
    if(key == 'f')
    {
        if(b1<=15)
            b1+=0.5;
        if(b2<=15)
            b2+=0.5;
        if(b3<=15)
            b3+=0.5;
        if(b4<=15)
            b4+=0.5;
    }
    if(key=='s'||key=='S')
    {
        if(mood==1)
            mood=0;
        else
             mood=1;
    }
    if(key=='1')
    {
        if(bl1==1)
            bl1=0;
        else
            bl1=1;
    }
    if(key=='2')
    {
        if(bl2==1)
            bl2=0;
        else
            bl2=1;
    }
    if(key=='3')
    {
        if(bl3==1)
            bl3=0;
        else
            bl3=1;
    }
    if(key=='4')
    {
        if(bl4==1)
            bl4=0;
        else
            bl4=1;
    }
    if(key=='5')
    {
        if(bl5==1)
            bl5=0;
        else
            bl5=1;
    }
    if(key=='1'||key=='2'||key=='3'||key=='4'||key=='5')
        moved=1;
    if(key=='+'&&t<20)
    {
        t++;
    }
    if(key=='-'&&t>0)
    {
        t--;
    }
    if(key=='p'||key=='P')
        iPauseTimer(0);
    if(key=='r'||key=='R')
        iResumeTimer(0);
    calculate();
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_F1)
    {
        if(help==1)
            help=0;
        else
            help=1;
    }
    if(key == GLUT_KEY_LEFT)
    {
        f1+=10;
        f2+=10;
        f3+=10;
        f4+=10;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        f1-=10;
        f2-=10;
        f3-=10;
        f4-=10;
    }
    calculate();
    //place your codes for other keys here
}


int main()
{
    //place your own initialization codes here.
    calculate();
    iSetTimer(25,change);
    iInitialize(1000, 700, "Curve");
    return 0;
}
