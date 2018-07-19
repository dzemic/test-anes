/*
 * Complex.h
 *
 *  Created on: Jul 13, 2018
 *      Author: andz8891
 */
#include <iostream>
using namespace std;

#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex {
    int real, imag;
public:
    Complex(int r, int i);

    Complex operator + (Complex const &obj);
    void get_complex();
    //string get_complex();
};

#endif /* COMPLEX_H_ */
