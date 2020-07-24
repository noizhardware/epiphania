SRC = epiphania.c
DEST = epiphania.exe
includePath = R:/c/s/i

all: $(SRC)
	gcc -std=c90 -g0 -Wall -pedantic-errors -o $(DEST) $(SRC) -I $(includePath)

debug:
	gcc -std=c90 -g -static-libasan -fsanitize=address -Wall -pedantic-errors -o $(DEST) $(SRC) -I $(includePath)
	./$(DEST)

clean:
	rm $(DEST)
	rm testhtml.html

go:
	./$(DEST)

edit:
	nano $(SRC)

emk:
	nano Makefile

ht:
	nano testhtml.html

.PHONY: ht
.PHONY: all
.PHONY: debug
.PHONY: clean
.PHONY: go
.PHONY: edit
.PHONY: emk
