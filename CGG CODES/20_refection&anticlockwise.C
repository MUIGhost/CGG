#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void reflectAboutYEqualsX(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reflectAboutXAxis(int *x, int *y) {
    *y = 2 * 200 - *y; // Reflect about x-axis
}

void rotate90AntiClockwise(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = 2 * 200 - temp; // Rotate 90 degrees anticlockwise
}

void reflectTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3) {
    reflectAboutYEqualsX(x1, y1);
    reflectAboutYEqualsX(x2, y2);
    reflectAboutYEqualsX(x3, y3);
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get user input for triangle coordinates
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Clear screen
    cleardevice();

    // Draw original triangle
    printf("Original Figure:");
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reflect about y=x
    printf("Reflection about y=x:");
    reflectTriangle(&x1, &y1, &x2, &y2, &x3, &y3);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reset triangle to original position
   // reflectTriangle(&x1, &y1, &x2, &y2, &x3, &y3);

    // Reflect about x-axis
    reflectAboutXAxis(&x1, &y1);
    reflectAboutXAxis(&x2, &y2);
    reflectAboutXAxis(&x3, &y3);
    printf("Reflection about x-axis:");
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reset triangle to original position
   // reflectAboutXAxis(&x1, &y1);
   // reflectAboutXAxis(&x2, &y2);
   // reflectAboutXAxis(&x3, &y3);

    // Rotate 90 degrees anticlockwise
    printf("Rotation 90 degrees anticlockwise:");
    rotate90AntiClockwise(&x1, &y1);
    rotate90AntiClockwise(&x2, &y2);
    rotate90AntiClockwise(&x3, &y3);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    closegraph();
    return 0;
}

//50 100 150 100 100 200