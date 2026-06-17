/** @file Barco.hh
    @brief Especificacion de la clase Barco
*/

#ifndef _BARCO_HH
#define _BARCO_HH

/** @cond       */ 
    #include <list> 
    #include <string>
    #include <iostream>
/** @endcond    */

using namespace std;

/** @class Barco
    @brief Representa un barco

    Es un barco que tiene como atributo los productos que quiere comprar 
    y cuantas unidades de estos y los productos que quiere vender y cuantos
    unidades de estos. Tambien tiene un atributo representando las ciudades 
    que ha visitado 
*/

class Barco {
private:

    int id_comprar;
    int cant_comprar;
    int id_vender;
    int cant_vender;
    list<string> viajes_realizados;

public: 
// Constructores 

    /** @brief Creadora por defecto 

        Se ejecuta automaticamente al declarar un barco.
        \pre <em>cierto</em>
        \post El resultado es un barco
    */
    Barco();

// Modificadores 

    /** @brief Modifica el barco

        Se modifcan los atributos privados  
        \pre Los dos productos existen y son diferentes							
        \post El resultado es el barco modificado.
    */
    void modificar_barco(int id_comprar, int cant_comprar, int id_vender, int cant_vender);

    /** @brief Se eliminan todas las ciudades visitadas por el barco 

        \pre <em>cierto</em>						
        \post El resultado es el barco con cero ciudades visitadas
    */
    void reset_ciudades();

    /** @brief Se añade a las ciudades visitadas la ciudad

        \pre <em>cierto</em>						
        \post El resultado es el barco una ciudad visitada de más 
    */
    void anadir_ciudad(string id_ciudad);

// Consultores 

    /** @brief Se escriben los atributos del barco

        Se escriben los cuatro valores del barco y tambien los viajes realizados 
		en la cuenca actual en orden cronologico.
        \pre <em>cierto</em>
        \post Se escribe por pantalla los cuatros valores del barco y los viajes realizados
    */
   	void escribir_barco() const;

    /** @brief Se devuelve el identificador del producto que se quiere comprar


        \pre <em>cierto</em>
        \post Se devuleve el id del producto que se quiere comprar 
    */
    int consultar_id_prod_comprar() const;

    /** @brief Se devuelve el identificador del producto que se quiere vender


        \pre <em>cierto</em>
        \post Se devuleve el id del producto que se quiere vender 
    */
    int consultar_id_prod_vender() const;

    /** @brief Se devuelve la cantidad de productos que se quiere comprar 


        \pre <em>cierto</em>
        \post Se devuelve cuantos productos se quieren comprar 
    */
    int consultar_cant_prod_comprar() const;

    /** @brief Se devuelve la cantidad de productos que se quiere vender 


        \pre <em>cierto</em>
        \post Se devuelve cuantos productos se quieren vender 
    */
    int consultar_cant_prod_vender() const;
};

#endif