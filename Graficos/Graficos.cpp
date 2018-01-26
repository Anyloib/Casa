// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <math.h>

#include <iostream>
using namespace std;

GLfloat red, green, blue;

void actualizar()
{
	//Aqui esta bien para cambiar los valores de las variables de mi programa!!

	/*red += 0.001;
	green += 0.002;
	blue += 0.003;

	if (red > 1) red = 0;
	if (green > 1) green = 0;
	if (blue > 1) blue = 0;*/
}

void dibujar()
{
	//Inicia la rutina con un modo de dibujo
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -0.5f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.5f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.2f, 0.7f);
	for(float i = 0; i < 360; i++)
	{
		glVertex3f(0.2*cos(i)+0.6, 0.2*sin(i)+0.7, 0.0f);
	}
	glEnd();
}

int main()
{
	//Declaración de Ventana
	GLFWwindow *window;
	
	//Propiedades de la ventana
	GLfloat ancho = 800;
	GLfloat alto = 800;

	//Inicialización de GLFW
	if (!glfwInit())
	{
		//Si no se inicia bien termina la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicialización de la ventana
	window = glfwCreateWindow(ancho, alto, "Gráficos", NULL, NULL);

	//Verificación de creación de ventana
	if (!window)
	{
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}


	//Establecer "windows" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;

	//Inicializar GLEW
	GLenum glewError = glewInit();

	//Verificar si GLEW se inicializo bien
	if (glewError != GLEW_OK)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGl: " << version << endl;

	red = green = blue = 0.0f;

	//Ciclo de Dibujo
	while (!glfwWindowShouldClose(window))
	{
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia
		glClearColor(red, green, blue, 1);

		//Limpiar pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de Dibujo
		actualizar();
		dibujar();

		//Intercambio de Buffers
		glfwSwapBuffers(window);
		//Buscar nueva señal de entrada
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

