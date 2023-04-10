#include "WebcamProcess.hpp"

void WebcamProcessing::processFrame(SDL_Surface **surface, SimpleCapParams capture)
{
    *surface = SDL_CreateRGBSurfaceFrom(
        capture.mTargetBuf,
        capture.mWidth,
        capture.mHeight,
        32,
        capture.mWidth * 4,
        0xFF000000, // Red mask
        0x00FF0000, // Green mask
        0x0000FF00, // Blue mask
        0x000000FF  // Alpha mask
    );
}