#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

using namespace std;

namespace tp3
{

 class Producto {

    int id; // ID del producto
    char nombre[20]; // 20 caracteres
    int existencias; // cantidad en tienda 

    public:

        Producto();
        Producto(int nuevoId, string nombre, int cantidad);
        ~Producto();

        void EditarId(int nuevoId);
        void EditarNombre(string nuevoNombre);
        void EditarExistencias(int nuevaCantidad);
        int ObtenerId();
        string ObtenerNombre();
        int ObtenerExistencias();

        string Mostrar();

        //friend ostream& operator << (ostream o, Producto *producto);     

 };

}

#endif