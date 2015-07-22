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

#include "CharacterInterface.h"
#include "Inputable.h"
#include "Drawable.h"

class Character : public CharacterInterface, public Inputable, public Drawable
{
    private:
        int raio;

        void up();
        void down();
        void left();
        void right();
    public:
        Character(int , int , int );

        void executeInput(int , int );
        void draw();
};
