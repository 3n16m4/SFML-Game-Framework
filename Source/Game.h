#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "States/StateBase.h"

class Game
{
    public:
        Game();

        void run();

        template<typename T, typename... Args>
        void pushState(Args&&... args);

        void popState();

    private:
        void handleEvents();
        void tryPop();

        StateBase& getCurrentState();

        sf::RenderWindow m_window;
        std::vector<std::unique_ptr<StateBase>> m_states;

        bool m_shouldPop = false;

};

template<typename T, typename... Args>
void Game::pushState(Args&&... args)
{
    m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
}

#endif // GAME_H_INCLUDED
