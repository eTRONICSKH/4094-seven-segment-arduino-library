//4094shiftRegisterSevenSeg.cpp

#include "Arduino.h"
#include "4094shiftRegisterSevenSeg.h"
#include "CharacterEncoding.h"

4094shiftRegisterSevenSeg::4094shiftRegisterSevenSeg(uint8_t data_pin, uint8_t clock_pin, uint8_t strobe_pin):_data_pin(data_pin), _clk_pin(clock_pin), _str_pin(strobe_pin){
  // Default Constructor of EmSevenSegment class
}

void 4094shiftRegisterSevenSeg::begin(bool type, uint8_t digit){
	_seg_type 	= type;
	_digit_num 	= digit;
	pinMode(_data_pin, OUTPUT);
	pinMode(_clk_pin, OUTPUT);
	pinMode(_str_pin, OUTPUT);
}

void 4094shiftRegisterSevenSeg::shiftOutData(int segmentBuffer[]){
	digitalWrite(_str_pin, LOW);
	for(int i=_digit_num-1;i>=0;i--){
		shiftOut(_data_pin, _clk_pin, MSBFIRST, segChar[segmentBuffer[i]]);
	}
	digitalWrite(_str_pin, HIGH);
}