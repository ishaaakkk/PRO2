/** @file Barco.cc
    @brief Codigo de la clase Barco
*/

#include "Barco.hh"

// Constructores 

Barco::Barco() {}       // si no se pone da error al compilar 

// Modificadores 

void Barco::modificar_barco(int id_comprar, int cant_comprar, int id_vender, int cant_vender) {
    this->id_comprar = id_comprar;
    this->cant_comprar = cant_comprar;
    this->id_vender = id_vender;
    this->cant_vender = cant_vender;
}

void Barco::reset_ciudades() {
    viajes_realizados.clear();
}

void Barco::anadir_ciudad(string id_ciudad) {
    viajes_realizados.push_back(id_ciudad);
}

// Consultores 

void Barco::escribir_barco() const {
    cout << id_comprar + 1 << ' ' << cant_comprar << ' ' << id_vender + 1 << ' ' << cant_vender << endl;
    
    list<string>:: const_iterator it = viajes_realizados.begin();
    while (it != viajes_realizados.end()) {
        cout << *it << endl;
        ++it;
    }
}

int Barco::consultar_id_prod_comprar() const {
    return id_comprar;
}

int Barco::consultar_id_prod_vender() const {
    return id_vender;
}

int Barco::consultar_cant_prod_comprar() const {
    return cant_comprar;
}

int Barco::consultar_cant_prod_vender() const {
    return cant_vender;
}

