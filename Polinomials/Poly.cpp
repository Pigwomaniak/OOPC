//
// Created by maciek on 01/11/2019.
//

#include "Poly.h"
Poly::Poly(){
	
}
Poly::Poly(double src){
	data[0] = src;
}
double& Poly::operator[](const unsigned int key){
	return data[key];
}

Poly& Poly::operator = (const Poly& src){
	data.clear();
	data = src.data;
	return *this;
}

std::ostream& operator << (std::ostream& out, const Poly& src){
	for(auto& [key, value]: src.data){
		out << "+" << value << "x^" << key << " ";
	}
	out << std::endl;
	return out;
}

Poly Poly::operator + (const Poly& src){
	for(auto& [key, value]: src.data){
		data[key] += value;
	}
	return *this;
}
