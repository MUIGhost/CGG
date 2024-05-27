#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Function to implement the DDA algorithm for line drawing
void dda(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel((int)x, (int)y, WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

// Function to implement the Boundary Fill algorithm
void boundaryFill(int x, int y, int fillColor, int borderColor) {
    int currentColor = getpixel(x, y);
    if (currentColor != borderColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill(x + 1, y, fillColor, borderColor);
        boundaryFill(x - 1, y, fillColor, borderColor);
        boundaryFill(x, y + 1, fillColor, borderColor);
        boundaryFill(x, y - 1, fillColor, borderColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Define the vertices of the convex polygon
    int x1 = 220, y1 = 220;
    int x2 = 260, y2 = 220;
    int x3 = 280, y3 = 260;
    int x4 = 240, y4 = 280;
    int x5 = 200, y5 = 260;

    // Draw the edges of the polygon using DDA
    dda(x1, y1, x2, y2);
    dda(x2, y2, x3, y3);
    dda(x3, y3, x4, y4);
    dda(x4, y4, x5, y5);
    dda(x5, y5, x1, y1);

    // Call the Boundary Fill function to fill the polygon
    boundaryFill(240, 240, GREEN, WHITE); // Starting point should be inside the polygon

    getch();
    closegraph();
    return 0;
}
