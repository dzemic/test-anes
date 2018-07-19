/*
 * Complex.cpp
 *
 *  Created on: Jul 13, 2018
 *      Author: andz8891
 */
#include "Complex.hpp"
using namespace std;

Complex::Complex (int r = 0, int i =0)
{
	real = r;
	imag = i;
}

// This is automatically called when '+' is used with
// between two Complex objects
// type class method
Complex Complex::operator + (Complex const &obj) {
     Complex res;
     res.real = Complex::real + obj.real;
     res.imag = Complex::imag + obj.imag;
     return res;
}

void Complex::get_complex() { cout << real << " + i omg" << imag << endl; }
//string Complex::get_complex() { return real + " + i omg" + imag; }

/*
 * #include "complex/Complex.hpp"
 *
 * vector<Complex> complex_vec;
	vector<Complex>::iterator it;

	srand(std::time(nullptr));
	//int random_variable = std::rand();
	//cout << "Random value on [0 " << RAND_MAX << "]: " << random_variable << '\n';

	for (int n=0; n != 20; ++n) {
		//cout << n << endl;
		int x = 1 + std::rand()/((RAND_MAX + 1u)/9);
		int y = 1 + std::rand()/((RAND_MAX + 1u)/9);
		int z = 1 + std::rand()/((RAND_MAX + 1u)/9);
		//cout << x << "|" <<y<< endl;
		Complex c1(x, y);
		Complex c2(z, x);
		Complex c3 = c1 + c2;
		complex_vec.push_back(c3);
	}

	cout << "Vector size : " << complex_vec.size() << endl;

	for (Complex &c : complex_vec) {
		c.print();
	}
 */

