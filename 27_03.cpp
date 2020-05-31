#include <iostream>
#include <math.h>
#include <fstream>
#icnlude <complex.h>
#include <cmath>
#include <cstdlib>
#include "Header.h"
#define N 6
#define pi 3.14159265358979
using namespace std;
//generate creates consiquence
void generate() {
	int v1,v2;
	ofstream rea_l;
	rea_l.open("real.txt");
	ofstream imagi;
	imagi.open("imaginary.txt");
	for (int i = 0; i < N; i++) {
		//after % symb, set range of numb 
		v1 = rand() % 10;
		v2 = rand() % 10;
		imagi << v2 << " ";
		rea_l << v1 <<" ";
	}
	rea_l.close();
	imagi.close();
}
//own class of Complex numbers
class Complex {
private:
	double re, im;
public:
	Complex() {};
	Complex(double r, double i) {
		re = r;
		im = i;
	}
	void show() {
		cout << "{" << re << "+i" << im << "}";
	}
	Complex add(Complex x);
	Complex multipl(Complex x);
	Complex Forier(Complex x);
	Complex revForier(Complex x);
};
//complex multiplication
Complex Complex::multipl(Complex x) {
	Complex z(re * x.re - im * x.im, x.re * im + x.im * re);
	return z;
}
//compex addition
Complex Complex::add(Complex x) {
	Complex z(re + x.re, im + x.im);
	return z;
}

Complex Complex::Forier(Complex x) {
	ifstream rea_l, imagi;
	rea_l.open("real.txt");
	imagi.open("imaginary.txt");
	//ofstream - output, ifstream - input
	ofstream res_real, res_imag;
	res_real.open("real_res.txt");
	res_imag.open("imag_res.txt");
	double real[N];
	double imag[N];
	double result;
	double Imag_result;
	for (int a = 0; a < N; a++) {
		rea_l >> real[a];
		imagi >> imag[a];
	}
	//Fourier transform
	for (int k = 0; k < N; k++) {
		result = 0;
		Imag_result = 0;
		for (int n = 0; n < N ; n++) {
			double temp_re = 0;
			double temp_im = 0;
			temp_re = real[n] * cos(2 * pi * k * n / N) + imag[n] * sin(2 * pi * k * n / N);
			temp_im = imag[n] * cos(2 * pi * k * n / N) - real[n] * sin(2 * pi * k * n / N);
			result += temp_re;
			Imag_result += temp_im;
		}
		res_real << result << " ";
		res_imag << Imag_result << " ";
	}
	rea_l.close();
	imagi.close();
	res_real.close();
	res_imag.close();
	Complex f(result, Imag_result);
	return f;
}
//Reverse Fourier transform
Complex Complex::revForier(Complex x) {
	ifstream input_real, input_imag;
	input_real.open("real_res.txt");
	input_imag.open("imag_res.txt");
	//
	ofstream output_real, output_imag;
	output_real.open("reverse_res_real.txt");
	output_imag.open("reverse_res_imag.txt");
	double re_real[N], re_imag[N];
	double re_result, Imag_result;
	double arr_re[N],arr_im[N];
	double re_temp, im_temp;
	for (int a = 0; a < N; a++) {
		input_real >> re_real[a];
		input_imag >> re_imag[a];
	}
	for (int k = 0; k < N; k++) {
		re_result = 0;
		Imag_result = 0;
		for (int n = 0; n < N; n++) {
			double temp_re = 0;
			double temp_im = 0;
			temp_re = re_real[n] * cos(2 * pi * k * n / N) + re_imag[n] * sin(2 * pi * k * n / N);
			temp_im = re_imag[n] * cos(2 * pi * k * n / N) - re_real[n] * sin(2 * pi * k * n / N);
			re_result += (temp_re/N);
			Imag_result += (temp_im/N);
		}
		arr_re[k] = re_result;
		arr_im[k] = Imag_result;
		//output_real << re_result << " ";
		//output_imag << Imag_result << " ";
	}
	output_imag << arr_im[0] << " ";
	output_real << arr_re[0] << " ";
	for (int iter = 1; iter < N; iter++) {
		output_imag << arr_im[N - iter] << " ";
		output_real << arr_re[N - iter] << " ";
	}
	input_real.close();
	input_imag.close();
	output_real.close();
	output_imag.close();
	Complex e(re_result, Imag_result);
	return e;
}

int main() {
	generate();
	Complex a(1.2,2);
	Complex f = a.Forier(a);
	f.show();
	Complex e = a.revForier(a);
	e.show();
}
