#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void scaleTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float scaleX, float scaleY) {
    x1 *= scaleX;
    y1 *= scaleY;
    x2 *= scaleX;
    y2 *= scaleY;
    x3 *= scaleX;
    y3 *= scaleY;

    drawTriangle(x1, y1, x2, y2, x3, y3);
}

void translateTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty) {
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;
    x3 += tx;
    y3 += ty;

    drawTriangle(x1, y1, x2, y2, x3, y3);
}

int main() {
    int x1, y1, x2, y2, x3, y3, tx, ty;
    float scaleX, scaleY;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    

    // Clear screen
    cleardevice();

    // Get user input for triangle coordinates
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Draw original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Get user input for scaling factor
    printf("Enter scaling factors (scaleX scaleY): ");
    scanf("%f %f", &scaleX, &scaleY);

    // Draw scaled triangle
    scaleTriangle(x1, y1, x2, y2, x3, y3, scaleX, scaleY);
    getch();
    cleardevice();

    // Get user input for translation values
    printf("Enter translation values (tx ty): ");
    scanf("%d %d", &tx, &ty);

    // Draw translated triangle
    translateTriangle(x1, y1, x2, y2, x3, y3, tx, ty);
    getch();
    cleardevice();

    closegraph();
    return 0;
}

//100 100 200 200 150 50
//1.5 1.5
//50 50
