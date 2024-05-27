#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to perform X shear transformation
void shearX(int *x, int y, float shear_factor) {
    *x += shear_factor * y;
}

// Function to perform Y shear transformation
void shearY(int x, int *y, float shear_factor) {
    *y += shear_factor * x;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    float shear_factor_x;
    float shear_factor_y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");



    // Get user input for triangle coordinates
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Draw original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Perform X shear transformation

    printf("Enter X shear factor: ");
    scanf("%f", &shear_factor_x);
    shearX(&x1, y1, shear_factor_x);
    shearX(&x2, y2, shear_factor_x);
    shearX(&x3, y3, shear_factor_x);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    // Reset triangle to original position
    printf("Resetting triangle to original position...\n");
    x1 = x1 - shear_factor_x * y1;
    x2 = x2 - shear_factor_x * y2;
    x3 = x3 - shear_factor_x * y3;

    // Perform Y shear transformation

    printf("Enter Y shear factor: ");
    scanf("%f", &shear_factor_y);
    shearY(x1, &y1, shear_factor_y);
    shearY(x2, &y2, shear_factor_y);
    shearY(x3, &y3, shear_factor_y);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();

    closegraph();
    return 0;
}
//100 100 200 100 150 200
//1.0
//1.0