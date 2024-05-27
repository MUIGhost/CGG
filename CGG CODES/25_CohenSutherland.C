#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Define region codes for the four regions
#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

// Define the clipping window coordinates
#define X_MIN 100
#define Y_MIN 100
#define X_MAX 300
#define Y_MAX 300

// Function to compute the region code for a point
int computeRegionCode(int x, int y) {
    int code = INSIDE;
    if (x < X_MIN) // to the left of clip window
        code |= LEFT;
    else if (x > X_MAX) // to the right of clip window
        code |= RIGHT;
    if (y < Y_MIN) // below the clip window
        code |= BOTTOM;
    else if (y > Y_MAX) // above the clip window
        code |= TOP;
    return code;
}

// Function to clip a line segment
void cohenSutherland(int x1, int y1, int x2, int y2) {
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
            // Partially inside, partially outside
            int x, y;
            int codeOut = code1 ? code1 : code2;
            // Find the intersection point
            if (codeOut & TOP) { // point is above the clip rectangle
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) { // point is below the clip rectangle
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) { // point is to the right of the clip rectangle
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) { // point is to the left of the clip rectangle
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            // Replace the outside point with intersection point
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
    cohenSutherland(x1, y1, x2, y2);

    getch();
    cleardevice();

    // Draw clipping window again
    printf("Clipped Figure:");
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
    cohenSutherland(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
//50 150 250 350
