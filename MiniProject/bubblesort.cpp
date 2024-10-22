#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

// Class to handle the graphical representation of the bar chart
class BarGraph {
private:
    int* arr;   // Pointer to the array
    int size;   // Size of the array
    int left, top, width, gap;

public:
    // Constructor to initialize the bar graph settings
    BarGraph(int* arr, int size) {
        this->arr = arr;
        this->size = size;
        left = 50;
        top = 400;
        width = 40;
        gap = 10;
    }

    // Function to draw the array as bars with optional highlights for comparison
    void drawArray(int comparedIndex1 = -1, int comparedIndex2 = -1) {
        cleardevice();  // Clear the screen for redrawing

        int right, bottom;
        int xPos = left;

        for (int i = 0; i < size; i++) {
            right = xPos + width;
            bottom = top - arr[i];  // The height is based on the value of the array element

            if (i == comparedIndex1 || i == comparedIndex2) {
                setfillstyle(SOLID_FILL, RED);  // Highlight compared elements in red
            } else {
                setfillstyle(SOLID_FILL, WHITE);
            }

            bar(xPos, top, right, bottom);  // Draw the bar

            if (i == comparedIndex1 || i == comparedIndex2) {
                drawArrow(xPos + (width / 2), top + 10);  // Draw arrow below the compared bar
            }

            xPos += width + gap;  // Move to the next position for the next bar
        }
    }

    // Function to draw an arrow below a specific bar
    void drawArrow(int x, int y) {
        int arrowHeight = 30;  // Height of the arrow
        int arrowWidth = 10;   // Width of the arrow at its base

        line(x, y, x, y + arrowHeight);           // Vertical line going down
        line(x, y, x - arrowWidth, y + 10);       // Left diagonal line forming the pointer
        line(x, y, x + arrowWidth, y + 10);       // Right diagonal line forming the pointer
    }
};

// Class to handle bubble sort logic and animation
class BubbleSort {
private:
    int* arr;
    int size;
    BarGraph* barGraph;

public:
    // Constructor to initialize the array and BarGraph object
    BubbleSort(int* arr, int size, BarGraph* barGraph) {
        this->arr = arr;
        this->size = size;
        this->barGraph = barGraph;
    }

    // Slow swap function to add delay between swaps
    void slowSwap(int& a, int& b) {
        int temp = a;
        delay(500);  // Delay to show the swap animation more slowly
        a = b;
        delay(500);  // Further delay after swap
        b = temp;
    }

    // Function to perform bubble sort with animation
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                // Draw the current state of the array and highlight the compared elements
                barGraph->drawArray(j, j + 1);
                delay(500);  // Pause to see the comparison

                if (arr[j] > arr[j + 1]) {
                    // Swap and redraw with animation
                    slowSwap(arr[j], arr[j + 1]);
                }

                // Redraw after swapping
                barGraph->drawArray(j, j + 1);
                delay(500);  // Delay after swap to show the new state
            }
        }
    }
};

// Main function
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, const_cast<char*>(""));  

    int arr[] = {120, 300, 150, 200, 180, 350, 100};  // Heights of the bars
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a BarGraph object
    BarGraph barGraph(arr, n);

    // Display the original unsorted array
    barGraph.drawArray();
    getch();  // Wait for a key press

    // Create a BubbleSort object and perform the sorting
    BubbleSort bubbleSort(arr, n, &barGraph);
    bubbleSort.sort();

    // Display the sorted array
    cleardevice();  // Clear before showing the final result
    barGraph.drawArray();
    getch();  // Wait for a key press before closing

    closegraph();  // Close the graphics window
    return 0;
}
