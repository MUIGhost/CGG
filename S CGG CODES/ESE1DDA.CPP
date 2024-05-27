#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void dda(int x1,int y1,int x2,int y2){
int dx,dy,step,i,x_inc,y_inc,x,y;
dx=x2-x1;
dy=y2-y2;
if(abs(dx)>abs(dy)){
step=dx;
}
else{
step =dy;
}
x_inc=dx/(float)step;
y_inc=dy/(float)step;
x=x1;
y=y1;
for(i=0;i<=step;i++)
{
putpixel(x,y,WHITE);
x=x+x_inc;
y=y+y_inc;
}
}
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
int x1,y1,x2,y2;
printf("Enter the first co-ordinates of the line:");
scanf("%d%d",&x1,&y1);
printf("Enter the second co-ordinates of the lien:");
scanf("%d%d",&x2,&y2);
dda(x1,y1,x2,y2);
getch();
return 0;
}
