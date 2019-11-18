//
// Created by maciek on 01/11/2019.
//
#pragma once
#include <map>
#include <iostream>


class Poly {
private:
	std::map<unsigned int, double> 	data;
public:
	Poly();
	Poly(double src);
	Poly(const Poly* src);
	double& operator [] (const unsigned int key);
	friend std::ostream& operator << (std::ostream& out, const Poly& src);
	Poly& operator = (const Poly& src);
	Poly operator + (const Poly& src);
	//Poly& operator - (const Poly src);
	//Poly& operator * (const Poly src);
};
