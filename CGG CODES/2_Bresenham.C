#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y, p, incrx, incry, i;

    x = x1;
    y = y1;

    if (x2 > x1) {
        incrx = 1;
    } else {
        incrx = -1;
    }

    if (y2 > y1) {
        incry = 1;
    } else {
        incry = -1;
    }

    if (dx > dy) {
        putpixel(x, y, WHITE);
        p = 2 * dy - dx;
        for (i = 0; i < dx; i++) {
            if (p >= 0) {
                y += incry;
                p += 2 * (dy - dx);
            } else {
                p += 2 * dy;
            }
            x += incrx;
            putpixel(x, y, WHITE);
        }
    } else {
        putpixel(x, y, WHITE);
        p = 2 * dx - dy;
        for (i = 0; i < dy; i++) {
            if (p >= 0) {
                x += incrx;
                p += 2 * (dx - dy);
            } else {
                p += 2 * dx;
            }
            y += incry;
            putpixel(x, y, WHITE);
        }
    }
}

int main() {
    int x1, y1, x2, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


    printf("Enter coordinates of first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

//300 100
//150 100