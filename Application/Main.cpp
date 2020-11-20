#include "pch.h"
#include "Engine/Graphics/Renderer.h"
#include "Engine/Graphics/Program.h"
#include "Engine/Graphics/Texture.h"

int main(int argc, char** argv)
{
	nc::Renderer renderer;

	renderer.Startup();
	renderer.Create("OpenGL", 800, 600);

	//initialization
	float vertices[] =
	{
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, //point 1, color 1, uv cord
		 0.0f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f,//point 2, color 2, uv cord
		 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f  //point 3, color 3, uv cord

	};

	/*std::string vertexShaderSource;
	nc::ReadFileToString("Shaders\\basic.vert", vertexShaderSource);

	std::string fragmentShaderSource;
	nc::ReadFileToString("Shaders\\basic.frag", fragmentShaderSource);*/

	nc::Program program;
	program.CreateShaderFromFile("shaders\\basic.vert", GL_VERTEX_SHADER);
	program.CreateShaderFromFile("shaders\\basic.frag", GL_FRAGMENT_SHADER);
	program.Link();
	program.Use();

	// create buffer
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// set position pipeline ( vertex attrib ) -- << Position >> --
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	// set color pipeline ( vertex attrib ) -- << Color >> --
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// set uv pipeline ( vertex attrib ) -- << UV >> --
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// uniform
	glm::mat4 transform = glm::mat4(1.0f);
	//GLuint uniform = glGetUniformLocation(program.GetProgramID(), "transform");
	//glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(transform));

	program.SetUniform("transform", transform);

	nc::Texture texture;
	texture.CreateTexture("textures\\birbOwl.png");



	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}

		SDL_PumpEvents();

		transform = glm::rotate(transform, 0.004f, glm::vec3(0, 0, 1));
		program.SetUniform("transform", transform);

		renderer.BeginFrame();

		//render triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);

		renderer.EndFrame();
	}

	return 0;
}

