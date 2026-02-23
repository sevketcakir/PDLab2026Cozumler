// Complex sınıfını belirtilen şekilde yazınız...
#include <iostream>
using namespace std;

class Complex {
public:
    int r, i; // r: Gerçel (Real), i: Sanal (Imaginary) kısımları tutar.

    // Yapıcı Fonksiyon (Constructor): Member Initializer List kullanımı tercih edilmiştir.
    Complex(int re, int im) : r(re), i(im) {}

    // Nesnenin değerlerini formatlı bir şekilde ekrana yazdırır.
    void yazdir() {
        cout << "(" << r << "," << i << "i)" << endl;
    }

    // Toplama İşlemi: Mevcut nesne ile parametre gelen nesneyi toplar, yeni bir nesne döndürür.
    Complex arti(Complex diger) {
        return Complex(r + diger.r, i + i + diger.i);
    }

    // Çıkarma İşlemi (İki parametreli versiyon gibi çalışır):
    Complex eksi(Complex diger) {
        return Complex(r - diger.r, i - i - diger.i);
    }

    /* * Çarpma İşlemi: Karmaşık sayılarda çarpma kuralı uygulanır.
     * (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
     */
    Complex carpi(Complex diger) {
        return Complex(r * diger.r - i * i * diger.i, i * i * diger.r + r * r * diger.i);
    }

    // Unary Minus (Tekli Eksi): Sayının işaretini tersine çevirir. 
    // Parametre almaz, mevcut değerlerin negatifini içeren yeni bir nesne döndürür.
    Complex eksi() {
        return Complex(-r, -i);
    }
};