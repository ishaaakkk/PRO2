/** @file Cuenca.cc
    @brief Codigo de la clase Cuenca
*/

#include "Cuenca.hh"

using namespace std;

// Constructores 

Cuenca::Cuenca() {}                 // si no se pone da error al compilar 

// Modificadores 

void Cuenca::leer_arbol(BinTree<string>& a , map<string, Ciudad>& ciudades) {
    BinTree<string> a1;
    BinTree<string> a2;
    string x;
    cin >> x;
    if (x != "#") {
        Ciudad c;
        ciudades[x] = c;
        leer_arbol(a1, ciudades);
        leer_arbol(a2, ciudades);
        a = BinTree<string>(x, a1, a2);
    }
}

void Cuenca::leer_rio() {
    arbol_ciudades = BinTree<string>();
    ciudades.clear();
    leer_arbol(arbol_ciudades, ciudades);
}

void Cuenca::poner_prod(string id_ciudad, int id_prod, int uds_obtenidas, int uds_necesitadas, int peso_prod, int volumen_prod) {
    ciudades[id_ciudad].poner_prod(id_prod, uds_obtenidas, uds_necesitadas, peso_prod, volumen_prod);
}

void Cuenca::modificar_prod(string id_ciudad, int id_prod, int uds_obtenidas, int uds_necesitadas, int peso_prod, int volumen_prod) {
    ciudades[id_ciudad].modificar_prod(id_prod, uds_obtenidas, uds_necesitadas, peso_prod, volumen_prod);
}

void Cuenca::quitar_prod(string id_ciudad, int id_prod, int peso_prod, int volumen_prod) {
    ciudades[id_ciudad].quitar_prod(id_prod, peso_prod, volumen_prod);
}

void Cuenca::leer_inventario(string id_ciudad, int num_elem, const Productos& productos) {
    reset_inventario_ciudad(id_ciudad);          // Cuando se lee un inventario de una ciudad que ya existe, el nuevo inventario substituye al anterior en caso de que lo tuviera
    int id_prod, uds_obtenidas, uds_necesitadas;
    for (int i = 0; i < num_elem; ++i) {
        cin >> id_prod >> uds_obtenidas >> uds_necesitadas;
        int peso_prod = productos.consultar_peso(id_prod - 1);
        int volumen_prod = productos.consultar_volumen(id_prod - 1);
        ciudades[id_ciudad].poner_prod(id_prod - 1, uds_obtenidas, uds_necesitadas, peso_prod, volumen_prod);
    }
}

void Cuenca::leer_inventarios(const Productos& productos) {
    string id_ciudad;
    cin >> id_ciudad;
    while (id_ciudad != "#") {
        reset_inventario_ciudad(id_ciudad);    // Cuando se lee un inventario de una ciudad que ya existe, el nuevo inventario substituye al anterior en caso de que lo tuviera
        int num_elem;
        cin >> num_elem;
        int id_prod, uds_obtenidas, uds_necesitadas;
        
        for (int i = 0; i < num_elem; ++i) {
            cin >> id_prod >> uds_obtenidas >> uds_necesitadas;
            int peso_prod = productos.consultar_peso(id_prod - 1);
            int volumen_prod = productos.consultar_volumen(id_prod - 1);
            ciudades[id_ciudad].poner_prod(id_prod - 1, uds_obtenidas, uds_necesitadas, peso_prod, volumen_prod);
        }
        cin >> id_ciudad;
    }
}

void Cuenca::reset_inventario_ciudad(string id_ciudad) {
    ciudades[id_ciudad].reset_inventario();             
}

void Cuenca::comerciar(string id_ciudad1, string id_ciudad2, const Productos& productos) {
    ciudades[id_ciudad1].comerciar(ciudades[id_ciudad2], productos);                           
}

void Cuenca::redistribuir(const Productos& productos) {
    redistribuir_aux(arbol_ciudades, productos, ciudades);
}

void Cuenca::redistribuir_aux(const BinTree<string>& a, const Productos& productos, map<string, Ciudad>& ciudades) {
    if (not a.empty()) {
        if (not a.left().empty()) 
            ciudades[a.value()].comerciar(ciudades[a.left().value()], productos);
        if (not a.right().empty()) 
            ciudades[a.value()].comerciar(ciudades[a.right().value()], productos); 
        redistribuir_aux(a.left(), productos, ciudades);
        redistribuir_aux(a.right(), productos, ciudades);
    }
}

void Cuenca::hacer_viaje(Barco& barco, const Productos& productos) {
    list<string> ruta;
    int id_prod_comprar = barco.consultar_id_prod_comprar();
    int id_prod_vender = barco.consultar_id_prod_vender();
    pair<int, int> prods_barco (barco.consultar_cant_prod_comprar(), barco.consultar_cant_prod_vender());

    int intercambios = mejor_ruta(ruta, arbol_ciudades, id_prod_comprar, id_prod_vender, prods_barco, ciudades);

    hacer_ruta(ruta, id_prod_comprar, id_prod_vender, prods_barco, productos, ciudades);

    cout << intercambios << endl;

    if (intercambios > 0) barco.anadir_ciudad(ruta.back());    
}

int Cuenca::mejor_ruta(list<string>& ruta, const BinTree<string>& a, int id_prod_comprar, int id_prod_vender, pair<int, int> prods_barco, map<string, Ciudad>& ciudades) {
    if (a.empty()) {
        ruta = list<string> ();
        return 0;
    }
    else {
        string id_ciudad = a.value();
        int intercambios = 0;
        
        if (ciudades[id_ciudad].prod_existe(id_prod_comprar)) {                        
            pair<int, int> p = ciudades[id_ciudad].consultar_prod(id_prod_comprar);     // devuelve un pair donde el primer elemento son las uds_obtenidas y el segundo las uds_necesitadas
            int sobrante = p.first - p.second;
                        // sobrante = uds_en_posesión - uds_necesitadas
            if (sobrante > 0) {                                                         // se compra productos para el barco solo si nos sobran productos en la ciudad
                int aux = min(sobrante, prods_barco.first);
                intercambios += aux;                                                    // añadimos a los intercambios el sobrante 
                prods_barco.first -= aux;
            }  
        }
        if (ciudades[id_ciudad].prod_existe(id_prod_vender)) {
            pair<int, int> p = ciudades[id_ciudad].consultar_prod(id_prod_vender);      // devuelve un pair donde el primer elemento son las uds_obtenidas y el segundo las uds_necesitadas
            int faltante = p.second - p.first; 
                        // faltante = uds_necesitadas - uds_en_posesion
            if (faltante > 0) {                                                         // se venden productos del barco solo si nos faltan productos en la ciudad
                int aux = min(faltante, prods_barco.second);
                intercambios += aux;                                                    // añadimos a los intercambios el faltante
                prods_barco.second -= aux;
            }
        }

        list<string> l1;
        list<string> l2;
        int intercambios1 = mejor_ruta(l1, a.left(), id_prod_comprar, id_prod_vender, prods_barco, ciudades);
        int intercambios2 = mejor_ruta(l2, a.right(), id_prod_comprar, id_prod_vender, prods_barco, ciudades);

        if (intercambios1 == 0 and intercambios2 == 0 and intercambios == 0) {
            ruta = list<string> ();
            return 0;
        }

        else if (intercambios1 > intercambios2) {
            ruta = l1;
            ruta.push_front(a.value());
            return intercambios1 + intercambios;
        }
        else if (intercambios1 < intercambios2) {
            ruta = l2;
            ruta.push_front(a.value());
            return intercambios2 + intercambios;
        }
        else {
            if (l1.size() <= l2.size()) {
                ruta = l1;
                ruta.push_front(a.value());
                return intercambios1 + intercambios;
            }
            else {
                ruta = l2;
                ruta.push_front(a.value());
                return intercambios2 + intercambios;
            }
        }
    }
}

void Cuenca::hacer_ruta(list<string> ruta, int id_prod_comprar, int id_prod_vender, pair<int, int> prods_barco, const Productos& productos, map<string, Ciudad>& ciudades) {
    list<string>::iterator it = ruta.begin();
    string id_ciudad;

    while (it != ruta.end()) {
        id_ciudad = *it;

        if (ciudades[id_ciudad].prod_existe(id_prod_comprar)) {                             // se comprueba si el producto que el barco quiere comprar existe en la ciudad 
            pair<int, int> p = ciudades[id_ciudad].consultar_prod(id_prod_comprar);         // devuelve un pair donde el primer elemento son las uds_obtenidas y el segudno las uds_necesitadas
            int sobrante = p.first - p.second;
                            // sobrante = uds_en_posesión - uds_necesitadas
            if (sobrante > 0) {
                int intercambio = min(sobrante, prods_barco.first);
                prods_barco.first = prods_barco.first - intercambio;

                pair<int, int> cant_prod_ciudad = ciudades[id_ciudad].consultar_prod(id_prod_comprar);

                int peso_prod = productos.consultar_peso(id_prod_comprar);
                int volumen_prod = productos.consultar_volumen(id_prod_comprar);
                ciudades[id_ciudad].modificar_prod(id_prod_comprar, cant_prod_ciudad.first - intercambio, cant_prod_ciudad.second, peso_prod, volumen_prod);

            }  
        }
        if (ciudades[id_ciudad].prod_existe(id_prod_vender)) {                                // se comprueba si el producto que el barco quiere vender existe en la ciudad 
            pair<int, int> p = ciudades[id_ciudad].consultar_prod(id_prod_vender);            // devuelve un pair donde el primer elemento son las uds_obtenidas y el segudno las uds_necesitadas
            int faltante = p.second - p.first;
                            // faltante = uds_necesitadas - uds_en_posesion
            if (faltante > 0) {
                int intercambio = min(faltante, prods_barco.second);
                prods_barco.second = prods_barco.second - intercambio;

                pair<int, int> cant_prod_ciudad = ciudades[id_ciudad].consultar_prod(id_prod_vender);

                int peso_prod = productos.consultar_peso(id_prod_vender);
                int volumen_prod = productos.consultar_volumen(id_prod_vender);
                ciudades[id_ciudad].modificar_prod(id_prod_vender, cant_prod_ciudad.first + intercambio, cant_prod_ciudad.second, peso_prod, volumen_prod);
            }
        }
        ++it;
    }
}

// Consultores 

void Cuenca::escribir_ciudad(string id_ciudad) const {
    map<string, Ciudad>::const_iterator it = ciudades.find(id_ciudad);
    it->second.escribir_ciudad();
}

bool Cuenca::ciudad_existe(string id_ciudad) const {
    return (ciudades.find(id_ciudad) != ciudades.end());
}

pair<int, int> Cuenca::consultar_prod(string id_ciudad, int id_prod) const {
    map<string, Ciudad>::const_iterator it;
    it = ciudades.find(id_ciudad);
    return (it->second).consultar_prod(id_prod);
}

bool Cuenca::prod_existe_en_ciudad(string id_ciudad, int id_prod) const {
    map<string, Ciudad>::const_iterator it;
    it = ciudades.find(id_ciudad);
    return (it->second).prod_existe(id_prod);
}

int Cuenca::peso_total_ciudad(string id_ciudad) const {
    map<string, Ciudad>::const_iterator it;
    it = ciudades.find(id_ciudad);
    return (it->second).peso_total_ciudad();
}

int Cuenca::volumen_total_ciudad(string id_ciudad) const {
    map<string, Ciudad>::const_iterator it;
    it = ciudades.find(id_ciudad);
    return (it->second).volumen_total_ciudad();
}

