#include "formproducto.h"
#include "ui_formproducto.h"
#include "excepcionNumeroNegativo.h"
#include <string.h>
#include <QMessageBox>

using namespace std;

formProducto::formProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formProducto)
{
    ui->setupUi(this);

    this->idProductoEsCorrecto = false;
    this->nombreProductoEsCorrecto = false;
    this->existenciasProductoEsCorrecto = false;
}

formProducto::~formProducto()
{
    delete ui;
}

void formProducto::on_editIdProducto_editingFinished()
{
    QString stringId = this->ui->editIdProducto->text();
    bool vacio = false;

    if (stringId.isEmpty())
    {
        vacio = true;
        this->ui->labelErrorIdProdcuto->setText("id producto invalido");
    } else {
        try {
            stringId.toInt(&vacio);
        } catch (ExcepcionNumeroNegativo& e){
            vacio = true;
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error de formato en el numero de id");
            msgbox->setText( e.what());
            msgbox->open();

        } catch(const exception &e){
            vacio = true;
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error de formato en el numero de id");
            msgbox->setText( e.what());
            msgbox->open();
        }
    }
    if (!vacio)
    {
        this->ui->labelErrorIdProdcuto->setText("");
        this->idProductoEsCorrecto = true;
    }  else  {
        this->ui->labelErrorIdProdcuto->setText("id producto invalido");
    }
}


void formProducto::on_editNombreProducto_editingFinished()
{
    QString stringNombreProducto = this->ui->editNombreProducto->text();
    bool vacio = false;
    if (stringNombreProducto.isEmpty())
    {
        vacio = true;
        this->ui->labelErrorNombreProducto->setText("nombre producto invalido");
    }
    if (!vacio)
    {
        this->ui->labelErrorNombreProducto->setText("");
        this->nombreProductoEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorNombreProducto->setText("nombre producto invalido");
    }
}


void formProducto::on_editExistenciasProducto_editingFinished()
{
    QString stringExistencias = this->ui->editExistenciasProducto->text();
    bool vacio = false;

    if (stringExistencias.isEmpty())
    {
        vacio = true;
        this->ui->labelErrorExistenciasProducto->setText("numero existencias invalido");
    } else {
        try{
            stringExistencias.toInt(&vacio);
        } catch (ExcepcionNumeroNegativo& e){
            vacio = true;
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error de formato en el numero de existencias");
            msgbox->setText( e.what());
            msgbox->open();
        } catch (const exception &e){
            vacio = true;
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error de formato en el numero de existencias");
            msgbox->setText( e.what());
            msgbox->open();
        }
    }
    if (!vacio)
    {
        this->ui->labelErrorExistenciasProducto->setText("");
        this->existenciasProductoEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorExistenciasProducto->setText("numero existencias invalido");
    }
}

void formProducto::CargarInformacion(int id, string nombre, int existencias)
{
    QString stringID = QString::number(id);
    this->ui->editIdProducto->setText(stringID);
    this->ui->editIdProducto->setReadOnly(true);

    QString stringNombre = QString::fromStdString(nombre);
    this->ui->editNombreProducto->setText(stringNombre);

    QString stringExistencias = QString::number(existencias);
    this->ui->editExistenciasProducto->setText(stringExistencias);
}

int formProducto::ObtenerID()
{    
    try {
        if(this->idProductoEsCorrecto){
            QString stringID = this->ui->editIdProducto->text();
            int id = stringID.toInt();
            return id;
        } else {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("ID no es correcto");
            msgbox->open();
        }
    }
    catch(const exception& e)
    {   // Catch all
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Error al leer id producto");
        msgbox->setText( e.what());
        msgbox->open();
    }
}

string formProducto::ObtenerNombre()
{    
    try {
        if (this->nombreProductoEsCorrecto) {
            QString stringNombre = this->ui->editNombreProducto->text();
            string nombre = stringNombre.toStdString();
            return nombre;
        } else{
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("Nombre producto no es correcto");
            msgbox->open();
        }
    } catch (const exception &e){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Error al leer nombre del producto");
        msgbox->setText( e.what());
        msgbox->open();
    }
}

int formProducto::ObtenerExistencias()
{
    try {
        if (this->existenciasProductoEsCorrecto){
            QString stringExistencias = this->ui->editExistenciasProducto->text();
            int existencias = stringExistencias.toInt();
            return existencias;
        } else {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error");
            msgbox->setText("Existencias no son correctas");
            msgbox->open();
        }
    } catch (const exception &e){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Error al leer existencias");
        msgbox->setText( e.what());
        msgbox->open();
    }

}

