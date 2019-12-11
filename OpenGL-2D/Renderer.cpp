#include "stdafx.h"
#include "Renderer.h"
#include "TextureManager.h"
#include "Drawable.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

Renderer* Renderer::m_pRenderer = nullptr;

Renderer::Renderer()
{
	TextureManager::getInstance()->create2DTexture("img/144.png");
	m_pRenderer = this;
	
}


Renderer::~Renderer()
{
	for (int i = 0; i < m_objects2D.size(); i++)
		delete m_objects2D[i];
}

Renderer* Renderer::get()
{
	return m_pRenderer;
}

void Renderer::initialize(int argc, char** argv)
{
	//INIT GLUT/////////////////////
	////////////////////////////////
	//init window and OpenGL context
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(400, 30);

	
	glutCreateWindow(argv[0]);
	
	
	//OpenGL global initializations
	glEnable(GL_DEPTH_TEST);

	//callback functions
	glutDisplayFunc(__drawScene);
	glutReshapeFunc(__reshapeWindow);
}

void Renderer::set2DMatrix()
{
	//set projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);

	//set modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void Renderer::reshapeWindow(int w, int h)
{
	//Reshape callback function
	m_windowHeight = h;
	m_windowWidth = w;
	glutReshapeWindow(800, 800);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

Drawable* Renderer::getObjectByName(string name)
{
	for (int i = 0; i < m_objects2D.size(); i++)
	{
		if (m_objects2D[i]->getName() == name) {

			return m_objects2D[i];
		}
	}
}

void Renderer::addObject(Drawable* pObj)
{
	m_objects2D.push_back(pObj);
}

void Renderer::drawScene()
{
	//clean the backbuffer
	
	TextureManager::getInstance()->useTexture("img/144.png");


	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex3f(-1, -1, -1.5);

	glTexCoord2f(1, 0);
	glVertex3f(1, -1, -1.5);

	glTexCoord2f(1, 1);
	glVertex3f(1, 1, -1.5);

	glTexCoord2f(0, 1);
	glVertex3f(-1, 1, -1.5);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//TextureManager::getInstance()->useTexture("img/144.png");
	//set the 2d modelview matrix
	set2DMatrix();
	

	for (int i=0; i<m_objects2D.size(); i++)
	{
		
		m_objects2D[i]->draw();
	}
}


//Nevermind these static functions: auxiliary stuff to fit openGL's callbacks
void Renderer::__drawScene()
{
	if (m_pRenderer)
		m_pRenderer->drawScene();
}
void Renderer::__reshapeWindow(int x, int y)
{
	if (m_pRenderer)
		m_pRenderer->reshapeWindow(x, y);
}