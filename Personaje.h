#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <vector>
#include <list>
#include <iostream>
#include <map>
using namespace std;

enum Estados
{
    INICIO,
    CERCA,
    ATACANDO_STARTUP,
    ATACANDO_ACTIVE,
    ATACANDO_RECOVERY,
    LEJOS,
    IZQUIERDA,
    DERECHA,
    ARRIBA,
    ABAJO,
    PARADO
};

enum ANIMACIONES
{
    ANIMACION_IDLE_RIGHT,
    ANIMACION_IDLE_LEFT,
    ANIMACION_WALKING_RIGHT,
    ANIMACION_WALKING_LEFT,
    ANIMACION_ATACANDO_STARTUP,
    ANIMACION_ATACANDO_ACTIVE,
    ANIMACION_ATACANDO_RECOVERY
};

class Personaje
{
    public:
        list<Personaje*> *personajes;
        int estado_actual;
        map< int, vector<SDL_Texture*>* > mapa_texturas;
        SDL_Texture* hitbox_azul;
        SDL_Texture* hitbox_roja;
        SDL_Rect rect,hitbox;
        int frame;
        int textura_actual_int;
        bool atacando;
        bool muerto;
        int animacion_actual;

        virtual void draw(SDL_Renderer* renderer);
        virtual void act()=0;
        void init(SDL_Renderer* renderer, list<Personaje*> *personajes);
        bool colision(SDL_Rect param);
        void attackCheck();
        void setAnimacion(int nombre);

        virtual bool soySho();

        Personaje();
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
