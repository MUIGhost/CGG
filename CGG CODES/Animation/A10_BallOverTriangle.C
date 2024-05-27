#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to draw a circle
void drawCircle(int xc, int yc, int radius) {
    circle(xc, yc, radius);
}

// Function to calculate distance between two points
float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to move the circle along the edge of the triangle
void moveAlongTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float *cx, float *cy, float *target_x, float *target_y, float step) {
    // Check if the target is reached
    if (distance(*cx, *cy, *target_x, *target_y) < step) {
	// Set the next target point
	if (*target_x == x1 && *target_y == y1) {
	    *target_x = x2;
	    *target_y = y2;
	} else if (*target_x == x2 && *target_y == y2) {
	    *target_x = x3;
	    *target_y = y3;
	} else {
	    *target_x = x1;
	    *target_y = y1;
	}
    }

    // Move towards the target
    *cx += (*target_x - *cx) * step;
    *cy += (*target_y - *cy) * step;
}

int main() {
    int gd = DETECT, gm;
    int xc = 320, yc = 240; // Center of the large triangle
    int sideLength = 150;    // Length of each side of the triangle
    float angle = 0.0;       // Initial angle for orientation of the triangle
    float small_x, small_y;  // Initial position of the small circle
    float target_x, target_y; // Target position for the small circle
    float step = 0.5;       // Step size for movement
    int smallRadius = 10;    // Radius of the small circle
    float x1 = xc - sideLength / 2, y1 = yc + sideLength * sqrt(3) / 2;
    float x2 = xc + sideLength, y2 = yc + sideLength * sqrt(3) / 2;
    float x3 = xc + sideLength / 2, y3 = yc - sideLength * sqrt(3) / 2;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Calculate the initial position of the small circle (resting on vertex)

    small_x = x1;
    small_y = y1;
    target_x = x2;
    target_y = y2;

    while (!kbhit()) {
	cleardevice();

	// Draw the large triangle
	drawTriangle(x1, y1, x2, y2, x3, y3);

	// Draw the small circle
	drawCircle(small_x, small_y, smallRadius);

	// Move the small circle along the edge of the triangle
	moveAlongTriangle(x1, y1, x2, y2, x3, y3, &small_x, &small_y, &target_x, &target_y, step);

	delay(100);
    }

    closegraph();
    return 0;
}
