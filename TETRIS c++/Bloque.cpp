// Bloque.cpp

#include "Bloque.h"

Bloque::Bloque()
{
  tamanoCelda = 30;
  estadoRotacion = 0;
  colores = GetColorCelda();
  filaOffset = 0;
  columnaOffset = 0;
}

void Bloque::Dibujar(int offsetX, int offsetY)
{
  std::vector < Posicion > tiles = GetPosicionCelda();
  for (Posicion item : tiles)
  {
    DrawRectangle(item.columna * tamanoCelda + offsetX, item.fila * tamanoCelda + offsetY, tamanoCelda - 1, tamanoCelda - 1, colores[id]);
  }
}

void Bloque::Mover(int filas, int columnas)
{
  filaOffset += filas;
  columnaOffset += columnas;
}

std::vector < Posicion > Bloque::GetPosicionCelda()
{
  std::vector < Posicion > teclas = celdas[estadoRotacion];
  std::vector < Posicion > TeclasModificadas;
  for (Posicion item : teclas)
  {
    Posicion nuevaPos = Posicion(item.fila + filaOffset, item.columna + columnaOffset);
      TeclasModificadas.push_back(nuevaPos);
  }
  return TeclasModificadas;
}

void Bloque::Rotar()
{
  estadoRotacion++;
  if (estadoRotacion == (int)celdas.size())
  {
    estadoRotacion = 0;
  }
}

void Bloque::UndoRotar()
{
  estadoRotacion--;
  if (estadoRotacion == -1)
  {
    estadoRotacion = celdas.size() - 1;
  }
}