#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void translateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int dx, int dy) {
    *x1 += dx;
    *y1 += dy;
    *x2 += dx;
    *y2 += dy;
    *x3 += dx;
    *y3 += dy;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    int dx1, dy1, dx2, dy2; // Translation amounts
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get user input for triangle coordinates
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Get user input for translation amounts
    printf("Enter translation amount for the first translation (dx1 dy1): ");
    scanf("%d %d", &dx1, &dy1);
    printf("Enter translation amount for the second translation (dx2 dy2): ");
    scanf("%d %d", &dx2, &dy2);

    // Clear screen
    cleardevice();

    // Draw original triangle
    printf("Original Figure:");
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // First translation
    printf("First Translation:");
    translateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, dx1, dy1);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Second translation
    printf("Second Translation:");
    translateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, dx2, dy2);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reset triangle to original position
    x1 -= dx2;
    y1 -= dy2;
    x2 -= dx2;
    y2 -= dy2;
    x3 -= dx2;
    y3 -= dy2;

    // Combined translation: Translate by dx2 first, then dx1
    printf("Translation from dx2 then dx1:");
    translateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, dx2, dy2);
    translateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, dx1, dy1);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reset triangle to original position
    x1 += dx2;
    y1 += dy2;
    x2 += dx2;
    y2 += dy2;
    x3 += dx2;
    y3 += dy2;

    // Combined translation: Translate by dx1 first, then dx2
     printf("Translation from dx1 then dx2:");
    translateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, dx1, dy1);
    translateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, dx2, dy2);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    closegraph();
    return 0;
}
//100 100 200 100 150 50
//30 50
//20 40