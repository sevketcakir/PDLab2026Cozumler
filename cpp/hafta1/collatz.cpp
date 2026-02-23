/* * Collatz Sanısı (3n + 1 Problemi):
 * Herhangi bir pozitif tam sayıdan başlayarak:
 * - Sayı çiftse ikiye böl,
 * - Sayı tekse üçle çarpıp bir ekle.
 * Bu işlemler tekrarlandığında sonuç her zaman 1'e ulaşır.
 */

#include <iostream>
using namespace std;

int main() {
    // Sayı çok büyük değerlere ulaşabileceği için 'long int' tercih edilmiştir.
    long int sayi, adim = 0;

    // Başlangıç değerini kullanıcıdan al
    cin >> sayi;

    // Sayı 1'e ulaşana kadar döngü devam eder
    while (sayi > 1) {
        
        // Sayı çift mi kontrol et
        if (sayi % 2 == 0) {
            sayi /= 2; // Çiftse: sayi = sayi / 2
        }
        // Sayı tekse
        else {
            sayi = 3 * sayi + 1; // Tekse: 3n + 1 kuralını uygula
        }

        // Her işlem sonunda adım sayısını bir artır
        adim++;
    }

    // Toplam kaç adımda 1'e ulaşıldığını ekrana yazdır
    cout << adim;
    
    return 0;
}