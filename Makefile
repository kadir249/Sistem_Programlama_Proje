INC="./libfdr"
LIB="./lib"
TARGET=main

all: kripto


kripto: ./lib/libfdr.a $(TARGET).c
	gcc -I$(INC) $(TARGET).c -o $@ -L$(LIB) -lfdr

clean:
	rm -rf kripto

cleanall:
	rm -rf kripto
	rm -f *.txt .kilit encripted decripted deneme.txt

run:
	./kripto -e deneme.txt encripted
	./kripto -d encripted decripted