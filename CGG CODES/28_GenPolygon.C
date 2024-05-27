#include <stdio.h>
#include <graphics.h>
#include<conio.h>

// Define clipping window coordinates
const int x_min = 100, y_min = 100, x_max = 400, y_max = 300;

// Function to draw the clipping window
void drawWindow() {
    rectangle(x_min, y_min, x_max, y_max);
}

// Function to check if a point is inside the clipping window
int inside(int x, int y, int edge) {
    if (edge == 1 && x >= x_min)
        return 1;
    if (edge == 2 && y <= y_max)
        return 1;
    if (edge == 3 && x <= x_max)
        return 1;
    if (edge == 4 && y >= y_min)
        return 1;
    return 0;
}

// Function to compute the intersection point of a polygon edge with a clipping window edge
void intersect(int x1, int y1, int x2, int y2, int edge, int* x, int* y) {
    switch (edge) {
        case 1: // Left edge
            *x = x_min;
            *y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
            break;
        case 2: // Top edge
            *x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
            *y = y_max;
            break;
        case 3: // Right edge
            *x = x_max;
            *y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
            break;
        case 4: // Bottom edge
            *x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
            *y = y_min;
            break;
    }
}

// Function to clip a polygon against a clipping window
void generalizedPolygonClipping(int poly[], int n) {
    int clipped[20]; // Clipped polygon vertices
    int k = 0; // Number of vertices in the clipped polygon
    int edge,i;

    for (edge = 1; edge <= 4; edge++) {
	int x_prev = poly[2 * n - 2];
	int y_prev = poly[2 * n - 1];

	for (i = 0; i < 2 * n; i += 2) {
	    int x = poly[i];
	    int y = poly[i + 1];

	    if (inside(x, y, edge)) {
		if (inside(x_prev, y_prev, edge)) {
		    // Both endpoints inside, add the current point to the output list
		    clipped[k++] = x;
		    clipped[k++] = y;
		} else {
		    // First point outside, second point inside, add intersection point to the output list
		    intersect(x_prev, y_prev, x, y, edge, &clipped[k], &clipped[k + 1]);
		    k += 2;
		    clipped[k++] = x;
		    clipped[k++] = y;
		}
	    } else if (inside(x_prev, y_prev, edge)) {
		// First point inside, second point outside, add intersection point to the output list
                intersect(x_prev, y_prev, x, y, edge, &clipped[k], &clipped[k + 1]);
                k += 2;
            }

            x_prev = x;
            y_prev = y;
        }

        // Copy the clipped polygon to the original array for the next iteration
	for (i = 0; i < k; i++) {
	    poly[i] = clipped[i];
	}
	n = k / 2;
	k = 0;
    }

    // Draw the clipped polygon
    setcolor(RED);
    drawpoly(n, clipped);
}

int main() {
     int poly[] = {150, 200, 300, 100, 400, 300, 250, 450,150,200};
    int n = sizeof(poly) / sizeof(poly[0]) / 2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    // Draw the clipping window
    printf("Original Figure:");
    drawWindow();

    // Define the polygon vertices (clockwise order)


    // Draw the original polygon
    setcolor(YELLOW);
    drawpoly(n, poly);

    getch();
    cleardevice();
    setcolor(WHITE);
    drawWindow();

    // Clip and draw the polygon against the clipping window
    printf("Clipped Polygon:");
    generalizedPolygonClipping(poly, n);

    getch();
    closegraph();
    return 0;
}
