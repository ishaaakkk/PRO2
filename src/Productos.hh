/** @file Productos.hh
    @brief Especificacion de la clase Productos
*/

#ifndef _PRODUCTOS_HH
#define _PRODUCTOS_HH

/** @cond       */ 
    #include <vector>
    #include <iostream>
/** @endcond    */

using namespace std;

/** @class Productos
    @brief Representa un conjunto de productos 

    Es un vector de todos los productos que tenemos con su respectivo peso y su volumen. 
    Tambien tiene un struct llamado Producto que contiene un entero llamado peso 
    y otro entero llamado volumen. 
*/

class Productos {
private:

    struct Producto {
        int peso;
        int volumen;
    };
    vector<Producto> v_productos;

    /** @brief Lee un Producto y lo devuelve

        Lee el peso y el volumen del producto y lo devuelve
        \pre <em>cierto</em>
        \post Devuelve un producto con su respectivo peso y volumen
    */
    static Producto leer_producto();

public: 

// Constructores 

    /** @brief Creadora por defecto 

        Se ejecuta automaticamente al declarar un productos.
        \pre <em>cierto</em>
        \post El resultado es la clase productos 
    */
    Productos();

// Modificadores 

    /** @brief Agrega productos al conjunto de productos

        Se lee el numero de productos nuevos, y se van añadiendo estos productos 
        al conjunto de productos con sus respectivos peso y volumenes 
        \pre <em>cierto</em>
        \post Se añaden al conjunto de productos los productos
    */
   	void agregar_productos(int num_productos);


// Consultores 

    /** @brief Consulta cuantos productos diferentes hay 					

        \pre <em>cierto</em>
        \post El resultado es el numero de productors diferentes que hay
    */
   	int consultar_num() const;

    /** @brief Se escribe el producto

        Se escriben los datos del producto 
        \pre El producto existe										
        \post Se escribe por pantalla el peso y el volumen del producto	
    */
   	void esribir_producto(int id_prod) const;

    /** @brief Consulta el peso de un determinado producto					

        \pre El producto existe
        \post Devuelve el peso del producto
    */
   	int consultar_peso(int id_prod) const;

    /** @brief Consulta el volumen de un determinado producto					

        \pre El producto existe
        \post Devuelve el volumen del producto
    */
   	int consultar_volumen(int id_prod) const;

};

#endif