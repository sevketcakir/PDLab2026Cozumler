/* * Mükemmel Sayı Kontrolü:
 * Kendisi hariç pozitif tam bölenlerinin toplamı 
 * kendisine eşit olan sayılara mükemmel sayı denir (Örn: 6, 28).
 */

#include <iostream>
using namespace std;

int main() {
    int sayi, toplam = 0;

    // Kullanıcıdan kontrol edilecek sayıyı al
    cin >> sayi;

    // Bir sayının kendisi hariç en büyük böleni, o sayının yarısından büyük olamaz.
    // Bu nedenle döngüyü sayi/2'ye kadar döndürmek performansı artırır.
    for(int i = 1; i <= sayi / 2; i++) {
        
        // Eğer sayı i'ye tam bölünüyorsa, i bir çarpandır/bölendir.
        if(sayi % i == 0) {
            toplam += i; // Böleni toplam değişkenine ekle
        }
    }

    // Pozitif bölenlerin toplamı orijinal sayıya eşit mi kontrol et
    if(sayi == toplam && sayi > 0) {
        cout << "mükemmel";
    }
    else {
        cout << "mükemmel değil";
    }

    return 0;
}