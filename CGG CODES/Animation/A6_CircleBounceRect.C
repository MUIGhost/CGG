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
   int rectX1 = 100, rectY1 = 100; // Top-left corner of the rectangle
    int rectX2 = 500, rectY2 = 300; // Bottom-right corner of the rectangle
    int small_r = 10;               // Radius of the small circle

    int small_x = rectX1 + small_r; // Initial x position of the small circle
    int small_y = rectY1 + small_r; // Initial y position of the small circle

    int dx = 1; // x direction of movement
    int dy = 1; // y direction of movement
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");



    while (!kbhit()) {
	cleardevice();

	// Draw the rectangle
	bresenhamLine(rectX1, rectY1, rectX2, rectY1); // Top side
	bresenhamLine(rectX2, rectY1, rectX2, rectY2); // Right side
	bresenhamLine(rectX2, rectY2, rectX1, rectY2); // Bottom side
	bresenhamLine(rectX1, rectY2, rectX1, rectY1); // Left side

	// Draw the small circle at the calculated position
	bresenhamCircle(small_x, small_y, small_r);

	// Update the position of the small circle
	small_x += dx;
	small_y += dy;

	// Check for collision with the rectangle boundaries and reverse direction if needed
	if (small_x + small_r >= rectX2 || small_x - small_r <= rectX1) {
	    dx = -dx;
	}
	if (small_y + small_r >= rectY2 || small_y - small_r <= rectY1) {
	    dy = -dy;
	}

	delay(5);
    }

    closegraph();
    return 0;
}