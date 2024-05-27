#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include<conio.h>

// Define the clipping window
const int x_min = 100, y_min = 100, x_max = 400, y_max = 300;

// Function to draw the clipping window
void drawWindow() {
    rectangle(x_min, y_min, x_max, y_max);
}

// Function to check if a point is inside the clipping window
int isInside(int x, int y) {
    return (x >= x_min && x <= x_max && y >= y_min && y <= y_max);
}

// Function to perform the midpoint subdivision for clipping
void midPointSubdivision(int x1, int y1, int x2, int y2) {
    // Base case: if both points are inside the window, draw the line
    if (isInside(x1, y1) && isInside(x2, y2)) {
	line(x1, y1, x2, y2);
	return;
    }

    // Base case: if the line segment is entirely outside the window, do nothing
    if ((x1 < x_min && x2 < x_min) || (x1 > x_max && x2 > x_max) ||
	(y1 < y_min && y2 < y_min) || (y1 > y_max && y2 > y_max)) {
	return;
    }


    // Calculate the midpoint
    int x_mid = (x1 + x2) / 2;
    int y_mid = (y1 + y2) / 2;

    // Check for termination: if the midpoint is the same as one of the endpoints
    if (x_mid == x1 && y_mid == y1 || x_mid == x2 && y_mid == y2) {
	// Perform Cohen-Sutherland style clipping for the remaining part
	if (isInside(x1, y1)) {
	    if (x2 < x_min) x2 = x_min;
	    if (x2 > x_max) x2 = x_max;
	    if (y2 < y_min) y2 = y_min;
	    if (y2 > y_max) y2 = y_max;
	} else {
	    if (x1 < x_min) x1 = x_min;
	    if (x1 > x_max) x1 = x_max;
	    if (y1 < y_min) y1 = y_min;
	    if (y1 > y_max) y1 = y_max;
	}
	if (isInside(x1, y1) && isInside(x2, y2)) {
	    line(x1, y1, x2, y2);
	}
	return;
    }

    // Recursive subdivision
    midPointSubdivision(x1, y1, x_mid, y_mid);
    midPointSubdivision(x_mid, y_mid, x2, y2);
}

int main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the clipping window
    setcolor(WHITE);
    drawWindow();

    // Draw lines partially inside and partially outside
    setcolor(BLUE);
    line(150, 150, 300, 350);
    line(250, 50, 400, 250);
    line(100, 250, 250, 450);
    line(400, 100, 550, 300);

    // Wait for user input
    getch();

    // Clear the screen
    cleardevice();

    // Draw the clipping window again
    setcolor(WHITE);
    drawWindow();

    // Perform and draw the clipped lines using Midpoint Subdivision algorithm
    setcolor(GREEN);
    midPointSubdivision(150, 150, 300, 350);
    midPointSubdivision(250, 50, 400, 250);
    midPointSubdivision(100, 250, 250, 450);
    midPointSubdivision(400, 100, 550, 300);

    // Wait for user input before closing the graphics window
    getch();
    closegraph();
    return 0;
}
