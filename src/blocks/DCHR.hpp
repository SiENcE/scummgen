#ifndef _DCHR_BLOCK_HPP_
#define _DCHR_BLOCK_HPP_

#include <fstream>
#include <stdint.h>
#include <vector>
using namespace std;

class LFLF;

class DCHR
{
private:
	uint16_t _nItems;
	vector<uint8_t> _ids;
	vector<uint32_t> _offsets;

	uint32_t getSize();
public:
	DCHR(LFLF *lflf);
	void write(fstream &f);
	~DCHR();
};

#endif

