#include "game.h"
#include "imgui-SFML.h"
#include "imgui.h"
#include <iostream>


void Game::run()
{

    while (m_running) {

        m_entities.update();

        ImGui::SFML::Update(m_window, m_deltaClock.restart());

        sEnemySpawner();
        sCollision();
        sUserInput();
        sInput();
        sGUI();
        sRender();

        // TODO: when implementing pause move this
        m_currentFrame++;

    }

}

Game::Game() {
    init();
}

void Game::init()
{
    m_window.create(sf::VideoMode(1280, 720), "SFML works!");
    m_window.setFramerateLimit(60);

    bool res = ImGui::SFML::Init(m_window);

    assert(res);

    spawnPlayer();
}

void Game::spawnPlayer()
{
    auto entity = m_entities.addEntity("player");
    entity->cTransform = std::make_shared<CTransform>(Vec2(200.0f, 200.0f), Vec2(1.0f, 1.0f), 0.0f);

    entity->cShape = std::make_shared<CShape>(32.0f, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f);
    entity->cInput = std::make_shared<CInput>();

    m_player = entity;
}

void Game::sMovement()
{
    // TODO: implement all entity movement in this function
    // read m_player->cInput component to determine if the player is moving

    for (auto e : m_entities.getEntities())
    {
        // TODO implement
    }

    m_player->cTransform->pos.x += m_player->cTransform->velocity.x;
    m_player->cTransform->pos.y += m_player->cTransform->velocity.y;
}

void Game::sLifespan()
{
    // if entity has no lifespan comp skip
    // if has more than 0 lifespan subtract 1 from lifespan
    // scale alpha channel based on lifespan
    // if lifespan reaches 0 destroy entity

}

void Game::sCollision()
{
    // implement all proper collision between entities
    // use collision radius not shape
}

void Game::sGUI()
{
    ImGui::ShowDemoWindow();
}

void Game::sRender()
{
    m_window.clear();

    m_player->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);

    m_player->cTransform->angle += 1.0f;
    m_player->cShape->circle.setRotation(m_player->cTransform->angle);

    m_window.draw(m_player->cShape->circle);

    // draw the ui last 
    ImGui::SFML::Render(m_window);

    m_window.display();
}

void Game::sInput()
{
    sf::Event event;

    while (m_window.pollEvent(event))
    {
        // pass event to imgui

        if (event.type == sf::Event::Closed)
        {
            m_running = false;
        }

        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::W:
                    std::cout << "W key pressed\n";
                    // TODO: set players input component up to true
                    break;
                case sf::Keyboard::Escape:
                    m_running = false;
                default:
                    break;
            }
        }

        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::W:
                    std::cout << "W key released\n";
                    // TODO: set players input component up to false
                    break;
                default:
                    break;
            }
        }

        // IMGUI code for mouse

        ImGui::SFML::ProcessEvent(m_window, event);



    }
}

void Game::sUserInput()
{
}

void Game::sEnemySpawner()
{
}
