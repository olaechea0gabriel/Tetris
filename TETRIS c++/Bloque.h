// Bloque.h

#include <vector>
#include <map>  // to order data so it can easily be looked up
#include "Posicion.h"
#include "Colores.h"

class Bloque
{
  public:
    Bloque();
    void Dibujar(int offsetX, int offsetY);
    void Mover(int filas, int columnas);
    std::vector <Posicion> GetPosicionCelda();
    void Rotar();
    void UndoRotar();
    int id;
    std::map <int, std::vector <Posicion> > celdas;

  private:
    int tamanoCelda;
    int estadoRotacion;
    std::vector < Color > colores;
    int filaOffset;
    int columnaOffset;
};