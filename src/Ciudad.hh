/** @file Ciudad.hh
    @brief Especificacion de la clase Ciudad 
*/

#ifndef _CIUDAD_HH
#define _CIUDAD_HH

#include "Productos.hh"


/** @cond       */  
    #include <map>
    #include <string>
    #include <iostream> 
/** @endcond    */

using namespace std;

/** @class Ciudad
    @brief Representa una ciudad

    Es una ciudad que tiene como atributos un map que contiene 
    el identificador del producto y el numero de productos que 
    tiene y el numero de productos que necesita. Tambien tiene 
    el peso total de la ciudad y el volumen total de la ciudad
*/

class Ciudad {
private:

    map<int, pair<int,int>> inventario_productos;   //primer int del pair son las unidades del producto que tiene 
                                                    //segundo int del pair son las unidades del producto que necesita 
    int peso_total;
    int volumen_total;

public:
// Constructores 

    /** @brief Creadora por defecto 

        Se ejecuta automaticamente al declarar una ciudad.
        \pre <em>cierto</em>
        \post El resultado es una ciudad con un inventario de productos vacios, un peso total 0 y un volumen total 0
    */
    Ciudad();

// Modificadores 

    /** @brief Se lee un producto y sus datos y se añade a su respectiva ciudad 				

        Tiene como parametros el identificador del producto, las unidades que tiene la ciudad 
        y las unidades necesarias para la ciudad. Tambien se tiene como parametro el peso del 
        producto y su volumen para poder modificar el peso total y el volumen total de la ciudad.
        \pre La ciudad existe, el producto existe y el producto no esta en el inventario de la ciudad 	    
        \post Se añade a la respectiva ciudad el producto con la cantidad que tiene y que necesita, 
        tambien se modifica aumenta el peso total y volumen total de la ciudad respecto a las uds
        que tiene del producto
    */
   	void poner_prod(int id_prod, int uds_obtenidas, int uds_necesitadas, int peso_prod, int volumen_prod);              

    /** @brief Se modifica la cantidad que tiene y que necesita de un determinado producto
     
	 	Tiene como parametros el identificador del producto, las unidades que tiene la ciudad 
        y las unidades necesarias para la ciudad. Tambien se tiene como parametro el peso del 
        producto y su volumen para poder modificar el peso total y el volumen total de la ciudad
        \pre La ciudad existe, el producto existe y el producto esta en el inventario de la ciudad 
        \post Se modifica las cantidad que tiene y que necesita una ciudad de un determinado producto y
		se modifica el peso total y volumen total de la ciudad, tambien se escribe el peso y volumen 
		total por la pantalla 
    */
   	void modificar_prod(int id_prod, int uds_obtenidas, int uds_necesitadas, int peso_prod, int volumen_prod);      

    /** @brief Se quitara un producto de una ciudad 

        Tiene como parametros el identificador del producto, el peso del producto 
        y el volumen del producto. Se quitar el producto de la ciudad y se restara 
        su respectivo peso al peso total de la ciudad y su respectivo volumen al
        volumen total de la ciudad 
        \pre El producto existe, la ciudad existe y el producto esta en el inventario 
        \post Se quitan los datos de ese producto en la ciudad modificandose el peso 
		y el volumen total si hace falta. Se escribe el peso y el volumen total.
    */
   void quitar_prod(int id_prod, int peso_prod, int volumen_prod);                                          

    /** @brief Se vacia el inventario de productos de la ciudad

        \pre <em>cierto</em>
        \post El resultado es una ciudad con el inventario de productos vacio
    */
   void reset_inventario();

    /** @brief Dos ciudades comercian entre ellas 

        Una ciudad le dará a la otra todos los productos que le sobren 
        hasta alcanzar si es posible los que la otra necesite, y viceversa.
        \pre Las dos ciudades existen y son diferentes                                    
        \post Las dos ciudades comercian entre ellas, una ciudad le dará a la otra todos los 
        productos que le sobren hasta alcanzar si es posible los que la otra necesite, y viceversa
    */
   void comerciar(Ciudad& ciudad_2, const Productos& productos);

// Consultores 

    /** @brief Se escribe la ciudad 

        Se escribira su inventario, el peso y el volumen total de
        los productos almacenados.								
        \pre <em>cierto</em>															        
        \post Se escribe por pantalla el inventario de la ciudad, el peso total y el
		volumen total de los productos almacenados
    */
    void escribir_ciudad() const;                       

    /** @brief Se escribe cuantas unidades de ese producto tiene y quiere la ciudad

        Tiene como parametro el identificador del producto. Se devuele un pair<int ,int> 
        donde el primer valor son el numero de unidades que tiene la ciudad de ese producto 
        y el segundo valor es el numero de unidades necesitadas por la ciudad de ese producto 
        \pre El producto existe, la ciudad existe y el producto esta en el inventario de la ciudad
        \post Se devuelve un pair de enteros donde se indica el numero de unidades que tiene una 
        ciudad de un producto y el numero de unidades necesarias para la ciudad de ese producto                         
    */
   	pair<int,int> consultar_prod(int id_prod) const;                      

    /** @brief Devuelve si un producto ya esta en el inventario

        Se retorna verdadero si el producto ya esta en el inventario 
        de la ciudad falso de otro modo
        \pre <em>cierto</em>                                                                                        
        \post Se devuelve un booleano donde indica si un producto esta en el inventario o no
    */
    bool prod_existe(int id_prod) const;

    /** @brief Retorna el peso total 

        \pre <em>cierto</em>                                                                                        
        \post Se retorna el peso total
    */
    int peso_total_ciudad() const;              

    /** @brief Retorna el volumen total 

        \pre <em>cierto</em>                                                                                        
        \post Se retorna el volumen total
    */
    int volumen_total_ciudad() const;           

};

#endif 