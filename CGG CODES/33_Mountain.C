#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <time.h>

// Function to draw fractal mountain
void drawMountain(int x1, int y1, int x2, int y2, int x3, int y3, int n) {
    if (n == 0) {
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
    } else {
        int mx1 = (x1 + x2) / 2 + rand() % (2 * n) - n;
        int my1 = (y1 + y2) / 2 + rand() % (2 * n) - n;
        int mx2 = (x2 + x3) / 2 + rand() % (2 * n) - n;
        int my2 = (y2 + y3) / 2 + rand() % (2 * n) - n;
        int mx3 = (x3 + x1) / 2 + rand() % (2 * n) - n;
        int my3 = (y3 + y1) / 2 + rand() % (2 * n) - n;

        drawMountain(x1, y1, mx1, my1, mx3, my3, n - 1);
        drawMountain(mx1, my1, x2, y2, mx2, my2, n - 1);
        drawMountain(mx3, my3, mx2, my2, x3, y3, n - 1);
    }
}

int main() {
    // Set initial vertices of the triangle
    int x1 = 100, y1 = 400;
    int x2 = 300, y2 = 200;
    int x3 = 500, y3 = 400;
     int n;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set random seed
    srand(time(NULL));

    

    // Number of iterations
   
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    // Draw mountain recursively
    setcolor(GREEN);
    drawMountain(x1, y1, x2, y2, x3, y3, n);

    getch();
    closegraph();
    return 0;
}
//10