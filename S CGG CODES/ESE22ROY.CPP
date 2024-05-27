#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include<conio.h>

// Function to draw the axes and the line Y = X
void drawReferenceLines() {
    int maxX = getmaxx();
    int maxY = getmaxy();
    setcolor(LIGHTGRAY);
    line(maxX / 2, 0, maxX / 2, maxY);  // Y-axis
    line(0, maxY / 2, maxX, maxY / 2);  // X-axis
    line(0, 0, maxX, maxY);             // Line Y = X
}

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, const char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3, label); // Text at the centroid
}

// Function to reflect a point about the origin
void reflectPointOrigin(int *x, int *y, int originX, int originY) {
    *x = 2 * originX - *x;
    *y = 2 * originY - *y;
}

// Function to reflect a point about the line Y = X
void reflectPointYX(int *x, int *y, int originX, int originY) {
    int temp = *x;
    *x = originY + (originY - *y);
    *y = originX + (originX - temp);
}

// Function to reflect a triangle about the origin
void reflectTriangleOrigin(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int originX, int originY) {
    reflectPointOrigin(x1, y1, originX, originY);
    reflectPointOrigin(x2, y2, originX, originY);
    reflectPointOrigin(x3, y3, originX, originY);
}

// Function to reflect a triangle about the line Y = X
void reflectTriangleYX(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int originX, int originY) {
    reflectPointYX(x1, y1, originX, originY);
    reflectPointYX(x2, y2, originX, originY);
    reflectPointYX(x3, y3, originX, originY);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    // Draw the origin axes and the line Y = X
    drawReferenceLines();

    // Define the initial vertices of the triangle
    int originX = getmaxx() / 2;
    int originY = getmaxy() / 2;
    int x1 = originX + 100, y1 = originY - 100;
    int x2 = originX + 200, y2 = originY - 100;
    int x3 = originX + 150, y3 = originY - 200;

    // Draw the original triangle in blue
    drawTriangle(x1, y1, x2, y2, x3, y3, BLUE, "Original");
    getch();

    // Reflect about the origin
    int x1_reflectOrigin = x1, y1_reflectOrigin = y1;
    int x2_reflectOrigin = x2, y2_reflectOrigin = y2;
    int x3_reflectOrigin = x3, y3_reflectOrigin = y3;
    reflectTriangleOrigin(&x1_reflectOrigin, &y1_reflectOrigin, &x2_reflectOrigin, &y2_reflectOrigin, &x3_reflectOrigin, &y3_reflectOrigin, originX, originY);
    drawTriangle(x1_reflectOrigin, y1_reflectOrigin, x2_reflectOrigin, y2_reflectOrigin, x3_reflectOrigin, y3_reflectOrigin, RED, "Reflect Origin");
    getch();

    // Reflect about the line Y = X
    int x1_reflectYX = x1, y1_reflectYX = y1;
    int x2_reflectYX = x2, y2_reflectYX = y2;
    int x3_reflectYX = x3, y3_reflectYX = y3;
    reflectTriangleYX(&x1_reflectYX, &y1_reflectYX, &x2_reflectYX, &y2_reflectYX, &x3_reflectYX, &y3_reflectYX, originX, originY);
    drawTriangle(x1_reflectYX, y1_reflectYX, x2_reflectYX, y2_reflectYX, x3_reflectYX, y3_reflectYX, GREEN, "Reflect Y = X");
    getch();

    closegraph();
    return 0;
}
