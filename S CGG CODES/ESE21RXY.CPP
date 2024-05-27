#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include<conio.h>
// Function to draw the axes
void drawAxes() {
    int maxX = getmaxx();
    int maxY = getmaxy();
    setcolor(LIGHTGRAY);
    line(maxX / 2, 0, maxX / 2, maxY);  // Y-axis
    line(0, maxY / 2, maxX, maxY / 2);  // X-axis
}

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, const char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 + 10, y1 + 10, label);
}

// Function to perform reflection of a point about the X axis
void reflectPointX(int *x, int *y, int originY) {
    *y = 2 * originY - *y;
}

// Function to perform reflection of a point about the Y axis
void reflectPointY(int *x, int *y, int originX) {
    *x = 2 * originX - *x;
}

// Function to reflect a triangle about the X axis
void reflectTriangleX(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int originY) {
    reflectPointX(x1, y1, originY);
    reflectPointX(x2, y2, originY);
    reflectPointX(x3, y3, originY);
}

// Function to reflect a triangle about the Y axis
void reflectTriangleY(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int originX) {
    reflectPointY(x1, y1, originX);
    reflectPointY(x2, y2, originX);
    reflectPointY(x3, y3, originX);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    // Draw the origin axes
    drawAxes();

    // Define the initial vertices of the triangle
    int originX = getmaxx() / 2;
    int originY = getmaxy() / 2;
    int x1 = originX + 100, y1 = originY - 100;
    int x2 = originX + 200, y2 = originY - 100;
    int x3 = originX + 150, y3 = originY - 200;

    // Draw the original triangle in blue
    drawTriangle(x1, y1, x2, y2, x3, y3, BLUE, "Original");
    getch();

    // Reflect about X axis
    int x1_reflectX = x1, y1_reflectX = y1;
    int x2_reflectX = x2, y2_reflectX = y2;
    int x3_reflectX = x3, y3_reflectX = y3;
    reflectTriangleX(&x1_reflectX, &y1_reflectX, &x2_reflectX, &y2_reflectX, &x3_reflectX, &y3_reflectX, originY);
    drawTriangle(x1_reflectX, y1_reflectX, x2_reflectX, y2_reflectX, x3_reflectX, y3_reflectX, RED, "Reflected X-axis");
    getch();

    // Reflect about Y axis
    int x1_reflectY = x1, y1_reflectY = y1;
    int x2_reflectY = x2, y2_reflectY = y2;
    int x3_reflectY = x3, y3_reflectY = y3;
    reflectTriangleY(&x1_reflectY, &y1_reflectY, &x2_reflectY, &y2_reflectY, &x3_reflectY, &y3_reflectY, originX);
    drawTriangle(x1_reflectY, y1_reflectY, x2_reflectY, y2_reflectY, x3_reflectY, y3_reflectY, GREEN, "Reflected Y-axis");
    getch();

    // Reflect about both X and Y axes
    int x1_reflectXY = x1_reflectX,y1_reflectXY = y1_reflectX;
    int x2_reflectXY = x2_reflectX, y2_reflectXY = y2_reflectX;
    int x3_reflectXY = x3_reflectX, y3_reflectXY = y3_reflectX;
    reflectTriangleY(&x1_reflectXY, &y1_reflectXY, &x2_reflectXY, &y2_reflectXY, &x3_reflectXY, &y3_reflectXY, originX);
    drawTriangle(x1_reflectXY, y1_reflectXY, x2_reflectXY, y2_reflectXY, x3_reflectXY, y3_reflectXY, YELLOW, "Reflected X and Y");
    getch();

    closegraph();
    return 0;
}
