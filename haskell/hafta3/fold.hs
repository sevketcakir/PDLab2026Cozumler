module Ogrenci where -- Bu satırı değiştirmeyin/silmeyin

{- 1. yinele
Parametre olarak verilen listedeki elemanların her birini iki defa tekrarlar.
fold fonksiyonlarından birini kullanmak zorunludur.
yinele [1,2,3] -> [1,1,2,2,3,3]
-}
yinele :: [a] -> [a]
yinele liste = foldr (\x acc->x:x:acc) [] liste
-- foldr fonksiyonu, verilen liste üzerinde sağdan sola doğru çalışır. Her bir eleman x için, x'i iki kez ekleyerek acc (birikmiş sonuç) ile birleştirir. Başlangıç değeri olarak boş bir liste [] kullanılır.

{- 2. ciftSayiAdeti
Parametre olarak verilen listedeki çift sayı adetini verir.
map veya filter fonksiyonlarından birini kullanmak zorunludur.
-}
ciftSayiAdeti :: [Int] -> Int
--ciftSayiAdeti liste = length (filter even liste)
ciftSayiAdeti liste = length (filter (\x->x) (map even liste))
-- (\x->x) ifadesi, map fonksiyonunun sonucunu doğrudan kullanmak için bir kimlik fonksiyonu olarak kullanılır. Bu, filter fonksiyonunun doğru şekilde çalışmasını sağlar.
-- Alternatif olarak id fonksiyonu da kullanılabilir: length (filter id (map even liste))

{- 3. palindrom
Parametre olarak gelen listenin tersten ve düzden okunuşunun aynı olduğunu kontrol eder.
fold fonksiyonlarından birini kullanmak zorunludur.
-}
palindrom :: Eq a => [a] -> Bool
palindrom liste = liste == foldl (\acc x->x:acc) [] liste
-- foldl ile listenin tersi oluşturulur.

{- 4. compress
Parametre olarak verilen listedeki ardışık tekrar eden değerleri teke indirger.
fold fonksiyonlarından birini kullanmak zorunludur.
compress [1,1,1,2,2,1,1,3] -> [1,2,1,3]
-}
compress :: Eq a => [a] -> [a]
compress liste = foldr (\x acc->if x==head acc then acc else x:acc) [last liste] liste
-- foldr ile listenin sonundan başlayarak ardışık tekrar eden değerler kontrol edilir. Eğer x, acc'nin başındaki elemanla aynıysa, acc olduğu gibi kalır; aksi takdirde x, acc'nin başına eklenir. Başlangıç değeri olarak listenin son elemanı kullanılır.




