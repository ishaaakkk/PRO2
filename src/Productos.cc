/** @file Productos.cc
    @brief Codigo de la clase Productos
*/

#include "Productos.hh"

// Constructores 
Productos::Productos() {}           // si no se pone da error al compilar 

// Modificadores 

Productos::Producto Productos::leer_producto() {
    Producto nuevo_producto;
    int p, v;
    cin >> p >> v;
    nuevo_producto.peso = p;
    nuevo_producto.volumen = v;
    return nuevo_producto;
}

void Productos::agregar_productos(int num_productos) {
    for (int i = 0; i < num_productos; ++i)
        v_productos.push_back(leer_producto());
}

// Consultores 

int Productos::consultar_num() const {
    return v_productos.size();
}

void Productos::esribir_producto(int id_prod) const {
    cout << id_prod + 1 << " " << v_productos[id_prod].peso << " " << v_productos[id_prod].volumen << endl;
}

int Productos::consultar_peso(int id_prod) const {
    return v_productos[id_prod].peso;
}

int Productos::consultar_volumen(int id_prod) const {
    return v_productos[id_prod].volumen;
}


