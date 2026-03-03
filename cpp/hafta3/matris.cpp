/***************************************************************************************
 * MATRİS SINIFI - OPERATÖR AŞIRI YÜKLEMESİ VE BELLEK YÖNETİMİ UYGULAMASI
 * * AÇIKLAMA:
 * Bu alıştırmada, dinamik bellek (pointer) kullanan bir 'Matris' sınıfı için
 * operatör aşırı yüklemesi (operator overloading) işlemlerini gerçekleştireceksiniz.
 * Sınıfımız dinamik bellek (new/delete) kullandığı için "Kural 3" (Rule of Three)
 * gereği kopya yapıcı (copy constructor) ve atama operatörünü sığ kopya (shallow copy)
 * hatasına düşmeden, derin kopyalama (deep copy) mantığıyla yazmanız beklenmektedir.
 * * GÖREVLERİNİZ:
 * Dosya içerisinde "TODO" ile işaretlenmiş aşağıdaki metotları doldurmalısınız:
 * 1. Matris(const Matris& diger)      : Kopya Yapıcı (Derin kopyalama yapmalı)
 * 2. operator=(const Matris& diger)   : Atama Operatörü (Eski belleği silip yenilemeli)
 * 3. operator+(const Matris& diger)   : İki matrisin toplamı
 * 4. operator*(const Matris& diger)   : İki matrisin çarpımı
 * 5. operator>>(...)                  : cin ile boyutları ve matris elemanlarını okuma
 * 6. operator<<(...)                  : cout ile matrisi ekrana yazdırma
 * * HATA KONTROLÜ (ÖNEMLİ):
 * Toplama ve çarpma operatörlerinde matris boyutlarının uyuşup uyuşmadığını kontrol
 * etmelisiniz. Eğer boyutlar işlem için uygun değilse ekrana tam olarak (tırnaksız):
 * "Boyut hatasi"
 * yazdırmalı ve programın çökmemesi için return Matris(0,0); döndürmelisiniz.
 * * --- VPL OTOMATİK DEĞERLENDİRME SİSTEMİ HAKKINDA DİKKAT EDİLECEK HUSUSLAR ---
 * 1. Bu dosyaya KESİNLİKLE main() fonksiyonu EKLEMEYİNİZ!
 * 2. VPL sistemi, sizin yazdığınız bu sınıfı arka planda gizli bir main.cpp dosyası
 * ile birleştirerek derleyecektir.
 * 3. Değerlendirme (Evaluate) tuşuna bastığınızda, gizli test programı sizin
 * yazdığınız operatörleri farklı boyutlardaki matrislerle çağıracak, sonuçları
 * beklenen çıktılarla karşılaştıracak ve kodunuzu otomatik olarak puanlayacaktır.
 ***************************************************************************************/
/**
 * Çözüm açıklaması:
 * Başlangıçta yapıcı ve yıkıcı metotlarda bulunan işlemler tahsis_kaldir() ve
 * tahsis_yap() metotlarına taşındı. Böylece kopya yapıcı ve atama operatöründe
 * bu işlemleri tekrar etmekten kurtulduk.
 * Yardımcı metot olarak deger_ata() metodu oluşturuldu. Bu metot, bir matrisin
 * elemanlarını diğer matrise atamak için kullanıldı. Kopya yapıcı ve atama
 * operatöründe bu metot çağrılarak kod tekrarı azaltıldı.
 */

 #include <iostream>
using namespace std;

#ifndef MATRIS_H
#define MATRIS_H

class Matris {
private:
    int** veri;
    unsigned int satir;
    unsigned int sutun;

public:
    // --- HAZIR VERİLEN METOTLAR ---
    // Varsayılan değerler (0) atandı, böylece "Matris m;" şeklinde boş oluşturulabilir.
    Matris(unsigned int s = 0, unsigned int c = 0) {
        tahsis_yap(s,c);
    }

    ~Matris() {
        tahsis_kaldir();
    }

    /**
     * Bu metot satır ve sütun sayısı parametrelerini alarak veri için dinamik
     * bellek tahsis eder. Eğer satır veya sütun sayısı 0 ise veri pointer'ını nullptr
     * yaparak boş bir matris oluşturur. Aksi halde, satır sayısı kadar int* pointer'ı
     * içeren bir dizi oluşturur ve her bir satır için sütun sayısı kadar int'lik bir dizi
     * tahsis eder. Tüm elemanlar 0 ile başlatılır.
     */
    void tahsis_yap(int satir, int sutun) {
        // sınıfın satir ve sutun üyesine parametre olarak gelen değerler atanır
        this->satir = satir;
        this->sutun = sutun;
        if (satir == 0 || sutun == 0) {
            veri = nullptr;
            return;
        }
        veri = new int*[satir]; // satır sayısı kadar int* pointer'ı içeren bir dizi oluşturulur
        for (unsigned int i = 0; i < satir; ++i) {
            veri[i] = new int[sutun]{0}; // her bir satır için sütun sayısı kadar int'lik bir dizi tahsis edilir ve tüm elemanlar 0 ile başlatılır
        }
    }
    /**
     * Bu metot, yapılan dinamik bellek tahsisini geri almak için kullanılır.
     */
    void tahsis_kaldir() {
        if (veri != nullptr) {
            for (unsigned int i = 0; i < satir; ++i) {
                delete[] veri[i]; // her bir satır için tahsis edilen sütun dizisi silinir
            }
            delete[] veri; // satır sayısı kadar tahsis edilen int* pointer'ı içeren dizi silinir
            veri = nullptr; // veri pointer'ı null yapılır
            satir = sutun = 0; // satır ve sütun sayısı sıfırlanır, böylece nesne boş bir matris durumuna getirilir
        }
    }
    /**
     * Bu metot, bir matrisin elemanlarını diğer matrise atamak için kullanılır.
     */
    void deger_ata(const Matris& m) { // boyutlar eşit varsaydık
        for(int i=0;i<satir;i++) {
            for(int j=0;j<sutun;j++) {
                veri[i][j] = m.veri[i][j];
            }
        }
    }

    // --- ÖĞRENCİNİN DOLDURACAĞI METOTLAR ---

    // 1. Kopya Yapıcı (Derin kopyalama)
    Matris(const Matris& diger) {
        // yapıcı metot olduğu için önce mevcut belleği temizlemeye gerek yok
        tahsis_yap(diger.satir, diger.sutun);
        deger_ata(diger);
    }

    // 2. Atama Operatörü
    Matris& operator=(const Matris& diger) {
        tahsis_kaldir(); // mevcut belleği temizle
        tahsis_yap(diger.satir, diger.sutun); // yeni boyutlara göre bellek tahsis et
        deger_ata(diger); // elemanları atamak için yardımcı metot çağrısı
        return *this;
    }

    // 3. Toplama
    Matris operator+(const Matris& diger) const {
        // Satır ve sütun sayıları eşit değilse "Boyut hatasi" yazdırıp boş matris döndürülür
        if (satir != diger.satir || sutun != diger.sutun) {
            cout << "Boyut hatasi";
            return Matris(0, 0);
        }
        else { // boyutlar eşit, toplama işlemi yapılabilir
            // Geri döndürülecek matris için yeni bir nesne oluşturulur ve elemanlar toplanarak atanır
            Matris donecek(satir, sutun);
            for(int i=0;i<satir;i++) {
                for(int j=0;j<sutun;j++) {
                    donecek.veri[i][j] = veri[i][j] + diger.veri[i][j];
                }
            }
            return donecek;
        }
    }

    // 4. Çarpma
    Matris operator*(const Matris& diger) const {
        // m1'in sütunu m2'nin satırına eşit değilse "Boyut hatasi" yazdırıp boş matris döndürülür
        if (sutun != diger.satir) {
            cout << "Boyut hatasi";
            return Matris(0, 0);
        }
        else { // boyutlar çarpma işlemi için uygun, çarpma işlemi yapılabilir
            // Geri döndürülecek matris için yeni bir nesne oluşturulur
            Matris donecek(satir, diger.sutun);
            for(int i=0;i<satir;i++) { // donecek'in satır sayısı m1'in satır sayısına eşit
                for(int j=0;j<diger.sutun;j++) { // donecek'in sütun sayısı m2'nin sütun sayısına eşit
                    for(int k=0;k<sutun;k++) { // çarpma işlemi için döngü
                        donecek.veri[i][j] += veri[i][k] * diger.veri[k][j]; // donecek'in i,j elemanına m1'in i,k elemanı ile m2'nin k,j elemanının çarpımını ekle
                    }
                }
            }
            return donecek; // çarpma işlemi tamamlandıktan sonra sonuç matris döndürülür
        }
    }

    // 5. Girdi (cin) Operatörü
    friend istream& operator>>(istream& in, Matris& m) {
        m.tahsis_kaldir(); // mevcut belleği temizle, böylece yeni boyutlara göre bellek tahsis edilebilir
        int satir, sutun; // kullanıcıdan satır ve sütun sayısını almak için geçici değişkenler
        in >> satir >> sutun; // kullanıcıdan satır ve sütun sayısını oku
        m.tahsis_yap(satir, sutun); // yeni boyutlara göre bellek tahsis et
        for(int i=0;i<m.satir;i++) {
            for(int j=0;j<m.sutun;j++) {
                in >> m.veri[i][j]; // kullanıcıdan matris elemanlarını oku ve ata
            }
        }
        return in;
    }

    // 6. Çıktı (cout) Operatörü
    friend ostream& operator<<(ostream& out, const Matris& m) {
        // matris elemanlarını ekrana yaz
        for(int i=0;i<m.satir;i++) {
            for(int j=0;j<m.sutun;j++) {
                out << m.veri[i][j] << " "; // her elemandan sonra bir boşluk bırak
            }
            out << endl; // her satırdan sonra yeni satıra geç
        }
        return out;
    }
};
#endif
