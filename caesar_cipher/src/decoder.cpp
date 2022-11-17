#include"decoder.h"
#include<iostream>
std::string decoder(std::string text, int key){
std::string output;


if(!key){
	return "no valid key";
}
else{
	if(key < -26){
		key = (key % 26) + 26;
	}
	else if(key > -26 && key < 0) {
		key = 26 - (-1 *(key));
	}
	else if(key > 26){
		key = key % 26;
	}
	int b = 0;
	for(int i = 0; i < text.size(); i++){	
		if(int(text[i]) == 32||int(text[i]) == 33|| int(text[i])==44 || int(text[i])==46 || int(text[i])==63){
			b = int(text[i]);
		}
		else if(int(text[i]) >= 65 && int(text[i]) <= 90){
			b =int(text[i]) - key;			
			if(b < 65){
				b = b + 26;
			}	
		}else if(int(text[i]) >= 97 && int(text[i]) <= 122){
			b =int(text[i]) - key;
			if(b < 97){
				b = b + 26;
			}
		
		}else{
			return "Undefined";
		}
	
		output += char(b);
		} 	
		return output;	
	}
}


