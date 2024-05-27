#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include<math.h>

// Bresenham Line Drawing Algorithm
void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2; // error value e_xy

    for (;;) {
	putpixel(x0, y0, WHITE);
	if (x0 == x1 && y0 == y1) break;
	e2 = 2 * err;
	if (e2 >= dy) { err += dy; x0 += sx; } // e_xy+e_x > 0
	if (e2 <= dx) { err += dx; y0 += sy; } // e_xy+e_y < 0
    }
}

// Midpoint Circle Drawing Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r;
    while (x <= y) {
	putpixel(xc + x, yc + y, WHITE);
	putpixel(xc - x, yc + y, WHITE);
	putpixel(xc + x, yc - y, WHITE);
	putpixel(xc - x, yc - y, WHITE);
	putpixel(xc + y, yc + x, WHITE);
	putpixel(xc - y, yc + x, WHITE);
	putpixel(xc + y, yc - x, WHITE);
	putpixel(xc - y, yc - x, WHITE);

	if (d < 0) {
	    d = d + 2 * x + 3;
	} else {
	    d = d + 2 * (x - y) + 5;
	    y--;
	}
	x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Car body
    setcolor(LIGHTGREEN);
    drawLine(182, 200, 420, 200);
    drawLine(420, 200, 410, 250);
    drawLine(410, 250, 190, 250);
    drawLine(190, 250, 182, 200);

    // Car top
    setcolor(CYAN);
    drawLine(260, 150, 360, 150);
    drawLine(360, 150, 390, 200);
    drawLine(390, 200, 220, 200);
    drawLine(220, 200, 260, 150);

    // Car windows
    setcolor(CYAN);
    drawLine(265, 155, 300, 155);
    drawLine(300, 155, 290, 195);
    drawLine(290, 195, 230, 195);
    drawLine(230, 195, 265, 155);

    drawLine(305, 155, 350, 155);
    drawLine(350, 155, 380, 195);
    drawLine(380, 195, 295, 195);
    drawLine(295, 195, 305, 155);

    // Wheels
    setcolor(WHITE);
    drawCircle(260, 252, 18);
    drawCircle(350, 252, 18);

    // Wheel centers
    setcolor(LIGHTGRAY);
    drawCircle(260, 252, 5);
    drawCircle(350, 252, 5);

    getch();
    closegraph();
    return 0;
}
