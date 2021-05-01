INC="./libfdr"
LIB="./lib"
TARGET=main

all: kripto


kripto: ./lib/libfdr.a $(TARGET).c
    gcc -I$(INC) $(TARGET).c -o $@ -L$(LIB) -lfdr

clean:
    rm -rf kripto