#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>  // For getch function
#include <time.h>
#include<dos.h>

#define PI 3.14159265

// Function to draw a line using Bresenham's algorithm
void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
	putpixel(x1, y1, WHITE);
	if (x1 == x2 && y1 == y2) break;
	int e2 = 2 * err;
	if (e2 > -dy) {
	    err -= dy;
	    x1 += sx;
	}
	if (e2 < dx) {
	    err += dx;
	    y1 += sy;
	}
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

// Function to draw the clock
void drawClock() {
    int gd = DETECT, gm;
    int hour, minute, second;
    int x0, y0, hour_x, hour_y, minute_x, minute_y, second_x, second_y;
    int radius = 100;
    float hour_angle, minute_angle, second_angle;

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    x0 = getmaxx() / 2;  // Center of the clock
    y0 = getmaxy() / 2;

    while (!kbhit()) {
	// Get current time
	time_t raw_time;
	struct tm *current_time;
	time(&raw_time);
	current_time = localtime(&raw_time);

	// Extract hours, minutes, and seconds
	hour = current_time->tm_hour;
	minute = current_time->tm_min;
	second = current_time->tm_sec;

	// Calculate angles for hour, minute, and second hands
	hour_angle = (hour % 12 + minute / 60.0) * (360 / 12) * (PI / 180) - PI / 2;
	minute_angle = (minute + second / 60.0) * (360 / 60) * (PI / 180) - PI / 2;
	second_angle = second * (360 / 60) * (PI / 180) - PI / 2;

	// Calculate positions for hour, minute, and second hands
	hour_x = cos(hour_angle) * (radius - 20) + x0;
	hour_y = sin(hour_angle) * (radius - 20) + y0;

	minute_x = cos(minute_angle) * (radius - 10) + x0;
	minute_y = sin(minute_angle) * (radius - 10) + y0;

	second_x = cos(second_angle) * radius + x0;
	second_y = sin(second_angle) * radius + y0;

	// Clear screen
	cleardevice();

	// Draw clock face using Bresenham's circle algorithm
	drawCircleBresenham(x0, y0, radius);
	outtextxy(x0 - 5, y0 - radius - 20, "12");
	outtextxy(x0 + radius + 10, y0 - 5, "3");
	outtextxy(x0 - 5, y0 + radius + 10, "6");
	outtextxy(x0 - radius - 20, y0 - 5, "9");

	// Draw hour, minute, and second hands using Bresenham's line algorithm
	drawLineBresenham(x0, y0, hour_x, hour_y);
	drawLineBresenham(x0, y0, minute_x, minute_y);
	drawLineBresenham(x0, y0, second_x, second_y);

	// Delay to update every second
	delay(1000);
    }

    closegraph();
}

int main() {
    drawClock();
    return 0;
}
