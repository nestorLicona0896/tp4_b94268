#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <fstream>

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
            cerr << "No se pudo guardar archivo para escribir los datos";
        }

        trastienda->GuardarEnStreamBinario(&archivoSalida);
        archivoSalida.close();
    }
}

void MainWindow::on_btnLeerArchivo_clicked()
{
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
            cerr << "No se pudo abrir archivo trastienda.dat para leer los datos";
        }
        this->trastienda = new Trastienda();

        trastienda->CargarDesdeStreamBinario(&archivoEntrada);

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

    bool ok = false;
    if (stringNombreTienda.isEmpty())
    {
        ok = true;
    }


    if (!ok)
    {
        this->ui->labelErrorNombreTienda->setText("");
        this->nombreTiendaEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorNombreTienda->setText("nombre invalido");
        this->nombreTiendaEsCorrecto = false;
    }

}

void MainWindow::on_editWebTienda_editingFinished()
{
    QString stringDireccionWeb = this->ui->editWebTienda->text();

    bool ok = false;

    if (stringDireccionWeb.isEmpty())
    {
        ok = true;
    }


    if (!ok)
    {
        this->ui->labelErrorWebTienda->setText("");
        this->webTiendaEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorWebTienda->setText("direccioin web invalida");
        this->webTiendaEsCorrecto = false;
    }
}

void MainWindow::on_editDireccionTienda_editingFinished()
{
    QString stringDireccionTienda = this->ui->editDireccionTienda->text();

    bool ok = false;

    if (stringDireccionTienda.isEmpty())
    {
        ok = true;
    }

    if (!ok)
    {
        this->ui->labelErrorDireccionTienda->setText("");
        this->direccionTiendaEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorDireccionTienda->setText("direccion invalido");
        this->direccionTiendaEsCorrecto = false;
    }
}

void MainWindow::on_editTelefonoTienda_editingFinished()
{
    QString stringTelefono = this->ui->editTelefonoTienda->text();

    bool ok = false;

    if (stringTelefono.isEmpty())
    {
        ok = true;
    }else {
        stringTelefono.toInt(&ok);
    }


    if (ok)
    {
        this->ui->labelErrorTelefonoTienda->setText("");
        this->telefonoTiendaEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorTelefonoTienda->setText("telefono invalido");
        this->telefonoTiendaEsCorrecto = false;
    }
}

void MainWindow::on_btnAgregarProducto_clicked()
{
    formProducto formProducto {this};
    int result = formProducto.exec();
    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Título del diálogo");

    if (result == QDialog::Accepted) {
        Producto *producto;
        int id = formProducto.ObtenerID();
        string stringNombre = formProducto.ObtenerNombre();
        int existencias = formProducto.ObtenerExistencias();

        if(!(this->trastienda->ObtenerInventario().empty())) {
            if(!(this->trastienda->BuscarProducto(id))){
                producto = new Producto(id, stringNombre, existencias);
                trastienda->AgregarProducto(producto);
                msgbox->setText(QString::fromStdString(stringNombre));
                msgbox->open();
                this->LlenarList();
            } else {
                msgbox->setText(QString::fromStdString("El producto ya existe"));
                msgbox->open();
            }
        } else {
            producto = new Producto(id, stringNombre, existencias);
            trastienda->AgregarProducto(producto);
            msgbox->setText(QString::fromStdString(stringNombre));
            msgbox->open();
            this->LlenarList();
        }
    }
}

void MainWindow::on_btnEditarProducto_clicked()
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
        Producto *aux = this->trastienda->ObtenerProducto(idProducto);
        formProducto formProducto {this};
        formProducto.CargarInformacion(aux->ObtenerId(), aux->ObtenerNombre(), aux->ObtenerExistencias());
        int result = formProducto.exec();

        if(result == QDialog::Accepted){

            this->trastienda->EditarProducto(idProducto, idProducto, formProducto.ObtenerNombre(), formProducto.ObtenerExistencias());
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
            this->trastienda->EliminarProducto(idProducto);
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Título del diálogo");
            msgbox->setText("ID producto eliminado: " + QString::number(idProducto));
            msgbox->open();
            this->LlenarList();
        }
    }
}

void MainWindow::LlenarList() {
    this->ui->listWidget->clear();
    for(Producto *p : this->trastienda->ObtenerInventario()){
        QString opcion = QString::fromStdString(p->Mostrar());
        QListWidgetItem *itemNuevo = new QListWidgetItem(opcion);
        itemNuevo->setData(1, p->ObtenerId());
        this->ui->listWidget->addItem(itemNuevo);
    }
    this->ui->listWidget->sortItems(Qt::AscendingOrder);
}

string MainWindow::ObtenerTelefonoTienda()
{
    QString stringTelefono = this->ui->editTelefonoTienda->text();
    string telefono = stringTelefono.toStdString();
    return telefono;
}

string MainWindow::ObtenerNombreTienda()
{
    QString stringNombre = this->ui->editNombreTienda->text();
    string nombre = stringNombre.toStdString();
    return nombre;
}

string MainWindow::ObtenerDireccionTienda()
{
    QString stringDireccion = this->ui->editDireccionTienda->text();
    string direccion = stringDireccion.toStdString();
    return direccion;
}

string MainWindow::ObtenerWebTienda()
{
    QString stringWeb = this->ui->editWebTienda->text();
    string web = stringWeb.toStdString();
    return web;
}



