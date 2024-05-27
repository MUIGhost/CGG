#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

// Function to draw a circle using Bresenham's algorithm
void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

// Bresenham's circle drawing algorithm
void bresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        drawCircle(xc, yc, x, y);
    }
}

// Function to rotate a point around a center
void rotatePoint(int xc, int yc, int x, int y, float angle, int *newX, int *newY) {
    *newX = xc + (x - xc) * cos(angle) - (y - yc) * sin(angle);
    *newY = yc + (x - xc) * sin(angle) + (y - yc) * cos(angle);
}

int main() {
    int gd = DETECT, gm;
    int xc = 320, yc = 240; // Center of the large circle
    int r = 100;            // Radius of the large circle
    int small_r = 20;       // Radius of the small circle
    float angle = 0.0;      // Initial angle
    float bigCircleAngle = 0.0; // Angle for rotating the large circle
   int rotation_radius = r + small_r; // Radius of the rotation path
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");



 

    while (!kbhit()) {
 int rotatedX, rotatedY;
     int small_x = rotatedX + rotation_radius * cos(angle);
        int small_y = rotatedY + rotation_radius * sin(angle);
        cleardevice();

        // Rotate the center of the large circle around itself
       
        rotatePoint(xc, yc, xc, yc, bigCircleAngle, &rotatedX, &rotatedY);

        // Draw the large circle at the new position
        bresenhamCircle(rotatedX, rotatedY, r);

        // Calculate the position of the small circle
   

        // Draw the small circle at the calculated position
        bresenhamCircle(small_x, small_y, small_r);

        // Update the angles for the next frame
        angle += 0.05;
        bigCircleAngle += 0.01;

        delay(50);
    }

    closegraph();
    return 0;
}