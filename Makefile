LIB="./libfdr"
TARGET=main

all: kripto

kripto:	./libfdr/libfdr.a $(TARGET).c
	gcc -I$(LIB) $(TARGET).c -o $@ -L$(LIB) -lfdr

clean:
	rm -rf kripto

cleanall:
	rm -rf kripto
	rm -f *.txt .kilit encripted decripted

run:	clean kripto
	./kripto -e ornek_metin.txt encripted
	./kripto -d encripted decripted