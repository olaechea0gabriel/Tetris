// Juego.h

#include "Tablero.h"
#include "Bloques.cpp"

class Juego
{
  public:
     Juego();
      ~Juego();
      void Dibujar();
      void ManejarDatosEntrada();
      void MoverBloqueAbajo();
      bool gameOver;
      int score;
      Music musica;

  private:
      void MoverBloqueI();
      void MoverBloqueD();
      Bloque ObtenerBloqueRandom();
      std::vector < Bloque > GetBloques();
      bool BloquePorFuera();
      void RotarBloque();
      void LockBloque();
      bool BloqueFits();
      void Reset();
      void UpdateScore (int LineasVaceadas, int PuntosAlBajar);
      Tablero tablero;
      std::vector < Bloque > bloques;
      Bloque BloqueActual;
      Bloque siguienteBloque;
      Sound RotarS;
      Sound VaciarS;
};