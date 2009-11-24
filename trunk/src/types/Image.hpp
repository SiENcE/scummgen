#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include <string>
#include <vector>
using namespace std;

class Cycle;
class Palette;
class XMLNode;

class Image
{
private:
	static const string XML_FILE_NAME;

	string _name;
	bool _transparent;
	string _bitmapPath;
	vector<string> _zPlanePaths;
	uint32_t _width;
	uint32_t _height;
	vector<vector<uint8_t> > _pixels;
	vector<Cycle *> _cycles;
public:
	Image();
	void load(string dirPath);
	void save(string dirPath);
	void fillPalette(Palette *palette, bool global);
	string getName() { return _name; }
	bool isTransparent() { return _transparent; }
	uint16_t getNumberOfZPlanePaths() { return _zPlanePaths.size(); }
	string getZPlanePath(uint16_t index) { return _zPlanePaths[index]; }
	uint32_t getWidth() { return _width; }
	uint32_t getHeight() { return _height; }
	uint32_t getPixel(uint32_t x, uint32_t y) { return _pixels[x][y]; }
	~Image();
};

#endif
