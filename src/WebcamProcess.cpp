#include "WebcamProcess.hpp"

void WebcamProcessing::processFrame(int x, int y, SDL_Surface* surface, SimpleCapParams capture)
{

    int id = y * capture.mWidth + x;
    
    int index = y * surface->pitch + x * surface->format->BytesPerPixel;
    Uint8 *pixel = (Uint8 *)surface->pixels + index;
    *pixel = capture.mTargetBuf[id];
}