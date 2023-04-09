#pragma once

#include "escapi.h"
#include <SDL.h>
#include <iostream>

namespace WebcamProcessing
{
    void processFrame(int x, int y, SDL_Surface* surface, SimpleCapParams capture);
};