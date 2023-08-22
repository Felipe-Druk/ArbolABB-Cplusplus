#ifndef TP3_ALGO2_INFORMASTICOS_ARBOLABB_H
#define TP3_ALGO2_INFORMASTICOS_ARBOLABB_H
#include <iostream>
#include "NodoABB.h"
#include "queue"
#include <vector>

template <typename Clave, typename Dato>
class ArbolABB
{

private:
    NodoABB<Clave, Dato> *raiz;
    int tamanio;

    // PRE: -
    // POST: Si la clave no existe se inserta en el arbol, si existe no se inserta ni modifica ningun valor
    void _insertar(Clave clave, Dato dato, NodoABB<Clave, Dato> *actual);

    // PRE: -
    // POST: Si la clave existe se elimina
    void _eliminar(Clave clave, NodoABB<Clave, Dato> *actual);

    // PRE: -
    // POST: Si se encuentra el dato se devuelve si no devuelve nullptr
    Dato *_consultar(Clave clave, NodoABB<Clave, Dato> *actual, Dato *retorno);

    // PRE: -
    // POST: Devuelve el sucesor inmediato
    NodoABB<Clave, Dato> *encontrar_sucesor(NodoABB<Clave, Dato> *actual);

public:
    ArbolABB();

    // PRE: -
    // POST: Si la clave no existe se inserta en el arbol, si existe no se inserta ni modifica ningun valor
    void insertar(Clave clave, Dato dato);

    // PRE: -
    // POST: Si la clave existe se elimina
    void eliminar(Clave clave);

    // PRE: -
    // POST: Si la clave existe se actualiza
    void actualizar(Clave clave, Dato dato_nuevo);

    // PRE: -
    // POST: Si se encuentra el dato se devuelve si no devuelve nullptr.
    Dato *consultar(Clave dato);

    // PRE: -
    // POST: Devuelve la cantidad de elementos en el arbol.
    int obtener_tamanio();

    // PRE: -
    // POST: Devuelve los nodos ordenandolos de la siguiente manera, el  subarbol izquierdo  se visita primero, luego el  nodo raiz y luego el subarbol derecho.
    void inorder();

    // PRE: -
    // POST: Devuelve los nodos ordenandolos de la siguiente manera, el nodo raiz se visita primero, luego el  subarbol izquierdo y luego el subarbol derecho.
    void preorder();

    // PRE: -
    // POST: Devuelve los nodos ordenandolos de la siguiente manera, el subarbol izquierdo , luego el  subarbol derecho y luego el nodo raiz.
    void postorder();

    // PRE: -
    // POST: Devuelve los nodos ordenados por niveles.
    void datos_ancho(std::vector<Dato> &datos);

    // DESTRUCTOR
    ~ArbolABB();
};

template <typename Clave, typename Dato>
ArbolABB<Clave, Dato>::ArbolABB()
{
    raiz = nullptr;
}

template <typename Clave, typename Dato>
void ArbolABB<Clave, Dato>::_insertar(Clave clave, Dato dato, NodoABB<Clave, Dato> *actual)
{
    Clave clave_actual = actual->obtener_clave();

    if (clave_actual < clave)
    {
        if (!actual->obtener_hijo_derecho())
        {
            actual->asignar_hijo_derecho(new NodoABB<Clave, Dato>(dato, clave, actual));
        }
        else
        {
            _insertar(clave, dato, actual->obtener_hijo_derecho());
        }
    }
    else
    {
        if (!actual->obtener_hijo_izquierdo())
        {
            actual->asignar_hijo_izquierdo(new NodoABB<Clave, Dato>(dato, clave, actual));
        }
        else
        {
            _insertar(clave, dato, actual->obtener_hijo_izquierdo());
        }
    }
}

template <typename Clave, typename Dato>
NodoABB<Clave, Dato> *ArbolABB<Clave, Dato>::encontrar_sucesor(NodoABB<Clave, Dato> *actual)
{
    if (!actual->obtener_hijo_izquierdo())
    {
        return actual;
    }
    return encontrar_sucesor(actual->obtener_hijo_izquierdo());
}

template <typename Clave, typename Dato>
void ArbolABB<Clave, Dato>::_eliminar(Clave clave, NodoABB<Clave, Dato> *actual)
{
    Clave clave_actual = actual->obtener_clave();

    if (clave_actual == clave)
    {
        tamanio--;
        if (!actual->obtener_hijo_izquierdo() && !actual->obtener_hijo_derecho())
        {
            if (actual != raiz)
            {
                actual->obtener_padre()->eliminar_hijo(actual);
            }
            else
            {
                raiz = nullptr;
            }

            delete actual;
        }
        else if (actual->obtener_hijo_izquierdo() && !actual->obtener_hijo_derecho())
        {
            if (actual != raiz)
            {
                actual->obtener_hijo_izquierdo()->asignar_padre(actual->obtener_padre());
                actual->obtener_padre()->reasignar_hijo(actual, actual->obtener_hijo_izquierdo());
            }
            else
            {
                raiz = actual->obtener_hijo_izquierdo();
                raiz->asignar_padre(nullptr);
            }

            actual->asignar_hijo_izquierdo(nullptr);
            delete actual;
        }
        else if (!actual->obtener_hijo_izquierdo() && actual->obtener_hijo_derecho())
        {
            if (actual != raiz)
            {
                actual->obtener_hijo_derecho()->asignar_padre(actual->obtener_padre());
                actual->obtener_padre()->reasignar_hijo(actual, actual->obtener_hijo_derecho());
            }
            else
            {
                raiz = actual->obtener_hijo_derecho();
                raiz->asignar_padre(nullptr);
            }

            actual->asignar_hijo_derecho(nullptr);
            delete actual;
        }
        else
        {
            NodoABB<Clave, Dato> *sucesor = encontrar_sucesor(actual->obtener_hijo_derecho());
            Clave clave_sucesor = sucesor->obtener_clave();
            Dato dato_sucesor = sucesor->obtener_dato();
            _eliminar(clave_sucesor, sucesor);
            actual->asignar_dato_clave(dato_sucesor, clave_sucesor);
        }
    }
    else if (clave_actual < clave)
    {
        if (actual->obtener_hijo_derecho())
        {
            _eliminar(clave, actual->obtener_hijo_derecho());
        }
    }
    else
    {
        if (actual->obtener_hijo_izquierdo())
        {
            _eliminar(clave, actual->obtener_hijo_izquierdo());
        }
    }
}

template <typename Clave, typename Dato>
Dato *ArbolABB<Clave, Dato>::_consultar(Clave clave, NodoABB<Clave, Dato> *actual, Dato *retorno)
{

    Clave clave_actual = actual->obtener_clave();

    clave_actual = pasar_palabra_a_minusculas(clave_actual);
    clave = pasar_palabra_a_minusculas(clave);

    if (clave_actual == clave)
    {
        *retorno = actual->obtener_dato();
        return retorno;
    }
    if (clave_actual < clave)
    {
        if (!actual->obtener_hijo_derecho())
        {
            delete retorno;
            retorno = nullptr;
            return retorno;
        }
        return _consultar(clave, actual->obtener_hijo_derecho(), retorno);
    }

    if (!actual->obtener_hijo_izquierdo())
    {
        delete retorno;
        retorno = nullptr;
        return retorno;
    }
    return _consultar(clave, actual->obtener_hijo_izquierdo(), retorno);
}

template <typename Clave, typename Dato>
void ArbolABB<Clave, Dato>::insertar(Clave clave, Dato dato)
{
    if (!raiz)
    {
        raiz = new NodoABB<Clave, Dato>(dato, clave);
        tamanio++;
    }
    else if (!consultar(clave))
    {
        _insertar(clave, dato, raiz);
        tamanio++;
    }
}

template <typename Clave, typename Dato>
void ArbolABB<Clave, Dato>::eliminar(Clave clave)
{
    if (raiz)
    {
        _eliminar(clave, raiz);
    }
}

template <typename Clave, typename Dato>
void ArbolABB<Clave, Dato>::actualizar(Clave clave, Dato dato_nuevo)
{
    Dato *dato_actual = consultar(clave);
    if (!dato_actual)
    {
        std::cout << "La clave ingresada no existe" << std::endl;
    }
    else
    {
        dato_actual = dato_nuevo;
        std::cout << "Se ha modificado exitosamente" << std::endl;
    }
}

template <typename Clave, typename Dato>
Dato *ArbolABB<Clave, Dato>::consultar(Clave clave)
{
    if (!raiz)
    {
        return nullptr;
    }
    Dato *retorno = new Dato;
    return _consultar(clave, raiz, retorno);
}

template <typename Clave, typename Dato>
void ArbolABB<Clave, Dato>::inorder()
{
    if (!raiz)
    {
        std::cout << "El árbol se encuentra vacio" << std::endl;
    }
    else
    {
        raiz->mostrar_inorder();
        std::cout << std::endl;
    }
}

template <typename Clave, typename Dato>
void ArbolABB<Clave, Dato>::preorder()
{
    if (!raiz)
    {
        std::cout << "El árbol se encuentra vacio" << std::endl;
    }
    else
    {
        raiz->mostrar_preorder();
        std::cout << std::endl;
    }
}

template <typename Clave, typename Dato>
void ArbolABB<Clave, Dato>::postorder()
{
    if (!raiz)
    {
        std::cout << "El árbol se encuentra vacio" << std::endl;
    }
    else
    {
        raiz->mostrar_postorder();
        std::cout << std::endl;
    }
}

template <typename Clave, typename Dato>
void ArbolABB<Clave, Dato>::datos_ancho(std::vector<Dato> &datos)
{
    std::queue<NodoABB<Clave, Dato> *> cola;
    cola.push(raiz);

    while (!cola.empty())
    {
        datos.push_back(cola.front()->obtener_dato());
        if (cola.front()->obtener_hijo_izquierdo())
        {
            cola.push(cola.front()->obtener_hijo_izquierdo());
        }
        if (cola.front()->obtener_hijo_derecho())
        {
            cola.push(cola.front()->obtener_hijo_derecho());
        }
        cola.pop();
    }
}

template <typename Clave, typename Dato>
int ArbolABB<Clave, Dato>::obtener_tamanio()
{
    return tamanio;
}

template <typename Clave, typename Dato>
ArbolABB<Clave, Dato>::~ArbolABB()
{
    if (raiz)
    {
        delete raiz;
    }
}

#endif //  _TP3_ALGO2_INFORMASTICOS_ARBOLABB_H_
