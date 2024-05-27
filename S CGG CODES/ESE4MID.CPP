#include<stdio.h>
#include<graphics.h>
void drawcircle(int xc,int yc,int x,int y);
void midcircle(int xc,int yc,int r)
{
int x=0,y=r;
int p=1-r;
drawcircle(xc,yc,x,y);
while(y>=x)
{
x++;
if(p<=0)
{
p=p+2*x+3;

}
else
{
y--;
p=p+2*x-2*y+5;
}
drawcircle(xc,yc,x,y);
}
}
void drawcircle(int xc,int yc,int x,int y)
{
putpixel(xc+x,yc+y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);
putpixel(xc+y,yc+x,WHITE);
putpixel(xc-y,yc+x,WHITE);
putpixel(xc+y,yc-x,WHITE);
putpixel(xc-y,yc-x,WHITE);
}
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
midcircle(140,160,90);
getchar();
return 0;
}