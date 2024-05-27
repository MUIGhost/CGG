#include <graphics.h>
#include <conio.h>

// Bresenham's line drawing algorithm
void bresenhamLine(int x1, int y1, int x2, int y2) {
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


// Edge Fill algorithm
void edgeFill(int *points, int numEdges, int fillColor) {
    int yMin = points[1], yMax = points[1],i,j,x,y;

    // Find the minimum and maximum y-coordinates
    for (i = 1; i < numEdges; i++) {
	if (points[2 * i + 1] < yMin)
	    yMin = points[2 * i + 1];
	if (points[2 * i + 1] > yMax)
	    yMax = points[2 * i + 1];
    }

    // Scan each horizontal line and fill the pixels between edges
    for (y = yMin; y <= yMax; y++) {
	int xIntersections[10];
	int numIntersections = 0;

	// Find intersections of scan line with edges
	for (i = 0; i < numEdges; i++) {
	    int x1 = points[2 * i], y1 = points[2 * i + 1];
	    int x2 = points[2 * ((i + 1) % numEdges)], y2 = points[2 * ((i + 1) % numEdges) + 1];

	    if ((y1 <= y && y < y2) || (y2 <= y && y < y1)) {
		// Calculate x-coordinate of intersection
		int xIntersection = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
		xIntersections[numIntersections++] = xIntersection;
	    }
	}

	// Sort the intersection points
	for (i = 0; i < numIntersections - 1; i++) {
	    for (j = i + 1; j < numIntersections; j++) {
		if (xIntersections[i] > xIntersections[j]) {
		    int temp = xIntersections[i];
		    xIntersections[i] = xIntersections[j];
		    xIntersections[j] = temp;
		}
	    }
	}

	// Fill the horizontal gaps between intersections
	for (i = 0; i < numIntersections; i += 2) {
	    for (x = xIntersections[i]; x <= xIntersections[i + 1]; x++) {
                putpixel(x, y, fillColor);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm,i;
int points[] = {150, 150, 250, 150, 225, 200, 200, 250, 175, 200};
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Vertices of the convex polygon
    

    // Draw the edges of the polygon
    for (i = 0; i < 8; i += 2) {
        bresenhamLine(points[i], points[i + 1], points[(i + 2) % 10], points[(i + 3) % 10]);
    }

    // Fill the polygon using the edge fill algorithm
    edgeFill(points, 5, YELLOW);

    getch();
    closegraph();
    return 0;
}
