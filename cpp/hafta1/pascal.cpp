#include <iostream>
#include <vector>
using namespace std;

/*
 * Pascal Üçgeni Oluşturma:
 * Her sayı, kendisinin hemen üstünde bulunan iki sayının toplamıdır.
 * * Parametre: 'vec' adlı referansla geçilmiş 2D vektör (matris).
 * Matrisin önceden boyutlandırıldığı (n x n) varsayılmıştır.
 */
void pascal(vector< vector< int > >& vec) {
    
    // Tüm satırların ilk sütununu 1 olarak başlatıyoruz.
    // Pascal üçgeninin sol kenarı her zaman 1'dir.
    for(int i = 0; i < vec.size(); i++) {
        vec[i][0] = 1;
    }

    // Üçgenin iç kısmını doldurmak için 1. satır ve 1. sütundan başlıyoruz.
    for(int i = 1; i < vec.size(); i++) {
        
        // Sütunları dolaşırken bir üst satırdaki elemanları kullanıyoruz.
        for(int j = 1; j < vec.size(); j++) {
            
            // Mevcut hücre = Üstteki hücre + Üst-soldaki hücre
            // vec[i][j] değerini hesaplarken bir önceki satıra (i-1) bakılır.
            vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
        }
    }
}