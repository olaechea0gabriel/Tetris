// Bloques.cpp

#include "Bloque.h"
#include "Posicion.h"

class BloqueL : public Bloque
{
  public:
      BloqueL()
      {
          id = 1;
          celdas[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
          celdas[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
          celdas[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
          celdas[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
          Mover(0, 3);
      }
};

class BloqueJ : public Bloque
{
  public:
      BloqueJ()
      {
          id = 2;
          celdas[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
          celdas[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
          celdas[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
          celdas[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
          Mover(0, 3);
      }
};

class BloqueI : public Bloque
{
  public:
      BloqueI()
      {
          id = 3;
          celdas[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
          celdas[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
          celdas[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
          celdas[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
          Mover(-1, 3);
      }
};

class BloqueO : public Bloque
{
  public:
      BloqueO()
      {
          id = 4;
          celdas[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
          Mover(0, 4);
      }
};

class BloqueS : public Bloque
{
  public:
      BloqueS()
      {
          id = 5;
          celdas[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
          celdas[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
          celdas[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
          celdas[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
          Mover(0, 3);
      }
};

class BloqueT : public Bloque
{
  public:
      BloqueT()
      {
          id = 6;
          celdas[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
          celdas[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
          celdas[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
          celdas[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
          Mover(0, 3);
      }
};

class BloqueZ : public Bloque
{
  public:
      BloqueZ()
      {
          id = 7;
          celdas[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
          celdas[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
          celdas[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
          celdas[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
          Mover(0, 3);
      }
};