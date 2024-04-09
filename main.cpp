#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lwr left
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lwr right
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
};

const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position, 1.0);\n"
		"}\0";

const GLchar* fragmentShaderSource = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";

int main() {
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	
	glfwMakeContextCurrent(window);
	
	gladLoadGL();
	
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);
	
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	
	GLuint VAO = 0;
	GLuint VBO = 0;
	
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		
		glClearColor(0.5f, 0.7f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		
		glfwSwapBuffers(window);
	}
	
	return 0;
}
