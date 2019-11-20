//
// Created by maciek on 01/11/2019.
//
#pragma once
#include <map>
#include <iostream>
#include <functional>


class Poly {
private:
	std::map<unsigned int, double, std::greater<>>	data;
public:
	Poly();
	Poly(double src);
	Poly(const Poly& src);
	double& operator [] (unsigned int key);
	double operator () (double x) const;
	friend std::ostream& operator << (std::ostream& out, const Poly& src);
	Poly& operator = (const Poly& src);
    friend Poly operator + (const Poly& prev, const Poly& src);
    friend Poly operator - (const Poly& prev, const Poly& src);
    friend Poly operator * (const Poly& prev, const Poly& src);
    friend Poly operator - (const Poly& src);
};
