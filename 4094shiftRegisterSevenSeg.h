#ifndef 4094shiftRegisterSevenSeg_h
#define 4094shiftRegisterSevenSeg_h

#include "Arduino.h"

#define CATHODE 1
#define ANODE 	0

class 4094shiftRegisterSevenSeg{
public:
	4094shiftRegisterSevenSeg(uint8_t data_pin, uint8_t clock_pin, uint8_t strobe_pin);
	void begin(bool type, uint8_t digit);

private:
	bool 	_seg_type;
	uint8_t _digit_num;
	uint8_t _data_pin;
	uint8_t _clk_pin;
	uint8_t _str_pin;

	char _main_buffer[];

	void shiftOutData(int segmentBuffer[]);

};

#endif
