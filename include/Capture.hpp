#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <SDL.h>

#include "escapi.h"
class Capture
{
    public:
        Capture() { ; }
        ~Capture() { ; }

        bool init();
        unsigned getCam() { return _selectedCam; }
        SimpleCapParams *getCamera() { return &_capture; }

        SDL_Surface *camFramePre = nullptr;
        SDL_Surface *camFramePost = nullptr;

    private:
        SimpleCapParams _capture;
        unsigned _selectedCam;
        int _camCount = 0;
        char _flag = 'a';
        unsigned int _width = 640,
                     _height = 480;
};