# 🚀 Programlama Dilleri Laboratuvarı Çözümleri 💻

Bu depo, Programlama Dilleri dersi laboratuvar uygulamaları (Bilmoodle VPL ortamı) için yazılmış örnek çözümleri içermektedir. 🎓 Çözümler, programlama paradigmalarına (Nesne Yönelimli, Fonksiyonel vb.) ve haftalık konulara göre ilgili dilin klasöründe (C++, Haskell, Go, Python) toplanmıştır.

## 🛠️ Derleme ve Çalıştırma (Moodle Dışı Kullanım İçin)
Farklı dillerdeki kodları kendi bilgisayarınızda çalıştırmak için aşağıdaki temel komutları kullanabilirsiniz:

* **C++ (.cpp):** `g++ ornek.cpp -o ornek` komutu ile derleyin ve `./ornek` ile çalıştırın.
* **Haskell (.hs):** `ghc ornek.hs` ile derleyip `./ornek` ile çalıştırabilir veya doğrudan etkileşimli kabukta `ghci ornek.hs` yazarak fonksiyonları test edebilirsiniz.
* **Go (.go):** `go run ornek.go` komutu ile doğrudan çalıştırabilirsiniz.
* **Python (.py):** `python3 ornek.py` komutu ile yorumlayıcı üzerinden çalıştırabilirsiniz.

---

## 📂 İçerik ve Haftalık Uygulamalar

### 🟦 C++ Klasörü (Nesne Yönelimli Programlama ve İleri Seviye Veri Yapıları)

#### 🔢 Hafta 1: Temel Algoritmalar
- 📉 **`collatz.cpp`:** Collatz Sanısı (3n + 1 Problemi) çözümüdür. Sayı çiftse ikiye böler, tekse üçle çarpıp bir ekleyerek sayının 1'e ulaşma adımlarını hesaplar.
- ✨ **`mukemmel.cpp`:** Kendisi hariç pozitif tam bölenlerinin toplamı kendisine eşit olan mükemmel sayıları (Örn: 6, 28) tespit eder.
- 🔺 **`pascal.cpp`:** Önceden boyutlandırılmış 2D `vector` matrisi kullanarak Pascal Üçgeni oluşturur. Her sayıyı, üstündeki ve üst-soldaki hücrenin toplamı olarak hesaplar. - ✂️ **`tkm.cpp`:** İki oyuncudan alınan girişlere göre tüm ihtimalleri değerlendirerek kazananı belirleyen temel Taş-Kağıt-Makas uygulamasıdır.

#### 🏛️ Hafta 2: Sınıflara (Classes) Giriş
- 🏦 **`banka.cpp`:** Müşteri hesap numarası ve bakiyeyi tutan `BankaHesabi` sınıfını modeller. Sınıf içerisinde para yatırma, bakiye kontrolü ile para çekme ve bakiyeyi formatlı yazdırma metodları yer alır.
- ➕ **`complex.cpp`:** Karmaşık sayıların gerçel (r) ve sanal (i) kısımlarını tutan `Complex` sınıfının temel halidir. Toplama, çıkarma, çarpma ve tekli eksi (işaret tersine çevirme) metodlarını sınıfa dahil eder.

#### 🧮 Hafta 3: Operatör Aşırı Yükleme (Operator Overloading) ve Dinamik Bellek
- ⚖️ **`complex.cpp`:** Karmaşık sayılar için sınıf yapısını genişleterek `+`, `-`, `*`, `[]`, `<<` ve tekli `-` operatörlerinin doğrudan nesneler üzerinde kullanılabilmesi için operatör aşırı yüklemelerini içerir.
- 💾 **`matris.cpp`:** Dinamik bellek yönetimi (new/delete) gerektiren `Matris` sınıfı uygulamasıdır. Kopya yapıcı (copy constructor) ve atama operatöründe (operator=) sığ kopya hatasını önlemek için derin kopyalama (deep copy) mantığı kullanılmıştır. İşlemler öncesinde satır/sütun uyumluluğunu denetler, uyumsuzluk durumunda "Boyut hatasi" verir. 

### 🟪 Haskell Klasörü (Fonksiyonel Programlama Temelleri)

#### 📜 Hafta 1: Liste İşlemleri, Çokuzlular ve Özel Fonksiyonlar
- 🎯 **`fonksiyonlar1.hs`:** Listeler üzerinde çalışan temel built-in fonksiyonların kullanımını (listenin son elemanını bulma, sondan ikinciyi bulma, ortanca elemanı indekse göre çıkarma) gösteren fonksiyonları içerir.
- 📦 **`fonksiyonlar2.hs`:** Üç elemanlı bir çokuzludan (tuple) pattern matching yöntemiyle (`_` joker karakteri kullanarak) birinci, ikinci ve üçüncü elemanları sırasıyla döndüren fonksiyonları barındırır.
- 🛠️ **`yenifonk.hs`:** `take`, `drop`, `length` gibi metotlarla listeyi ortadan ikiye bölen (`yariyaBol`); liste elemanlarının tam sayı ortalamasını alan (`tamsayiOrtalama`); liste üreteçleri (list comprehensions) kullanarak belirli bir aralıkta 3'e ve 5'e tam bölünenleri filtreleyen (`uceVeBeseBolunenler`) ve string metnin palindrom olup olmadığını test eden (`palindromMu`) özel fonksiyon tanımlamalarını kapsar.