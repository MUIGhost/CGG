#include <graphics.h>
#include <conio.h>
#include <math.h>

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


// Function to draw a circle using Bresenham's Algorithm
void bresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (y >= x) {
        // For each pixel we draw all eight pixels
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

     bresenhamLine(90,150,150,150);
    bresenhamCircle(160,150,8);
    bresenhamCircle(160,150,2);

    bresenhamLine(170,150,210,150);
    bresenhamCircle(220,150,8);
    bresenhamCircle(220,150,2);
    bresenhamLine(230,150,280,150);
    bresenhamLine(280,150,280,110);
    bresenhamLine(280,110,230,110);
    bresenhamLine(230,110,200,90);
    bresenhamLine(200,90,160,90);
    bresenhamLine(160,90,130,110);
    bresenhamLine(130,110,90,110);
    bresenhamLine(90,110,90,150);

   

    //window
    bresenhamLine(162,92,135,110);
    bresenhamLine(135,110,226,110);
    bresenhamLine(162,92,198,92);
    bresenhamLine(180,110,180,92);
    bresenhamLine(226,110,198,92);


    getch();
    closegraph();
    return 0;
}
