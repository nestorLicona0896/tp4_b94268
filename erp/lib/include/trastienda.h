#ifndef TRASTIENDA_H
#define TRASTIENDA_H

#include <vector>
#include "producto.h"
#include <string>

using namespace std;

namespace tp3
{

    class Trastienda { 

        vector<Producto*> inventario; 
       
        char nombre[15]; // 15 caracteres
        char sitioWeb[24]; // 24 caracteres
        char direccion[24] ; // 24 caracteres
        char telefono[8]; // 8 caracteres   

       

        public:

            Trastienda();
            Trastienda(string nombre, string sitio, string direccion, string telefono);
            ~Trastienda();

            void EditarNombre(string nuevoNombre);
            void EditarSitioWeb(string nuevoSitio);
            void EditarDireccion(string nuevaDireccion);
            void EditarTelefono(string nuevoTelefono);
            string ObtenerNombre();
            string ObtenerSitioWeb();
            string ObtenerDireccion();
            string ObtenerTelefono();

            void AgregarProducto(Producto *unProducto);
            void EditarProducto(int idActual, int nuevoId, string nuevoNombre, int lasExistencias);
            void EliminarProducto(int id);
            string MostrarProductos();
            Producto* ObtenerProducto(int id);
            vector<Producto*> ObtenerInventario();
            bool BuscarProducto(int id);

            void GuardarEnStreamBinario(ostream *streamSalida);
            void CargarDesdeStreamBinario(istream *streamEntrada);
            

            //friend ostream& operator << (ostream o, Trastienda *tienda);

    };
}

#endif