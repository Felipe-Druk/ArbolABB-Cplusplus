#ifndef TP3_ALGO2_INFORMASTICOS_NODOABBABB_H
#define TP3_ALGO2_INFORMASTICOS_NODOABBABB_H
#include <iostream>

template <typename Clave, typename Dato>
class NodoABB
{

private:
    Dato dato;
    Clave clave;
    NodoABB *padre;
    NodoABB *hijo_derecho;
    NodoABB *hijo_izquierdo;

public:
    // CONSTRUCTOR
    NodoABB(Dato dato, Clave clave);

    // CONSTRUCTOR
    NodoABB(Dato dato, Clave clave, NodoABB *padre);

    // PRE: -
    // POST: Asigna el dato y la clave
    void asignar_dato_clave(Dato dato, Clave clave);

    // PRE: -
    // POST: Asigna el hijo derecho
    void asignar_hijo_derecho(NodoABB *hijo_derecho);

    // PRE: -
    // POST: Asigna el hijo izquierdo
    void asignar_hijo_izquierdo(NodoABB *hijo_izquierdo);

    // PRE: -
    // POST: Asigna el padre
    void asignar_padre(NodoABB *padre);

    // PRE: -
    // POST: Devuelve el dato
    Dato obtener_dato();

    // PRE: -
    // POST: Obtiene la clave actual
    Clave obtener_clave();

    // PRE: -
    // POST: Obtiene el hijo derecho
    NodoABB *obtener_hijo_derecho();

    // PRE: -
    // POST: Obtiene el hijo izquierdo
    NodoABB *obtener_hijo_izquierdo();

    // PRE: -
    // POST: Obtiene el padre
    NodoABB *obtener_padre();

    // PRE: -
    // POST: Elimina el hijo dado
    void eliminar_hijo(NodoABB *hijo);

    // PRE: -
    // POST: Reasigna el hijo dado
    void reasignar_hijo(NodoABB *hijo_anterior, NodoABB *nuevo_hijo);

    // PRE: -
    // POST: Devuelve los nodos ordenandolos de la siguiente manera, el  subarbol izquierdo  se visita primero, luego el  nodo raiz y luego el subarbol derecho
    void mostrar_inorder();

    // PRE: -
    // POST: Devuelve los nodos ordenandolos de la siguiente manera, el nodo raiz se visita primero, luego el  subarbol izquierdo y luego el subarbol derecho
    void mostrar_preorder();

    // PRE: -
    // POST: Devuelve los nodos ordenandolos de la siguiente manera, el subarbol izquierdo , luego el  subarbol derecho y luego el nodo raiz
    void mostrar_postorder();

    // DESTRUCTOR.
    ~NodoABB();
};

template <typename Clave, typename Dato>
NodoABB<Clave, Dato>::NodoABB(Dato _dato, Clave clave)
{
    this->dato = _dato;
    this->clave = clave;
    hijo_derecho = nullptr;
    hijo_izquierdo = nullptr;
    padre = nullptr;
}

template <typename Clave, typename Dato>
NodoABB<Clave, Dato>::NodoABB(Dato _dato, Clave clave, NodoABB<Clave, Dato> *padre)
{
    this->dato = _dato;
    this->clave = clave;
    hijo_derecho = nullptr;
    hijo_izquierdo = nullptr;
    this->padre = padre;
}

template <typename Clave, typename Dato>
void NodoABB<Clave, Dato>::asignar_dato_clave(Dato _dato, Clave _clave)
{
    this->dato = _dato;
    this->clave = _clave;
}

template <typename Clave, typename Dato>
void NodoABB<Clave, Dato>::asignar_hijo_derecho(NodoABB<Clave, Dato> *_hijo_derecho)
{
    this->hijo_derecho = _hijo_derecho;
}

template <typename Clave, typename Dato>
void NodoABB<Clave, Dato>::asignar_hijo_izquierdo(NodoABB<Clave, Dato> *_hijo_izquierdo)
{
    this->hijo_izquierdo = _hijo_izquierdo;
}

template <typename Clave, typename Dato>
void NodoABB<Clave, Dato>::asignar_padre(NodoABB<Clave, Dato> *_padre)
{
    this->padre = _padre;
}

template <typename Clave, typename Dato>
Dato NodoABB<Clave, Dato>::obtener_dato()
{
    return dato;
}

template <typename Clave, typename Dato>
Clave NodoABB<Clave, Dato>::obtener_clave()
{
    return clave;
}

template <typename Clave, typename Dato>
NodoABB<Clave, Dato> *NodoABB<Clave, Dato>::obtener_hijo_derecho()
{
    return hijo_derecho;
}

template <typename Clave, typename Dato>
NodoABB<Clave, Dato> *NodoABB<Clave, Dato>::obtener_hijo_izquierdo()
{
    return hijo_izquierdo;
}

template <typename Clave, typename Dato>
NodoABB<Clave, Dato> *NodoABB<Clave, Dato>::obtener_padre()
{
    return padre;
}

template <typename Clave, typename Dato>
void NodoABB<Clave, Dato>::eliminar_hijo(NodoABB<Clave, Dato> *hijo)
{
    if (hijo == hijo_derecho)
    {
        hijo_derecho = nullptr;
    }
    else
    {
        hijo_izquierdo = nullptr;
    }
}

template <typename Clave, typename Dato>
void NodoABB<Clave, Dato>::reasignar_hijo(NodoABB<Clave, Dato> *hijo_anterior, NodoABB<Clave, Dato> *nuevo_hijo)
{
    if (hijo_anterior == hijo_izquierdo)
    {
        hijo_izquierdo = nuevo_hijo;
    }
    else
    {
        hijo_derecho = nuevo_hijo;
    }
}

template <typename Clave, typename Dato>
void NodoABB<Clave, Dato>::mostrar_inorder()
{
    if (hijo_izquierdo)
    {
        hijo_izquierdo->mostrar_inorder();
    }
    std::cout << dato << " ";
    if (hijo_derecho)
    {
        hijo_derecho->mostrar_inorder();
    }
}

template <typename Clave, typename Dato>
void NodoABB<Clave, Dato>::mostrar_preorder()
{
    std::cout << dato << " ";
    if (hijo_izquierdo)
    {
        hijo_izquierdo->mostrar_preorder();
    }
    if (hijo_derecho)
    {
        hijo_derecho->mostrar_preorder();
    }
}

template <typename Clave, typename Dato>
void NodoABB<Clave, Dato>::mostrar_postorder()
{
    if (hijo_izquierdo)
    {
        hijo_izquierdo->mostrar_postorder();
    }
    if (hijo_derecho)
    {
        hijo_derecho->mostrar_postorder();
    }
    std::cout << dato << " ";
}

template <typename Clave, typename Dato>
NodoABB<Clave, Dato>::~NodoABB()
{
    if (hijo_izquierdo)
    {
        delete hijo_izquierdo;
        hijo_izquierdo = nullptr;
    }

    if (hijo_derecho)
    {
        delete hijo_derecho;
        hijo_derecho = nullptr;
    }
}

#endif // TP3_ALGO2_INFORMASTICOS_NODOABBABB_H
