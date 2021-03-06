#include "pch.h"
#include "Engine/Engine.h"
#include "Engine/Graphics/Model.h"
#include "Engine/Graphics/Renderer.h"
#include "Engine/Graphics/Program.h"
#include "Engine/Graphics/Texture.h"
#include <Engine/Graphics/VertexIndexArray.h>

int main(int argc, char** argv)
{

	nc::Engine engine;
	engine.Startup();

	//initialization
	//float vertices[] =
	//{
	//	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, //point 1, color 1, uv cord
	//	 0.0f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f,//point 2, color 2, uv cord
	//	 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f  //point 3, color 3, uv cord

	//};

	//static float vertices[] = {
	//	// front
	//	-1.0f, -1.0f,  1.0f, 0.0f, 0.0f,
	//	 1.0f, -1.0f,  1.0f, 1.0f, 0.0f,
	//	 1.0f,  1.0f,  1.0f, 1.0f, 1.0f,
	//	-1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
	//	// back
	//	-1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
	//	 1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
	//	 1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
	//	-1.0f,  1.0f, -1.0f, 1.0f, 1.0f,
	//};

	static float vertices[] =
	{

		// Back Face
		-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f,


		// Front Face
		-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f,


		// Left Face
		-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f,
		-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f,


		 // Right Face
		 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f,
		 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f,


		 // Bottom Face
		-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
		 1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,
		 1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
		 1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
		-1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f,
		-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f,


		 //Top Face
		-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		 1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		 1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		 1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f
	};


	static GLushort indices[] =
	{
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

	nc::VertexArray vertexArray;
	vertexArray.Create("vertex");

	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> texcoords;
	nc::Model::Load("models/ogre.obj", positions, normals, texcoords);

	if (!positions.empty()) // Position
	{
		vertexArray.CreateBuffer(positions.size() * sizeof(glm::vec3), static_cast<GLsizei>(positions.size()), positions.data());
		vertexArray.SetAttribute(0, 3, 0, 0);
	}

	if (!normals.empty()) // Normals
	{
		// complete code
		vertexArray.CreateBuffer(normals.size() * sizeof(glm::vec3), static_cast<GLsizei>(normals.size()), normals.data());
		vertexArray.SetAttribute(1, 3, 0, 0);
	}

	if (!texcoords.empty()) // UV
	{
		// complete code
		vertexArray.CreateBuffer(texcoords.size() * sizeof(glm::vec2), static_cast<GLsizei>(texcoords.size()), texcoords.data());
		vertexArray.SetAttribute(2, 2, 0, 0);
	}



	/*std::string vertexShaderSource;
	nc::ReadFileToString("Shaders\\basic.vert", vertexShaderSource);

	std::string fragmentShaderSource;
	nc::ReadFileToString("Shaders\\basic.frag", fragmentShaderSource);*/

	nc::Program program;
	program.CreateShaderFromFile("shaders\\phong.vert", GL_VERTEX_SHADER);
	program.CreateShaderFromFile("shaders\\phong.frag", GL_FRAGMENT_SHADER);
	program.Link();
	program.Use();

	// create buffer
	/*nc::VertexIndexArray vertexIndexArray;
	vertexIndexArray.Create("vertex");
	vertexIndexArray.CreateBuffer(sizeof(vertices), sizeof(vertices) / (sizeof(float) * 5), vertices);
	vertexIndexArray.SetAttribute(0, 3, 5 * sizeof(float), 0);
	vertexIndexArray.SetAttribute(1, 2, 5 * sizeof(float), 3 * sizeof(float));
	vertexIndexArray.CreateIndexBuffer(GL_UNSIGNED_SHORT, sizeof(indices) / sizeof(GLushort), indices);*/

	/*nc::VertexArray vertexArray;
	vertexArray.Create("vertex");
	vertexArray.CreateBuffer(sizeof(vertices), sizeof(vertices) / (sizeof(float) * 5), vertices);
	vertexArray.SetAttribute(0, 3, 6 * sizeof(float), 0);
	vertexArray.SetAttribute(1, 3, 6 * sizeof(float), 3 * sizeof(float));*/



	// uniform
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800 / 600.0f, 0.01f, 1000.0f);

	glm::vec3 eye{ 0, 0, 5 };
	glm::mat4 view = glm::lookAt(eye, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	nc::Texture texture;
	texture.CreateTexture("textures\\ogre_diffuse_flip.bmp");
	
	program.SetUniform("transform", model);
	
	program.SetUniform("material.ambient", glm::vec3{ 1, 1, 1 });
	program.SetUniform("material.diffuse", glm::vec3{ 1, 1, 1 });
	program.SetUniform("material.specular", glm::vec3{ 1, 1, 1 });
	program.SetUniform("material.shininess", 32.0f);

	program.SetUniform("light.ambient", glm::vec3{ 0.1f, 0.1f, 0.1f });
	program.SetUniform("light.diffuse", glm::vec3{ 1, 1, 1 });
	program.SetUniform("light.specular", glm::vec3{ 1, 1, 1 });

	glm::vec4 light{ 5, 2, 5, 1 };




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
		engine.Update();

		float angle = 0;
		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_Q) == nc::InputSystem::eButtonState::HELD)
		{
			angle -= 0.5f;
		}
		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_E) == nc::InputSystem::eButtonState::HELD)
		{
			angle += 0.5f;
		}


		model = glm::rotate(model, angle * glm::pi<float>() * engine.GetTimer().DeltaTime(), glm::vec3(0, 1, 0));

		
		// model, view, projection
		
		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == nc::InputSystem::eButtonState::HELD)
		{
			eye.x -= 2 * engine.GetTimer().DeltaTime();
		}

		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == nc::InputSystem::eButtonState::HELD)
		{
			eye.x += 2 * engine.GetTimer().DeltaTime();
		}

		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_W) == nc::InputSystem::eButtonState::HELD)
		{
			eye.y -= 2 * engine.GetTimer().DeltaTime();
		}

		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_S) == nc::InputSystem::eButtonState::HELD)
		{
			eye.y += 2 * engine.GetTimer().DeltaTime();
		}
		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_Z) == nc::InputSystem::eButtonState::HELD)
		{
			eye.z -= 2 * engine.GetTimer().DeltaTime();
		}

		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_C) == nc::InputSystem::eButtonState::HELD)
		{
			eye.z += 2 * engine.GetTimer().DeltaTime();
		}

		view = glm::lookAt(eye, eye + glm::vec3{ 0, 0, -1 }, glm::vec3{ 0, 1, 0 });

		glm::mat4 mvp = projection * view * model;
		program.SetUniform("mvp", mvp);

		glm::mat4 model_view = view * model;
		program.SetUniform("model_view", model_view);

		glm::vec4 position = view * light;
		program.SetUniform("light.postion", position);


		engine.GetSystem<nc::Renderer>()->BeginFrame();

		//vertexIndexArray.Draw();
		vertexArray.Draw();

		engine.GetSystem<nc::Renderer>()->EndFrame();
	}

	engine.Shutdown();

	return 0;
}

