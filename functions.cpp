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

#include "headers/functions.h"
#include "headers/types.h"

#include <iostream>
#include <cstdlib>
#include <GLFW/glfw3.h>

void initialize()
{
    if (!glfwInit())
        std::cerr << "Impossível inicializar o GLFW." << std::endl;
}

void finalize()
{
    glfwTerminate();
}

static void error(int e, const char* descricao)
{
    std::cerr << e << ": " << descricao << std::endl;
}

long randomize(int i, int f)
{
    static bool start = true;

    if (start)
    {
        srand(time(0));
        start = false;
    }

    long n;

    if(f == 0)
      n = rand() % i;
   else
      n = (rand() % (f - i)) + i;

   return n;
}

double toRadian(int i)
{
    return (i*PI)/180.d;
}

double toRadian(float f)
{
    return (f*PI)/180.d;
}

double toRadian(double d)
{
    return (d*PI)/180.d;
}

template<class T>
bool vectorContains(std::vector<T> v, T p)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == p)
            return true;
    }

    return false;
}
