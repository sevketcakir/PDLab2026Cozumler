module Ogrenci where --Bu satırı değiştirmeyin/silmeyin

--enSonEleman fonksiyonunu yazın
enSonEleman::[a]->a
enSonEleman = last
--enSonEleman liste = last liste --diğer çözüm

--sondanIkinci fonksiyonunu yazın(listenin sondan ikinci elemanını verir)
sondanIkinci::[a]->a
sondanIkinci liste = (last.init) liste
--sondanIkinci liste = last (init liste) --diğer çözüm

--ortanca fonksiyonunu yazın
ortanca::[a]->a
ortanca liste = liste !! ((length liste) `div` 2)
--ortanca liste = liste !! (div (length liste) 2) --diğer çözüm
