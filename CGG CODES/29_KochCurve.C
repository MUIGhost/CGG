#include <graphics.h>
#include <stdlib.h>
#include <math.h>

// Function to draw a Koch curve
void koch(int x1, int y1, int x2, int y2, int iterations) {
    if (iterations == 0) {
        // Draw a line if iterations are exhausted
        line(x1, y1, x2, y2);
    } else {
        // Calculate the intermediate points
        int x3 = x1 + (x2 - x1) / 3;
        int y3 = y1 + (y2 - y1) / 3;
        int x4 = x1 + 2 * (x2 - x1) / 3;
        int y4 = y1 + 2 * (y2 - y1) / 3;
        int x = x3 + (x4 - x3) / 2 - (y4 - y3) * sqrt(3) / 2;
        int y = y3 + (y4 - y3) / 2 + (x4 - x3) * sqrt(3) / 2;

        // Recursively draw the segments
        koch(x1, y1, x3, y3, iterations - 1);
        koch(x3, y3, x, y, iterations - 1);
        koch(x, y, x4, y4, iterations - 1);
        koch(x4, y4, x2, y2, iterations - 1);
    }
}

int main() {
    int x1 = 100, y1 = 200, x2 = 500, y2 = 200;
    int iterations;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Set initial points of the Koch curve
    

    // Input the number of iterations
    
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    // Draw the Koch curve
    koch(x1, y1, x2, y2, iterations);

    getch();
    closegraph();
    return 0;
}

//3 or 4