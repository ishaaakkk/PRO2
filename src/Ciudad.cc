/** @file Ciudad.cc
    @brief Codigo de la clase Ciudad
*/

#include "Ciudad.hh"

// Constructores 

Ciudad::Ciudad() {
    peso_total = volumen_total = 0;
}             
    
// Modificadores 

void Ciudad::poner_prod(int id_prod, int uds_obtenidas, int uds_necesitadas, int peso_prod, int volumen_prod) { 
    inventario_productos[id_prod] = make_pair(uds_obtenidas, uds_necesitadas);
    peso_total += (peso_prod * uds_obtenidas);
    volumen_total += (volumen_prod * uds_obtenidas);
}

void Ciudad::modificar_prod(int id_prod, int uds_obtenidas, int uds_necesitadas, int peso_prod, int volumen_prod) {
    peso_total -= (peso_prod * inventario_productos[id_prod].first);                // Primero restamos la cantidad actual que tenemos de ese producto
    volumen_total -= (volumen_prod * inventario_productos[id_prod].first);          // y luego añadimos la nueva cantidad 
    
    peso_total += (peso_prod * uds_obtenidas);
    volumen_total += (volumen_prod * uds_obtenidas);

    inventario_productos[id_prod].first = uds_obtenidas;
    inventario_productos[id_prod].second = uds_necesitadas; 
    
}

void Ciudad::quitar_prod(int id_prod, int peso_prod, int volumen_prod) {
    peso_total -= (peso_prod * inventario_productos[id_prod].first);
    volumen_total -= (volumen_prod * inventario_productos[id_prod].first);
    inventario_productos.erase(id_prod);
}

void Ciudad::reset_inventario() {
    inventario_productos.clear();
    peso_total = 0;
    volumen_total = 0;
}

void Ciudad::comerciar(Ciudad& ciudad_2, const Productos& productos) {
    map<int, pair<int, int>>::iterator it1 = this->inventario_productos.begin();
    map<int, pair<int, int>>::iterator it2 = ciudad_2.inventario_productos.begin();
    while (it1 != this->inventario_productos.end() and it2 != ciudad_2.inventario_productos.end()) {

        int id_prod1 = it1->first;
        int id_prod2 = it2->first;

        if (id_prod1 > id_prod2) ++it2;
        else if (id_prod1 < id_prod2) ++it1;
        else {

            int sobrante1 = it1->second.first - it1->second.second;
            int sobrante2 = it2->second.first - it2->second.second;

            int peso_prod = productos.consultar_peso(id_prod1);
            int volumen_prod = productos.consultar_volumen(id_prod1);

            if (sobrante1 > 0 and sobrante2 < 0) {              // solo hacemos intercambio si le sobran productos a la ciudad_1 y necesita productos a la ciudad 2         
                int intercambio = min(sobrante1, -sobrante2);
                it1->second.first -= intercambio;               // se decrementan las unidades en posesión de la ciudad 1   
                it2->second.first += intercambio;               // se incrementan las unidades en posesión de la ciudad 2

                // Actualizar el peso y el volumen total 
                this->peso_total -= intercambio * peso_prod;
                this->volumen_total -= intercambio * volumen_prod;
                ciudad_2.peso_total += intercambio * peso_prod;
                ciudad_2.volumen_total += intercambio * volumen_prod;

            }
            else if (sobrante1 < 0 and sobrante2 > 0) {         // solo hacemos intercambio si necesita productos a la ciudad_1 y le sobran productos a la ciudad 2                 
                int intercambio = min(-sobrante1, sobrante2);
                it1->second.first += intercambio;               // se incrementan las unidades en posesión de la ciudad 1
                it2->second.first -= intercambio;               // se decrementan las unidades en posesión de la ciudad 2

                // Actualizar el peso y el volumen total 
                this->peso_total += intercambio * peso_prod;
                this->volumen_total += intercambio * volumen_prod;
                ciudad_2.peso_total -= intercambio * peso_prod;
                ciudad_2.volumen_total -= intercambio * volumen_prod;
            }
            ++it1;
            ++it2;
        }    
    }
}

// Consultores 

void Ciudad::escribir_ciudad() const {
    map<int, pair<int, int>>:: const_iterator it = inventario_productos.begin();
    while (it != inventario_productos.end()) {
        cout << (it->first) + 1 << " " << it->second.first << " " << it->second.second << endl;    
        ++it;
    }
    cout << peso_total << " " << volumen_total << endl;
}

pair<int,int> Ciudad::consultar_prod(int id_prod) const {
    map<int, pair<int, int>>::const_iterator it;
    it = inventario_productos.find(id_prod);
    pair<int, int> p = it->second;
    return p;
}

bool Ciudad::prod_existe(int id_prod) const {
    if (inventario_productos.count(id_prod) == 0) return false;
    else return true;
}

int Ciudad::peso_total_ciudad() const {
    return peso_total;
}

int Ciudad::volumen_total_ciudad() const {
    return volumen_total;
}


