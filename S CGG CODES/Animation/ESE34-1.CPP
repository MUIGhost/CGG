#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include<dos.h>
#include <math.h>
#include <conio.h>  // For getch function

#define PI 3.14159265

// Function to draw a line using DDA algorithm
void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
	putpixel((x), (y), WHITE);
	x += xIncrement;
	y += yIncrement;
    }
}

// Function to draw a circle using Bresenham's algorithm
void drawCircleBresenham(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    while (y >= x) {
	putpixel(xc + x, yc + y, WHITE);
	putpixel(xc - x, yc + y, WHITE);
	putpixel(xc + x, yc - y, WHITE);
	putpixel(xc - x, yc - y, WHITE);
	putpixel(xc + y, yc + x, WHITE);
	putpixel(xc - y, yc + x, WHITE);
	putpixel(xc + y, yc - x, WHITE);
	putpixel(xc - y, yc - x, WHITE);
	x++;
	if (d > 0) {
	    y--;
	    d = d + 4 * (x - y) + 10;
	} else {
	    d = d + 4 * x + 6;
	}
    }
}

// Function to draw the pendulum
void drawPendulum(int x0, int y0, int x, int y) {
    // Clear the screen
    cleardevice();

    // Draw the horizon line
    drawLineDDA(0, y0, getmaxx(), y0);

    // Draw the pendulum line
    drawLineDDA(x0, y0, x, y);

    // Draw the pendulum ball
    drawCircleBresenham(x, y, 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x0 = getmaxx() / 2; // X-coordinate of the pivot point
    int y0 = getmaxy() / 4; // Y-coordinate of the pivot point
    int length = 200;       // Length of the pendulum

    float angle = PI / 4;    // Initial angle (45 degrees)
    float angularVelocity = 0.0;
    float angularAcceleration = 0.0;
    float damping = 0.999;   // Damping factor to simulate friction

    // Gravity constant
    float g = 0.1;

    while (!kbhit()) { // Continue the loop until a key is pressed
	// Calculate the angular acceleration
	angularAcceleration = (-1 * g / length) * sin(angle);

	// Update the angular velocity and angle
	angularVelocity += angularAcceleration;
	angularVelocity *= damping; // Apply damping
	angle += angularVelocity;

	// Calculate the new position of the pendulum ball
	int x = x0 + length * sin(angle);
	int y = y0 + length * cos(angle);

	// Draw the pendulum
	drawPendulum(x0, y0, x, y);

	// Introduce a delay to slow down the animation
	delay(20);
    }

    getch();
    closegraph();
    return 0;
}
