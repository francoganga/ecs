#pragma once

#include "entity.h"
#include "entity_manager.h"

#include <SFML/Graphics.hpp>

class Game
{
    sf::RenderWindow m_window;
    EntityManager m_entities;
    sf::Font m_font;
    sf::Text m_text;
    sf::Clock m_deltaClock;
    int m_score = 0;
    int m_currentFrame = 0;
    bool m_running = true;
    std::shared_ptr<Entity> m_player;

    void init();
    void spawnPlayer();
    void sEnemySpawner();
    void spawnSmallEnemies(std::shared_ptr<Entity> e);
    void spawnBullet(std::shared_ptr<Entity> e, const Vec2& target);
    void spawnSpecialWeapon(std::shared_ptr<Entity> e);
    void sMovement();
    void sLifespan();
    void sCollision();
    void sUserInput();
    void sGUI();

    void sRender();
    void sInput();
    public:
    Game();
    void run();

};
