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

#include "headers/Quadrado.h"

Quadrado::Quadrado(){}

Quadrado::Quadrado(int i, int j)
{
    this->i = i;
    this->j = j;
}

Quadrado::~Quadrado()
{
    levantarMuros();
}

void Quadrado::levantarMuros()
{
    for (int i = 0; i < arestas.size(); i++)
        delete arestas[i];
    arestas.clear();
}

void Quadrado::addAresta(Aresta* a)
{
    arestas.push_back(a);
}

bool Quadrado::isConectado(Quadrado* q)
{
    std::vector<Aresta> arestasAdjacente = q->getArestas();

    for (int i = 0; i < arestas.size(); i++)
    {
        for (int j = 0; j < arestasAdjacente.size(); j++)
        {
            if (arestas[i] == arestasAdjacente[j])
                return true;
        }
    }

    return false;
}

bool Quadrado::isMuro()
{
    return arestas.empty();
}

std::vector<Aresta*> Quadrado::getArestas()
{
    return arestas;
}

int Quadrado::getI()
{
    return i;
}

int Quadrado::getJ()
{
    return j;
}
