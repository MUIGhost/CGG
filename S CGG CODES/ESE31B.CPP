#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h> // Include math.h for round function
#include <dos.h>  // Include dos.h for delay function

// Pre-defined 5-sided polygon vertices
int pentagonX[] = {200, 250, 350, 400, 300};
int pentagonY[] = {350, 200, 200, 350, 400};
int numPentagonPoints = sizeof(pentagonX) / sizeof(pentagonX[0]);

double round(double x) {
    return floor(x + 0.5);
}

// Function to evaluate a point on the Bezier curve using de Casteljau's algorithm
void evaluateBezierPoint(int *x, int *y, int *controlPointsX, int *controlPointsY, int numPoints, float t) {
    int *tempX = (int *)malloc(numPoints * sizeof(int));
    int *tempY = (int *)malloc(numPoints * sizeof(int));

    // Initialize temporary arrays with control points
    for (int i = 0; i < numPoints; i++) {
        tempX[i] = controlPointsX[i];
        tempY[i] = controlPointsY[i];
    }

    // Apply de Casteljau's algorithm recursively
    for (int r = 1; r < numPoints; r++) {
        for (int i = 0; i < numPoints - r; i++) {
            tempX[i] = round((1 - t) * tempX[i] + t * tempX[i + 1]);
            tempY[i] = round((1 - t) * tempY[i] + t * tempY[i + 1]);
        }
    }

    // Assign the final evaluated point
    *x = tempX[0];
    *y = tempY[0];

    // Free temporary arrays
    free(tempX);
    free(tempY);
}

// Function to draw Bezier curve using midpoint method
void drawBezierCurve(int numPoints, int *controlPointsX, int *controlPointsY) {
    float t;
    int prevX, prevY;
    for (t = 0.0; t <= 1.0; t += 0.001) {
        int x_pixel, y_pixel;
        evaluateBezierPoint(&x_pixel, &y_pixel, controlPointsX, controlPointsY, numPoints, t);
        if (t > 0.0) {
            line(prevX, prevY, x_pixel, y_pixel);
        }
        prevX = x_pixel;
        prevY = y_pixel;
    }
}

// Function to draw pre-defined polygon
void drawPolygon(int *x, int *y, int numPoints) {
    for (int i = 0; i < numPoints - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[numPoints - 1], y[numPoints - 1], x[0], y[0]); // Connect the last point to the first to close the polygon
}

int main() {
    int gd = DETECT, gm;
    int numPoints;

    printf("Enter the number of control points (n >= 2): ");
    scanf("%d", &numPoints);

    if (numPoints < 2) {
        printf("Invalid input. Number of control points must be at least 2.\n");
        return 1;
    }

    int *x = (int *)malloc(numPoints * sizeof(int));
    int *y = (int *)malloc(numPoints * sizeof(int));

    printf("Enter the coordinates of control points:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("Control Point %d (x, y): ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    // Draw pre-defined polygon
    drawPolygon(pentagonX, pentagonY, numPentagonPoints);

    // Draw Bezier curve using midpoint method
    drawBezierCurve(numPoints, x, y);

    delay(5000);
    closegraph();

    free(x);
    free(y);
    return 0;
}
