//
// Created by maciek on 01/11/2019.
//

#include "Poly.h"
#include <cmath>

Poly::Poly(){
	data[0] = 0;
}
Poly::Poly(double src){
	data[0] = src;
}
Poly::Poly(const Poly &src) {
    data = src.data;
}
double& Poly::operator[](unsigned int key){
	return data[key];
}

Poly& Poly::operator = (const Poly& src){
	data.clear();
	data = src.data;
	return *this;
}

std::ostream& operator << (std::ostream& out, const Poly& src){
	for(auto& element: src.data){
	    if(element.second > 0){
	        out << "+";
	    }
		out << element.second;
	    if(element.first != 0){
	        out << "x^" << element.first << " ";
	    }
	}
	out << std::endl;
	return out;
}

Poly operator + (const Poly& prev, const Poly& src){
    Poly out = prev;
	for(auto& element: src.data){
		out.data[element.first] += element.second;
	}
	return out;
}

Poly operator - (const Poly& prev, const Poly& src){
    Poly out = prev;
    for(auto& element: src.data){
        out.data[element.first] -= element.second;
        if(out.data[element.first] == 0){
            out.data.erase(element.first);
        }
    }
    if(out.data.empty()){
        out[0] = 0;
    }
    return out;
}

Poly operator * (const Poly& prev, const Poly& src){
    Poly out;
    for(auto& srcElement: src.data){
        for(auto& prevElement: prev.data){
            out.data[srcElement.first + prevElement.first] += srcElement.second * prevElement.second;
        }
    }
    return out;
}

Poly operator - (const Poly& src){
    Poly out;
    out = out - src;
    return out;
}

double Poly::operator()(double x) const {
    double out = 0;
    for(auto& element: data){
        out += element.second * pow(x, element.first);
    }
    return out;
}