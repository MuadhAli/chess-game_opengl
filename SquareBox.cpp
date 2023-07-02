#include <GL/glut.h>
#include <cstdlib>
#include <string>

bool isBoxClicked = false;  // Flag to check if the box is clicked

void drawText(float x, float y, std::string text)
{
    glRasterPos2f(x, y);  // Set the position to start drawing text
    
    for (char c : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);  // Render each character
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);  // Set the coordinates range
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glBegin(GL_QUADS);  // Begin drawing a quadrilateral
    
    if (isBoxClicked)
        glColor3f(0.0, 1.0, 0.0);  // Set color to green if the box is clicked
    else
        glColor3f(1.0, 0.0, 0.0);  // Set color to red
    
    glVertex2f(-0.5, -0.5);    // Specify the vertices of the square
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    
    glEnd();  // End drawing
    
    glColor3f(1.0, 1.0, 1.0);  // Set color to white
    drawText(-0.35, 0.0, "Welcome to the game");  // Draw the text
    
    glFlush();  // Force execution of OpenGL commands
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float normalizedX = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        float normalizedY = (float)(glutGet(GLUT_WINDOW_HEIGHT) - y) / glutGet(GLUT_WINDOW_HEIGHT) * 2 - 1;
        
        if (normalizedX >= -0.5 && normalizedX <= 0.5 && normalizedY >= -0.5 && normalizedY <= 0.5)
        {
            isBoxClicked = true;
            glutPostRedisplay();  // Request redrawing the window
            
            // Execute the main program using system command
            system("./a.out");
        }
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Square Box");
    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    
    glutMainLoop();
    
    return 0;
}
