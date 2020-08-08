SRC = epiphania.c
DEST = epiphania.exe
DESTnix = epiphania
includePath = R:/s/c/i
includePathNix = ~/s/cBao

all: $(SRC)
	gcc -ansi -g0 -O3 -Wall -Wextra -Wshadow -Wvla -pedantic-errors -o $(DEST) $(SRC) -I $(includePath) -Wno-long-long

nix: $(SRC)
	gcc -ansi -g0 -Wall -Wextra -Wshadow -Wvla -pedantic-errors -o $(DESTnix) $(SRC) -I $(includePathNix)

debug:
	gcc -ansi -g -static-libasan -fsanitize=address -Wall -Wextra -Wshadow -Wvla -pedantic-errors -o $(DESTnix) $(SRC) -I $(includePathNix) -Wno-long-long
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
.PHONY: nix
.PHONY: emk
