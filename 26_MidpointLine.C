#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define INSIDE 0 // Inside of the clip window
#define LEFT 1   // Left side of the clip window
#define RIGHT 2  // Right side of the clip window
#define BOTTOM 4 // Below the clip window
#define TOP 8    // Above the clip window

#define X_MIN 100
#define Y_MIN 100
#define X_MAX 300
#define Y_MAX 300

// Function to determine the region code for a point
int computeRegionCode(int x, int y) {
    int code = INSIDE;
    if (x < X_MIN)
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;
    if (y < Y_MIN)
        code |= BOTTOM;
    else if (y > Y_MAX)
        code |= TOP;
    return code;
}

// Function to clip a line segment using midpoint algorithm
void midpointLineClipping(int x1, int y1, int x2, int y2) {
    int code1 = computeRegionCode(x1, y1);
    int code2 = computeRegionCode(x2, y2);
    int accept = 0;

    while (1) {
        if (!(code1 | code2)) { // Both endpoints are inside the window
            accept = 1;
            break;
        } else if (code1 & code2) { // Both endpoints are outside the window
            break;
        } else {
            int x, y;
            int codeOut = code1 ? code1 : code2;

            if (codeOut & TOP) { // Point is above the clip window
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) { // Point is below the clip window
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) { // Point is to the right of the clip window
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) { // Point is to the left of the clip window
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeRegionCode(x2, y2);
            }
        }
    }

    // If the line segment is accepted, draw it
    if (accept) {
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int x1, y1, x2, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw clipping window
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    // Draw line segment
    printf("Enter coordinates of line (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    setcolor(BLUE);
    line(x1, y1, x2, y2);

    // Clip the line segment
    midpointLineClipping(x1, y1, x2, y2);

    getch();
    cleardevice();

    // Draw clipping window again
    printf("Clipped Figure:");
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
    midpointLineClipping(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
//50 150 350 250