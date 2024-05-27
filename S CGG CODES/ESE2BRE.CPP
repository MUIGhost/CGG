#include <graphics.h>
#include <stdio.h>
#include<conio.h>
#include<math.h>

// Function to implement Bresenham's line drawing algorithm
void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
	putpixel(x1, y1, WHITE);  // Plot the point
	if (x1 == x2 && y1 == y2) break;  // If end point is reached, break
	int e2 = 2 * err;
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
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Example usage
    int x1, y1, x2, y2;

    // Example 1: A diagonal line
    x1 = 100;
    y1 = 100;
    x2 = 300;
    y2 = 300;
    drawLineBresenham(x1, y1, x2, y2);

    // Wait for a key press
    getch();
    closegraph();

    return 0;
}
