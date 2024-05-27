#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159265

// Function to perform 2D rotation of a point
void rotatePoint(int *x, int *y, int cx, int cy, float angle) {
    float radians = angle * PI / 180.0;
    int newX = cx + (*x - cx) * cos(radians) - (*y - cy) * sin(radians);
    int newY = cy + (*x - cx) * sin(radians) + (*y - cy) * cos(radians);
    *x = newX;
    *y = newY;
}

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, const char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 + 10, y1 + 10, label);  // Adjusted text placement
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define the initial vertices of the triangle
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 200;

    // Draw the original triangle in blue
    drawTriangle(x1, y1, x2, y2, x3, y3, BLUE, "Original");
    getch(); // Wait for user to press Enter

    // Define the angles of rotation
    int angle1 = 30;
    int angle2 = 60;

    // Rotate the original triangle by angle1 and then by angle2
    int x1_rotated1 = x1, y1_rotated1 = y1;
    int x2_rotated1 = x2, y2_rotated1 = y2;
    int x3_rotated1 = x3, y3_rotated1 = y3;
    int cx = (x1 + x2 + x3) / 3;
    int cy = (y1 + y2 + y3) / 3;
    rotatePoint(&x1_rotated1, &y1_rotated1, cx, cy, angle1);
    rotatePoint(&x2_rotated1, &y2_rotated1, cx, cy, angle1);
    rotatePoint(&x3_rotated1, &y3_rotated1, cx, cy, angle1);
    rotatePoint(&x1_rotated1, &y1_rotated1, cx, cy, angle2);
    rotatePoint(&x2_rotated1, &y2_rotated1, cx, cy, angle2);
    rotatePoint(&x3_rotated1, &y3_rotated1, cx, cy, angle2);
    drawTriangle(x1_rotated1, y1_rotated1, x2_rotated1, y2_rotated1, x3_rotated1, y3_rotated1, RED, "Rotation by angle1, then angle2");
    getch(); // Wait for user to press Enter

    // Rotate the original triangle by angle2 and then by angle1
    int x1_rotated2 = x1, y1_rotated2 = y1;
    int x2_rotated2 = x2, y2_rotated2 = y2;
    int x3_rotated2 = x3, y3_rotated2 = y3;
    rotatePoint(&x1_rotated2, &y1_rotated2, cx, cy, angle2);
    rotatePoint(&x2_rotated2, &y2_rotated2, cx, cy, angle2);
    rotatePoint(&x3_rotated2, &y3_rotated2, cx, cy, angle2);
    rotatePoint(&x1_rotated2, &y1_rotated2, cx, cy, angle1);
    rotatePoint(&x2_rotated2, &y2_rotated2, cx, cy, angle1);
    rotatePoint(&x3_rotated2, &y3_rotated2, cx, cy, angle1);
    drawTriangle(x1_rotated2, y1_rotated2, x2_rotated2, y2_rotated2, x3_rotated2, y3_rotated2, GREEN, "Rotation by angle2, then angle1");
    getch(); // Wait for user to press Enter

    closegraph();
    return 0;
}
