// Tablero.h
#include "Tablero.h"
#include <vector> 
#include <raylib.h> // To create a graphical programs. 

class Tablero
{
  public:
      Tablero();
      void Inicializar();
      void Imprimir();
      void Dibujar();
      bool AfueraDeCelda(int fila, int columna);
      bool CeldaVacia(int fila, int columna);
      int VaciarFilaLlena();
      int tablero[20][10];

  private:
      bool FilaLlena(int fila);
      void VaciarFila(int fila);
      void MoverFilaAbajo(int fila, int numFilas);
      int numFilas;
      int numColumnas;
      int tamanoCelda;
      std::vector < Color > colores;
};