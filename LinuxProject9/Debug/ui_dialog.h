/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *camera;
    QLabel *frameROI;
    QLabel *getframeROI;
    QLabel *frame_counter;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1196, 669);
        camera = new QLabel(Dialog);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(10, 10, 640, 480));
        camera->setAutoFillBackground(true);
        frameROI = new QLabel(Dialog);
        frameROI->setObjectName(QStringLiteral("frameROI"));
        frameROI->setEnabled(true);
        frameROI->setGeometry(QRect(660, 10, 111, 111));
        getframeROI = new QLabel(Dialog);
        getframeROI->setObjectName(QStringLiteral("getframeROI"));
        getframeROI->setGeometry(QRect(960, 130, 121, 121));
        frame_counter = new QLabel(Dialog);
        frame_counter->setObjectName(QStringLiteral("frame_counter"));
        frame_counter->setGeometry(QRect(50, 500, 171, 16));
        horizontalSlider = new QSlider(Dialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 550, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(220, 550, 42, 22));

        retranslateUi(Dialog);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        camera->setText(QString());
        frameROI->setText(QString());
        getframeROI->setText(QString());
        frame_counter->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
