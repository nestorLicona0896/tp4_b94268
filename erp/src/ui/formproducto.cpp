#include "formproducto.h"
#include "ui_formproducto.h"
#include <string.h>

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

    bool ok = false;

    if (stringId.isEmpty())
    {
        ok = true;
    }else {
        stringId.toInt(&ok);
    }


    if (ok)
    {
        this->ui->labelErrorIdProdcuto->setText("");
        this->idProductoEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorIdProdcuto->setText("id producto invalido");
        this->idProductoEsCorrecto = false;
    }
}


void formProducto::on_editNombreProducto_editingFinished()
{
    QString stringNombreProducto = this->ui->editNombreProducto->text();

    bool ok = false;
    if (stringNombreProducto.isEmpty())
    {
        ok = true;
    }


    if (!ok)
    {
        this->ui->labelErrorNombreProducto->setText("");
        this->nombreProductoEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorNombreProducto->setText("nombre producto invalido");
        this->nombreProductoEsCorrecto = false;
    }
}


void formProducto::on_editExistenciasProducto_editingFinished()
{
    QString stringExistencias = this->ui->editExistenciasProducto->text();

    bool ok = false;

    if (stringExistencias.isEmpty())
    {
        ok = true;
    }else {
        stringExistencias.toInt(&ok);
    }


    if (ok)
    {
        this->ui->labelErrorExistenciasProducto->setText("");
        this->existenciasProductoEsCorrecto = true;
    }
    else
    {
        this->ui->labelErrorExistenciasProducto->setText("numero existencias invalido");
        this->existenciasProductoEsCorrecto = false;
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
    QString stringID = this->ui->editIdProducto->text();
    int id = stringID.toInt();
    return id;
}

string formProducto::ObtenerNombre()
{
    QString stringNombre = this->ui->editNombreProducto->text();
    string nombre = stringNombre.toStdString();
    return nombre;
}

int formProducto::ObtenerExistencias()
{
    QString stringExistencias = this->ui->editExistenciasProducto->text();
    int existencias = stringExistencias.toInt();
    return existencias;
}

