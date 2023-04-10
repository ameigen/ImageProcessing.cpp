#pragma once

#include "escapi.h"
#include <SDL.h>
#include <iostream>

namespace WebcamProcessing
{
    void processFrame(SDL_Surface **surface, SimpleCapParams capture);
};