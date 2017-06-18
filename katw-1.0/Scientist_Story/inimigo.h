#pragma once

#include "personagem.h"

#define TIMERS_N 3
#define VAR_BOOL_N 5
#include "itemobj.h"
class InimigoBase : public Personagem
{
    public:
        InimigoBase();
        int typeInimigo;
        bool hitWall;

    public:
        virtual void onDead();
        virtual void executaColisao();
        virtual void onAI();
        virtual void update(unsigned int dt);
        virtual void render();
        virtual void onNotValidPosition(bool isX);

        Timer timer[TIMERS_N]; //Timers para uso geral
        bool var[VAR_BOOL_N]; //Boleanas para uso geral

};

class InimigoBoss : public InimigoBase
{
    public:
        InimigoBoss();
        Timer timerSpawn;
        int size_ent;

    public:
        virtual void onDead();
        virtual void executaColisao();
        virtual void onAI();
        virtual void update(unsigned int dt);
        virtual void render();

        void spawnEnemy();

};


#define BOSS_WAIT_L 0
#define BOSS_WAIT_R 1
#define BOSS_TELEPORTE 2
#define BOSS_UN_TELEPORTE 3
#define BOSS_CHARGE 4
#define BOSS_UNCHARGE 5
#define BOSS_ATK 6

class InimigoLastBoss : public InimigoBase
{
    public:
        InimigoLastBoss();
        ~InimigoLastBoss();
        Timer timerTeleporte;
        Timer timerAtira;

        Tiro* tiro;

    public:
        virtual void onDead();
        virtual void executaColisao();
        virtual void onAI();
        virtual void update(unsigned int dt);
        virtual void render();

        void atira();

};
