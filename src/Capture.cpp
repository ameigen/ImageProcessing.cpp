#include "Capture.hpp"

bool Capture::init()
{
    _camCount = setupESCAPI();
    if (_camCount == 0)
        return false;

    _capture.mHeight = _height;
    _capture.mWidth = _width;
    _capture.mTargetBuf = new int[_capture.mHeight * _capture.mWidth];
    _selectedCam = 0;
    /*
    for (int i = 0; i < _camCount; i++)
    {
        char* name = (char*)malloc(100);
        getCaptureDeviceName(i, name, 100);
		std::cout << "Device ID:" << i << '\n' << '\t' << name << std::endl;
		std::cout << std::endl;
	}
    int selectedCam;
	std::cout << "Please enter the ID of the desired device. Default = 0.\n";
	std::cin >> selectedCam;
	if (selectedCam > _camCount)
		selectedCam = 0;
    */
    char* name = (char *)malloc(100);
    getCaptureDeviceName(0, name, 100);
    std::cout << "Using capture device \"" << std::string(name) << "\"\n";
	if (initCapture(_selectedCam, &_capture) == 0)
		return false;
    return true;
}