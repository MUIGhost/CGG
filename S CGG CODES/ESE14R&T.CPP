#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159265

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to perform 2D rotation of a point
void rotatePoint(int *x, int *y, int cx, int cy, float angle) {
    float radians = angle * PI / 180.0;
    int newX = cx + (*x - cx) * cos(radians) - (*y - cy) * sin(radians);
    int newY = cy + (*x - cx) * sin(radians) + (*y - cy) * cos(radians);
    *x = newX;
    *y = newY;
}

// Function to perform 2D rotation of a triangle
void rotateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int angle) {
    int cx = (*x1 + *x2 + *x3) / 3;
    int cy = (*y1 + *y2 + *y3) / 3;

    rotatePoint(x1, y1, cx, cy, angle);
    rotatePoint(x2, y2, cx, cy, angle);
    rotatePoint(x3, y3, cx, cy, angle);
}

// Function to perform 2D translation of a triangle
void translateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int tx, int ty) {
    *x1 += tx;
    *y1 += ty;
    *x2 += tx;
    *y2 += ty;
    *x3 += tx;
    *y3 += ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define the initial vertices of the triangle
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 200;

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    int choice;
    int angle, tx, ty;

    // Continuously ask for transformations
    while (1) {
        printf("Choose transformation:\n");
        printf("1. Rotate\n");
        printf("2. Translate\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter rotation angle: ");
                scanf("%d", &angle);
                rotateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, angle);
                cleardevice(); // Clear the previous triangle
                drawTriangle(x1, y1, x2, y2, x3, y3); // Draw the rotated triangle
                break;
            case 2:
                printf("Enter translation values (tx ty): ");
                scanf("%d %d", &tx, &ty);
                translateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, tx, ty);
                cleardevice(); // Clear the previous triangle
                drawTriangle(x1, y1, x2, y2, x3, y3); // Draw the translated triangle
                break;
            case 3:
                closegraph();
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
