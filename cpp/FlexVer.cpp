/**
 * FlexVer C++
 * A parser for the FlexVer (<https://github.com/unascribed/FlexVer>) version standard
 *
 * LICENSED UNDER CC0 1.0:
 * 	To the extent possible under law, the author has dedicated all copyright
 * 	and related and neighboring rights to this software to the public domain
 * 	worldwide. This software is distributed without any warranty.
 * 	See <https://creativecommons.org/publicdomain/zero/1.0/>
 */

#include "FlexVer.hpp"

bool FlexVer::compare( const FlexVer &other ) {
	return false;
}

std::string FlexVer::to_string() const {
	return std::string();
}

bool FlexVer::operator==( const FlexVer &other ) const {
	return false;
}
bool FlexVer::operator<( const FlexVer& other ) const {
	return false;
}
bool FlexVer::operator<=( const FlexVer& other ) const {
	return false;
}
bool FlexVer::operator>( const FlexVer& other ) const {
	return false;
}
bool FlexVer::operator>=( const FlexVer& other ) const {
	return false;
}

