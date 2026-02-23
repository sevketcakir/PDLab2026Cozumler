/**
 * Taş-kağıt-makas uygulaması:
 * İki oyuncudan alınan hamle girişlerine göre kazananı belirler.
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Oyuncuların hamlelerini tutacak değişkenler (taş, kağıt veya makas)
    string o1, o2;

    // Kullanıcıdan hamle girişlerini al (Örn: taş kağıt)
    cin >> o1 >> o2;

    // 1. Durum: Hamleler aynıysa oyun berabere biter.
    if(o1 == o2) {
        cout << "berabere";
    }
    // 2. Durum: Birinci oyuncunun kazandığı tüm ihtimallerin kontrolü
    // Taş makası, kağıt taşı, makas kağıdı yener.
    else if(  (o1 == "taş" && o2 == "makas")
            || (o1 == "kağıt" && o2 == "taş")
            || (o1 == "makas" && o2 == "kağıt")) 
    {
        cout << "birinci oyuncu kazandı";
    }
    // 3. Durum: Beraberlik yoksa ve birinci oyuncu kazanmadıysa, ikinci oyuncu kazanmıştır.
    else {
        cout << "ikinci oyuncu kazandı";
    }

    return 0;
}