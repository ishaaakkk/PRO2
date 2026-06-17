/** @mainpage
    Programa principal
*/

/** @file program.cc
    @brief Programa principal 
*/

#include "Cuenca.hh"
#include "Barco.hh"
#include "Productos.hh"

int main () {
    Cuenca cuenca;
    Barco barco;            
    Productos productos;

    int num_productos;
    cin >> num_productos;
    productos.agregar_productos(num_productos);
    
    cuenca.leer_rio();  

    int id_comprar, cant_comprar, id_vender, cant_vender;
    cin >> id_comprar >> cant_comprar >> id_vender >> cant_vender;
    barco.modificar_barco(id_comprar - 1, cant_comprar, id_vender - 1, cant_vender);

    string s;
    cin >> s;
    while (s != "fin") {
        
        if (s == "leer_rio" or s == "lr") {

            if (s == "leer_rio") cout << "#leer_rio" << endl;
            else cout << "#lr" << endl;

            cuenca.leer_rio();
            barco.reset_ciudades();

        } else if (s == "leer_inventario" or s == "li") {

            string id_ciudad;
            cin >> id_ciudad;
            cout << "#" << s << " " << id_ciudad << endl;
            int num_elem;
            cin >> num_elem;

            if (not cuenca.ciudad_existe(id_ciudad)) {
                cout << "error: no existe la ciudad" << endl;
                string aux;
                for (int i = 0; i < num_elem; ++i) 
                    cin >> aux >> aux >> aux;                       // se tienen que leer los datos aunque la ciudad no exista 
            
            } else {
                
                cuenca.leer_inventario(id_ciudad, num_elem, productos);

            }

        } else if (s == "leer_inventarios" or s == "ls") {

            cout << "#" << s << endl;

            cuenca.leer_inventarios(productos);

        } else if (s == "modificar_barco" or s == "mb") {

            cout << "#" << s << endl;
            int id_comprar, cant_comprar, id_vender, cant_vender;
            cin >> id_comprar >> cant_comprar >> id_vender >> cant_vender;

            if (id_comprar > productos.consultar_num() or id_vender > productos.consultar_num()) 
                cout << "error: no existe el producto" << endl;
            else if (id_comprar == id_vender)
                cout << "error: no se puede comprar y vender el mismo producto" << endl;
            else barco.modificar_barco(id_comprar - 1, cant_comprar, id_vender - 1, cant_vender);

        } else if (s == "escribir_barco" or s == "eb") {

            cout << "#" << s << endl;
            barco.escribir_barco();

        } else if (s == "consultar_num" or s == "cn") {

            cout << "#" << s << endl;

            cout << productos.consultar_num() << endl;

        } else if (s == "agregar_productos" or s == "ap") {
            
            int num_productos;
            cin >> num_productos;
            cout << "#" << s << " " << num_productos << endl;

            productos.agregar_productos(num_productos);

        } else if (s == "escribir_producto" or s == "ep") {

            int id_prod;
            cin >> id_prod;
            cout << "#" << s << " " << id_prod << endl;

            if (id_prod > productos.consultar_num()) 
                cout << "error: no existe el producto" << endl;
            else productos.esribir_producto(id_prod - 1);

        } else if (s == "escribir_ciudad" or s == "ec") {

            string id_ciudad;
            cin >> id_ciudad;
            cout << "#" << s << " " << id_ciudad << endl;

            if (not cuenca.ciudad_existe(id_ciudad)) 
                cout << "error: no existe la ciudad" << endl;
            else cuenca.escribir_ciudad(id_ciudad);

        } else if (s == "poner_prod" or s == "pp") {

            string id_ciudad;
            cin >> id_ciudad;
            int id_prod, uds_obtenidas, uds_necesitadas;
            cin >> id_prod >> uds_obtenidas >> uds_necesitadas;
            cout << "#" << s << " " << id_ciudad << " " << id_prod << endl;

            if (id_prod > productos.consultar_num())
                cout << "error: no existe el producto" << endl;
            else if (not cuenca.ciudad_existe(id_ciudad)) 
                cout << "error: no existe la ciudad" << endl;
            else if (cuenca.prod_existe_en_ciudad(id_ciudad, id_prod - 1))
                cout << "error: la ciudad ya tiene el producto" << endl;
            else {
                int peso_prod = productos.consultar_peso(id_prod - 1);
                int volumen_prod = productos.consultar_volumen(id_prod - 1);
                cuenca.poner_prod(id_ciudad, id_prod - 1, uds_obtenidas, uds_necesitadas, peso_prod, volumen_prod);
                cout << cuenca.peso_total_ciudad(id_ciudad) << " " << cuenca.volumen_total_ciudad(id_ciudad) << endl;                            
            }

        } else if (s == "modificar_prod" or s == "mp") {

            string id_ciudad;
            cin >> id_ciudad;
            int id_prod, uds_obtenidas, uds_necesitadas;
            cin >> id_prod >> uds_obtenidas >> uds_necesitadas;
            cout << "#" << s << " " << id_ciudad << " " << id_prod << endl;

            if (id_prod > productos.consultar_num())
                cout << "error: no existe el producto" << endl;
            else if (not cuenca.ciudad_existe(id_ciudad)) 
                cout << "error: no existe la ciudad" << endl;
            else if (not cuenca.prod_existe_en_ciudad(id_ciudad, id_prod - 1))
                cout << "error: la ciudad no tiene el producto" << endl;
            else {
                int peso_prod = productos.consultar_peso(id_prod - 1);
                int volumen_prod = productos.consultar_volumen(id_prod - 1);
                cuenca.modificar_prod(id_ciudad, id_prod - 1, uds_obtenidas, uds_necesitadas, peso_prod, volumen_prod);
                cout << cuenca.peso_total_ciudad(id_ciudad) << " " << cuenca.volumen_total_ciudad(id_ciudad) << endl;                       
            }
            
        } else if (s == "quitar_prod" or s == "qp") {

            string id_ciudad;
            cin >> id_ciudad;
            int id_prod;
            cin >> id_prod;
            cout << "#" << s << " " << id_ciudad << " " << id_prod << endl;

            if (id_prod > productos.consultar_num())
                cout << "error: no existe el producto" << endl;
            else if (not cuenca.ciudad_existe(id_ciudad)) 
                cout << "error: no existe la ciudad" << endl;
            else if (not cuenca.prod_existe_en_ciudad(id_ciudad, id_prod - 1))
                cout << "error: la ciudad no tiene el producto" << endl;                
            else {
                int peso_prod = productos.consultar_peso(id_prod - 1);
                int volumen_prod = productos.consultar_volumen(id_prod - 1);
                cuenca.quitar_prod(id_ciudad, id_prod - 1, peso_prod, volumen_prod);
                cout << cuenca.peso_total_ciudad(id_ciudad) << " " << cuenca.volumen_total_ciudad(id_ciudad) << endl;        
            }
            
        } else if (s == "consultar_prod" or s == "cp") {

            string id_ciudad;
            cin >> id_ciudad;
            int id_prod;
            cin >> id_prod;
            cout << "#" << s << " " << id_ciudad << " " << id_prod << endl;

            if (id_prod > productos.consultar_num())
                cout << "error: no existe el producto" << endl;
            else if (not cuenca.ciudad_existe(id_ciudad)) 
                cout << "error: no existe la ciudad" << endl;
            else if (not cuenca.prod_existe_en_ciudad(id_ciudad, id_prod - 1))
                cout << "error: la ciudad no tiene el producto" << endl; 
            else {
                pair<int, int> uds = cuenca.consultar_prod(id_ciudad, id_prod - 1);
                int uds_obtenidas = uds.first;
                int uds_necesitadas = uds.second;
                cout << uds_obtenidas << " " << uds_necesitadas << endl;
            }
            
        } else if (s == "comerciar" or s == "co") {

            string id_ciudad1, id_ciudad2;
            cin >> id_ciudad1 >> id_ciudad2;
            cout << "#" << s << " " << id_ciudad1 << " " << id_ciudad2 << endl;

            if (not cuenca.ciudad_existe(id_ciudad1) or not cuenca.ciudad_existe(id_ciudad2))
                cout << "error: no existe la ciudad" << endl; 
            else if (id_ciudad1 == id_ciudad2)
                cout << "error: ciudad repetida" << endl;
            else {
                cuenca.comerciar(id_ciudad1, id_ciudad2, productos);
            }
                
        } else if (s == "redistribuir" or s == "re") {

            cout << "#" << s << endl;

            cuenca.redistribuir(productos);

        } else if (s == "hacer_viaje" or s == "hv") {

            cout << "#" << s << endl;
            cuenca.hacer_viaje(barco, productos);
            
        } else if (s == "//") {
            string aux;
            getline(cin, aux);
        }
        
        cin >> s;
    }
}