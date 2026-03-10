module Ogrenci where -- Bu satırı değiştirmeyin/silmeyin

-- 1. Parametre olarak verilen bir listeyi tam ortadan ikiye bölerek
-- iki elemanlı bir çokuzlu (tuple) olarak döndüren yariyaBol fonksiyonunu yazın.
-- (İpucu: take, drop, length ve div fonksiyonlarını kullanabilirsiniz)
yariyaBol :: [a] -> ([a], [a])
yariyaBol liste = (take (length liste `div` 2) liste, drop (length liste `div` 2) liste)
--Diğer bir çözüm, div fonksiyonunu prefix biçimde kullanarak(tırnaksız):
-- yariyaBol liste = (take (div (length liste) 2) liste, drop (div (length liste) 2) liste) -- diğer çözüm


-- 2. Parametre olarak verilen tam sayı listesinin ortalamasını
-- tam sayı cinsinden (küsuratsız) bulan tamsayiOrtalama fonksiyonunu yazın.
-- (İpucu: sum, length ve div kullanın)
tamsayiOrtalama :: [Int] -> Int
tamsayiOrtalama liste = (sum liste) `div` (length liste)
--tamsayiOrtalama liste = div (sum liste) (length liste) -- diğer çözüm


-- 3. 1'den parametre olarak verilen n sayısına kadar (n dahil) olan sayılardan
-- hem 3'e hem de 5'e tam bölünenleri liste üreteci (list comprehension)
-- kullanarak bulan uceVeBeseBolunenler fonksiyonunu yazın.
uceVeBeseBolunenler :: Int -> [Int]
uceVeBeseBolunenler sayi = [x | x<-[3..sayi+1],x `mod` 3 == 0, x `mod` 5 == 0]


-- 4. Parametre olarak verilen bir metnin (String) palindrom
-- (tersten okunuşu kendisine eşit) olup olmadığını test eden
-- palindromMu fonksiyonunu yazın.
palindromMu :: String -> Bool
palindromMu metin = metin == reverse metin
