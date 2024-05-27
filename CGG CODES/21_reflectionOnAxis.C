#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to reflect the triangle about the X-axis
void reflectAboutXAxis(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3) {
    *y1 = 2 * 200 - *y1;
    *y2 = 2 * 200 - *y2;
    *y3 = 2 * 200 - *y3;
}

// Function to reflect the triangle about the Y-axis
void reflectAboutYAxis(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3) {
    *x1 = 2 * 200 - *x1;
    *x2 = 2 * 200 - *x2;
    *x3 = 2 * 200 - *x3;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get user input for triangle coordinates
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Draw original triangle
    printf("Original Figure:");
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reflect about X-axis
    printf("Reflection About x-axis:");
    reflectAboutXAxis(&x1, &y1, &x2, &y2, &x3, &y3);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reset triangle to original position
    reflectAboutXAxis(&x1, &y1, &x2, &y2, &x3, &y3);

    // Reflect about Y-axis
    printf("Reflection About y-axis:");
    reflectAboutYAxis(&x1, &y1, &x2, &y2, &x3, &y3);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    closegraph();
    return 0;
}

//50 100 150 100 100 200