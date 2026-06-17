OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

all: program.exe clean practica.tar

program.exe: program.o Barco.o Ciudad.o Cuenca.o Productos.o
	g++ -o program.exe *.o $(OPCIONS)

# Compilacion de archivos objeto

Barco.o: src/Barco.cc src/Barco.hh
	g++ -c src/Barco.cc $(OPCIONS) 

Ciudad.o: src/Ciudad.cc src/Ciudad.hh
	g++ -c src/Ciudad.cc $(OPCIONS)

Cuenca.o: src/Cuenca.cc src/Cuenca.hh src/Ciudad.hh src/BinTree.hh
	g++ -c src/Cuenca.cc $(OPCIONS) 

Productos.o: src/Productos.cc src/Productos.hh
	g++ -c src/Productos.cc $(OPCIONS) 

program.o: src/program.cc src/Cuenca.hh src/Barco.hh src/Productos.hh
	g++ -c src/program.cc $(OPCIONS) 

# Generador del .tar 

practica.tar: src/program.cc src/Cuenca.hh src/Cuenca.cc src/Ciudad.hh src/Ciudad.cc src/Productos.hh src/Productos.cc src/Barco.hh src/Barco.cc
	tar -cvf practica.tar -C src program.cc Cuenca.hh Cuenca.cc Ciudad.hh Ciudad.cc Productos.hh Productos.cc Barco.cc Barco.hh -C ../docs justificacion_funciones.pdf -C .. Makefile
	
#
# Limpieza de archivos generados
#

clean:
	rm -f *.o

