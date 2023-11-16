#include <GL/glut.h>

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Set line color to red
    glColor3f(1.0, 0.0, 0.0);

    // Draw the first line
    drawLine(1, 2, 4, 4); // Replace these coordinates with P1 and P2

    // Set line color to green
    glColor3f(0.0, 1.0, 0.0);

    // Draw the second line
    drawLine(1, 8, 2, 4);

    glFlush();
}

void reshape(int width, int height) {
    // Set the viewport to match the window size
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Calculate the aspect ratio and set the orthogonal view accordingly
    float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
    gluOrtho2D(0.0, 5.0 * aspectRatio, 0.0, 5.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Line Drawing");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape); // Set the reshape function

    glutMainLoop();
    return 0;
}
