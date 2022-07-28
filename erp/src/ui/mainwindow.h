#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./../../lib/include/trastienda.h"
#include "./../../lib/include/producto.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include "formproducto.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnEscribirArchivo_clicked();

    void on_btnLeerArchivo_clicked();

    void on_editNombreTienda_editingFinished();

    void on_editWebTienda_editingFinished();

    void on_editDireccionTienda_editingFinished();

    void on_editTelefonoTienda_editingFinished();

    void on_btnAgregarProducto_clicked();

    void on_btnEditarProducto_clicked();

    void on_btnEliminarProdcuto_clicked();

    string ObtenerNombreTienda();
    string ObtenerWebTienda();
    string ObtenerDireccionTienda();
    string ObtenerTelefonoTienda();
    void LlenarList();

private:
    Ui::MainWindow *ui;

    tp3::Trastienda *trastienda;
    bool nombreTiendaEsCorrecto;
    bool webTiendaEsCorrecto;
    bool direccionTiendaEsCorrecto;
    bool telefonoTiendaEsCorrecto;

};
#endif // MAINWINDOW_H
