#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Function to implement the DDA algorithm for line drawing
void dda(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xInc;
        y += yInc;
    }
}

// Function to implement the Scan Line Fill algorithm
void scanLineFill(int x[], int y[], int numVertices) {
    int i, j, k;
    int ymin = y[0], ymax = y[0];
    for (i = 1; i < numVertices; i++) {
        if (y[i] < ymin) ymin = y[i];
        if (y[i] > ymax) ymax = y[i];
    }

    int interX[1000];
    for (int scanline = ymin; scanline <= ymax; scanline++) {
        k = 0;
        for (i = 0; i < numVertices; i++) {
            j = (i + 1) % numVertices;
            if ((y[i] <= scanline && y[j] > scanline) || (y[j] <= scanline && y[i] > scanline)) {
                interX[k++] = x[i] + (scanline - y[i]) * (x[j] - x[i]) / (y[j] - y[i]);
            }
        }

        for (i = 0; i < k - 1; i++) {
            for (j = 0; j < k - 1 - i; j++) {
                if (interX[j] > interX[j + 1]) {
                    int temp = interX[j];
                    interX[j] = interX[j + 1];
                    interX[j + 1] = temp;
                }
            }
        }

        for (i = 0; i < k; i += 2) {
            dda(interX[i], scanline, interX[i + 1], scanline);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Define the vertices of the concave polygon
    int x[] = {150, 100, 250, 300, 200};
    int y[] = {50, 200, 200, 100, 100};
    int numVertices = sizeof(x) / sizeof(x[0]);

    // Draw the edges of the polygon using DDA
    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        dda(x[i], y[i], x[j], y[j]);
    }

    // Call the Scan Line Fill function to fill the polygon
    scanLineFill(x, y, numVertices);

    getch();
    closegraph();
    return 0;
}
