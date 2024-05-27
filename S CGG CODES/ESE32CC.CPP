#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <time.h>

// Function to calculate the distance between two points
float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to draw the fractal line (coastline) using midpoint displacement method
void drawFractalLine(int x1, int y1, int x2, int y2, int depth, float displacement) {
    if (depth == 0 || distance(x1, y1, x2, y2) < 1) {
        line(x1, y1, x2, y2);
    } else {
        // Calculate midpoint and displace it randomly
        int mx = (x1 + x2) / 2;
        int my = (y1 + y2) / 2 + (rand() % (int)(2 * displacement)) - displacement;

        // Reduce displacement for next iteration
        displacement /= 2.0;

        // Recursively draw the two halves
        drawFractalLine(x1, y1, mx, my, depth - 1, displacement);
        drawFractalLine(mx, my, x2, y2, depth - 1, displacement);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Initialize random number generator
    srand(time(0));

    // Initial line segment
    int x1 = 100, y1 = 300;
    int x2 = 500, y2 = 300;

    int depth;
    printf("Enter the number of iterations: ");
    scanf("%d", &depth);

    // Draw the fractal coastline
    drawFractalLine(x1, y1, x2, y2, depth, 100.0);

    getch();
    closegraph();

    return 0;
}
