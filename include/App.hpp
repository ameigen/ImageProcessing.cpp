#pragma once

#include <string>
#include <iostream>
#include <SDL.h>
#include "Capture.hpp"
#include "escapi.h"
#include "WebcamProcess.hpp"

class App
{
    public:
        App(const char* name = "SDL_App", unsigned width = 1280, unsigned height = 720);
        ~App();

        bool init(const char* name, unsigned, unsigned height);
        void run();
        void processInput();
        void update();
        void render();
        void close();

    private:
        bool _running;
        double _deltaTime;
        unsigned _windowWidth,
                 _windowHeight,
                 _timeSinceLastFrame,
                 _maxFrameRate;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        Capture _capture; 
        void _capProcessTime();
        void _handleKeyDownEvents(SDL_Event &event);
        void _handleWindowEvents(SDL_Event &event);
        void _handleMouseMotionEvents(SDL_Event &event);
        void _handleMouseButtonEvents(SDL_Event &event);



                
};