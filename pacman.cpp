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
    1 TESTAR AMBIENTE
*/

#include "headers/functions.h"
#include "headers/Window.h"
#include "headers/InputInterface.h"
#include "headers/Ambiente.h"

//#include <iostream>
//#include <typeinfo>

//#include "headers/Debug.h"

int main()
{
    int w = 640, h = 480;

    initialize();
    Window* janela = new Window("Pacman - Teste", w, h);
    InputInterface i(janela, 1, 0, 0);
    Ambiente ambiente(w, h);

    //Just to allow close
    i.addInputable(janela);

    i.addInputable(&ambiente);
    janela->addDrawable(&ambiente);

    while (!janela->shouldClose())
    {
        janela->prepareEnvironment();

        janela->draw();

        i.execute();
        janela->setEnvironment();
    }

    delete janela;
    finalize();
    return 0;
}
