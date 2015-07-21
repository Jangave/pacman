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
#include "headers/Ambiente.h"
#include "headers/Quadrado.h"
#include "headers/Aresta.h"
#include "headers/Character.h"

#include <vector>
#include <limits>
#include <stack>

template<>
bool vectorContains<Quadrado*>(std::vector<Quadrado*> v, Quadrado* p)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == p)
            return true;
    }

    return false;
}

int Ambiente::PESO = 1;
int Ambiente::QTD_ALTURA = 15;
int Ambiente::QTD_LARGURA = 15;

Ambiente::Ambiente(int width, int height)
{
    for (int i = 0; i < Ambiente::QTD_ALTURA; i++)
    {
        std::vector<Quadrado*> linha;
        for (int j = 0; j < Ambiente::QTD_LARGURA; j++)
        {
            Quadrado* q = new Quadrado(i, j);
            linha.push_back(q);
            linha[j]->levantarMuros();

            addDrawable(q);
        }

        matriz.push_back(linha);
    }

    Character* c = new Character(width/2, height/2);
    addDrawable(c);
    addInputable(c);
}

Ambiente::~Ambiente()
{
    for (int i = 0; i < Ambiente::QTD_ALTURA; i++)
    {
        for (int j = 0; j < Ambiente::QTD_LARGURA; j++)
        {
            delete matriz[i][j];
        }
    }
    matriz.clear();
}

void Ambiente::limpa()
{
    for (int i = 0; i < Ambiente::QTD_ALTURA; i++)
    {
        for (int j = 0; j < Ambiente::QTD_LARGURA; j++)
        {
            matriz[i][j]->levantarMuros();
        }
    }
}

void Ambiente::geraLabirinto()
{
    limpa();
    std::stack<Quadrado*> pilhaDePosicoes;

    Quadrado* atual = matriz[randomize(Ambiente::QTD_ALTURA)][randomize(Ambiente::QTD_LARGURA)];
    int qtdVisitadas = -1;

    while (qtdVisitadas < (Ambiente::QTD_ALTURA * Ambiente::QTD_LARGURA))
    {
        std::vector<Quadrado*> vizinhasMuro = getAdjacentesMuros(atual);
        if (!vizinhasMuro.empty())
        {
            Quadrado* proximo = vizinhasMuro.at(randomize(vizinhasMuro.size()));
            Aresta* a = new Aresta(atual, proximo, Ambiente::PESO);

            atual->addAresta(a);
            proximo->addAresta(a);

            pilhaDePosicoes.push(atual);

            atual = proximo;
            qtdVisitadas++;
        }
        else
        {
            atual = pilhaDePosicoes.top();
            pilhaDePosicoes.pop();
        }

        imperfeito();
    }
}

void Ambiente::imperfeito()
{
    for (int i = 0; i < Ambiente::QTD_ALTURA; i++)
    {
        for (int j = 0; j < Ambiente::QTD_LARGURA; j++)
        {
            Quadrado* q = matriz[i][j];

            if (randomize(std::numeric_limits<int>::max()) % (QTD_ALTURA * QTD_LARGURA * QTD_LARGURA * QTD_ALTURA) == (QTD_ALTURA * QTD_LARGURA * QTD_LARGURA * QTD_ALTURA) - 1)
            {
                std::vector<Quadrado*> adj = getAdjacentes(q);
                Quadrado* proximo = NULL;
                int contadora = 0;

                std::vector<Quadrado*> acessiveis = pegaAcessiveis(q);
                do
                {
                    proximo = adj.at(randomize(adj.size()));
                    contadora++;
                } while (vectorContains<Quadrado*>(acessiveis, q) && !acessiveis.empty() && contadora <= 3);

                Aresta* a = new Aresta(q, proximo, Ambiente::PESO);
                q->addAresta(a);
                proximo->addAresta(a);
            }
        }
    }
}

std::vector<Quadrado*> Ambiente::pegaAcessiveis(Quadrado* atual)
{
    std::vector<Aresta*> adj = atual->getArestas();
    std::vector<Quadrado*> acessiveis;

    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[i]->getOrigem() != atual)
            acessiveis.push_back(adj[i]->getOrigem());
        else
            acessiveis.push_back(adj[i]->getDestino());
    }

    return acessiveis;
}

std::vector<Quadrado*> Ambiente::getAdjacentesMuros(Quadrado* atual)
{
    std::vector<Quadrado*> adj = getAdjacentes(atual);
    std::vector<Quadrado*> retorno;

    for (int i = 0; i < adj.size(); i++)
    {
        Quadrado* q = adj[i];
        if (!atual->isConectado(q) && q->isMuro())
            retorno.push_back(q);
    }

    return retorno;
}

std::vector<Quadrado*> Ambiente::getAdjacentes(Quadrado* atual)
{
    std::vector<Quadrado*> adj;

    for (int i = 0; i < Ambiente::QTD_ALTURA; i++)
    {
        for (int j = 0; j < Ambiente::QTD_LARGURA; j++)
        {
            if ((i == atual->getI() - 1 && j == atual->getJ()) ||
                (i == atual->getI() + 1 && j == atual->getJ()) ||
                (i == atual->getI() && j == atual->getJ() - 1) ||
                (i == atual->getI() && j == atual->getJ() + 1))
                    adj.push_back(matriz[i][j]);
        }
    }
    return adj;
}

void Ambiente::addInputable(Inputable* i)
{
    inputables.push_back(i);
}

void Ambiente::executeInput(int key, int action)
{
    for (int i = 0; i < inputables.size(); i++)
    {
        inputables[i]->executeInput(key, action);
    }
}

void Ambiente::addDrawable(Drawable* d)
{
    drawables.push_back(d);
}

void Ambiente::draw()
{
    for (int i = 0; i < drawables.size(); i++)
    {
        drawables[i]->draw();
    }
}
