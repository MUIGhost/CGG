#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

// Function to draw a line using Bresenham's algorithm
void drawLine(int x1, int y1, int x2, int y2) {
    int e2;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        putpixel(x1, y1, WHITE);

        if (x1 == x2 && y1 == y2)
            break;

        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// Function to draw a circle using Bresenham's algorithm
void drawCircle(int xc, int yc, int radius) {
    int x = radius, y = 0;
    int radiusError = 1 - x;

    while (x >= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        y++;

        if (radiusError < 0)
            radiusError += 2 * y + 1;
        else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

// Function to move the circle along the edge of the triangle
void moveAlongTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float *cx, float *cy, float *target_x, float *target_y, float step) {
    // Calculate distance to target
    float distance_to_target = sqrt(pow(*target_x - *cx, 2) + pow(*target_y - *cy, 2));

    // Check if the target is reached
    if (distance_to_target < step) {
        // Update target to next vertex
        if (*target_x == x1 && *target_y == y1) {
            *target_x = x2;
            *target_y = y2;
        } else if (*target_x == x2 && *target_y == y2) {
            *target_x = x3;
            *target_y = y3;
        } else {
            *target_x = x1;
            *target_y = y1;
        }
    }

    // Move towards the target
    *cx += (*target_x - *cx) * step / distance_to_target;
    *cy += (*target_y - *cy) * step / distance_to_target;
}

int main() {
    int gd = DETECT, gm;
    int xc = 320, yc = 240; // Center of the large triangle
    int sideLength = 150;    // Length of each side of the triangle
    float small_x, small_y;  // Initial position of the small circle
    float target_x, target_y; // Target position for the small circle
    float step = 2.0;        // Step size for movement
    int smallRadius = 10;    // Radius of the small circle
    int x1 = xc - sideLength / 2, y1 = yc + sideLength * sqrt(3) / 2;
    int x2 = xc + sideLength, y2 = yc + sideLength * sqrt(3) / 2;
    int x3 = xc + sideLength / 2, y3 = yc - sideLength * sqrt(3) / 2;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Calculate the initial position of the small circle (resting on vertex)
    small_x = x1;
    small_y = y1;
    target_x = x2;
    target_y = y2;

    while (!kbhit()) {
        cleardevice();

        // Draw the large triangle using Bresenham's algorithm
        drawLine(x1, y1, x2, y2);
        drawLine(x2, y2, x3, y3);
        drawLine(x3, y3, x1, y1);

        // Draw the small circle using Bresenham's algorithm
        drawCircle((int)small_x, (int)small_y, smallRadius);

        // Move the small circle along the edge of the triangle
        moveAlongTriangle(x1, y1, x2, y2, x3, y3, &small_x, &small_y, &target_x, &target_y, step);

        delay(100);
    }

    closegraph();
    return 0;
}
