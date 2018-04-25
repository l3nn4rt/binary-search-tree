### makefile ###

# compiles and assembles into an excutable
# "$ make [default]"
default: AlberoBinario clean info

# shows usage
# "$ make info"
info:
	@echo ""
	@echo "  Usage: ./AlberoBinario [NODE1 NODE2 ...]"
	@echo ""

# removes binaries, not executable
# "$ make clean"
clean:
	@printf "Removing bin/ directory... "
	@rm -fr bin/
	@echo "Done"

#removes binaries and executable
# "$ make clean-all" 
clean-all: clean
	@printf "Removing executable... "
	@rm -f AlberoBinario
	@echo "Done"
	@echo "All removed."



### where stuff does stuff... ###

AlberoBinario: bin/ bin/main.o bin/strumenti.o bin/manipolazione.o bin/deque.o bin/stampa.o
	@printf "Building final executable... "
	@gcc -Wall -o AlberoBinario bin/main.o bin/strumenti.o bin/manipolazione.o bin/deque.o bin/stampa.o
	@echo "Done"

bin/:
	@printf "Making bin/ directory... "
	@mkdir -p bin/
	@echo "Done"

bin/main.o: src/intestazioni.h src/main.c
	@printf "Compiling main... "
	@gcc -c -Wall -o bin/main.o src/main.c
	@echo "Done"

bin/strumenti.o: src/intestazioni.h src/strumenti.c
	@printf "Compiling strumenti... "
	@gcc -c -Wall -o bin/strumenti.o src/strumenti.c
	@echo "Done"

bin/manipolazione.o: src/intestazioni.h src/manipolazione.c
	@printf "Compiling manipolazione... "
	@gcc -c -Wall -o bin/manipolazione.o src/manipolazione.c
	@echo "Done"

bin/stampa.o: src/intestazioni.h src/deque.h src/stampa.c
	@printf "Compiling stampa... "
	@gcc -c -Wall -o bin/stampa.o src/stampa.c
	@echo "Done"

bin/deque.o: src/deque.h src/deque.c
	@printf "Compiling deque... "
	@gcc -c -Wall -o bin/deque.o src/deque.c
	@echo "Done"
