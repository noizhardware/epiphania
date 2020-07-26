SRC = epiphania.c
DEST = epiphania.exe
DESTnix = epiphania
includePath = R:/s/c/i
includePathNix = R:/s/c/i

all: $(SRC)
	gcc -std=c90 -g0 -Wall -pedantic-errors -o $(DEST) $(SRC) -I $(includePath)

debug:
	gcc -std=c90 -g -static-libasan -fsanitize=address -Wall -pedantic-errors -o $(DESTnix) $(SRC) -I $(includePathNix)
	./$(DESTnix)

clean:
	rm $(DEST)
	rm testhtml.html

go:
	./$(DEST)
	
gon:
	./$(DESTnix)

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
.PHONY: gon
.PHONY: edit
.PHONY: emk
