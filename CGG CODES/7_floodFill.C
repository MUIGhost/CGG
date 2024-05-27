#include <graphics.h>
#include <conio.h>

// Function to implement Bresenham's Line Drawing Algorithm
void bresenhamLine(int x1, int y1, int x2, int y2) {
 int dx = abs(x2 - x1);
int dy = abs(y2 - y1);
int sx = x1 < x2 ? 1 : -1;
int sy = y1 < y2 ? 1 : -1;
int err = dx - dy;
while (1) {
int e2;
putpixel(x1, y1, WHITE);
if (x1 == x2 && y1 == y2) break;
e2 = 2 * err;
if (e2 > -dy) { err -= dy; x1 += sx; }
if (e2 < dx) { err += dx; y1 += sy; }
}
}


// Function to implement the Flood Fill Algorithm
void floodFill(int x, int y, int fillColor, int bgColor) {
    if (getpixel(x, y) == bgColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, bgColor);
        floodFill(x - 1, y, fillColor, bgColor);
        floodFill(x, y + 1, fillColor, bgColor);
        floodFill(x, y - 1, fillColor, bgColor);
    }
}

int main() {
    int gd = DETECT, gm,i;
 int poly[10] = {150, 140, 170, 140, 180, 160, 160, 180, 150, 140};
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    

    // Draw the polygon using Bresenham's line algorithm
     for (i = 0; i < 8; i += 2) {
        bresenhamLine(poly[i], poly[i + 1], poly[i + 2], poly[i + 3]);
    }

     floodFill(160, 160, YELLOW, BLACK);

    getch();
    closegraph();
    return 0;
}
