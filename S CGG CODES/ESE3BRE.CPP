#include<stdio.h>
#include<graphics.h>
void drawcircle(int xc,int yc,int x,int y);
void brecircle(int xc,int yc,int r)
{
int x=0,y=r;
int p=3-2*r;
drawcircle(xc,yc,x,y);
while(y>=x)
{
x++;
if(p>0)
{
y--;
p=p+4*x-4*y+10;
}
else{
p=p+4*x+6;
}
drawcircle(xc,yc,x,y);
}
}
void drawcircle(int xc,int yc,int x,int y)
{
putpixel(xc+x,yc+y,RED);
putpixel(xc-x,yc+y,RED);
putpixel(xc+x,yc-y,RED);
putpixel(xc-x,yc-y,RED);
putpixel(xc+y,yc+x,RED);
putpixel(xc-y,yc+x,RED);
putpixel(xc+y,yc-x,RED);
putpixel(xc-y,yc-x,RED);
}
int main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
brecircle(200,200,90);
getchar();

return 0;
}