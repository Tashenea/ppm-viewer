
#include "PpmWindow.hpp"
int main(int argc, char* argv[])
{
	PpmWindow win{ 0, 0, 500, 500, "PPM Viewer" };
	win.end();
	win.show();
	return Fl::run();
}