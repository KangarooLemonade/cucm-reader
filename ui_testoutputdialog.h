/********************************************************************************
** Form generated from reading UI file 'testoutputdialog.ui'
**
** Created: Mon Aug 27 13:55:46 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestOutputDialog
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *outputLabel;
    QTextBrowser *textEdit;

    void setupUi(QDialog *TestOutputDialog)
    {
        if (TestOutputDialog->objectName().isEmpty())
            TestOutputDialog->setObjectName(QString::fromUtf8("TestOutputDialog"));
        TestOutputDialog->resize(431, 325);
        widget = new QWidget(TestOutputDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 41, 258, 217));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        outputLabel = new QLabel(widget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        gridLayout->addWidget(outputLabel, 0, 0, 1, 1);

        textEdit = new QTextBrowser(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);


        retranslateUi(TestOutputDialog);

        QMetaObject::connectSlotsByName(TestOutputDialog);
    } // setupUi

    void retranslateUi(QDialog *TestOutputDialog)
    {
        TestOutputDialog->setWindowTitle(QApplication::translate("TestOutputDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        outputLabel->setText(QApplication::translate("TestOutputDialog", "Output:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestOutputDialog: public Ui_TestOutputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTOUTPUTDIALOG_H
