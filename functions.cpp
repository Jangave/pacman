/**************************************************************************
    Jangave/pacman game. Simple pacman-style game to help in development of Jangave Engine.
    Copyright (C) 2015  Gabriel Vinícius Canzi Candido

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/

#include <iostream>

#include "headers/functions.h"

#include <GLFW/glfw3.h>

void initialize()
{
    if (!glfwInit())
        std::cerr << "Impossível inicializar o GLFW." << std::endl;

    glfwSwapInterval(1); //vsync - how many frames to wait until swap buffers; standard(zero) wastes a lot of CPU and GPU
}

void finalize(Window w)
{
    if (w.window())
        glfwDestroyWindow(w.window());
    glfwTerminate();
}

void finalize()
{
    glfwTerminate();
}

static void error(int e, const char* descricao)
{
    std::cerr << e << ": " << descricao << std::endl;
}

void prepareEnvironment(Window w)
{
    int width, height;
    glfwGetFramebufferSize(w.window(), &width, &height);

    glViewport(0, 0, width, height);
    int ratio = width / (float) height;

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-ratio, ratio, -1., 1., 1., -1.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void setEnvironment(Window w)
{
    glfwSwapBuffers(w.window());
    glfwPollEvents();
}
