#include <GL/glut.h>
#include <cmath>

// Window dimensions
const int windowWidth = 800;
const int windowHeight = 600;

// Time parameter for animation (0 to 1)
float timeOfDay = 0.0f;

// Function to draw the sun
void drawSun(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f); // Sun color (yellow)
    glVertex2f(x, y); // Center of the sun
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

// Function to draw the sky
void drawSky() {
    // Set sky color based on the time of day
    if (timeOfDay < 0.5f) {
        // Sunrise - light blue to orange
        glColor3f(1.0f, 0.8f - timeOfDay * 0.6f, 0.0f); // From light blue to orange
    } else {
        // Sunset - orange to dark blue
        glColor3f(1.0f - (timeOfDay - 0.5f) * 2.0f, 0.4f, 0.4f); // From orange to dark blue
    }
    
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f); // Bottom-left corner
    glVertex2f(1.0f, -1.0f);  // Bottom-right corner
    glVertex2f(1.0f, 1.0f);   // Top-right corner
    glVertex2f(-1.0f, 1.0f);  // Top-left corner
    glEnd();
}

// Function to draw the horizon
void drawHorizon() {
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray for horizon
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.2f); // Left side of horizon
    glVertex2f(1.0f, -0.2f);  // Right side of horizon
    glVertex2f(1.0f, -1.0f);  // Bottom-right corner
    glVertex2f(-1.0f, -1.0f); // Bottom-left corner
    glEnd();
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw sky
    drawSky();

    // Draw horizon
    drawHorizon();

    // Draw the sun
    float sunX = 0.0f;
    float sunY = -0.5f + timeOfDay; // Move sun up and down
    float sunRadius = 0.1f;
    drawSun(sunX, sunY, sunRadius);

    glFlush();
    glutSwapBuffers();
}

// Function to update timeOfDay (animating the sunrise and sunset)
void update(int value) {
    // Increment time
    timeOfDay += 0.01f;
    if (timeOfDay > 1.0f) {
        timeOfDay = 0.0f; // Loop back to the start
    }
    
    // Redraw the scene with updated time
    glutPostRedisplay();
    
    // Continue updating every 16 milliseconds (~60 fps)
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Sunrise and Sunset");

    // Set the 2D orthographic projection
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    
    // Set clear color (black background)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Register callback functions
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0); // Start the animation

    // Start the main loop
    glutMainLoop();

    return 0;
}
