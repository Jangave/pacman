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

#include "headers/Aresta.h"

Aresta::Aresta(Quadrado* origem, Quadrado* destino, int peso)
{
    this->origem = origem;
    this->destino = destino;
    this->peso = peso;
}

Quadrado* Aresta::getOrigem()
{
    return this->origem;
}

Quadrado* Aresta::getDestino()
{
    return this->destino;
}

int Aresta::getPeso()
{
    return this->peso;
}
