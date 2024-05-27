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

void drawTeddyBear(int xc, int yc, int radius) {
    // Head
    drawCircleMidPoint(xc, yc, radius);

    // Eyes
    drawCircleMidPoint(xc - radius / 4, yc - radius / 4, radius / 10); // Left eye
    drawCircleMidPoint(xc + radius / 4, yc - radius / 4, radius / 10); // Right eye

    // Nose (triangle)
    line(xc, yc, xc - radius / 10, yc + radius / 5);
    line(xc, yc, xc + radius / 10, yc + radius / 5);
    line(xc - radius / 10, yc + radius / 5, xc + radius / 10, yc + radius / 5);

    // Mouth (arc)
    arc(xc, yc + radius / 4, 180, 360, radius / 4);
}

int main() {
    int xc, yc, radius;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the coordinates of the center (x y): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the radius of the teddy bear's face: ");
    scanf("%d", &radius);

    drawTeddyBear(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}

//350 240
//60