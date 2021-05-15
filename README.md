BSM 308 Sistem Programlama Dersi Projesi 1. Öğretim A Şubesi (Prof. Dr. Ahmet ÖZMEN)
Dosya Adı: Sistem_Programlama_Projesi
Grup Adı: Code4Enigma
Proje Grup Elemanları:  Mücahid Işık b181210111 1. Öğretim
                        Duhan Uzun b181210051 1. Öğretim
                        Kadir Çelik b181210057 1. Öğretim
                        Hüseyin Hıra b181210105 1. Öğretim
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                        Açıklama
Projemize ilk olarak projede kullanılması zorunlu olan libfdr kütüphanesini ekledik. Sonra libfdr kütüphanesinde bulunan "fields" ve bir C dili kütüphanesi olan "string.h" yardımıyla içinde Huffman algoritmasına göre düzenlenmiş veriler bulunan ".kilit" dosyasını okuduk. ".kilit" dosyasından okunan kelime-kod ikililerini sırasıyla encode işleminde key-value olarak, decode işlemindeyse value-key olarak JRB ağacına ekledik. Daha sonra encode ve decode işlemlerini yaptık. Encode işleminde bir metinde bulunan kelimeler JRB ağacındaki karşılıklarına göre kriptolanırken, decode işlemindeyse kriptolanmış bir metin JRB ağacındaki kelime karşılığına göre çözümlenmektedir.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                Projenin Çalıştırılması
1) make komutu: Projeyi derler ve "kripto" adlı çalıştırılabilir dosyayı oluşturur.
2) clean komutu: Derleme sonucunda oluşan "kripto" adlı dosyayı siler.
3) cleanall komutu: Proje klasöründe bulunan "kripto", "encripted", "decripted", ".kilit" ve ".txt" uzantılı dosyaları siler.
4) run komutu: Önce clean daha sonra make komutunu çalıştırır. En sonunda projede bulunan komutları çalıştırır.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                       Ek Bilgiler
1) Projenin çalıştırılabilmesi için bir libfdr klasörünün bulunması gerekmektedir. libfdr klasörünün için "fields.h", "jval.h", "jrb.h" ve libfdr kütüphanesi derlendiğinde oluşan object dosyalarını içinde barındıran "libfdr.a" dosyasının bulunması gerekmektedir.
2) Encode işleminin yapılması için komut satırına "./kripto -e giris_metni cikis_metni" parametrelerinin yazılması gerekmektedir.
3) Decode işleminin yapılması için komut satırına "./kripto -d giris_metni cikis_metni" parametrelerinin yazılması gerekmektedir.