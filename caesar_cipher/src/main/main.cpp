#include<iostream>
#include "encoder.h"
#include "decoder.h"
#include "unit_test.h"


int main(){
		int key;

		
	while(true){
		std::string before_encoder;
		
		std::cout<<"Press word for run,and for stop put break"<<std::endl;	
		std::getline(std::cin,before_encoder);
		if(before_encoder == "break"){
			break;
		}
		std::cout<<"Press key"<<std::endl;
		std::cin>>key;	
       if (std::cin.fail())
       {
          std::cout<<"emergency regime activated!!!!"<<std::endl;
          std::cin.clear();  
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          return main();
       }
		std::string after_encoder = encoder(before_encoder, key);
		std::cout<<after_encoder<<std::endl;
		std::string after_decoder = decoder(after_encoder, key);
		unit_test(before_encoder,after_decoder);
		
		std::cin.ignore(10000, '\n');	
	}
return 0;
}
