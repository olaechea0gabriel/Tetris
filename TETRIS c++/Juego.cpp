// Juego.cpp

#include "Juego.h"
#include <random>

Juego::Juego()
{
    tablero = Tablero();
    bloques = ObtenerBloques();
    BloqueActual = ObtenerBloqueRandom();
    nextBlock = ObtenerBloqueRandom();
    gameOver = false;
    score = 0;
    InitAudioDevice();
    musica = LoadMusicStream("Sounds/music.mp3");
    PonerMusica(music);
    RotarS = LoadSound("Sounds/rotate.mp3");
    VaciarS = LoadSound("Sounds/clear.mp3");
}

Juego::~Juego()
{
    UnloadSound(RotarS);
    UnloadSound(VaciarS);
    UnloadMusicStream(musica);
    CloseAudioDevice();
}

Bloque Juego::ObtenerBloqueRandom()
{
    if (bloques.empty())
    {
        bloques = GetBloques();
    }
    int randomIndex = rand() % bloques.size();
    Bloque bloque = bloques[randomIndex];
    bloques.erase(bloques.begin() + randomIndex);
    return bloque;
}

std::vector < Bloque > Juego::GetBloques()
{
    return {BloqueI(), BloqueJ(), BloqueL(), BloqueO(), BloqueS(), BloqueT(), BloqueZ()};
}

void Juego::Dibujar()
{
    tablero.Dibujar();
    BloqueActual.Dibujar(11, 11);
    switch (SiguienteBloque.id)
    {
      case 3:
          SiguienteBloque.Dibujar(255, 290);
          break;
      case 4:
          SiguienteBloque.Dibujar(255, 280);
          break;
      default:
          SiguienteBloque.Dibujar(270, 270);
          break;
    }
}

void Juego::ManejarDatosEntrada()
{
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoverBloqueI();
        break;
    case KEY_RIGHT:
        MoverBloqueD();
        break;
    case KEY_DOWN:
        MoverBloqueAbajo();
        UpdateScore(0, 1);
        break;
    case KEY_UP:
        RotarBloque();
        break;
    }
}

void Juego::MoverBloqueI()
{
    if (!gameOver)
    {
        BloqueActual.Mover(0, -1);
        if (BloquePorFuera() || BloqueFits() == false)
        {
            BloqueActual.Mover(0, 1);
        }
    }
}

void Juego::MoverBloqueD()
{
    if (!gameOver)
    {
        BloqueActual.Mover(0, 1);
        if (BloquePorFuera() || BloqueFits() == false)
        {
            BloqueActual.Mover(0, -1);
        }
    }
}

void Juego::MoverBloqueAbajo()
{
    if (!gameOver)
    {
        BloqueActual.Mover(1, 0);
        if (BloquePorFuera() || BloqueFits() == false)
        {
            BloqueActual.Mover(-1, 0);
            LockBloque();
        }
    }
}

bool Juego::BloquePorFuera()
{
    std::vector < Posicion > teclas = BloqueActual.GetPosicionCeldas();
    for (Posicion item : teclas)
    {
        if (tablero.AfueraDeCelda(item.fila, item.columna))
        {
            return true;
        }
    }
    return false;
}

void Juego::RotarBloque()
{
    if (!gameOver)
    {
        BloqueActual.Rotar();
        if (A() || BloqueFits() == false)
        {
            BloqueActual.UndoRotacion();
        }
        else
        {
            PonerMusica(RotarS);
        }
    }
}

void Game::LockBloque()
{
    std::vector < Posicion > teclas = BloqueActual.GetCellPositions();
    for (Posicion item : teclas)
    {
        tablero.tablero[item.fila][item.columna] = BloqueActual.id;
    }
    BloqueActual = SiguienteBloque;
    if (BloqueFits() == false)
    {
        gameOver = true;
    }
    SiguienteBloque = GetBloqueRandom();
    int FilasVaciadas = tablero.VaciarFilasLlenas();
    if (FilasVaciadas > 0)
    {
        PonerSonido(VaciarS);
        UpdateScore(filasVaceadas, 0);
    }
}

bool Juego::BloqueFits()
{
    std::vector < Posicion > teclas = BloqueActual.GetPosicionesDeCelda();
    for (Posicion item : teclas)
    {
        if (tablero.CeldaVacia(item.fila, item.columna) == false)
        {
            return false;
        }
    }
    return true;
}

void Juego::Reset()
{
    tablero.Inicializar();
    bloquess = GetBloques();
    BloqueActual = GetBloqueRandom();
    SiguienteBloque = GetBloqueRandom();
    score = 0;
}

void Juego::UpdateScore(int LineasVaciadas, int PuntosAlBajar)
{
    switch (LineasVaciadas)
    {
      case 1:
          score += 100;
          break;
      case 2:
          score += 300;
          break;
      case 3:
          score += 500;
          break;
      default:
          break;
    }

    score += PuntosAlBajar;
}