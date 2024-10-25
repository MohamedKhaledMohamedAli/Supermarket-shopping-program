/********************************************************************************
** Form generated from reading UI file 'Supermarket.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPERMARKET_H
#define UI_SUPERMARKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Supermarket
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QListWidget *CategoryList;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QListWidget *itemList;
    QHBoxLayout *horizontalLayout;
    QLabel *QuantityLabel;
    QLineEdit *QuantiyInput;
    QPushButton *ApplyButtom;
    QHBoxLayout *horizontalLayout_2;
    QLabel *SumLabel;
    QLCDNumber *SumNumber;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Supermarket)
    {
        if (Supermarket->objectName().isEmpty())
            Supermarket->setObjectName("Supermarket");
        Supermarket->resize(800, 600);
        centralwidget = new QWidget(Supermarket);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        CategoryList = new QListWidget(groupBox);
        CategoryList->setObjectName("CategoryList");
        CategoryList->setStyleSheet(QString::fromUtf8("font: italic 12pt \"Segoe UI\";"));

        gridLayout->addWidget(CategoryList, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        itemList = new QListWidget(groupBox_2);
        itemList->setObjectName("itemList");

        gridLayout_2->addWidget(itemList, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        QuantityLabel = new QLabel(groupBox_2);
        QuantityLabel->setObjectName("QuantityLabel");
        QuantityLabel->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";\n"
"font: 700 11pt \"Segoe UI\";"));

        horizontalLayout->addWidget(QuantityLabel);

        QuantiyInput = new QLineEdit(groupBox_2);
        QuantiyInput->setObjectName("QuantiyInput");
        QuantiyInput->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        QuantiyInput->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(QuantiyInput);

        ApplyButtom = new QPushButton(groupBox_2);
        ApplyButtom->setObjectName("ApplyButtom");

        horizontalLayout->addWidget(ApplyButtom);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        SumLabel = new QLabel(groupBox_2);
        SumLabel->setObjectName("SumLabel");
        SumLabel->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));

        horizontalLayout_2->addWidget(SumLabel);

        SumNumber = new QLCDNumber(groupBox_2);
        SumNumber->setObjectName("SumNumber");

        horizontalLayout_2->addWidget(SumNumber);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_2);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        Supermarket->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Supermarket);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Supermarket->setMenuBar(menubar);
        statusbar = new QStatusBar(Supermarket);
        statusbar->setObjectName("statusbar");
        Supermarket->setStatusBar(statusbar);

        retranslateUi(Supermarket);

        QMetaObject::connectSlotsByName(Supermarket);
    } // setupUi

    void retranslateUi(QMainWindow *Supermarket)
    {
        Supermarket->setWindowTitle(QCoreApplication::translate("Supermarket", "Supermarket", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Supermarket", "Category", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Supermarket", "Items", nullptr));
        QuantityLabel->setText(QCoreApplication::translate("Supermarket", "Quantity", nullptr));
        ApplyButtom->setText(QCoreApplication::translate("Supermarket", "Apply", nullptr));
        SumLabel->setText(QCoreApplication::translate("Supermarket", "Sum", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Supermarket: public Ui_Supermarket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPERMARKET_H
