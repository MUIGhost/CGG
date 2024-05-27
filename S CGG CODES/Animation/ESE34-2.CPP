#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
const int PI=3.148;
void moveBallBetweenTriangles() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the big circle
    int big_circle_x = 300, big_circle_y = 200, big_circle_radius = 100;
    circle(big_circle_x, big_circle_y, big_circle_radius);

    // Parameters for the small circle
    int small_circle_radius = 15;
    double angle = 270; // Start from top position

    // Calculate the starting position of the small circle
    int small_circle_x = big_circle_x + (big_circle_radius - small_circle_radius) * cos(angle * PI / 180);
    int small_circle_y = big_circle_y + (big_circle_radius - small_circle_radius) * sin(angle * PI / 180);

    while (!kbhit()) {
	// Clear previous position of the small circle
	cleardevice();

	// Draw the big circle
	circle(big_circle_x, big_circle_y, big_circle_radius);

	// Draw the small circle
	circle(small_circle_x, small_circle_y, small_circle_radius);

	// Increment the angle for the next position
	angle += 1;
	if (angle >= 360)
	    angle = 0;

	// Update the position of the small circle using parametric equations
	small_circle_x = big_circle_x + (big_circle_radius - small_circle_radius) * cos(angle * PI / 180);
	small_circle_y = big_circle_y + (big_circle_radius - small_circle_radius) * sin(angle * PI / 180);

	delay(50);

}

    closegraph();

}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
	    moveBallBetweenTriangles();
getch();
return 0;
}
