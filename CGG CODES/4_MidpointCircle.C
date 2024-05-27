#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawCircleMidPoint(int xc, int yc, int radius) {
    int x = 0, y = radius;
    int p = 1 - radius;

    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
}

int main() {
    int xc, yc, radius;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter coordinates of center (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius of circle: ");
    scanf("%d", &radius);

    drawCircleMidPoint(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}
//300 200
//50