#include <iostream>
#include "src/graphics/window.h"

int main()
{
	using namespace sparky::graphics;
	using namespace sparky;

	Window window = Window("Sparky!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f };

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	std::cout << glGetString(GL_VERSION) << std::endl;
	while(!window.closed())
	{
		window.clear();
		
		window.update();
	}
	return 0;
}