#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include<conio.h>

// Define region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define the clipping window
const int x_min = 100, y_min = 100, x_max = 400, y_max = 300;

// Function to draw the clipping window
void drawWindow() {
    rectangle(x_min, y_min, x_max, y_max);
}

// Function to compute the region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < x_min)
	code |= LEFT;
    else if (x > x_max)
	code |= RIGHT;
    if (y < y_min)
	code |= BOTTOM;
    else if (y > y_max)
	code |= TOP;
    return code;
}


// Function implementing Cohen-Sutherland algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
	if ((code1 == 0) && (code2 == 0)) {
	    accept = 1;
	    break;
	} else if (code1 & code2) {
	    break;
	} else {
	    int code_out;
	    int x, y;

	    if (code1 != 0)
		code_out = code1;
	    else
		code_out = code2;

	    if (code_out & TOP) {
		x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
		y = y_max;
	    } else if (code_out & BOTTOM) {
		x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
		y = y_min;
	    } else if (code_out & RIGHT) {
		y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
		x = x_max;
	    } else if (code_out & LEFT) {
		y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
		x = x_min;
	    }

	    if (code_out == code1) {
		x1 = x;
		y1 = y;
		code1 = computeCode(x1, y1);
	    } else {
		x2 = x;
		y2 = y;
		code2 = computeCode(x2, y2);
	    }
	}
    }

    if (accept) {
	setcolor(GREEN);
	line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    // Draw the clipping window
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

    // Draw the window again
    setcolor(WHITE);
    drawWindow();

    // Clip lines using Cohen-Sutherland algorithm and display the result
    cohenSutherlandClip(150, 150, 300, 350);
    cohenSutherlandClip(250, 50, 400, 250);
    cohenSutherlandClip(100, 250, 250, 450);
    cohenSutherlandClip(400, 100, 550, 300);

    // Wait for user to close the graphics window
    getch();
    closegraph();

    return 0;
}
