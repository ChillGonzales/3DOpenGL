#include "window.h"
#include <iostream>

namespace sparky { namespace graphics {

	Window::Window(const char* title, int width, int height)
	{
		m_Title = title;
		m_Height = height;
		m_Width = width;
		if (!init())
			glfwTerminate();

	}

	Window::~Window()
	{
	}

	bool Window::init()
	{
		glewExperimental = GL_TRUE;
		if (!glewInit())
		{
			std::cout << "Failed to initialize GLEW." << std::endl;
			return false;
		}
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW." << std::endl;
			return false;
		}
		
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		return true;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	
	void Window::update()
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glViewport(0, 0, m_Width, m_Height);
		glfwSwapBuffers(m_Window);
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}









	
	
}}