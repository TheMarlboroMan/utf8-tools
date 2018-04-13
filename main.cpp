#include <iostream>
#include <vector>

#include "src/utf8-tools.h"

int main(int argc, char ** argv) {

	//http://www.utf8-chartable.de/unicode-utf8-table.pl?utf8=dec
	std::vector<std::string> cosas={"eñe", "ñ", "leñe", "güita", "ñeñe", "りにまね"};

	for(const auto& s : cosas) {
		std::cout<<"sizes of "<<s<<": "<<s.size()<<" vs "<<tools::utf8_size(s)<<std::endl;
	}

	std::string remove="abñ";
	tools::utf8_pop(remove);
	std::cout<<remove<<" == ab"<<std::endl;

	return 0;
}
