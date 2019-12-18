#pragma once
#include "./Player.h"
#include "TextureManager.h"

class Drawable;
#include <vector>
using namespace std;

class Renderer
{
	static Renderer* m_pRenderer;
	int m_windowWidth = 0, m_windowHeight = 0;

	TextureManager textureManager;

	vector <Drawable*> m_objects2D;

	void set2DMatrix();
public:
	Renderer();
	~Renderer();
	int idWin;
	void initialize(int argc, char** argv);

	void destroyW();

	static Renderer* get(); //this method returns the only instance to the renderer. Needs to be called after the constructor

	void drawScene();
	void addObject(Drawable* pObj);
	void reshapeWindow(int x, int y);

	Drawable* getObjectByName(string name);

	static void __drawScene();
	static void __reshapeWindow(int x, int y);
};

