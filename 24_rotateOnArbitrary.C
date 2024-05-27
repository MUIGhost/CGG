#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

// Function to draw a point
void drawPoint(int x, int y) {
    putpixel(x, y, WHITE);
}

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to rotate a point about another point
void rotatePoint(int *x, int *y, int pivotX, int pivotY, float angle) {
    float rad = angle * (3.14159 / 180.0);
    int newX = pivotX + (*x - pivotX) * cos(rad) - (*y - pivotY) * sin(rad);
    int newY = pivotY + (*x - pivotX) * sin(rad) + (*y - pivotY) * cos(rad);
    *x = newX;
    *y = newY;
}

// Function to rotate a triangle about an arbitrary point
void rotateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int pivotX, int pivotY, float angle) {
    rotatePoint(x1, y1, pivotX, pivotY, angle);
    rotatePoint(x2, y2, pivotX, pivotY, angle);
    rotatePoint(x3, y3, pivotX, pivotY, angle);
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    int pivotX, pivotY;
    float angle;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get user input for triangle coordinates
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Get user input for pivot point
    printf("Enter pivot point coordinates (pivotX pivotY): ");
    scanf("%d %d", &pivotX, &pivotY);

    // Get user input for rotation angle
    printf("Enter rotation angle in degrees: ");
    scanf("%f", &angle);

    // Draw original triangle and pivot point
    drawTriangle(x1, y1, x2, y2, x3, y3);
    drawPoint(pivotX, pivotY);
    getch();
    cleardevice();

    // Rotate triangle about arbitrary pivot point
    rotateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, pivotX, pivotY, angle);

    // Draw rotated triangle and pivot point
    printf("Rotation about Arbitrary Point:");
    drawTriangle(x1, y1, x2, y2, x3, y3);
    drawPoint(pivotX, pivotY);
    getch();

    closegraph();
    return 0;
}
//100 100 200 100 150 200
//200 200
//45