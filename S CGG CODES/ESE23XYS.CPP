#include <stdio.h>
#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, const char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3, label); // Text at the centroid
}

// Function to perform X shear transformation on a triangle
void shearTriangleX(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float shearX) {
    *x1 = *x1 + shearX * (*y1);
    *x2 = *x2 + shearX * (*y2);
    *x3 = *x3 + shearX * (*y3);
}

// Function to perform Y shear transformation on a triangle
void shearTriangleY(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float shearY) {
    *y1 = *y1 + shearY * (*x1);
    *y2 = *y2 + shearY * (*x2);
    *y3 = *y3 + shearY * (*x3);
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
    getch();

    // Apply X shear transformation
    int x1_shearX = x1, y1_shearX = y1;
    int x2_shearX = x2, y2_shearX = y2;
    int x3_shearX = x3, y3_shearX = y3;
    float shearX = 1.0; // Shear factor along X-axis
    shearTriangleX(&x1_shearX, &y1_shearX, &x2_shearX, &y2_shearX, &x3_shearX, &y3_shearX, shearX);
    drawTriangle(x1_shearX, y1_shearX, x2_shearX, y2_shearX, x3_shearX, y3_shearX, RED, "Shear X");
    getch();

    // Apply Y shear transformation
    int x1_shearY = x1, y1_shearY = y1;
    int x2_shearY = x2, y2_shearY = y2;
    int x3_shearY = x3, y3_shearY = y3;
    float shearY = 1.0; // Shear factor along Y-axis
    shearTriangleY(&x1_shearY, &y1_shearY, &x2_shearY, &y2_shearY, &x3_shearY, &y3_shearY, shearY);
    drawTriangle(x1_shearY, y1_shearY, x2_shearY, y2_shearY, x3_shearY, y3_shearY, GREEN, "Shear Y");
    getch();

    closegraph();
    return 0;
}
