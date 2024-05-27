#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void scaleTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float scaleX, float scaleY) {
    *x1 *= scaleX;
    *y1 *= scaleY;
    *x2 *= scaleX;
    *y2 *= scaleY;
    *x3 *= scaleX;
    *y3 *= scaleY;
}

void rotatePoint(int *x, int *y, float angle) {
    float radians = angle * (3.14159 / 180);
    float newX = *x * cos(radians) - *y * sin(radians);
    float newY = *x * sin(radians) + *y * cos(radians);
    *x = (int)newX;
    *y = (int)newY;
}

void rotateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float angle) {
    int centroidX = (*x1 + *x2 + *x3) / 3;
    int centroidY = (*y1 + *y2 + *y3) / 3;

    *x1 -= centroidX;
    *y1 -= centroidY;
    *x2 -= centroidX;
    *y2 -= centroidY;
    *x3 -= centroidX;
    *y3 -= centroidY;

    rotatePoint(x1, y1, angle);
    rotatePoint(x2, y2, angle);
    rotatePoint(x3, y3, angle);

    *x1 += centroidX;
    *y1 += centroidY;
    *x2 += centroidX;
    *y2 += centroidY;
    *x3 += centroidX;
    *y3 += centroidY;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    float scaleX, scaleY;
    float angle;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    printf("Enter scaling factors (scaleX scaleY): ");
    scanf("%f %f", &scaleX, &scaleY);
    scaleTriangle(&x1, &y1, &x2, &y2, &x3, &y3, scaleX, scaleY);

    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    printf("Enter rotation angle in degrees: ");
    scanf("%f", &angle);
    rotateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, angle);

    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();

    closegraph();
    return 0;
}

//100 100 200 100 150 200
//1.5 0.8
//45