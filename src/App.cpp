#include "App.hpp"

App::App(const char *name, unsigned width, unsigned height)
{
    _running = false;
    _window = nullptr;
    _renderer = nullptr;
    _maxFrameRate = 144;
    _timeSinceLastFrame = 0;
    _deltaTime = 0;
    if (init(name, width, height))
        run();
}

App::~App()
{
    std::cout << "Closing App\n";
}

bool App::init(const char* name, unsigned width, unsigned height)
{
    _windowWidth = width;
    _windowHeight = height;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Error with SDL Initialization." << '\n';
        return false;
    }
    _window = SDL_CreateWindow(
                                        name, 
                                        SDL_WINDOWPOS_CENTERED, 
                                        SDL_WINDOWPOS_CENTERED, 
                                        _windowWidth, 
                                        _windowHeight, 
                                        0);
    if (!_window)
    {
        std::cout << "Error with SDL window initialization." << '\n';
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!_renderer)
    {
        std::cout << "Error with SDL window initialization." << '\n';
        return false;
    }

    if (!_capture.init())
    {
        std::cout << "Error with initalizing webcam capture." << '\n';
    }
    _running = true;
    return true;
}

void App::run()
{
    std::cout << "Application starting..." << '\n';
    while (_running)
    {
        processInput();
        update();
        render();
    }
}

void App::processInput()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                _running = false;
                break;
            case SDL_KEYDOWN:
                _handleKeyDownEvents(event);
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    _running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                _handleMouseButtonEvents(event);
                break;
            case SDL_MOUSEMOTION:
                _handleMouseMotionEvents(event);
                break;
            case SDL_WINDOWEVENT:
                _handleWindowEvents(event);
                break;
            default:
                break;
        }
    }
}

void App::update()
{
    _capProcessTime();
    doCapture(_capture.getCam());
    while (isCaptureDone(_capture.getCam()) == 0) {}
            /*
                Need to fix these functions, they do not 
                currently create the frame data correctly.
            */
            WebcamProcessing::processFrame(&_capture.camFramePre , *_capture.getCamera());
            WebcamProcessing::processFrame(&_capture.camFramePost , *_capture.getCamera());
}

void App::render()
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, _capture.camFramePre);
    SDL_RenderClear(_renderer);
    SDL_RenderCopy(_renderer, texture, NULL, new SDL_Rect{((int)_windowWidth / 2) - 640, ((int)_windowHeight / 2) - 480, 640, 480});
    SDL_RenderPresent(_renderer);
}

void App::close()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void App::_capProcessTime()
{
    unsigned waitTime = (_maxFrameRate / 1000) - (SDL_GetTicks() - _timeSinceLastFrame);
    if (waitTime > 0 && waitTime <= (_maxFrameRate / 1000))
        SDL_Delay(waitTime);
    _deltaTime = (SDL_GetTicks() - _timeSinceLastFrame) / 1000.0;
    _timeSinceLastFrame = SDL_GetTicks();
}

void App::_handleKeyDownEvents(SDL_Event &event)
{
    std::cout <<
    event.key.keysym.scancode <<
    '\n';
}

void App::_handleWindowEvents(SDL_Event &event)
{
    std::cout <<
    event.window.type <<
    '\n';
}

void App::_handleMouseMotionEvents(SDL_Event &event)
{
    std::cout <<
    "Mouse Movement At(" <<
    event.motion.x <<
     ',' <<
    event.motion.y <<
    ")\n";
}

void App::_handleMouseButtonEvents(SDL_Event &event)
{
    std::cout << 
    "Mouse Button: " <<
    (int)event.button.button <<
    " clicked at (" <<
    event.button.x <<
    ',' <<
    event.button.y <<
    ")\n";
}