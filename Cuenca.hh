/** @file Cuenca.hh
    @brief Especificacion de la clase Cuenca
*/

#ifndef _CUENCA_HH_
#define _CUENCA_HH_

#include "Ciudad.hh"
#include "Productos.hh"
#include "Barco.hh"

/** @cond       */ 
    #include "BinTree.hh"
    #include <map>
/** @endcond    */

using namespace std;

/** @class Cuenca
    @brief Representa una cuenca 

    Es un cuenca fluvial donde hay ciudadades en sus fuentes, en los puntos 
    en que dos afluentes se unen y en la desembocadura. La cuenca tambien tiene 
	un barco mediante el cual se puede comerciar entre las diferentes ciudades. 
*/

class Cuenca {
private:

	BinTree<string> arbol_ciudades;
    map<string, Ciudad> ciudades;
    
    /** @brief Lee la estructura de la cuenca con formato arboreo

        Tiene por referencia el arbol en el que se quiera guardadar la estructra 
        de la cuenca y tambien tienes por referencia el conjunto de ciudades 
        para poder añadirlas
        \pre <em>cierto</em>
        \post El resultado es un arbol binario con la estructura de la cuenca y
        las ciudades añadidas al conjunto de ciudades 
    */
    static void leer_arbol(BinTree<string>& a, map<string, Ciudad>& ciudades);

    /** @brief Funcion auxiliar para poder hacer la función de redistribuir 

        Cada ciudad comercia con la ciudad que tiene a la izquierda y a la derecha
        \pre <em>cierto</em>
        \post Todas las ciudades comercian con las ciudades que tiene a la izquierda y a la derecha
    */
    static void redistribuir_aux(const BinTree<string>& a, const Productos& productos, map<string, Ciudad>& ciudades);

    /** @brief Funcion que obtiene la mejor ruta para el barco
       
        Esta funcion tiene como parametro la funcion lista que es donde se guardara
        la mejora ruta, y tambien tiene los atributos del barco, donde el pair<int ,int> 
        prods_barco el primer entero representa la cantidad de producto que se quiere 
        compra y el segundo entero la cantidad de productos que se quiere vender  
        \pre <em>cierto</em>
        \post Se devuelve un entero con el numero de intercambios y en lista ruta se guarda la mejora ruta
    */
    static int mejor_ruta(list<string>& ruta, const BinTree<string>& a, int id_prod_comprar, int id_prod_vender, pair<int, int> prods_barco, map<string, Ciudad>& ciudades);

    /** @brief Se realiza la ruta indicar por la lista ruta
       
        El barco hace la ruta entre las ciudades que tiene la lista ruta, 
        tambien tiene los atributos del barco donde el donde el pair<int ,int> prods_barco 
        el primer entero representa la cantidad de producto que se quiere compra y el 
        segundo entero la cantidad de productos que se quiere vender 
        \pre <em>cierto</em>
        \post Se devuelve un entero con el numero de intercambios y en lista ruta se guarda la mejora ruta
    */
    static void hacer_ruta(list<string> ruta, int id_prod_comprar, int id_prod_vender, pair<int, int> prods_barco, const Productos& productos, map<string, Ciudad>& ciudades);

public: 

// Constructores 

    /** @brief Creadora por defecto 

        Se ejecuta automaticamente al declarar una cuenca.
        \pre <em>cierto</em>
        \post El resultado es un cuenca
    */
    Cuenca();

// Modificadores 

    /** @brief Lee un rio

     *  
        Se lee la estructura del rio, obteniendo una estructura arborea con
        los respectivos nombres de las ciudades en los nodos
        \pre <em>cierto</em>
        \post El resultado es una cuenca con una nueva configuracion y un barco 
		con cero ciudades visitada														 
    */
    void leer_rio();

    /** @brief Lee el inventario de una ciudad							                 
     
        Se tiene como parametros el identificador de la ciudad y del producto, asi comos las
        unidades que tiene la ciudad de ese producto y las unidades que necesita. Tambien se 
        tiene como parametro el peso y el volumen del producto. 
        Se añadira este producto a su respectiva ciudad 
        \pre La ciudad existe y el numero de unidades necesitadas siempre ha de ser mayor que 0		            
        \post Se añadira a la ciudad deseada la cantidad de elementos del inventario
		con su identificador, las cantidad que tiene la ciudad y la cantidad que necesita
    */
    void leer_inventario(string id_ciudad, int num_elem, const Productos& productos);

    /** @brief Lee los inventarios de diferentes ciudades  

        Se leeran los inventarios de ciudades del rio, en las mismas
		condiciones que la funcion leer_inventario() de la clase Ciudad. 
        \pre Las ciudades existen. 
        \post El resultado son las respectivas ciudades con sus inventarios leidos
    */
   	void leer_inventarios(const Productos& productos);


    /** @brief Se lee un producto y sus datos y se añade a su respectiva ciudad 				

        Tiene como parametros el identificador de la ciudad y del producto, las unidades 
        que tiene la ciudad y las unidades necesarias para la ciudad. Tambien se tiene 
        como parametro el peso del producto y su volumen para poder modificar el peso 
        total y el volumen total de la ciudad.
        \pre La ciudad existe, el producto existe y el producto no esta en el inventario de la ciudad 	    
        \post Se añade a la respectiva ciudad el producto con la cantidad que tiene y que necesita 
    */
   	void poner_prod(string id_ciudad, int id_prod, int uds_obtenidas, int uds_necesitadas, int peso_prod, int volumen_prod); 

    /** @brief Se modifica la cantidad que tiene y que necesita de un determinado producto
     
	 	Tiene como parametros el identificador de la ciudad y del producto, las unidades 
        que tiene la ciudad y las unidades necesarias para la ciudad. Tambien se tiene 
        como parametro el peso del producto y su volumen para poder modificar el peso 
        total y el volumen total de la ciudad
        \pre La ciudad existe, el producto existe y el producto esta en el inventario de la ciudad 
        \post Se modifica las cantidad que tiene y que necesita una ciudad de un determinado 
        producto y se modifica el peso total y volumen total de la ciudad, tambien se escribe 
        el peso y volumen total por la pantalla 
    */
   	void modificar_prod(string id_ciudad, int id_prod, int uds_obtenidas, int uds_necesitadas, int peso_prod, int volumen_prod); 
    
    /** @brief Se quitara un producto de una ciudad 

        Tiene como parametros el identificador de la ciudad y del producto, 
        el peso del producto y el volumen del producto. Se quitar el 
        producto de la ciudad y se restara su respectivo peso al peso total
        de la ciudad y su respectivo volumen al volumen total de la ciudad 
        \pre El producto existe, la ciudad existe y el producto esta en el inventario 
        \post Se quitan los datos de ese producto en la ciudad modificandose el peso 
		y el volumen total si hace falta. Se escribe el peso y el volumen total.
    */
    void quitar_prod(string id_ciudad, int id_prod, int peso_prod, int volumen_prod);

    /** @brief Se elimina el inventario de una ciudad

        \pre La ciudad existe
        \post Se vacia el inventario de productos de la ciudad
    */
    void reset_inventario_ciudad(string id_ciudad);

    /** @brief Dos ciudades comercian entre ellas 

        Una ciudad le dará a la otra todos los productos que le sobren 
        hasta alcanzar si es posible los que la otra necesite, y viceversa.
        \pre Las dos ciudades existen y son diferentes                          
        \post Las dos ciudades comercian
    */
   	void comerciar(string id_ciudad1, string id_ciudad2, const Productos& productos);

    /** @brief La ciudad de la desembocadura comercia con su ciudad rio arriba
	  	a mano derecha y luego con la ciudad rio arriba a mano izquierda,
		y asi sucesivamente. 

        \pre <em>cierto</em>  
        \post Las ciudades que tienen un rio que las conecta comercian entre ellas
    */
   	void redistribuir(const Productos& productos);

    /** @brief Se busca la mejor ruta para comprar y vender productos 

	 	El barco busca la ruta a partir de la desembocadura que le permita 
		comprar y vender el mayor numero posible de productos. En caso que haya
		mas de una ruta que lo cumpla, se queda con la mas corta, y en caso de que 
		tengan la misma longitud, se queda con la que viene rio arriba a mano derecha. 
		Una vez encontrada la ruta, se hace el viaje y se compran y venden los productos 
		a lo largo de la ruta, modificandose los inventarios de las ciudades.
        \pre <em>cierto</em>
        \post Se hace la mejor ruta obenida comerciando entre las diferentes ciudades y 
		se escribe el total de unidades de productos compradas y vendidas por el barco,
        tambien se añade a las ciudades visitadas por el barco la ultima ciudad donde 
        se ha hecho alguna tipo de intercambio
    */
   	void hacer_viaje(Barco& barco, const Productos& productos);

// Consultores 

    /** @brief Se escribe la ciudad 

        Se escribe los datos de la ciudad								
        \pre La ciudad existe 																        
        \post Se escribe por pantalla el inventario de la ciudad, el peso total y el
		volumen total de los productos almacenados
    */
    void escribir_ciudad(string id_ciudad) const;           

    /** @brief Retorna si una ciudad existe en la cuenca

        Tiene como parametro el identificador de una ciudad y se 
        retorna verdadero si la ciudad existe, falso de otro modo
        \pre <em>cierto</em>                                                                                        
        \post Se devuelve un booleano donde indica si una ciudad existe o no
    */    
    bool ciudad_existe(string id_ciudad) const; 

    /** @brief Se escribe cuantas unidades de ese producto tiene y quiere la ciudad

        Tiene como parametro el identificador del producto. Se devuele un pair<int ,int> 
        donde el primer valor son el numero de unidades que tiene la ciudad de ese producto 
        y el segundo valor es el numero de unidades necesitadas por la ciudad de ese producto 
        \pre El producto existe, la ciudad existe y el producto esta en el inventario de la ciudad
        \post Se devuelve un pair de enteros donde se indica el numero de unidades que tiene 
        una ciudad de un producto y el numero de unidades necesarias para la ciudad de ese producto                         
    */
   	pair<int,int> consultar_prod(string id_ciudad, int id_prod) const; 

    /** @brief Retorna si un producto ya esta en el inventario de la ciudad 

        Se retorna verdadero si el producto ya esta en el inventario de la ciudad falso de otro modo
        \pre <em>cierto</em>                                                                                        
        \post Se devuelve un booleano donde indica si un producto esta dentro del inventario de la ciduad o no
    */
    bool prod_existe_en_ciudad(string id_ciudad, int id_prod) const;

    /** @brief Retorna el peso total que tiene una ciudad

        \pre <em>cierto</em>                                                                                        
        \post Se retorna el peso total de la ciudad  
    */
   int peso_total_ciudad(string id_ciudad) const;                   

    /** @brief Retorna el volumen total que tiene una ciudad

        \pre <em>cierto</em>                                                                                        
        \post Se retorna el volumen total de la ciudad  
    */
   int volumen_total_ciudad(string id_ciudad) const;           

};

#endif