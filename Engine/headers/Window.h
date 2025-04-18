#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

class Window{
public:
	Window();
	Window(int width, int height, std::string title);
	~Window();
	void createWindow(int width, int height, const char* title);
	void closeWindow();
	void setTitle(std::string title);
	void setSize(int width, int height);
	void setPosition(int x, int y);
	void setFullscreen(bool fullscreen);
	void setResizable(bool resizable);
	void setVSync(bool vsync);
	void setIcon(const char* iconPath);
	void setBackgroundColor(float r, float g, float b, float a);
	void setMouseCursorVisible(bool visible);
	void setMouseCursorPosition(int x, int y);
	void setMouseCursorGrabbed(bool grabbed);
	void setMouseCursorScale(float scale);
	void setMouseCursorHidden(bool hidden);

private:
	int width;
	int height;
	std::string title;
	bool fullscreen;
	bool resizable;
	bool vsync;
	float backgroundColor[4];
	bool mouseCursorVisible;
	int mouseCursorPosition[2];
	bool mouseCursorGrabbed;
	float mouseCursorScale;
	bool mouseCursorHidden;
	// Add any other necessary private members or methods here



};



#endif // !WINDOW_H



