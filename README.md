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
- 🔺 **`pascal.cpp`:** Önceden boyutlandırılmış 2D `vector` matrisi kullanarak Pascal Üçgeni oluşturur. Her sayıyı, üstündeki ve üst-soldaki hücrenin toplamı olarak hesaplar.
- ✂️ **`tkm.cpp`:** İki oyuncudan alınan girişlere göre tüm ihtimalleri değerlendirerek kazananı belirleyen temel Taş-Kağıt-Makas uygulamasıdır.

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

#### 🪆 Hafta 2: Özyinelemeli (Recursive) Fonksiyonlar ve Liste İşlemleri
- 📏 **`uzunluk`:** `x:xs` deseni ile listeyi baş (ilk eleman) ve kuyruk (geri kalan) olarak ayırır, her adımda 1 ekleyerek kuyruğun uzunluğunu özyinelemeli olarak hesaplar.
- ✖️ **`ciftFaktoryel`:** Çift faktöriyel (n!!) işlemini hesaplar. 1 ve 2 değerleri için durma noktası (base case) belirlenmiş olup, diğer durumlarda sayıyı `n-2` ile çarparak geriye doğru ilerler.
- 🪞 **`palindrom`:** Listenin ilk ve son elemanının eşit olup olmadığını kontrol eder ve içte kalan alt listenin (`init xs`) palindrom olup olmadığını özyinelemeli olarak sınar.
- 🎯 **`indistekiEleman`:** Aranan indeks 0 olana kadar listeyi sürekli bir eleman kaydırır (`_:xs`) ve indeksi 1 azaltarak istenen sıradaki elemana ulaşır.
- 🗜️ **`compress`:** Ardışık tekrar eden elemanları teke düşürür. `x:y:xs` deseniyle yan yana duran iki elemanı karşılaştırır, eşitlerse birini atlayarak devam eder.
- 🖨️ **`tekrarla`:** Verilen bir elemanı, belirtilen `n` sayısı kadar tekrarlayarak özyinelemeli olarak yepyeni bir liste inşa eder.
- 🏆 **`enBuyuk`:** Listenin ilk elemanı ile kuyruk kısmının en büyük değerini (`max` fonksiyonu ile) kıyaslayarak listedeki maksimum elemanı bulur.
- 🗑️ **`elemanSil`:** Belirtilen bir elemanı listede arar; eşleşme durumunda elemanı atlar, eşleşmezse sonuca ekleyerek hedeflenen elemanın tüm kopyalarını listeden siler.
- 🔗 **`arayaEkle`:** Belirtilen özel bir karakteri veya elemanı (örn: '-'), listenin mevcut elemanlarının arasına tek tek yerleştirir (Örn: "PAU" -> "P-A-U").
- 🧬 **`siraliBirlestir`:** Zaten sıralı olarak verilmiş iki farklı listeyi baştan eleman eleman karşılaştırıp (`x <= y`), yine küçükten büyüğe sıralı olacak şekilde tek bir listede birleştirir (Merge işlemi).
- 🧹 **`tekrarlariSil`:** Listedeki tekrar eden elemanları temizler. Listedeki ilk elemanı tutar ve `elemanSil` fonksiyonunu çağırarak bu elemanın listenin geri kalanındaki tüm kopyalarını yok ederek ilerler.

#### 🧠 Hafta 3: Yüksek Mertebeden Fonksiyonlar (Map, Filter, Fold)
- 🔁 **`yinele`:** `foldr` fonksiyonunu kullanarak listedeki her bir elemanı sağdan sola doğru okur ve sonuç listesine (accumulator) her elemanı iki kez ekleyerek ardışık tekrarlı yeni bir liste inşa eder.
- 🔢 **`ciftSayiAdeti`:** `map` ile listedeki her elemanın çift olup olmadığını (True/False) belirler, ardından `filter` ile sadece 'True' olanları süzerek çift sayıların toplam miktarını (`length`) hesaplar.
- 🪞 **`palindrom`:** `foldl` fonksiyonunun işleyiş mantığını (soldan sağa doğru çalışarak elemanları listenin başına eklemesi) kullanarak listenin tersini alır ve orijinal liste ile kıyaslayarak palindrom olup olmadığını denetler.
- 🗜️ **`compress`:** Ardışık tekrar eden elemanları teke düşürür. `foldr` kullanarak sağdan sola ilerler, sıradaki elemanı birikmiş listenin (`acc`) başındaki eleman ile kıyaslar (`head acc`). Eşitse atlar, değilse listeye ekler. Başlangıç değeri olarak listenin son elemanı (`last liste`) kullanılır.
