#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void rotatePoint(int *x, int *y, float angle) {
    float rad = angle * PI / 180.0; // Convert angle to radians
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    int xNew = (*x) * cosTheta - (*y) * sinTheta;
    int yNew = (*x) * sinTheta + (*y) * cosTheta;

    *x = xNew;
    *y = yNew;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    float angle1, angle2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get user input for triangle coordinates
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Get user input for rotation angles
    printf("Enter rotation angle 1 (in degrees): ");
    scanf("%f", &angle1);
    printf("Enter rotation angle 2 (in degrees): ");
    scanf("%f", &angle2);

    // Clear screen
    cleardevice();

    // Draw original triangle
    printf("Original Figure:");
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // First rotation
    printf("First Rotation:");
    rotatePoint(&x1, &y1, angle1);
    rotatePoint(&x2, &y2, angle1);
    rotatePoint(&x3, &y3, angle1);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Second rotation
    printf("Second Rotation:");
    x1 = x1 - x2;
    y1 = y1 - y2;
    x3 = x3 - x2;
    y3 = y3 - y2;
    rotatePoint(&x1, &y1, angle2);
    rotatePoint(&x3, &y3, angle2);
    x1 = x1 + x2;
    y1 = y1 + y2;
    x3 = x3 + x2;
    y3 = y3 + y2;
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reset triangle to original position
    printf("Original Figure:");
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Combined rotation: Rotate by angle2 first, then angle1
    printf("From angle2 then angle1:");
    x1 = x1 - x2;
    y1 = y1 - y2;
    x3 = x3 - x2;
    y3 = y3 - y2;
    rotatePoint(&x1, &y1, angle2);
    rotatePoint(&x3, &y3, angle2);
    x1 = x1 + x2;
    y1 = y1 + y2;
    x3 = x3 + x2;
    y3 = y3 + y2;
    x1 = x1 - x2;
    y1 = y1 - y2;
    x3 = x3 - x2;
    y3 = y3 - y2;
    rotatePoint(&x1, &y1, angle1);
    rotatePoint(&x3, &y3, angle1);
    x1 = x1 + x2;
    y1 = y1 + y2;
    x3 = x3 + x2;
    y3 = y3 + y2;
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reset triangle to original position
    printf("Original Figure:");
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Combined rotation: Rotate by angle1 first, then angle2
    printf("From angle1 then angle2:");
    x1 = x1 - x2;
    y1 = y1 - y2;
    x3 = x3 - x2;
    y3 = y3 - y2;
    rotatePoint(&x1, &y1, angle1);
    rotatePoint(&x3, &y3, angle1);
    x1 = x1 + x2;
    y1 = y1 + y2;
    x3 = x3 + x2;
    y3 = y3 + y2;
    x1 = x1 - x2;
    y1 = y1 - y2;
    x3 = x3 - x2;
    y3 = y3 - y2;
    rotatePoint(&x1, &y1, angle2);
    rotatePoint(&x3, &y3, angle2);
    x1 = x1 + x2;
    y1 = y1 + y2;
    x3 = x3 + x2;
    y3 = y3 + y2;
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    closegraph();
    return 0;
}
//100 100 200 100 150 50
//30
//60