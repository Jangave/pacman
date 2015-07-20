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

#ifndef _ambiente_
#define _ambiente_

#include "Quadrado.fwd.h"

#include <vector>

class Ambiente
{
    private:
        const static int QTD_LARGURA = 15, QTD_ALTURA = 15, PESO = 1;
        std::vector<std::vector<Quadrado*> > matriz;
        Quadrado *entrada, *saida;

        void init();
        void imperfeito();
        std::vector<Quadrado*> pegaAcessiveis(Quadrado* );
        std::vector<Quadrado*> getAdjacentesMuros(Quadrado* );
        std::vector<Quadrado*> getAdjacentes(Quadrado* );
    public:
        void geraLabirinto();
        ~Ambiente();
};

#endif // _ambiente_
