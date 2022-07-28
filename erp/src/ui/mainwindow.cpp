#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <fstream>
#include "excepcionNumeroNegativo.h"

using namespace std;

using namespace tp3;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->trastienda = new Trastienda();

    this->nombreTiendaEsCorrecto= false;
    this->webTiendaEsCorrecto = false;
    this->direccionTiendaEsCorrecto = false;
    this->telefonoTiendaEsCorrecto = false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete trastienda;
}

void MainWindow::on_btnEscribirArchivo_clicked()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar archivo de datos", "",
                                                         tr("Archivo de datos (*.dat);;All Files (*)"));
    if(nombreArchivo != " "){
        string stringNombre = this->ObtenerNombreTienda();
        string stringWeb = this->ObtenerWebTienda();
        string stringDireccion = this->ObtenerDireccionTienda();
        string stringTelefono = this->ObtenerTelefonoTienda();

        this->trastienda->EditarNombre(stringNombre);
        this->trastienda->EditarSitioWeb(stringWeb);
        this->trastienda->EditarDireccion(stringDireccion);
        this->trastienda->EditarTelefono(stringTelefono);

        ofstream archivoSalida;
        archivoSalida.open(nombreArchivo.toStdString() + ".dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {            
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error al escribir archivo");
            msgbox->setText("No se ha podido crear el archivo");
            msgbox->open();
        }
        try {
            trastienda->GuardarEnStreamBinario(&archivoSalida);
        } catch(const exception &e) {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error al escribir archivo binario");
            msgbox->setText( e.what());
            msgbox->open();
        }
        archivoSalida.close();
    }
}

void MainWindow::on_btnLeerArchivo_clicked()
{
    this->ui->labelErrorNombreTienda->setText("");
    this->ui->labelErrorDireccionTienda->setText("");
    this->ui->labelErrorTelefonoTienda->setText("");
    this->ui->labelErrorWebTienda->setText("");
    string name;
    QString fileName = QFileDialog::getOpenFileName(this,
                "Abrir archivo de datos", "",
                tr("Archivo de datos (*.dat);;All Files (*)"));
    if (fileName != "")
    {
        name = fileName.toStdString();
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Título del diálogo");
        msgbox->setText(fileName);
        msgbox->open();
        ifstream archivoEntrada;
        archivoEntrada.open(name, ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error al leer archivo");
            msgbox->setText("No se ha podido abrir el archivo");
            msgbox->open();
        }
        this->trastienda = new Trastienda();        
        try {
            trastienda->CargarDesdeStreamBinario(&archivoEntrada);
        } catch (const exception &e){
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error al leer archivo binario");
            msgbox->setText( e.what());
            msgbox->open();
        }
        this->ui->editNombreTienda->setText(QString::fromStdString(trastienda->ObtenerNombre()));
        this->ui->editWebTienda->setText(QString::fromStdString(trastienda->ObtenerSitioWeb()));
        this->ui->editDireccionTienda->setText(QString::fromStdString(trastienda->ObtenerDireccion()));
        this->ui->editTelefonoTienda->setText(QString::fromStdString(trastienda->ObtenerTelefono()));
        this->LlenarList();
        archivoEntrada.close();
    }
}

void MainWindow::on_editNombreTienda_editingFinished()
{
    QString stringNombreTienda = this->ui->editNombreTienda->text();

    bool vacio = false;
    if (stringNombreTienda.isEmpty())
    {
        vacio = true;
        this->ui->labelErrorNombreTienda->setText("nombre invalido");
    }
    if (!vacio)
    {
        this->ui->labelErrorNombreTienda->setText("");
        this->nombreTiendaEsCorrecto = true;
    } else {
        this->ui->labelErrorNombreTienda->setText("nombre invalido");
    }
}

void MainWindow::on_editWebTienda_editingFinished()
{
    QString stringDireccionWeb = this->ui->editWebTienda->text();
    bool vacio = false;

    if (stringDireccionWeb.isEmpty())
    {
        vacio = true;
        this->ui->labelErrorWebTienda->setText("direccioin web invalida");
    }
    if (!vacio)
    {
        this->ui->labelErrorWebTienda->setText("");
        this->webTiendaEsCorrecto = true;
    } else {
        this->ui->labelErrorWebTienda->setText("direccioin web invalida");   
    }
}

void MainWindow::on_editDireccionTienda_editingFinished()
{
    QString stringDireccionTienda = this->ui->editDireccionTienda->text();
    bool vacio = false;

    if (stringDireccionTienda.isEmpty())
    {
        vacio = true;
        this->ui->labelErrorDireccionTienda->setText("direccion invalida");
    }
    if (!vacio)
    {
        this->ui->labelErrorDireccionTienda->setText("");
        this->direccionTiendaEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorDireccionTienda->setText("direccion invalida");
    }
}

void MainWindow::on_editTelefonoTienda_editingFinished()
{
    QString stringTelefono = this->ui->editTelefonoTienda->text();
    bool vacio = false;

    if (stringTelefono.isEmpty())
    {
        vacio = true;
        this->ui->labelErrorTelefonoTienda->setText("telefono invalido");
    } else {
        try {
           stringTelefono.toInt(&vacio);
        } catch (ExcepcionNumeroNegativo& e){
            vacio = true;
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error de formato en el numero de telefono");
            msgbox->setText( e.what());
            msgbox->open();
        }
        catch (const exception &e){
            vacio = true;
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error de formato");
            msgbox->setText( e.what());
            msgbox->open();
        }
    }
    if (!vacio)
    {
        this->ui->labelErrorTelefonoTienda->setText("");
        this->telefonoTiendaEsCorrecto = true;
    } else  {
        this->ui->labelErrorTelefonoTienda->setText("telefono invalido");  
    }
}

void MainWindow::on_btnAgregarProducto_clicked()
{
    formProducto formProducto {this};
    formProducto.setWindowTitle("Agregar Producto");
    int result = formProducto.exec();
    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Agregar Producto");

    if (result == QDialog::Accepted) {
        Producto *producto;
        int id = formProducto.ObtenerID();
        string stringNombre = formProducto.ObtenerNombre();
        int existencias = formProducto.ObtenerExistencias();

        if(!(this->trastienda->ObtenerInventario().empty())) {
            if(!(this->trastienda->BuscarProducto(id))){
                producto = new Producto(id, stringNombre, existencias);
                try {
                    trastienda->AgregarProducto(producto);
                } catch (const exception &e){
                    QMessageBox *msgbox = new QMessageBox(this);
                    msgbox->setWindowTitle("Error al agregar");
                    msgbox->setText( e.what());
                    msgbox->open();
                }
                msgbox->setText(QString::fromStdString(stringNombre));
                msgbox->open();
                this->LlenarList();
            } else {
                msgbox->setText(QString::fromStdString("El producto ya existe"));
                msgbox->open();
            }
        } else {
            producto = new Producto(id, stringNombre, existencias);
            try {
                trastienda->AgregarProducto(producto);
            } catch(const exception &e){
                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Error al agregar");
                msgbox->setText( e.what());
                msgbox->open();
            }
            msgbox->setText(QString::fromStdString(stringNombre));
            msgbox->open();
            this->LlenarList();
        }
    }
}

void MainWindow::on_btnEditarProducto_clicked()
{
    QListWidgetItem *itemSeleccionado = this->ui->listWidget->currentItem();
    int result = 0;
    formProducto formProducto {this};
    formProducto.setWindowTitle("Editar Producto");
    if (itemSeleccionado == nullptr)
    {
        // no hay ítem seleccionado
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Editar Producto");
        msgbox->setText("No hay ítem seleccionado");
        msgbox->open();
    }
    else
    {
        QString stringID = itemSeleccionado->data(1).toString();
        int idProducto = stringID.toInt();
        try {
            Producto *aux = this->trastienda->ObtenerProducto(idProducto);
            formProducto.CargarInformacion(aux->ObtenerId(), aux->ObtenerNombre(), aux->ObtenerExistencias());
            result = formProducto.exec();
        } catch (const exception &e){
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error al cargar datos para editar");
            msgbox->setText( e.what());
            msgbox->open();
        }

        if(result == QDialog::Accepted){
            try {
                this->trastienda->EditarProducto(idProducto, idProducto, formProducto.ObtenerNombre(), formProducto.ObtenerExistencias());
            } catch (const exception &e){
                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Error al editar");
                msgbox->setText( e.what());
                msgbox->open();
            }
            this->LlenarList();
        }
    }
}

void MainWindow::on_btnEliminarProdcuto_clicked()
{
    QListWidgetItem *itemSeleccionado = this->ui->listWidget->currentItem();

    if (itemSeleccionado == nullptr)
    {
        // no hay ítem seleccionado
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Título del diálogo");
        msgbox->setText("No hay ítem seleccionado");
        msgbox->open();
    }
    else
    {
        QString stringID = itemSeleccionado->data(1).toString();
        int idProducto = stringID.toInt();

        if (this->trastienda->BuscarProducto(idProducto) == true)
        {
            try {
                this->trastienda->EliminarProducto(idProducto);
                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Eliminar Producto");
                msgbox->setText("ID producto eliminado: " + QString::number(idProducto));
                msgbox->open();
            }
            catch(const exception& e)
            {
                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Error al eliminar");
                msgbox->setText( e.what());
                msgbox->open();
            }
            this->LlenarList();
        }
    }
}

void MainWindow::LlenarList() {
    this->ui->listWidget->clear();
    for(Producto *p : this->trastienda->ObtenerInventario()){
        try {
            QString opcion = QString::fromStdString(p->Mostrar());
            QListWidgetItem *itemNuevo = new QListWidgetItem(opcion);
            itemNuevo->setData(1, p->ObtenerId());
            this->ui->listWidget->addItem(itemNuevo);
        }
        catch(const exception& e)
        {   // Catch all
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error al cargar lista");
            msgbox->setText( e.what());
            msgbox->open();
        }
    }
    this->ui->listWidget->sortItems(Qt::AscendingOrder);
}

string MainWindow::ObtenerTelefonoTienda()
{
    try {
        if(this->telefonoTiendaEsCorrecto){
            QString stringTelefono = this->ui->editTelefonoTienda->text();
            string telefono = stringTelefono.toStdString();
            return telefono;
        } else {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("Telefono no es correcto");
            msgbox->open();
        }
    }
    catch(const exception& e)
    {   // Catch all
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Error al leer el telefono");
        msgbox->setText( e.what());
        msgbox->open();
    }
}

string MainWindow::ObtenerNombreTienda()
{
    try {
        if(this->nombreTiendaEsCorrecto){
            QString stringNombre = this->ui->editNombreTienda->text();
            string nombre = stringNombre.toStdString();
            return nombre;
        } else {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("Nombre tienda no es correcto");
            msgbox->open();
        }
    }
    catch(const exception& e)
    {   // Catch all
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Error al leer el nombre de la tienda");
        msgbox->setText( e.what());
        msgbox->open();
    }
}

string MainWindow::ObtenerDireccionTienda()
{
    try {
        if(this->direccionTiendaEsCorrecto){
            QString stringDireccion = this->ui->editDireccionTienda->text();
            string direccion = stringDireccion.toStdString();
            return direccion;
        } else {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("Direccion no es correcta");
            msgbox->open();
        }
    }
    catch(const exception& e)
    {   // Catch all
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Error al leer la direccion");
        msgbox->setText( e.what());
        msgbox->open();
    }
}

string MainWindow::ObtenerWebTienda()
{
    try {
        if(this->webTiendaEsCorrecto){
            QString stringWeb = this->ui->editWebTienda->text();
            string web = stringWeb.toStdString();
            return web;
        } else {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("Direccion web no es correcta");
            msgbox->open();
        }
    }
    catch(const exception& e)
    {   // Catch all
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Error al leer la direccion web");
        msgbox->setText( e.what());
        msgbox->open();
    }
}



