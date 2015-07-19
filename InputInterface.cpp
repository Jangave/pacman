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

#include "headers/InputInterface.h"

#include <GLFW/glfw3.h>

int InputInterface::key = GLFW_KEY_UNKNOWN;
int InputInterface::action = GLFW_PRESS;

InputInterface::InputInterface(Window w, int FLAG_KEYBOARD, int FLAG_MOUSE, int FLAG_JOYSTICK)
{
    glfwSetKeyCallback(w.window(), keyboard_callback);
}

static void InputInterface::keyboard_callback(GLFWwindow* window, int k, int scancode, int a, int mods)
{
    key = k;
    action = a;
}

void InputInterface::addInputable(Inputable* i)
{
    l.push_back(i);
}

void InputInterface::execute()
{
    for (int i = 0; i < l.size(); i++)
    {
        l[i]->executeInput(key, action);
    }
}
