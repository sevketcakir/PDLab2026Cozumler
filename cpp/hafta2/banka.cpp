#include <iostream>
using namespace std;

class BankaHesabi {
private:
    int hesapNo;
    double bakiye;

public:
    // 1. Parametreli Yapıcı (Constructor)
    // Öğrenci Görevi: hesapNo ve bakiye değişkenlerine ilk değer ataması yapınız.
    BankaHesabi(int no, double ilkBakiye) {
        this->hesapNo = no;
        this->bakiye = ilkBakiye;
    }
    // 2. paraYatir Metodu
    // Öğrenci Görevi: Gelen miktarı bakiyeye ekleyiniz.
    void paraYatir(double miktar) {
        bakiye += miktar;
    }
    // 3. paraCek Metodu
    // Öğrenci Görevi: Çekilmek istenen miktar bakiyeden küçük veya eşitse bakiyeden düşün ve true dönün.
    // Bakiye yetersizse işlem yapmayın ve false dönün.
    bool paraCek(double miktar) {
        if(miktar <= bakiye) {
            bakiye -= miktar;
            return true;
        }
        else 
            return false;
    }
    // 4. bakiyeYazdir Metodu
    // Öğrenci Görevi: Ekrana tam olarak "Hesap: [hesapNo] - Bakiye: [bakiye]" formatında yazdırın.
    // Örnek: "Hesap: 1001 - Bakiye: 500"
    void bakiyeYazdir() {
        cout << "Hesap: " << hesapNo << " - Bakiye: " << bakiye << endl;
    }
};

// --- DİKKAT: main fonksiyonunu değiştirmeyiniz (VPL testleri için gereklidir) ---
int main() {
    int islemTuru;
    int hNo;
    double miktar;
    
    // Başlangıç değerlerini okuma
    if (!(cin >> hNo >> miktar)) return 0; 
    
    BankaHesabi hesap1(hNo, miktar);
    
    // İşlem menüsü okuma dongüsü (1: Yatır, 2: Çek, 3: Yazdır)
    while(cin >> islemTuru) {
        if (islemTuru == 1) {
            cin >> miktar;
            hesap1.paraYatir(miktar);
        } else if (islemTuru == 2) {
            cin >> miktar;
            bool durum = hesap1.paraCek(miktar);
            if (!durum) {
                cout << "Yetersiz bakiye!" << endl;
            }
        } else if (islemTuru == 3) {
            hesap1.bakiyeYazdir();
        }
    }
    
    return 0;
}