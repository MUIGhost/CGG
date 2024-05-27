#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <stdio.h>
#define MIN_SEGMENT_LENGTH 5

float calculateLength(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}
void kochCurve(int x1, int y1, int x2, int y2, int depth) {
    float length = calculateLength(x1, y1, x2, y2);
    if (depth == 0 || length < MIN_SEGMENT_LENGTH) {
	drawLine(x1, y1, x2, y2);
    } else {
	int deltaX = x2 - x1, deltaY = y2 - y1;
	int x3 = x1 + deltaX / 3, y3 = y1 + deltaY / 3;
	int x4 = x1 + 2 * deltaX / 3, y4 = y1 + 2 * deltaY / 3;
	int x5 = (int)(x1 + (x4 - x1) * cos(M_PI / 3) - (y4 - y1) * sin(M_PI / 3));
	int y5 = (int)(y1 + (x4 - x1) * sin(M_PI / 3) + (y4 - y1) * cos(M_PI / 3));

	kochCurve(x1, y1, x3, y3, depth - 1);
	kochCurve(x3, y3, x5, y5, depth - 1);
	kochCurve(x5, y5, x4, y4, depth - 1);
	kochCurve(x4, y4, x2, y2, depth - 1);
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	int centerX = 320, centerY = 240, radius = 100, numArms = 6, armAngle = 360 / numArms;
	drawLine(centerX - radius, centerY, centerX + radius, centerY);
	for (int i = 0; i < numArms; i++) {
	    int x1 = centerX, y1 = centerY;
	    int x2 = centerX + (int)(radius * cos(M_PI * 2 * i / numArms));
	    int y2 = centerY + (int)(radius * sin(M_PI * 2 * i / numArms));
	    kochCurve(x1, y1, x2, y2, 4);
	}
getchar();
return 0;
}