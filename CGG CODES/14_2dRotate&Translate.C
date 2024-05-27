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

    int x1New = x1 * cosTheta - y1 * sinTheta;
    int y1New = x1 * sinTheta + y1 * cosTheta;
    int x2New = x2 * cosTheta - y2 * sinTheta;
    int y2New = x2 * sinTheta + y2 * cosTheta;
    int x3New = x3 * cosTheta - y3 * sinTheta;
    int y3New = x3 * sinTheta + y3 * cosTheta;

    drawTriangle(x1New, y1New, x2New, y2New, x3New, y3New);
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
    int x1, y1, x2, y2, x3, y3;
    float angle;
    int tx, ty;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get user input for triangle coordinates
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Clear screen
    cleardevice();

    // Draw original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Get user input for rotation angle
    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angle);

    // Draw rotated triangle
    rotateTriangle(x1, y1, x2, y2, x3, y3, angle);
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
//100 100 200 100 150 50
//45
//50 50