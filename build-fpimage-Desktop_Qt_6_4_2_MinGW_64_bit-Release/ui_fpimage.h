/********************************************************************************
** Form generated from reading UI file 'fpimage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FPIMAGE_H
#define UI_FPIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FPImage
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *EcranSuspect;
    QPlainTextEdit *ERes;
    QLineEdit *EFile;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *BSelectFile;
    QPushButton *BRestore;
    QPushButton *BRestoreDelta;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *Ecran;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_2;
    QLabel *EcranBis;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FPImage)
    {
        if (FPImage->objectName().isEmpty())
            FPImage->setObjectName("FPImage");
        FPImage->resize(932, 623);
        centralWidget = new QWidget(FPImage);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        EcranSuspect = new QLabel(centralWidget);
        EcranSuspect->setObjectName("EcranSuspect");
        EcranSuspect->setMinimumSize(QSize(200, 154));
        EcranSuspect->setMaximumSize(QSize(200, 154));
        EcranSuspect->setFrameShape(QFrame::Panel);
        EcranSuspect->setFrameShadow(QFrame::Sunken);
        EcranSuspect->setLineWidth(2);
        EcranSuspect->setMidLineWidth(0);
        EcranSuspect->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(EcranSuspect);

        ERes = new QPlainTextEdit(centralWidget);
        ERes->setObjectName("ERes");
        ERes->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(ERes);

        EFile = new QLineEdit(centralWidget);
        EFile->setObjectName("EFile");

        verticalLayout->addWidget(EFile);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        BSelectFile = new QPushButton(centralWidget);
        BSelectFile->setObjectName("BSelectFile");
        BSelectFile->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(BSelectFile);

        BRestore = new QPushButton(centralWidget);
        BRestore->setObjectName("BRestore");
        BRestore->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(BRestore);

        BRestoreDelta = new QPushButton(centralWidget);
        BRestoreDelta->setObjectName("BRestoreDelta");

        verticalLayout->addWidget(BRestoreDelta);


        horizontalLayout_2->addLayout(verticalLayout);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::Panel);
        scrollArea->setLineWidth(2);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 346, 541));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        Ecran = new QLabel(scrollAreaWidgetContents);
        Ecran->setObjectName("Ecran");

        gridLayout->addWidget(Ecran, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setFrameShape(QFrame::Panel);
        scrollArea_2->setLineWidth(2);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 346, 541));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        EcranBis = new QLabel(scrollAreaWidgetContents_3);
        EcranBis->setObjectName("EcranBis");
        EcranBis->setScaledContents(true);
        EcranBis->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(EcranBis, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout_2->addWidget(scrollArea_2);

        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        FPImage->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FPImage);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 932, 21));
        FPImage->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FPImage);
        mainToolBar->setObjectName("mainToolBar");
        FPImage->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FPImage);
        statusBar->setObjectName("statusBar");
        FPImage->setStatusBar(statusBar);

        retranslateUi(FPImage);

        QMetaObject::connectSlotsByName(FPImage);
    } // setupUi

    void retranslateUi(QMainWindow *FPImage)
    {
        FPImage->setWindowTitle(QCoreApplication::translate("FPImage", "Superesolutive v1.0b", nullptr));
        EcranSuspect->setText(QString());
        BSelectFile->setText(QCoreApplication::translate("FPImage", "Select input", nullptr));
        BRestore->setText(QCoreApplication::translate("FPImage", "Superresolve", nullptr));
        BRestoreDelta->setText(QCoreApplication::translate("FPImage", "Superresolve Delta", nullptr));
        Ecran->setText(QString());
        EcranBis->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FPImage: public Ui_FPImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FPIMAGE_H
