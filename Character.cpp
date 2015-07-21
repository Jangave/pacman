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

#include "headers/Character.h"
#include "headers/functions.h"

#include <cmath>

Character::Character(int x, int y)
{
    size = 15;
    this->position.x = x;
    this->position.y = y;
}

void Character::up()
{
    this->position.y++;
}

void Character::down()
{
    this->position.y--;
}

void Character::left()
{
    this->position.x--;
}

void Character::right()
{
    this->position.x++;
}

void Character::executeInput(int key, int action)
{
    if (action == GLFW_PRESS)
    {
        if (key == GLFW_KEY_RIGHT)
            this->right();
        else if (key == GLFW_KEY_LEFT)
            this->left();
        else if (key == GLFW_KEY_UP)
            this->up();
        else if (key == GLFW_KEY_DOWN)
            this->down();
    }
}

void Character::draw()
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(this->position.x, this->position.y, 0);
        for (int i = 45; i <= 315; i++)
            glVertex3f(cos(toRadian(i)) * size + this->position.x, sin(toRadian(i)) * size + this->position.y, 0);
    glEnd();
}
