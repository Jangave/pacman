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

#include "headers/Window.h"
#include <cstdlib>

Window::Window(const char* title, int width, int height)
{
    this->w = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!this->w)
        std::cerr << "It was not possible to create a window." << std::endl;
    else
        glfwMakeContextCurrent(this->w); //Makes window as active context
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(this->w);
}

GLFWwindow* Window::window()
{
    return this->w;
}

void Window::addDrawable(Drawable* d)
{
    l.push_back(d);
}

void Window::draw()
{
    for (int i = 0; i < l.size(); i++)
    {
        l[i]->draw();
    }
}

void Window::executeInput(int key, int action)
{
    if (action == GLFW_PRESS)
        if (key == GLFW_KEY_ESCAPE)
            exit(255);
}
