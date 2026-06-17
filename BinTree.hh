/** @file BinTree.hh
    @brief Especificació de la classe BinTree<T>

    Aquesta capçalera defineix la classe BinTree<T> per a arbres binaris genèrics.
    Distribuïda per als cursos de PRO2 a la FIB-UPC.
*/

#ifndef BINTREE_HH
#define BINTREE_HH

#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class BinTree {

public:

    // Constructors i destructor

    /** @brief Constructor per defecte
        \pre cert
        \post Retorna un arbre buit
    */
    BinTree();

    /** @brief Constructor amb arrel i dos subarbres
        \pre cert
        \post Retorna un arbre amb arrel x, fill esquerre a i fill dret d
    */
    BinTree(const T& x, const BinTree& a, const BinTree& d);

    /** @brief Constructor còpia */
    BinTree(const BinTree& other);

    /** @brief Destructor */
    ~BinTree();

    /** @brief Operador d'assignació */
    BinTree& operator=(BinTree other);

    // Consultors

    /** @brief Consulta si l'arbre és buit
        \pre cert
        \post Retorna cert si l'arbre és buit, fals altrament
    */
    bool empty() const;

    /** @brief Consulta el valor de l'arrel
        \pre L'arbre no és buit
        \post Retorna el valor de l'arrel
    */
    const T& value() const;

    /** @brief Retorna el fill esquerre
        \pre L'arbre no és buit
        \post Retorna el subarbre esquerre
    */
    BinTree left() const;

    /** @brief Retorna el fill dret
        \pre L'arbre no és buit
        \post Retorna el subarbre dret
    */
    BinTree right() const;

private:

    struct Node {
        T val;
        BinTree left;
        BinTree right;
        int refs;
        Node(const T& v, const BinTree& l, const BinTree& r)
            : val(v), left(l), right(r), refs(1) {}
    };

    Node* node;

    void swap(BinTree& other);
};

// Implementació inline

template <class T>
BinTree<T>::BinTree() : node(nullptr) {}

template <class T>
BinTree<T>::BinTree(const T& x, const BinTree& a, const BinTree& d) {
    node = new Node(x, a, d);
}

template <class T>
BinTree<T>::BinTree(const BinTree& other) : node(other.node) {
    if (node) ++node->refs;
}

template <class T>
BinTree<T>::~BinTree() {
    if (node) {
        --node->refs;
        if (node->refs == 0) delete node;
    }
}

template <class T>
BinTree<T>& BinTree<T>::operator=(BinTree other) {
    swap(other);
    return *this;
}

template <class T>
void BinTree<T>::swap(BinTree& other) {
    Node* tmp = node;
    node = other.node;
    other.node = tmp;
}

template <class T>
bool BinTree<T>::empty() const {
    return node == nullptr;
}

template <class T>
const T& BinTree<T>::value() const {
    assert(node != nullptr);
    return node->val;
}

template <class T>
BinTree<T> BinTree<T>::left() const {
    assert(node != nullptr);
    return node->left;
}

template <class T>
BinTree<T> BinTree<T>::right() const {
    assert(node != nullptr);
    return node->right;
}

#endif
