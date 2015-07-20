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

#ifndef _window_
#define _window_

#include "Drawable.h"
#include "Inputable.h"

#include <GLFW/glfw3.h>
#include <vector>

class Window : public Inputable
{
    private:
        GLFWwindow* w;
        std::vector<Drawable*> l;
    public:
        Window(const char* , int , int );
        bool shouldClose();
        GLFWwindow* window();
        void prepareEnvironment();
        void setEnvironment();

        void addDrawable(Drawable* );
        void draw();
        void executeInput(int , int );
};

#endif // _window_
