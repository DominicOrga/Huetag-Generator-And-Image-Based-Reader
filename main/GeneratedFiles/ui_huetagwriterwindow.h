/********************************************************************************
** Form generated from reading UI file 'huetagwriterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUETAGWRITERWINDOW_H
#define UI_HUETAGWRITERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_huetagwriterwindow
{
public:
    QLabel *markerImageLabel;
    QLineEdit *idLineEdit;
    QPushButton *closeButton;
    QPushButton *saveImageButton;
    QLabel *IDLabel;
    QPushButton *generateMarkerButton;
    QLabel *warningLabel;
    QLabel *IDLabel_2;
    QLabel *IDLabel_3;
    QLabel *IDLabel_4;
    QLabel *parityBitsLabel;
    QLabel *mainBitsLabel;
    QLabel *markerIdLabel;

    void setupUi(QDialog *huetagwriterwindow)
    {
        if (huetagwriterwindow->objectName().isEmpty())
            huetagwriterwindow->setObjectName(QStringLiteral("huetagwriterwindow"));
        huetagwriterwindow->resize(702, 920);
        huetagwriterwindow->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        markerImageLabel = new QLabel(huetagwriterwindow);
        markerImageLabel->setObjectName(QStringLiteral("markerImageLabel"));
        markerImageLabel->setGeometry(QRect(70, 30, 560, 560));
        markerImageLabel->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        idLineEdit = new QLineEdit(huetagwriterwindow);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));
        idLineEdit->setGeometry(QRect(340, 710, 201, 31));
        QFont font;
        font.setPointSize(10);
        idLineEdit->setFont(font);
        idLineEdit->setStyleSheet(QLatin1String("border: 1px solid white;\n"
"background-color: rgb(66, 66, 66); color : white;"));
        idLineEdit->setReadOnly(false);
        closeButton = new QPushButton(huetagwriterwindow);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(550, 860, 121, 35));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto Light"));
        font1.setPointSize(12);
        closeButton->setFont(font1);
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QStringLiteral("background-color : rgb(198, 40, 40); color : white;"));
        saveImageButton = new QPushButton(huetagwriterwindow);
        saveImageButton->setObjectName(QStringLiteral("saveImageButton"));
        saveImageButton->setGeometry(QRect(410, 860, 121, 35));
        saveImageButton->setFont(font1);
        saveImageButton->setFocusPolicy(Qt::NoFocus);
        saveImageButton->setStyleSheet(QLatin1String("background-color : rgb(106, 27, 154); color : white;\n"
"qproperty-frame : false;"));
        IDLabel = new QLabel(huetagwriterwindow);
        IDLabel->setObjectName(QStringLiteral("IDLabel"));
        IDLabel->setGeometry(QRect(70, 710, 261, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto Light"));
        font2.setPointSize(14);
        IDLabel->setFont(font2);
        IDLabel->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0,0); color: rgb(255,255,255);"));
        IDLabel->setAlignment(Qt::AlignCenter);
        generateMarkerButton = new QPushButton(huetagwriterwindow);
        generateMarkerButton->setObjectName(QStringLiteral("generateMarkerButton"));
        generateMarkerButton->setGeometry(QRect(550, 710, 121, 35));
        generateMarkerButton->setFont(font1);
        generateMarkerButton->setStyleSheet(QLatin1String("background-color : rgb(25, 118, 210); color : white;\n"
"qproperty-frame : false;"));
        warningLabel = new QLabel(huetagwriterwindow);
        warningLabel->setObjectName(QStringLiteral("warningLabel"));
        warningLabel->setGeometry(QRect(210, 750, 331, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto Light"));
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        warningLabel->setFont(font3);
        warningLabel->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0,0); color: rgb(255,0,0);"));
        warningLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        IDLabel_2 = new QLabel(huetagwriterwindow);
        IDLabel_2->setObjectName(QStringLiteral("IDLabel_2"));
        IDLabel_2->setGeometry(QRect(30, 600, 91, 31));
        IDLabel_2->setFont(font1);
        IDLabel_2->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0,0); color: rgb(255,255,255);"));
        IDLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        IDLabel_3 = new QLabel(huetagwriterwindow);
        IDLabel_3->setObjectName(QStringLiteral("IDLabel_3"));
        IDLabel_3->setGeometry(QRect(30, 630, 91, 31));
        IDLabel_3->setFont(font1);
        IDLabel_3->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0,0); color: rgb(255,255,255);"));
        IDLabel_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        IDLabel_4 = new QLabel(huetagwriterwindow);
        IDLabel_4->setObjectName(QStringLiteral("IDLabel_4"));
        IDLabel_4->setGeometry(QRect(30, 660, 91, 31));
        IDLabel_4->setFont(font1);
        IDLabel_4->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0,0); color: rgb(255,255,255);"));
        IDLabel_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        parityBitsLabel = new QLabel(huetagwriterwindow);
        parityBitsLabel->setObjectName(QStringLiteral("parityBitsLabel"));
        parityBitsLabel->setGeometry(QRect(130, 660, 561, 31));
        parityBitsLabel->setFont(font1);
        parityBitsLabel->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0,0); color: rgb(255,255,255);"));
        parityBitsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        mainBitsLabel = new QLabel(huetagwriterwindow);
        mainBitsLabel->setObjectName(QStringLiteral("mainBitsLabel"));
        mainBitsLabel->setGeometry(QRect(130, 630, 541, 31));
        mainBitsLabel->setFont(font1);
        mainBitsLabel->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0,0); color: rgb(255,255,255);"));
        mainBitsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        markerIdLabel = new QLabel(huetagwriterwindow);
        markerIdLabel->setObjectName(QStringLiteral("markerIdLabel"));
        markerIdLabel->setGeometry(QRect(130, 600, 541, 31));
        markerIdLabel->setFont(font1);
        markerIdLabel->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0,0); color: rgb(255,255,255);"));
        markerIdLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(huetagwriterwindow);

        QMetaObject::connectSlotsByName(huetagwriterwindow);
    } // setupUi

    void retranslateUi(QDialog *huetagwriterwindow)
    {
        huetagwriterwindow->setWindowTitle(QApplication::translate("huetagwriterwindow", "huetagwriterwindow", Q_NULLPTR));
        markerImageLabel->setText(QString());
        idLineEdit->setText(QString());
        closeButton->setText(QApplication::translate("huetagwriterwindow", "Close", Q_NULLPTR));
        saveImageButton->setText(QApplication::translate("huetagwriterwindow", "Save Image", Q_NULLPTR));
        IDLabel->setText(QApplication::translate("huetagwriterwindow", "Huetag ID (1 - 16777215):", Q_NULLPTR));
        generateMarkerButton->setText(QApplication::translate("huetagwriterwindow", "Generate", Q_NULLPTR));
        warningLabel->setText(QApplication::translate("huetagwriterwindow", "Only signed numbers allowed.", Q_NULLPTR));
        IDLabel_2->setText(QApplication::translate("huetagwriterwindow", "Marker ID:", Q_NULLPTR));
        IDLabel_3->setText(QApplication::translate("huetagwriterwindow", "Main Bits: ", Q_NULLPTR));
        IDLabel_4->setText(QApplication::translate("huetagwriterwindow", "Parity Bits:", Q_NULLPTR));
        parityBitsLabel->setText(QApplication::translate("huetagwriterwindow", "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ", Q_NULLPTR));
        mainBitsLabel->setText(QApplication::translate("huetagwriterwindow", "00 00 00 00 00 00 00 00 00 00 00 00 00", Q_NULLPTR));
        markerIdLabel->setText(QApplication::translate("huetagwriterwindow", "10152195", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class huetagwriterwindow: public Ui_huetagwriterwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUETAGWRITERWINDOW_H
