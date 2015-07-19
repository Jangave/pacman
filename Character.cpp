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

#include <cmath>

void Character::up()
{
    this->position.y--;
}

void Character::down()
{
    this->position.y++;
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

}

void Character::draw()
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 0, 0);
        for (int i = 0; i <= 360; i++)
            glVertex3f(cos(i*3.14159/180.), sin(i*3.14159/180.), 0);
    glEnd();
}
