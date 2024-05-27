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

void rotateTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float angle) {
    float rad = angle * PI / 180.0; // Convert angle to radians
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    int x1New = (int)(x1 * cosTheta - y1 * sinTheta);
    int y1New = (int)(x1 * sinTheta + y1 * cosTheta);
    int x2New = (int)(x2 * cosTheta - y2 * sinTheta);
    int y2New = (int)(x2 * sinTheta + y2 * cosTheta);
    int x3New = (int)(x3 * cosTheta - y3 * sinTheta);
    int y3New = (int)(x3 * sinTheta + y3 * cosTheta);

    drawTriangle(x1New, y1New, x2New, y2New, x3New, y3New);
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    float angle1, angle2;
    float combinedAngle = angle1 + angle2;
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

    // Draw first rotation
    printf("First Rotation:");
    rotateTriangle(x1, y1, x2, y2, x3, y3, angle1);
    getch();
    cleardevice();

    // Draw second rotation
    printf("Second Rotation:");
    rotateTriangle(x1, y1, x2, y2, x3, y3, angle2);
    getch();
    cleardevice();

    // Calculate and draw combined rotation
    printf("Combined R(01 + 02):");
    rotateTriangle(x1, y1, x2, y2, x3, y3, combinedAngle);
    getch();
    cleardevice();

    closegraph();
    return 0;
}

//100 100 200 100 150 50
//30
//45