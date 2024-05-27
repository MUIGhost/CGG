#include <stdio.h>
#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, const char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 + 10, y1 + 10, label);  // Adjusted text placement
}

// Function to perform translation of a point
void translatePoint(int *x, int *y, int dx, int dy) {
    *x += dx;
    *y += dy;
}

// Function to draw the original and translated triangles
void drawTranslatedTriangles(int x1, int y1, int x2, int y2, int x3, int y3, int dx1, int dy1, int dx2, int dy2) {
    int x1_trans1 = x1, y1_trans1 = y1;
    int x2_trans1 = x2, y2_trans1 = y2;
    int x3_trans1 = x3, y3_trans1 = y3;

    // Perform first translation by (dx1, dy1) and then by (dx2, dy2)
    translatePoint(&x1_trans1, &y1_trans1, dx1, dy1);
    translatePoint(&x2_trans1, &y2_trans1, dx1, dy1);
    translatePoint(&x3_trans1, &y3_trans1, dx1, dy1);
    translatePoint(&x1_trans1, &y1_trans1, dx2, dy2);
    translatePoint(&x2_trans1, &y2_trans1, dx2, dy2);
    translatePoint(&x3_trans1, &y3_trans1, dx2, dy2);
    drawTriangle(x1_trans1, y1_trans1, x2_trans1, y2_trans1, x3_trans1, y3_trans1, RED, "Translation by (dx1, dy1) and (dx2, dy2)");
    getch(); // Wait for user to press Enter

    // Reset to original position
    x1_trans1 = x1; y1_trans1 = y1;
    x2_trans1 = x2; y2_trans1 = y2;
    x3_trans1 = x3; y3_trans1 = y3;

    // Perform first translation by (dx2, dy2) and then by (dx1, dy1)
    translatePoint(&x1_trans1, &y1_trans1, dx2, dy2);
    translatePoint(&x2_trans1, &y2_trans1, dx2, dy2);
    translatePoint(&x3_trans1, &y3_trans1, dx2, dy2);
    translatePoint(&x1_trans1, &y1_trans1, dx1, dy1);
    translatePoint(&x2_trans1, &y2_trans1, dx1, dy1);
    translatePoint(&x3_trans1, &y3_trans1, dx1, dy1);
    drawTriangle(x1_trans1, y1_trans1, x2_trans1, y2_trans1, x3_trans1, y3_trans1, GREEN, "Translation by (dx2, dy2) and (dx1, dy1)");
    getch(); // Wait for user to press Enter
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define the initial vertices of the triangle
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 200;

    // Draw the original triangle in blue
    drawTriangle(x1, y1, x2, y2, x3, y3, BLUE, "Original");
    getch(); // Wait for user to press Enter

    // Define the translation distances
    int dx1 = 50, dy1 = 30;
    int dx2 = 30, dy2 = 40;

    // Draw the translated triangles
    drawTranslatedTriangles(x1, y1, x2, y2, x3, y3, dx1, dy1, dx2, dy2);

    closegraph();
    return 0;
}
