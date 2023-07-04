#include <GL/glut.h>
#include <cstdlib>
#include <string>

bool isBox1Clicked = false;  // Flag to check if box 1 is clicked
bool isBox2Clicked = false;  // Flag to check if box 2 is clicked
bool shouldCloseWindow = false;  // Flag to indicate if the window should be closed

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

    // Box 1
    glBegin(GL_QUADS);  // Begin drawing a quadrilateral

    if (isBox1Clicked)
        glColor3f(0.0, 1.0, 0.0);  // Set color to green if box 1 is clicked
    else
        glColor3f(1.0, 0.0, 0.0);  // Set color to red

    glVertex2f(-0.9, -0.5);    // Specify the vertices of box 1
    glVertex2f(-0.7, -0.5);
    glVertex2f(-0.7, 0.5);
    glVertex2f(-0.9, 0.5);

    glEnd();  // End drawing

    // Box 2
    glBegin(GL_QUADS);  // Begin drawing a quadrilateral

    if (isBox2Clicked)
        glColor3f(0.0, 1.0, 0.0);  // Set color to green if box 2 is clicked
    else
        glColor3f(1.0, 0.0, 0.0);  // Set color to red

    glVertex2f(0.7, -0.5);    // Specify the vertices of box 2
    glVertex2f(0.9, -0.5);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.7, 0.5);

    glEnd();  // End drawing

    glColor3f(1.0, 1.0, 1.0);  // Set color to white
    drawText(-0.89, 0.0, "Click to run ");  // Draw the text for box 1

    drawText(-0.53, 0.70, "welcome to the chess game created with opengl designed and developed ");  // Draw the text for box 1
    drawText(-0.50, 0.63, "Afrah Abdul Aziz");  // Draw the text for box 1
    drawText(-0.50, 0.57, "Bhagyashree K");  // Draw the text for box 1
    drawText(-0.20, 0.20, " CHESS RULES");   
    drawText(-0.50, 0.0, "1. Setup: Chess is played on a square board with 64 squares.");  // Draw the text for box 1
    drawText(-0.50, -0.10, "2. Piece Movement: Each piece moves in a specific way.");  // Draw the text for box 1
    drawText(-0.50, -0.20, "3. Objective: The objective is to checkmate the opponent's king.");  // Draw the text for box 1
    drawText(-0.50, -0.30, "4. Special Moves: Castling, en passant, and promotion.");  // Draw the text for box 1
    drawText(-0.50, -0.40, "5. Check and Checkmate: Check and checkmate conditions.");  // Draw the text for box 1
    drawText(-0.50, -0.50, "6. Draw: Stalemate, threefold repetition, and fifty-move rule.");  // Draw the text for box 1


    drawText(-0.50, -0.80, "Keys to play the game will be displyed in the next page");  // Draw the text for box 1


    drawText(0.70, 0.0, "Click to close");  // Draw the text for box 2

    glFlush();  // Force execution of OpenGL commands

    if (shouldCloseWindow)
    {
        glutDestroyWindow(glutGetWindow());  // Close the window
        exit(0);
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float normalizedX = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        float normalizedY = (float)(glutGet(GLUT_WINDOW_HEIGHT) - y) / glutGet(GLUT_WINDOW_HEIGHT) * 2 - 1;

        // Check if box 1 is clicked
        if (normalizedX >= -0.9 && normalizedX <= -0.7 && normalizedY >= -0.5 && normalizedY <= 0.5)
        {
            isBox1Clicked = true;
            glutPostRedisplay();  // Request redrawing the window

            // Execute ./a.out using system command
            system("./a.out");
        }

        // Check if box 2 is clicked
        if (normalizedX >= 0.7 && normalizedX <= 0.9 && normalizedY >= -0.5 && normalizedY <= 0.5)
        {
            isBox2Clicked = true;
            shouldCloseWindow = true;
            glutPostRedisplay();  // Request redrawing the window
        }
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 700);
    glutCreateWindow("Square Boxes");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}
