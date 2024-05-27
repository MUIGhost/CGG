#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void translateTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty) {
    drawTriangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty, x3 + tx, y3 + ty);
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    int tx1, ty1, tx2, ty2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Get user input for triangle coordinates
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Get user input for translation amounts
    printf("Enter translation amount for the first translation (tx1 ty1): ");
    scanf("%d %d", &tx1, &ty1);
    printf("Enter translation amount for the second translation (tx2 ty2): ");
    scanf("%d %d", &tx2, &ty2);

    // Clear screen
    cleardevice();

    // Draw original triangle
    printf("Original Figure:");
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // First translation
    printf("First Translation:");
    translateTriangle(x1, y1, x2, y2, x3, y3, tx1, ty1);
    getch();
    cleardevice();

    // Second translation
    printf("Second Translation:");
    translateTriangle(x1, y1, x2, y2, x3, y3, tx2, ty2);
    getch();
    cleardevice();

    // Combined translation
    printf("Additive Translation:");
    translateTriangle(x1, y1, x2, y2, x3, y3, tx1 + tx2, ty1 + ty2);
    getch();
    cleardevice();

    closegraph();
    return 0;
}
//100 100 200 100 150 50
//30 50
//20 40