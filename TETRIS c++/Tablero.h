// Tablero.cpp
#include <iostream>
#include "Colores.h"

Tablero::Tablero()
{
  numFilas = 20;
  numColumnas = 10;
  tamanoCelda = 30;
  Inicializar();
  colores = GetColorCelda();
}

void Tablero::Inicializar()
{
  for (int fila = 0; fila < numFilas; fila++)
  {
    for (int columna = 0; columna < numColumnas; columna++)
    {
      tablero[fila][columna] = 0;
    }
  }
}

void Tablero::Imprimir()
{
  for (int fila = 0; fila < numFilas; fila++)
  {
    for (int columna = 0; columna < numColumnas; columna++)
    {
      std::cout << tablero[fila][columna] << " " ;
    }
    std::cout << std::endl;
  }
}

void Tablero::Dibujar()
{
  for (int fila = 0; fila < numFilas; fila++)
  {
    for (int columna = 0; columna < numColumnas; columna++)
    {
      int valorCelda = tablero[fila][columna];
      DrawRectangle(columna * tamanoCelda + 11, fila * tamanoCelda + 11, tamanoCelda - 1, tamanoCelda - 1, colores[valorCelda]);
    }
  }
}

bool Tablero::AfueraDeCelda(int fila, int columna)
{
  if (fila >= 0 && fila < numFilas && columna >= 0 && columna < numColumnas)
  {
    return false;
  }
  return true;
}

bool Tablero::CeldaVacia(int fila, int columna)
{
  if (tablero[fila][columna] == 0)
  {
    return true;
  }
  return false;
}

int Tablero::VaciarFilaLlena()
{
  int lleno = 0;
  for (int fila = numFilas - 1; fila >= 0; fila--)
  {
    if (FilaLlena(fila))
    {
      VaciarFila(fila);
      lleno++;
    }
    else if (lleno > 0)
    {
      MoverFilaAbajo(fila, lleno);
    }
  }
  return lleno;
}

bool Tablero::FilaLlena(int fila)
{
  for (int columna = 0; columna < numColumnas; columna++)
  {
    if (tablero[fila][columna] == 0)
    {
      return false;
    }
  }
  return true;
}

void Tablero::VaciarFila(int fila)
{
  for (int columna = 0; columna < numColumnas; columna++)
  {
    tablero[fila][columna] = 0;
  }
}

void Tablero::MoverFilaAbajo(int fila, int numFilas)
{
  for (int columna = 0; columna < numColumnas; columna++)
  {
    tablero[fila + numFilas][columna] = tablero[fila][columna];
    tablero[fila][columna] = 0;
  }
}