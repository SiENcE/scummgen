#ifndef _COSTUME_HPP_
#define _COSTUME_HPP_

#include <stdint.h>
#include <string>
#include <vector>
using namespace std;

class Palette;
class PaletteData;
class XMLNode;

typedef enum
{
	ANIM_WEST,
	ANIM_EAST,
	ANIM_SOUTH,
	ANIM_NORTH
} AnimDirection;

class Anim
{
private:
	uint8_t _id;
	string _name;
	bool _loop;
	vector<vector<uint8_t> > _commands;

	void loadSubAnim(XMLNode *node, AnimDirection direction);
	void saveSubAnim(XMLNode *node, AnimDirection direction);
public:
	static const uint8_t N_DIRECTIONS;

	Anim();
	void load(XMLNode *node);
	void save(XMLNode *node);
	uint8_t getID() { return _id; }
	void setID(uint8_t id) { _id = id; }
	string getName() { return _name; }
	bool isLoop() { return _loop; }
	uint16_t getNumberOfCommands(AnimDirection direction) { return _commands[(int)direction].size(); }
	uint8_t getCommand(AnimDirection direction, uint16_t index) { return _commands[(int)direction][index]; }
	~Anim();
};

class Frame
{
private:
	string _bitmapPath;
	uint16_t _x;
	uint16_t _y;
	uint16_t _width;
	uint16_t _height;
	int16_t _xOffset;
	int16_t _yOffset;
	vector<vector<uint8_t> > _pixels;
public:
	Frame();
	void load(XMLNode *node, string dirPath);
	void save(XMLNode *node, string dirPath);
	void prepare(Palette *palette, PaletteData *paletteData, vector<uint8_t> &redirectionPalette);
	uint16_t getX() { return _x; }
	uint16_t getY() { return _y; }
	uint16_t getWidth() { return _width; }
	uint16_t getHeight() { return _height; }
	int16_t getXOffset() { return _xOffset; }
	int16_t getYOffset() { return _yOffset; }
	uint32_t getPixel(uint32_t x, uint32_t y) { return _pixels[x][y]; }
	~Frame();
};

class Costume
{
private:
	static const string XML_FILE_NAME;

	uint16_t _id;
	string _name;
	uint16_t _width;
	uint16_t _height;
	bool _mirror;
	vector<Anim *> _anims;
	vector<Frame *> _frames;
	vector<uint8_t> _redirectionPalette;
	PaletteData *_paletteData;
public:
	Costume();
	void load(string dirPath);
	void save(string dirPath);
	void prepare(Palette *palette);
	uint16_t getID() { return _id; }
	void setID(uint16_t id) { _id = id; }
	string getName() { return _name; }
	uint16_t getWidth() { return _width; }
	uint16_t getHeight() { return _height; }
	bool isMirror() { return _mirror; }
	uint32_t getNumberOfAnims() { return _anims.size(); }
	Anim *getAnim(uint32_t index) { return _anims[index]; }
	uint8_t getNumberOfFrames() { return _frames.size(); }
	Frame *getFrame(uint8_t index) { return _frames[index]; }
	uint8_t getNumberOfColors() { return _redirectionPalette.size(); }
	uint8_t getColor(uint8_t index) { return _redirectionPalette[index]; }
	~Costume();
};

#endif
