//
// Created by maciek on 01/11/2019.
//
#pragma once
#include <map>


class Poly {
public:
	Poly();
	Poly(const Poly* src);
	double& operator [] (const double key);

private:
	std::map<double, double> 	data;
};
