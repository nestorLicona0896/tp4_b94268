#ifndef FORMPRODUCTO_H
#define FORMPRODUCTO_H

#include <QDialog>

using namespace std;

namespace Ui {
class formProducto;
}

class formProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formProducto(QWidget *parent = nullptr);
    ~formProducto();

    void on_editIdProducto_editingFinished();

    void on_editNombreProducto_editingFinished();

    void on_editExistenciasProducto_editingFinished();

    void CargarInformacion(int id, string nombre, int existencias);

    int ObtenerID();

    std::string ObtenerNombre();

    int ObtenerExistencias();

    Ui::formProducto *ui;

private:

    bool idProductoEsCorrecto;
    bool nombreProductoEsCorrecto;
    bool existenciasProductoEsCorrecto;
};

#endif // FORMPRODUCTO_H
