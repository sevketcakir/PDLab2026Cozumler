#include<iostream>
using namespace std;
class Complex {
    private:
    int re,im; // re: gerçek kısmı, im: sanal kısmı
    public:
    // Yapıcı metot
    Complex(int r, int i):re(r), im(i) { }
    // Çıkarma operatörü aşırı yükleme
    Complex operator-(const Complex &diger) const {
        return Complex(re-diger.re, im-diger.im);
    }
    // Eksi operatörü aşırı yükleme(tekli)
    Complex operator-() const {
        return Complex(-re, -im);
    }
    // << operatörü aşırı yükleme
    friend ostream& operator<< (ostream &out, const Complex &c) {
        out << "(" << c.re << "," << c.im << "i)" << endl;
        return out;
    }
    // + operatörü aşırı yükleme
    Complex operator+(const Complex &diger) const {
        return Complex(re+diger.re, im+diger.im);
    }
    // * operatörü aşırı yükleme
    Complex operator*(const Complex &diger) const {
        return Complex(re*diger.re-im*diger.im, re*diger.im+im*diger.re);
    }
    // [] operatörü aşırı yükleme
    int operator[] (int index) const {
        // index 0: gerçek kısmı, index 1: sanal kısmı
        if(index == 0) return re;
        else return im;
    }
};
