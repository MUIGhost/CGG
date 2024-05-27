#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <time.h>
#include<conio.h>
#define MAX_ITERATIONS 6

// Function to get the midpoint with random displacement
void midpointDisplacement(int x1, int y1, int x2, int y2, int x3, int y3, int depth, float displacement) {
    if (depth == 0) {
        // Draw the triangle
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
    } else {
        // Calculate midpoints
        int mx1 = (x1 + x2) / 2;
        int my1 = (y1 + y2) / 2 + (rand() % (int)(2 * displacement)) - displacement;

        int mx2 = (x2 + x3) / 2;
        int my2 = (y2 + y3) / 2 + (rand() % (int)(2 * displacement)) - displacement;

        int mx3 = (x3 + x1) / 2;
        int my3 = (y3 + y1) / 2 + (rand() % (int)(2 * displacement)) - displacement;

        // Reduce displacement for next iteration
        displacement /= 2.0;

        // Recursively subdivide
        midpointDisplacement(x1, y1, mx1, my1, mx3, my3, depth - 1, displacement);
        midpointDisplacement(mx1, my1, x2, y2, mx2, my2, depth - 1, displacement);
        midpointDisplacement(mx3, my3, mx2, my2, x3, y3, depth - 1, displacement);
        midpointDisplacement(mx1, my1, mx2, my2, mx3, my3, depth - 1, displacement);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Initialize random number generator
    srand(time(0));

    // Initial triangle vertices
    int x1 = 320, y1 = 50;
    int x2 = 50, y2 = 450;
    int x3 = 590, y3 = 450;

    int depth;
    printf("Enter the number of iterations (1 to %d): ", MAX_ITERATIONS);
    scanf("%d", &depth);

    if (depth < 1 || depth > MAX_ITERATIONS) {
        printf("Invalid number of iterations.\n");
        closegraph();
        return 1;
    }

    // Draw the fractal mountain
    midpointDisplacement(x1, y1, x2, y2, x3, y3, depth, 100.0);

    getch();
    closegraph();

    return 0;
}
