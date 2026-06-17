
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

all: program.exe clean practica.tar

program.exe: program.o Barco.o Ciudad.o Cuenca.o Productos.o
	g++ -o program.exe *.o  $(OPCIONS)

# Compilacion de archivos objeto

Barco.o: Barco.cc Barco.hh
	g++ -c Barco.cc $(OPCIONS) 

Ciudad.o: Ciudad.cc Ciudad.hh
	g++ -c Ciudad.cc $(OPCIONS)

Cuenca.o: Cuenca.cc Cuenca.hh Ciudad.hh BinTree.hh
	g++ -c Cuenca.cc $(OPCIONS) 

Productos.o: Productos.cc Productos.hh
	g++ -c Productos.cc $(OPCIONS) 

program.o: program.cc Cuenca.hh Barco.hh Productos.hh
	g++ -c program.cc $(OPCIONS) 


# Generador del .tar 

practica.tar: program.cc Cuenca.hh Cuenca.cc Ciudad.hh Ciudad.cc Productos.hh Productos.cc Barco.hh Barco.cc
	tar -cvf practica.tar program.cc Cuenca.hh Cuenca.cc Ciudad.hh Ciudad.cc Productos.hh Productos.cc Barco.cc Barco.hh html.zip justificacion_funciones.pdf Makefile

#
# Limpieza de archivos generados
#

clean:
	rm -f *.o
