/********************************************************************************
** Form generated from reading UI file 'formproducto.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPRODUCTO_H
#define UI_FORMPRODUCTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_formProducto
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *editIdProducto;
    QLabel *label_2;
    QLineEdit *editExistenciasProducto;
    QLabel *label_3;
    QLineEdit *editNombreProducto;
    QLabel *label;
    QLabel *labelErrorIdProdcuto;
    QLabel *labelErrorNombreProducto;
    QLabel *labelErrorExistenciasProducto;

    void setupUi(QDialog *formProducto)
    {
        if (formProducto->objectName().isEmpty())
            formProducto->setObjectName(QString::fromUtf8("formProducto"));
        formProducto->resize(307, 237);
        buttonBox = new QDialogButtonBox(formProducto);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(70, 180, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        editIdProducto = new QLineEdit(formProducto);
        editIdProducto->setObjectName(QString::fromUtf8("editIdProducto"));
        editIdProducto->setGeometry(QRect(120, 30, 161, 25));
        label_2 = new QLabel(formProducto);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 80, 61, 21));
        editExistenciasProducto = new QLineEdit(formProducto);
        editExistenciasProducto->setObjectName(QString::fromUtf8("editExistenciasProducto"));
        editExistenciasProducto->setGeometry(QRect(120, 130, 161, 25));
        label_3 = new QLabel(formProducto);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 136, 81, 21));
        editNombreProducto = new QLineEdit(formProducto);
        editNombreProducto->setObjectName(QString::fromUtf8("editNombreProducto"));
        editNombreProducto->setGeometry(QRect(120, 80, 161, 25));
        editNombreProducto->setMaxLength(20);
        label = new QLabel(formProducto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 30, 21, 21));
        labelErrorIdProdcuto = new QLabel(formProducto);
        labelErrorIdProdcuto->setObjectName(QString::fromUtf8("labelErrorIdProdcuto"));
        labelErrorIdProdcuto->setGeometry(QRect(120, 60, 161, 17));
        labelErrorNombreProducto = new QLabel(formProducto);
        labelErrorNombreProducto->setObjectName(QString::fromUtf8("labelErrorNombreProducto"));
        labelErrorNombreProducto->setGeometry(QRect(120, 110, 161, 17));
        labelErrorExistenciasProducto = new QLabel(formProducto);
        labelErrorExistenciasProducto->setObjectName(QString::fromUtf8("labelErrorExistenciasProducto"));
        labelErrorExistenciasProducto->setGeometry(QRect(120, 160, 161, 17));

        retranslateUi(formProducto);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, formProducto, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, formProducto, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(formProducto);
    } // setupUi

    void retranslateUi(QDialog *formProducto)
    {
        formProducto->setWindowTitle(QCoreApplication::translate("formProducto", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("formProducto", "nombre", nullptr));
        label_3->setText(QCoreApplication::translate("formProducto", "existencias", nullptr));
        label->setText(QCoreApplication::translate("formProducto", "id", nullptr));
        labelErrorIdProdcuto->setText(QString());
        labelErrorNombreProducto->setText(QString());
        labelErrorExistenciasProducto->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class formProducto: public Ui_formProducto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPRODUCTO_H
