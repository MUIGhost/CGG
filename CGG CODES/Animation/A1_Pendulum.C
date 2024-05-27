#include <graphics.h>
#include <math.h>
#include <conio.h>



// Bresenham's Line Drawing Algorithm
void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy, e2;
    
    while (1) {
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

// Bresenham's Circle Drawing Algorithm
void bresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r, d = 3 - 2 * r;
    while (y >= x) {
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

// Pendulum Swing Animation
void pendulumSwing() {
    int x1 = 320, y1 = 50, length = 150;
    float angle = -M_PI / 4, angleIncrement = 0.05;
    int direction = 1; // 1 for forward, -1 for backward

    while (!kbhit()) {
        int x2 = x1 + length * sin(angle);
        int y2 = y1 + length * cos(angle);

        cleardevice();
        bresenhamLine(x1, y1, x2, y2);
        bresenhamCircle(x2, y2, 10);

        delay(50);

        // Change the direction when reaching the ends
        if (angle >= M_PI / 4) {
            direction = -1;
        } else if (angle <= -M_PI / 4) {
            direction = 1;
        }
        angle += direction * angleIncrement;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    pendulumSwing();

    closegraph();
    return 0;
}
