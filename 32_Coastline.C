#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

// Function to draw fractal coastline
void drawCoastline(int x1, int y1, int x2, int y2, int n) {
    if (n == 0) {
        line(x1, y1, x2, y2);
    } else {
        int dx = x2 - x1;
        int dy = y2 - y1;

        // Calculate midpoints with some randomness
        int mx = (x1 + x2) / 2 + rand() % (2 * n) - n;
        int my = (y1 + y2) / 2 + rand() % (2 * n) - n;

        drawCoastline(x1, y1, mx, my, n - 1);
        drawCoastline(mx, my, x2, y2, n - 1);
    }
}

int main() {
     // Set initial endpoints of coastline
    int x1 = 100, y1 = 400;
    int x2 = 500, y2 = 400;
     int n;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set random seed
    srand(time(NULL));

   

    // Number of iterations
   
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    // Draw coastline recursively
    drawCoastline(x1, y1, x2, y2, n);

    getch();
    closegraph();
    return 0;
}
 //8