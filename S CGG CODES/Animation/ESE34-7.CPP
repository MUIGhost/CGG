#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        x++;
    }
}

// Bresenham's line drawing algorithm
void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy,e2;
    
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

int main() {
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100; // Top vertex of the right-angled triangle
    int x2 = 100, y2 = 400; // Bottom-left vertex of the triangle
    int x3 = 500, y3 = 400; // Bottom-right vertex of the triangle
    int r = 10;             // Radius of the ball

    // Calculate the slope of the hypotenuse
    float slope = (float)(y3 - y1) / (x3 - x1);

    // Calculate the angle of the hypotenuse
    float angle = atan(slope);

    // Initial position of the ball
    int ball_x = x1 - r * sin(angle);
    int ball_y = y1 + r * cos(angle);

    // Speed of the ball
    int speed = 4;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");



    while (!kbhit()) {
        cleardevice();

        // Draw the right-angled triangle
        bresenhamLine(x1, y1, x2, y2); // Left side
        bresenhamLine(x2, y2, x3, y3); // Bottom side
        bresenhamLine(x1, y1, x3, y3); // Hypotenuse

        // Draw the ball at the current position
        drawCircle(ball_x, ball_y, r);

        // Update the position of the ball
        ball_x += speed;
        ball_y = y1 + slope * (ball_x - x1) - r * sin(angle);

        // Ensure the ball remains on the hypotenuse by adjusting for the radius
        ball_y -= r * cos(angle);

        // Check if the ball reaches the bottom of the hypotenuse
        if (ball_x >= x3 + r * sin(angle)) {
            ball_x = x1 - r * sin(angle); // Reset the ball position to the top
            ball_y = y1 + r * cos(angle);
        }

        delay(30);
    }

    closegraph();
    return 0;
}