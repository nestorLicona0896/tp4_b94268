/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionType_Here;
    QWidget *centralwidget;
    QPushButton *btnEscribirArchivo;
    QPushButton *btnLeerArchivo;
    QListWidget *listWidget;
    QPushButton *btnEditarProducto;
    QPushButton *btnAgregarProducto;
    QPushButton *btnEliminarProdcuto;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *editNombreTienda;
    QLineEdit *editWebTienda;
    QLineEdit *editDireccionTienda;
    QLineEdit *editTelefonoTienda;
    QLabel *labelErrorNombreTienda;
    QLabel *labelErrorWebTienda;
    QLabel *labelErrorDireccionTienda;
    QLabel *labelErrorTelefonoTienda;
    QLabel *label_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 390);
        actionType_Here = new QAction(MainWindow);
        actionType_Here->setObjectName(QString::fromUtf8("actionType_Here"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnEscribirArchivo = new QPushButton(centralwidget);
        btnEscribirArchivo->setObjectName(QString::fromUtf8("btnEscribirArchivo"));
        btnEscribirArchivo->setGeometry(QRect(80, 250, 121, 31));
        btnLeerArchivo = new QPushButton(centralwidget);
        btnLeerArchivo->setObjectName(QString::fromUtf8("btnLeerArchivo"));
        btnLeerArchivo->setGeometry(QRect(80, 310, 121, 31));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(300, 31, 321, 271));
        btnEditarProducto = new QPushButton(centralwidget);
        btnEditarProducto->setObjectName(QString::fromUtf8("btnEditarProducto"));
        btnEditarProducto->setGeometry(QRect(420, 330, 89, 31));
        btnAgregarProducto = new QPushButton(centralwidget);
        btnAgregarProducto->setObjectName(QString::fromUtf8("btnAgregarProducto"));
        btnAgregarProducto->setGeometry(QRect(300, 330, 89, 31));
        btnEliminarProdcuto = new QPushButton(centralwidget);
        btnEliminarProdcuto->setObjectName(QString::fromUtf8("btnEliminarProdcuto"));
        btnEliminarProdcuto->setGeometry(QRect(530, 330, 89, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 26, 71, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 76, 71, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 126, 71, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 176, 71, 31));
        editNombreTienda = new QLineEdit(centralwidget);
        editNombreTienda->setObjectName(QString::fromUtf8("editNombreTienda"));
        editNombreTienda->setGeometry(QRect(100, 30, 171, 25));
        editNombreTienda->setMaxLength(15);
        editWebTienda = new QLineEdit(centralwidget);
        editWebTienda->setObjectName(QString::fromUtf8("editWebTienda"));
        editWebTienda->setGeometry(QRect(100, 80, 171, 25));
        editWebTienda->setMaxLength(24);
        editDireccionTienda = new QLineEdit(centralwidget);
        editDireccionTienda->setObjectName(QString::fromUtf8("editDireccionTienda"));
        editDireccionTienda->setGeometry(QRect(100, 130, 171, 25));
        editDireccionTienda->setMaxLength(24);
        editTelefonoTienda = new QLineEdit(centralwidget);
        editTelefonoTienda->setObjectName(QString::fromUtf8("editTelefonoTienda"));
        editTelefonoTienda->setGeometry(QRect(100, 180, 171, 25));
        editTelefonoTienda->setMaxLength(8);
        labelErrorNombreTienda = new QLabel(centralwidget);
        labelErrorNombreTienda->setObjectName(QString::fromUtf8("labelErrorNombreTienda"));
        labelErrorNombreTienda->setGeometry(QRect(100, 60, 171, 17));
        labelErrorWebTienda = new QLabel(centralwidget);
        labelErrorWebTienda->setObjectName(QString::fromUtf8("labelErrorWebTienda"));
        labelErrorWebTienda->setGeometry(QRect(100, 110, 171, 17));
        labelErrorDireccionTienda = new QLabel(centralwidget);
        labelErrorDireccionTienda->setObjectName(QString::fromUtf8("labelErrorDireccionTienda"));
        labelErrorDireccionTienda->setGeometry(QRect(100, 160, 171, 17));
        labelErrorTelefonoTienda = new QLabel(centralwidget);
        labelErrorTelefonoTienda->setObjectName(QString::fromUtf8("labelErrorTelefonoTienda"));
        labelErrorTelefonoTienda->setGeometry(QRect(100, 210, 171, 17));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 10, 261, 17));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionType_Here->setText(QCoreApplication::translate("MainWindow", "Type Here", nullptr));
        btnEscribirArchivo->setText(QCoreApplication::translate("MainWindow", "escribir archivo", nullptr));
        btnLeerArchivo->setText(QCoreApplication::translate("MainWindow", "leer archivo", nullptr));
        btnEditarProducto->setText(QCoreApplication::translate("MainWindow", "editar", nullptr));
        btnAgregarProducto->setText(QCoreApplication::translate("MainWindow", "agregar", nullptr));
        btnEliminarProdcuto->setText(QCoreApplication::translate("MainWindow", "eliminar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Web", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Direccion", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Telefono", nullptr));
        labelErrorNombreTienda->setText(QString());
        labelErrorWebTienda->setText(QString());
        labelErrorDireccionTienda->setText(QString());
        labelErrorTelefonoTienda->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "ID - Nombre del producto, existencias", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
