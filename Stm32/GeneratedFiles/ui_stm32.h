/********************************************************************************
** Form generated from reading UI file 'stm32.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STM32_H
#define UI_STM32_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stm32Class
{
public:
    QWidget *centralWidget;
    QLabel *serialPortLabel;
    QComboBox *serialPortComboBox;
    QLabel *waitRequestLabel;
    QSpinBox *waitRequestSpinBox;
    QLabel *responseLabel;
    QLineEdit *responseLineEdit;
    QLabel *trafficLabel;
    QLabel *statusLabel;
    QPushButton *runButton;
    QTextEdit *showDataEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *showDataLabel;
    QLabel *trafficLabel2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Stm32Class)
    {
        if (Stm32Class->objectName().isEmpty())
            Stm32Class->setObjectName(QStringLiteral("Stm32Class"));
        Stm32Class->resize(989, 808);
        centralWidget = new QWidget(Stm32Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        serialPortLabel = new QLabel(centralWidget);
        serialPortLabel->setObjectName(QStringLiteral("serialPortLabel"));
        serialPortLabel->setGeometry(QRect(100, 70, 51, 16));
        serialPortComboBox = new QComboBox(centralWidget);
        serialPortComboBox->setObjectName(QStringLiteral("serialPortComboBox"));
        serialPortComboBox->setGeometry(QRect(160, 70, 69, 22));
        waitRequestLabel = new QLabel(centralWidget);
        waitRequestLabel->setObjectName(QStringLiteral("waitRequestLabel"));
        waitRequestLabel->setGeometry(QRect(100, 140, 81, 21));
        waitRequestSpinBox = new QSpinBox(centralWidget);
        waitRequestSpinBox->setObjectName(QStringLiteral("waitRequestSpinBox"));
        waitRequestSpinBox->setGeometry(QRect(190, 140, 71, 22));
        waitRequestSpinBox->setMaximum(10000);
        waitRequestSpinBox->setValue(1000);
        waitRequestSpinBox->setDisplayIntegerBase(10);
        responseLabel = new QLabel(centralWidget);
        responseLabel->setObjectName(QStringLiteral("responseLabel"));
        responseLabel->setGeometry(QRect(100, 200, 54, 21));
        responseLineEdit = new QLineEdit(centralWidget);
        responseLineEdit->setObjectName(QStringLiteral("responseLineEdit"));
        responseLineEdit->setGeometry(QRect(170, 200, 451, 20));
        trafficLabel = new QLabel(centralWidget);
        trafficLabel->setObjectName(QStringLiteral("trafficLabel"));
        trafficLabel->setGeometry(QRect(100, 350, 521, 51));
        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(100, 410, 451, 31));
        runButton = new QPushButton(centralWidget);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setGeometry(QRect(500, 60, 75, 23));
        showDataEdit = new QTextEdit(centralWidget);
        showDataEdit->setObjectName(QStringLiteral("showDataEdit"));
        showDataEdit->setGeometry(QRect(170, 240, 451, 101));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 260, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(690, 70, 131, 16));
        showDataLabel = new QLabel(centralWidget);
        showDataLabel->setObjectName(QStringLiteral("showDataLabel"));
        showDataLabel->setGeometry(QRect(690, 110, 271, 571));
        trafficLabel2 = new QLabel(centralWidget);
        trafficLabel2->setObjectName(QStringLiteral("trafficLabel2"));
        trafficLabel2->setGeometry(QRect(100, 500, 521, 201));
        Stm32Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Stm32Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 989, 23));
        Stm32Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Stm32Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Stm32Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Stm32Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Stm32Class->setStatusBar(statusBar);

        retranslateUi(Stm32Class);

        QMetaObject::connectSlotsByName(Stm32Class);
    } // setupUi

    void retranslateUi(QMainWindow *Stm32Class)
    {
        Stm32Class->setWindowTitle(QApplication::translate("Stm32Class", "Stm32\346\225\260\346\215\256\346\250\241\346\213\237\345\231\250", Q_NULLPTR));
        serialPortLabel->setText(QApplication::translate("Stm32Class", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        waitRequestLabel->setText(QApplication::translate("Stm32Class", "\347\255\211\345\276\205\350\257\267\346\261\202\346\227\266\351\227\264", Q_NULLPTR));
        responseLabel->setText(QApplication::translate("Stm32Class", "\345\223\215\345\272\224:", Q_NULLPTR));
        trafficLabel->setText(QApplication::translate("Stm32Class", "\351\200\232\344\277\241\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("Stm32Class", "\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        runButton->setText(QApplication::translate("Stm32Class", "\345\274\200\345\247\213", Q_NULLPTR));
        label->setText(QApplication::translate("Stm32Class", "\346\216\245\346\224\266\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Stm32Class", "\346\250\241\346\213\237\347\224\237\344\272\247\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        showDataLabel->setText(QApplication::translate("Stm32Class", "TextLabel", Q_NULLPTR));
        trafficLabel2->setText(QApplication::translate("Stm32Class", "\351\200\232\344\277\241\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Stm32Class: public Ui_Stm32Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STM32_H
