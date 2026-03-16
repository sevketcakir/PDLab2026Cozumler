module Ogrenci where --Bu satırı değiştirmeyin/silmeyin
{-
Listeleri kullanan özyinelemeli fonksiyonlar genellikle şu şekilde tanımlanır:
 - Durma noktasını belirle(edge/base case): Genellikle boş liste veya tek
   elemanlı liste gibi durumlar için tanımlanır.
 - Özyinelemeli adım(recursive step): Listenin ilk elemanını(baş) işleyip,
   geri kalan liste(kuyruk) üzerinde aynı fonksiyonu çağırarak devam eder.
-}
-- 1. uzunluk fonksiyonunu yazın (listenin uzunluğunu verir)
uzunluk :: [a] -> Int
uzunluk [] = 0 -- boş listenin uzunluğu 0'dır
uzunluk (x:xs) = 1+uzunluk xs -- listenin uzunluğu 1 (ilk eleman) + geri kalan listenin uzunluğu

-- 2. ciftFaktoryel fonksiyonunu yazın (n!! = n * (n-2) * (n-4)...)
ciftFaktoryel :: Integer -> Integer
ciftFaktoryel 1 = 1 -- tek sayılar için durma noktası(edge case)
ciftFaktoryel 2 = 2 -- çift sayılar için durma noktası(edge case)
ciftFaktoryel n = n*ciftFaktoryel (n-2) -- n çift veya tek olsun, n-2'ye kadar çarpma işlemi devam eder

-- 3. palindrom fonksiyonunu yazın (özyinelemeli olarak kontrol etmeli)
palindrom :: (Eq a) => [a] -> Bool
palindrom [] = True -- boş liste palindromdur
palindrom [_] = True -- tek elemanlı liste palindromdur
palindrom (x:xs) = x == last xs && palindrom (init xs) -- ilk ve son eleman eşit olmalı ve geri kalan kısmın da palindrom olması gerekir

-- 4. indistekiEleman fonksiyonunu yazın
indistekiEleman :: [a] -> Int -> a
indistekiEleman (x:_) 0 = x -- indeks 0 ise ilk eleman döndürülür
indistekiEleman (_:xs) n = indistekiEleman xs (n-1) -- indeks 0 değilse, liste bir eleman kaydırılır ve indeks 1 azaltılır, bu işlem indeks 0 olana kadar devam eder

-- 5. compress fonksiyonunu yazın (ardışık tekrar eden elemanları teke düşürür)
compress :: (Eq a) => [a] -> [a]
compress [] = [] -- boş liste için boş liste döndürülür
compress [x] = [x] -- tek elemanlı liste için aynı eleman döndürülür
compress (x:y:xs)
    | x == y    = compress (y:xs) -- eşitse, ikinci elemanı al ve devam et
    | otherwise = x : compress (y:xs) -- eşit değilse, ilk elemanı al ve devam et

-- 6. Tekrarla fonksiyonunu yazın (verilen elemanı n kere içeren bir liste oluşturur)
tekrarla :: Int -> a -> [a]
tekrarla 0 _ = [] -- n sıfır ise boş liste döndürülür
tekrarla n x = x:tekrarla (n-1) x -- n sıfır değilse, elemanı al ve n-1 ile tekrar çağırarak devam et

-- 7. enBuyuk fonksiyonunu yazın (listedeki en büyük elemanı bulur)
enBuyuk :: (Ord a) => [a] -> a
enBuyuk [x] = x -- tek elemanlı liste için o eleman en büyük olarak döndürülür
enBuyuk (x:xs) = max x (enBuyuk xs) -- ilk eleman ile geri kalan listenin en büyük elemanını karşılaştırarak en büyük değeri bulur

-- 8. elemanSil fonksiyonunu yazın (verilen elemanı listeden tamamen siler)
elemanSil :: (Eq a) => a -> [a] -> [a]
elemanSil _ [] = [] -- boş liste için boş liste döndürülür
elemanSil y (x:xs)
    | x == y    = elemanSil y xs -- eşitse, bu elemanı atla ve devam et
    | otherwise = x:elemanSil y xs -- eşit değilse, bu elemanı al ve devam et

-- 9. arayaEkle fonksiyonunu yazın.
-- Verilen bir elemanı, bir listenin tüm elemanlarının arasına yerleştirir.
-- Örn: arayaEkle '-' "PAU" -> "P-A-U"
arayaEkle :: a -> [a] -> [a]
arayaEkle _ [x] = [x] -- tek elemanlı liste için o eleman döndürülür
arayaEkle y (x:xs) = x:y:arayaEkle y xs -- ilk elemanı al, araya elemanı ekle ve geri kalan liste için aynı işlemi yaparak devam et

-- 10. siraliBirlestir fonksiyonunu yazın.
-- Sıralı verilmiş iki listeyi, yine sıralı olacak şekilde tek bir listede birleştirir.
-- Örn: siraliBirlestir [1,4,5] [2,3,6] -> [1,2,3,4,5,6]
siraliBirlestir :: (Ord a) => [a] -> [a] -> [a]
siraliBirlestir l1 [] = l1 -- ikinci liste boşsa, birinci liste döndürülür
siraliBirlestir [] l2 = l2 -- birinci liste boşsa, ikinci liste döndürülür
siraliBirlestir (x:xs) (y:ys)
    | x <= y    = x : siraliBirlestir xs (y:ys) -- x küçük veya eşitse, x'i al ve geri kalan birinci liste ile ikinci listeyi birleştirerek devam et
    | otherwise = y : siraliBirlestir (x:xs) ys -- y küçükse, y'i al ve birinci liste ile geri kalan ikinci listeyi birleştirerek devam et

-- 11. tekrarlariSil fonksiyonunu yazın.
-- Bir listedeki tekrar eden elemanları siler, her elemandan sadece ilkini tutar.
-- İpucu: Bu fonksiyonun içinde, az önce yazdığınız 'elemanSil' fonksiyonunu çağırabilirsiniz!
tekrarlariSil :: (Eq a) => [a] -> [a]
tekrarlariSil [] = [] -- boş liste için boş liste döndürülür
tekrarlariSil (x:xs) = x : tekrarlariSil (elemanSil x xs) -- ilk elemanı al, geri kalan listeden bu elemanı tamamen sil ve kalan liste için aynı işlemi yaparak devam et
