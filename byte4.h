#include <cstdint>

struct byte4 {
	uint8_t x, y, z, w;
	byte4() {}
	byte4(uint8_t x, uint8_t y, uint8_t z, uint8_t w) : x(x), y(y), z(z), w(w) {}
};