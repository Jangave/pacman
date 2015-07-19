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

/** TO-DO
    * Arrumar tipo cor [functions.h]
*/

#include "headers/functions.h"
#include "headers/types.h"
#include "headers/Window.h"
#include "headers/InputInterface.h"
#include "headers/Character.h"

#include "headers/Inputable.h"
#include "headers/Drawable.h"

//#include <iostream>
//#include <typeinfo>

//#include "headers/Debug.h"

int main()
{
    initialize();
    Window* janela = new Window("Pacman - Teste", 640, 480);
    InputInterface i(*janela, 1, 0, 0);
    Character* c = new Character();

    i.addInputable(c);
    i.addInputable(janela);

    janela->addDrawable(c);

    while (!janela->shouldClose())
    {
        prepareEnvironment(*janela);

        janela->draw();

        i.execute();
        setEnvironment(*janela);
    }

    finalize(*janela);
    return 0;
}
