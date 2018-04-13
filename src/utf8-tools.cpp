#include "utf8-tools.h"

#include <iostream> //TODO: Remove.

using namespace tools;

bool tools::is_utf8(char _c) {
	return _c & 128;
}

size_t tools::utf8_size(const std::string& _c) {

	size_t res=0;
	for(size_t i=0; i < _c.size(); i++) {

		if(is_utf8(_c[i])) {
			++res;
			i+=count_leading_ones(_c[i])-1;
		}
		else {
			++res;
		}
	}

	return res;
}

size_t tools::count_leading_ones(char _c) {

	size_t res = 0;
	while(1) {
		if(!(_c  & 128)) break; //We will go on while there is a one in the leftmost bit.
		++res;
		_c <<= 1; //Bitshifting 1 position to the left will add zeroes to the right and consume ones from the left.

	}
	return res;
}

void tools::utf8_pop(std::string& _s) {

	if(_s.size() && !is_utf8(_s.back())) {
		_s.pop_back();
	}
	else {
		while(_s.size()) {
			_s.pop_back();
			if(!is_utf8(_s.back())) break;
		}
	}
}
