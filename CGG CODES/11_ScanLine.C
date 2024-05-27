#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_POINTS 20
#define INT_MAX  32767
#define INT_MIN  (-32768)


// Structure to represent a point (x, y)
struct Point {
    int x, y;
};

// Function to draw a line using Bresenham's algorithm
void drawLine(int x1, int y1, int x2, int y2) {
       int dx = abs(x2 - x1);
int dy = abs(y2 - y1);
int sx = x1 < x2 ? 1 : -1;
int sy = y1 < y2 ? 1 : -1;
int err = dx - dy;
while (1) {
int e2;
putpixel(x1, y1, WHITE);
if (x1 == x2 && y1 == y2) break;
e2 = 2 * err;
if (e2 > -dy) { err -= dy; x1 += sx; }
if (e2 < dx) { err += dx; y1 += sy; }
}
}

// Function to fill a polygon using the Scanline Fill algorithm
void scanlineFill(struct Point poly[], int n) {
    int i, y, ymin, ymax, x1, y1, x2, y2,j;

    // Find the minimum and maximum y-coordinates of the polygon
    ymin = poly[0].y;
    ymax = poly[0].y;
    for (i = 1; i < n; i++) {
	if (poly[i].y < ymin)
	    ymin = poly[i].y;
	if (poly[i].y > ymax)
	    ymax = poly[i].y;
    }

    // For each scanline from ymin to ymax
    for (y = ymin; y <= ymax; y++) {
	int intersections[MAX_POINTS];
	int count = 0;

	// Find intersections with the polygon edges
	for (i = 0; i < n; i++) {
	    int j = (i + 1) % n;
	    y1 = poly[i].y;
	    y2 = poly[j].y;
	    if ((y1 < y && y2 >= y) || (y2 < y && y1 >= y)) {
		x1 = poly[i].x;
		x2 = poly[j].x;
		intersections[count++] = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
	    }
	}

	// Sort the intersections
	for (i = 0; i < count - 1; i++) {
	    for (j = 0; j < count - i - 1; j++) {
                if (intersections[j] > intersections[j + 1]) {
                    int temp = intersections[j];
                    intersections[j] = intersections[j + 1];
                    intersections[j + 1] = temp;
		}
            }
        }

        // Fill the scanline between pairs of intersections
        for (i = 0; i < count; i += 2) {
            drawLine(intersections[i], y, intersections[i + 1], y);
        }
    }
}

int main() {
    int gd = DETECT, gm,i;
    struct Point poly[] = {{100, 100}, {200, 100}, {250, 200}, {200, 300}, {100, 300}};
    int n = sizeof(poly) / sizeof(poly[0]);

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    // Draw the polygon
    for (i = 0; i < n; i++) {
        int j = (i + 1) % n;
        drawLine(poly[i].x, poly[i].y, poly[j].x, poly[j].y);
    }

    // Fill the polygon
    scanlineFill(poly, n);

    delay(5000);
    closegraph();

    return 0;
}
