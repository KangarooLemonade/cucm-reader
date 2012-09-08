/********************************************************************************
** Form generated from reading UI file 'testoutputdialog.ui'
**
** Created: Fri Sep 7 21:13:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTOUTPUTDIALOG_H
#define UI_TESTOUTPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestOutputDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *outputLabel;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textEdit;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QTextBrowser *routePatternBrowser;
    QTextBrowser *routeListBrowser;
    QTextBrowser *routeGroupBrowser;
    QTreeWidget *treeWidget;

    void setupUi(QDialog *TestOutputDialog)
    {
        if (TestOutputDialog->objectName().isEmpty())
            TestOutputDialog->setObjectName(QString::fromUtf8("TestOutputDialog"));
        TestOutputDialog->resize(763, 696);
        layoutWidget = new QWidget(TestOutputDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 42, 740, 654));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        outputLabel = new QLabel(layoutWidget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        horizontalLayout->addWidget(outputLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextBrowser(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(640, 192));

        verticalLayout->addWidget(textEdit);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        routePatternBrowser = new QTextBrowser(layoutWidget);
        routePatternBrowser->setObjectName(QString::fromUtf8("routePatternBrowser"));
        routePatternBrowser->setMaximumSize(QSize(240, 16777215));

        horizontalLayout_4->addWidget(routePatternBrowser);

        routeListBrowser = new QTextBrowser(layoutWidget);
        routeListBrowser->setObjectName(QString::fromUtf8("routeListBrowser"));
        routeListBrowser->setMaximumSize(QSize(240, 16777215));

        horizontalLayout_4->addWidget(routeListBrowser);

        routeGroupBrowser = new QTextBrowser(layoutWidget);
        routeGroupBrowser->setObjectName(QString::fromUtf8("routeGroupBrowser"));
        routeGroupBrowser->setMaximumSize(QSize(240, 16777215));

        horizontalLayout_4->addWidget(routeGroupBrowser);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        treeWidget = new QTreeWidget(layoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        gridLayout_3->addWidget(treeWidget, 1, 0, 1, 1);


        retranslateUi(TestOutputDialog);

        QMetaObject::connectSlotsByName(TestOutputDialog);
    } // setupUi

    void retranslateUi(QDialog *TestOutputDialog)
    {
        TestOutputDialog->setWindowTitle(QApplication::translate("TestOutputDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        outputLabel->setText(QApplication::translate("TestOutputDialog", "Debug Window:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TestOutputDialog", "Route Patterns:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TestOutputDialog", "Route Lists: ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TestOutputDialog", "Route Groups:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestOutputDialog: public Ui_TestOutputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTOUTPUTDIALOG_H
