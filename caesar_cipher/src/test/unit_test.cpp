
#include"unit_test.h"

void unit_test(std::string encode, std::string decode){
	if(encode == decode){
		std::cout<<"Test case was complited"<<std::endl;
	}else{
		std::cout<<"Test failed :("<<std::endl;
	}
}
