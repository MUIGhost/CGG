#include <graphics.h>
#include <conio.h>
#include <math.h>

// Function to implement Bresenham's Line Drawing Algorithm
void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy,e2;

    while (1) {
	putpixel(x1, y1, WHITE);
	if (x1 == x2 && y1 == y2) break;
	e2 = 2 * err;
	if (e2 > -dy) { err -= dy; x1 += sx; }
	if (e2 < dx) { err += dx; y1 += sy; }
    }
}

// Function to implement the Fence Fill Algorithm
void fenceFill(int *points, int numEdges, int fillColor) {
    int i, j, temp, x1, y1, x2, y2, minX, maxX, minY, maxY;



    // Find bounding box of the polygon
    minX = maxX = points[0];
    minY = maxY = points[1];
    for (i = 2; i < numEdges * 2; i += 2) {
	if (points[i] < minX) minX = points[i];
	if (points[i] > maxX) maxX = points[i];
	if (points[i + 1] < minY) minY = points[i + 1];
	if (points[i + 1] > maxY) maxY = points[i + 1];
    }


    // Fence fill algorithm
    for (y1 = minY; y1 <= maxY; y1++) {
	int isInside = 0;
	for (x1 = minX; x1 <= maxX; x1++) {
	    if (getpixel(x1, y1) == WHITE) {
		isInside = !isInside;
	    }
	    if (isInside) {
		putpixel(x1, y1, fillColor);
		delay(1);  // Add delay for visualization
	    }
	}
    }
}

int main() {
    int gd = DETECT, gm, i;
    int poly[] = {150, 150, 250, 150, 200, 200, 250, 250, 150, 250, 200, 200};
    int numEdges = sizeof(poly) / (2 * sizeof(int));

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the polygon using Bresenham's line algorithm
    for (i = 0; i < (numEdges - 1) * 2; i += 2) {
        bresenhamLine(poly[i], poly[i + 1], poly[i + 2], poly[i + 3]);
    }
    // Close the polygon
    bresenhamLine(poly[(numEdges - 1) * 2], poly[(numEdges - 1) * 2 + 1], poly[0], poly[1]);

    // Fill the polygon using Fence Fill algorithm
    fenceFill(poly, numEdges, YELLOW);

    getch();
    closegraph();
    return 0;
}
