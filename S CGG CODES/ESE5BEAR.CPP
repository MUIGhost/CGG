#include <graphics.h>
#include <stdio.h>

// Midpoint Circle Drawing Algorithm
void drawCircle(int xc, int yc, int r, int color) {
    int x = 0, y = r;
    int d = 1 - r;
    while (x <= y) {
        // Drawing the 8 octants
        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc + x, yc - y, color);
        putpixel(xc - x, yc - y, color);
        putpixel(xc + y, yc + x, color);
        putpixel(xc - y, yc + x, color);
        putpixel(xc + y, yc - x, color);
        putpixel(xc - y, yc - x, color);

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
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    // Color definitions
    int headColor = BROWN;
    int earColor = BROWN;
    int eyeColor = BLACK;
    int noseColor = WHITE;

    // Circle properties
    int headX = 320, headY = 240, headR = 100;
    int earOffsetX = 70, earOffsetY = 70, earR = 40;
    int eyeOffsetX = 35, eyeOffsetY = 20, eyeR = 10;
    int noseR = 10;
    int mouthR = 40; // Radius of the mouth

    // Draw and fill head
    drawCircle(headX, headY, headR, LIGHTGRAY);
    setfillstyle(SOLID_FILL, headColor);
    floodfill(headX, headY, LIGHTGRAY);

    // Draw and fill ears
    drawCircle(headX - earOffsetX, headY - earOffsetY, earR, BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(headX - earOffsetX - 11, headY - earOffsetY + 10, BROWN);

    drawCircle(headX + earOffsetX, headY - earOffsetY, earR, BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(headX + earOffsetX + 11, headY - earOffsetY + 10, BROWN);

    // Draw and fill eyes
    drawCircle(headX - eyeOffsetX, headY - eyeOffsetY, eyeR, WHITE);
    setfillstyle(SOLID_FILL, eyeColor);
    floodfill(headX - eyeOffsetX, headY - eyeOffsetY, WHITE);

    drawCircle(headX + eyeOffsetX, headY - eyeOffsetY, eyeR, WHITE);
    setfillstyle(SOLID_FILL, eyeColor);
    floodfill(headX + eyeOffsetX, headY - eyeOffsetY, WHITE);

    // Draw and fill nose inside the mouth
    drawCircle(headX, headY + eyeOffsetY, noseR, WHITE);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(headX,headY+eyeOffsetY,WHITE);

    // Draw mouth boundary
    drawCircle(headX, headY + 2 * eyeOffsetY, mouthR, WHITE);
    setfillstyle(SOLID_FILL, noseColor);
    floodfill(headX, headY + 2 * eyeOffsetY, WHITE);

    getchar();
    closegraph();
    return 0;
}
