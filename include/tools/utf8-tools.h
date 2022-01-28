#ifndef UTF8_TOOLS_H
#define UTF8_TOOLS_H

#include <string>
#include <cstddef> //size_t

namespace tools {

//! Checks is the character marks the beginning of an UTF-8 sequence.

//! The UTF-8 marker is denoted as much 1 leftmost bits as the sequence lasts 
//! followed by a single 0 bit.
bool is_utf8(char _c);

//!Gets the number of characters in a string containing utf8 encoded characters.

//!Each utf8 character is encoded as at least two bits: the first one has 
//!a pattern of as much leading ones.as bytes are used in the character. We can
//!count byte by byte and skip the adequate amount when we find the mark.
size_t utf8_size(const std::string& _c);

//! Count leading ones for 8 bit characters.

//! Thanks to https://codingforspeed.com/counting-the-number-of-leading-zeros-for-a-32-bit-integer-signed-or-unsigned/ for the idea :).
size_t count_leading_ones(char _c);

//! Pops a character of a string, utf8 compatible.
void utf8_pop(std::string&);
}

#endif
