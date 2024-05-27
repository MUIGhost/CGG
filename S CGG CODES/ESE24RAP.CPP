#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include<conio.h>
#include<stdlib.h>

// Function to draw the X and Y axes
void drawAxes() {
    int maxX = getmaxx();
    int maxY = getmaxy();
    line(0, maxY / 2, maxX, maxY / 2); // X-axis
    line(maxX / 2, 0, maxX / 2, maxY); // Y-axis
}

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, const char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3, label); // Text at the centroid
}

// Function to rotate a point (x, y) about another point (cx, cy) by angle theta
void rotatePoint(int *x, int *y, int cx, int cy, float theta) {
    float radians = theta * (3.14159265358979323846 / 180.0);
    *x = cx + (*x - cx) * cos(radians) - (*y - cy) * sin(radians);
    *y = cy + (*x - cx) * sin(radians) + (*y - cy) * cos(radians);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    // Draw the X and Y axes
    drawAxes();

    // Define the initial vertices of the triangle
    int originX = getmaxx() / 2;
    int originY = getmaxy() / 2;
    int x1 = 100 + originX, y1 = 100 + originY;
    int x2 = 200 + originX, y2 = 100 + originY;
    int x3 = 150 + originX, y3 = 200 + originY;

    // Draw the original triangle in blue
    drawTriangle(x1, y1, x2, y2, x3, y3, BLUE, "Original");
    getch();

    // Input the arbitrary point
    int arbitraryX, arbitraryY;
    printf("Enter the arbitrary point coordinates (x y): ");
    scanf("%d %d", &arbitraryX, &arbitraryY);

    // Input the rotation angle
    float theta;
    printf("Enter the rotation angle in degrees: ");
    scanf("%f", &theta);

    // Rotate the triangle about the arbitrary point by angle theta
    rotatePoint(&x1, &y1, arbitraryX + originX, arbitraryY + originY, theta);
    rotatePoint(&x2, &y2, arbitraryX + originX, arbitraryY + originY, theta);
    rotatePoint(&x3, &y3, arbitraryX + originX, arbitraryY + originY, theta);
    cleardevice();
    setcolor(WHITE);
    drawAxes();
    // Draw the rotated triangle in red
    drawTriangle(x1, y1, x2, y2, x3, y3, RED, "Rotated");
    getch();

    closegraph();
    return 0;
}
