/********************************************************************************
** Form generated from reading UI file 'huetagreaderwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUETAGREADERWINDOW_H
#define UI_HUETAGREADERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_huetagreaderwindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *BrowseButton;
    QLabel *MainImageView;
    QLabel *BinaryThreshImageView;
    QLabel *ContoursImageView;
    QLineEdit *ImagePathText;
    QSlider *BinaryThreshSlider;
    QLineEdit *BinaryThreshText;
    QLabel *ContourEpsilonLabel_8;
    QLabel *ContourEpsilonLabel_9;
    QLabel *ContourEpsilonLabel_10;
    QLineEdit *ContourAreaThresholdText;
    QLabel *ContourEpsilonLabel_15;
    QSlider *ContourAreaThresholdSlider;
    QLabel *ContourEpsilonLabel_16;
    QLabel *ContourEpsilonLabel_17;
    QLineEdit *ContourAreaMaxThreshText;
    QLabel *ContourEpsilonLabel_18;
    QSlider *ContourAreaMaxThreshSlider;
    QLabel *ContourEpsilonLabel_19;
    QLabel *ContourEpsilonLabel_20;
    QPushButton *BinaryThreshImagePreview;
    QPushButton *ContoursImagePreview;
    QPushButton *ManageMarkerButton;
    QPushButton *UpdateButton;
    QPushButton *LogButton;
    QLabel *ImagePreview;
    QLabel *DataCellCoordImageView;
    QLabel *ContourEpsilonLabel_13;
    QPushButton *DataCellCoordImagePreview;
    QLabel *ContourEpsilonLabel_3;
    QLabel *ContourEpsilonLabel_5;
    QSlider *GaussianKernelSlider;
    QPushButton *BlurImagePreview;
    QLabel *ContourEpsilonLabel_2;
    QLineEdit *GaussianKernelText;
    QLabel *BlurImageView;
    QLabel *ContourEpsilonLabel_21;

    void setupUi(QMainWindow *huetagreaderwindowClass)
    {
        if (huetagreaderwindowClass->objectName().isEmpty())
            huetagreaderwindowClass->setObjectName(QStringLiteral("huetagreaderwindowClass"));
        huetagreaderwindowClass->resize(1898, 1014);
        huetagreaderwindowClass->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        centralWidget = new QWidget(huetagreaderwindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BrowseButton = new QPushButton(centralWidget);
        BrowseButton->setObjectName(QStringLiteral("BrowseButton"));
        BrowseButton->setGeometry(QRect(1720, 20, 141, 35));
        QFont font;
        font.setFamily(QStringLiteral("Roboto Light"));
        font.setPointSize(12);
        BrowseButton->setFont(font);
        BrowseButton->setStyleSheet(QLatin1String("background-color : rgb(106, 27, 154); color : white;\n"
"qproperty-frame : false;"));
        MainImageView = new QLabel(centralWidget);
        MainImageView->setObjectName(QStringLiteral("MainImageView"));
        MainImageView->setGeometry(QRect(830, 80, 1028, 785));
        MainImageView->setAutoFillBackground(false);
        MainImageView->setStyleSheet(QStringLiteral("background-color: rgb(0,0,0);"));
        MainImageView->setScaledContents(true);
        BinaryThreshImageView = new QLabel(centralWidget);
        BinaryThreshImageView->setObjectName(QStringLiteral("BinaryThreshImageView"));
        BinaryThreshImageView->setGeometry(QRect(30, 80, 368, 276));
        BinaryThreshImageView->setAutoFillBackground(false);
        BinaryThreshImageView->setStyleSheet(QStringLiteral("background-color: rgb(0,0,0);"));
        BinaryThreshImageView->setScaledContents(true);
        ContoursImageView = new QLabel(centralWidget);
        ContoursImageView->setObjectName(QStringLiteral("ContoursImageView"));
        ContoursImageView->setGeometry(QRect(430, 80, 368, 276));
        ContoursImageView->setAutoFillBackground(false);
        ContoursImageView->setStyleSheet(QStringLiteral("background-color: rgb(0,0,0);"));
        ContoursImageView->setScaledContents(true);
        ImagePathText = new QLineEdit(centralWidget);
        ImagePathText->setObjectName(QStringLiteral("ImagePathText"));
        ImagePathText->setGeometry(QRect(830, 20, 881, 31));
        QFont font1;
        font1.setPointSize(10);
        ImagePathText->setFont(font1);
        ImagePathText->setStyleSheet(QLatin1String("border: 1px solid white;\n"
"background-color: rgb(66, 66, 66); color : white;"));
        ImagePathText->setReadOnly(true);
        BinaryThreshSlider = new QSlider(centralWidget);
        BinaryThreshSlider->setObjectName(QStringLiteral("BinaryThreshSlider"));
        BinaryThreshSlider->setGeometry(QRect(100, 460, 221, 22));
        BinaryThreshSlider->setMaximum(255);
        BinaryThreshSlider->setValue(50);
        BinaryThreshSlider->setOrientation(Qt::Horizontal);
        BinaryThreshText = new QLineEdit(centralWidget);
        BinaryThreshText->setObjectName(QStringLiteral("BinaryThreshText"));
        BinaryThreshText->setGeometry(QRect(270, 420, 51, 22));
        QFont font2;
        font2.setFamily(QStringLiteral("Roboto Light"));
        font2.setPointSize(9);
        BinaryThreshText->setFont(font2);
        BinaryThreshText->setStyleSheet(QLatin1String("border: 1px solid white;\n"
"background-color: rgb(66, 66, 66) ; \n"
"color : white;"));
        BinaryThreshText->setAlignment(Qt::AlignCenter);
        BinaryThreshText->setReadOnly(true);
        ContourEpsilonLabel_8 = new QLabel(centralWidget);
        ContourEpsilonLabel_8->setObjectName(QStringLiteral("ContourEpsilonLabel_8"));
        ContourEpsilonLabel_8->setGeometry(QRect(180, 414, 81, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto Light"));
        font3.setPointSize(10);
        ContourEpsilonLabel_8->setFont(font3);
        ContourEpsilonLabel_8->setStyleSheet(QStringLiteral("background-color : rgb(33, 33, 33); color : white;"));
        ContourEpsilonLabel_8->setAlignment(Qt::AlignCenter);
        ContourEpsilonLabel_9 = new QLabel(centralWidget);
        ContourEpsilonLabel_9->setObjectName(QStringLiteral("ContourEpsilonLabel_9"));
        ContourEpsilonLabel_9->setGeometry(QRect(120, 357, 181, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Roboto Light"));
        font4.setPointSize(14);
        ContourEpsilonLabel_9->setFont(font4);
        ContourEpsilonLabel_9->setStyleSheet(QStringLiteral("background-color : rgb(33, 33, 33); color : white;"));
        ContourEpsilonLabel_9->setAlignment(Qt::AlignCenter);
        ContourEpsilonLabel_10 = new QLabel(centralWidget);
        ContourEpsilonLabel_10->setObjectName(QStringLiteral("ContourEpsilonLabel_10"));
        ContourEpsilonLabel_10->setGeometry(QRect(32, 357, 31, 31));
        ContourEpsilonLabel_10->setFont(font4);
        ContourEpsilonLabel_10->setStyleSheet(QStringLiteral("background-color : rgb(198, 40, 40); color : white;"));
        ContourEpsilonLabel_10->setAlignment(Qt::AlignCenter);
        ContourAreaThresholdText = new QLineEdit(centralWidget);
        ContourAreaThresholdText->setObjectName(QStringLiteral("ContourAreaThresholdText"));
        ContourAreaThresholdText->setGeometry(QRect(670, 420, 51, 22));
        ContourAreaThresholdText->setFont(font2);
        ContourAreaThresholdText->setStyleSheet(QLatin1String("border: 1px solid white;\n"
"background-color: rgb(66, 66, 66) ; \n"
"color : white;"));
        ContourAreaThresholdText->setAlignment(Qt::AlignCenter);
        ContourAreaThresholdText->setReadOnly(true);
        ContourEpsilonLabel_15 = new QLabel(centralWidget);
        ContourEpsilonLabel_15->setObjectName(QStringLiteral("ContourEpsilonLabel_15"));
        ContourEpsilonLabel_15->setGeometry(QRect(450, 414, 211, 31));
        ContourEpsilonLabel_15->setFont(font3);
        ContourEpsilonLabel_15->setStyleSheet(QStringLiteral("background-color : rgb(33, 33, 33); color : white;"));
        ContourEpsilonLabel_15->setAlignment(Qt::AlignCenter);
        ContourAreaThresholdSlider = new QSlider(centralWidget);
        ContourAreaThresholdSlider->setObjectName(QStringLiteral("ContourAreaThresholdSlider"));
        ContourAreaThresholdSlider->setGeometry(QRect(500, 460, 221, 22));
        ContourAreaThresholdSlider->setMaximum(100);
        ContourAreaThresholdSlider->setValue(50);
        ContourAreaThresholdSlider->setOrientation(Qt::Horizontal);
        ContourEpsilonLabel_16 = new QLabel(centralWidget);
        ContourEpsilonLabel_16->setObjectName(QStringLiteral("ContourEpsilonLabel_16"));
        ContourEpsilonLabel_16->setGeometry(QRect(520, 357, 181, 31));
        ContourEpsilonLabel_16->setFont(font4);
        ContourEpsilonLabel_16->setStyleSheet(QStringLiteral("background-color : rgb(33, 33, 33); color : white;"));
        ContourEpsilonLabel_16->setAlignment(Qt::AlignCenter);
        ContourEpsilonLabel_17 = new QLabel(centralWidget);
        ContourEpsilonLabel_17->setObjectName(QStringLiteral("ContourEpsilonLabel_17"));
        ContourEpsilonLabel_17->setGeometry(QRect(432, 357, 31, 31));
        ContourEpsilonLabel_17->setFont(font4);
        ContourEpsilonLabel_17->setStyleSheet(QStringLiteral("background-color : rgb(198, 40, 40); color : white;"));
        ContourEpsilonLabel_17->setAlignment(Qt::AlignCenter);
        ContourAreaMaxThreshText = new QLineEdit(centralWidget);
        ContourAreaMaxThreshText->setObjectName(QStringLiteral("ContourAreaMaxThreshText"));
        ContourAreaMaxThreshText->setGeometry(QRect(670, 513, 51, 22));
        ContourAreaMaxThreshText->setFont(font2);
        ContourAreaMaxThreshText->setStyleSheet(QLatin1String("border: 1px solid white;\n"
"background-color: rgb(66, 66, 66) ; \n"
"color : white;"));
        ContourAreaMaxThreshText->setAlignment(Qt::AlignCenter);
        ContourAreaMaxThreshText->setReadOnly(true);
        ContourEpsilonLabel_18 = new QLabel(centralWidget);
        ContourEpsilonLabel_18->setObjectName(QStringLiteral("ContourEpsilonLabel_18"));
        ContourEpsilonLabel_18->setGeometry(QRect(440, 507, 221, 31));
        ContourEpsilonLabel_18->setFont(font3);
        ContourEpsilonLabel_18->setStyleSheet(QStringLiteral("background-color : rgb(33, 33, 33); color : white;"));
        ContourEpsilonLabel_18->setAlignment(Qt::AlignCenter);
        ContourAreaMaxThreshSlider = new QSlider(centralWidget);
        ContourAreaMaxThreshSlider->setObjectName(QStringLiteral("ContourAreaMaxThreshSlider"));
        ContourAreaMaxThreshSlider->setGeometry(QRect(500, 550, 221, 22));
        ContourAreaMaxThreshSlider->setMaximum(100);
        ContourAreaMaxThreshSlider->setValue(100);
        ContourAreaMaxThreshSlider->setOrientation(Qt::Horizontal);
        ContourEpsilonLabel_19 = new QLabel(centralWidget);
        ContourEpsilonLabel_19->setObjectName(QStringLiteral("ContourEpsilonLabel_19"));
        ContourEpsilonLabel_19->setGeometry(QRect(1230, 880, 181, 31));
        ContourEpsilonLabel_19->setFont(font4);
        ContourEpsilonLabel_19->setStyleSheet(QStringLiteral("background-color : rgb(33, 33, 33); color : white;"));
        ContourEpsilonLabel_19->setAlignment(Qt::AlignCenter);
        ContourEpsilonLabel_20 = new QLabel(centralWidget);
        ContourEpsilonLabel_20->setObjectName(QStringLiteral("ContourEpsilonLabel_20"));
        ContourEpsilonLabel_20->setGeometry(QRect(832, 865, 31, 31));
        ContourEpsilonLabel_20->setFont(font4);
        ContourEpsilonLabel_20->setStyleSheet(QStringLiteral("background-color : rgb(198, 40, 40); color : white;"));
        ContourEpsilonLabel_20->setAlignment(Qt::AlignCenter);
        BinaryThreshImagePreview = new QPushButton(centralWidget);
        BinaryThreshImagePreview->setObjectName(QStringLiteral("BinaryThreshImagePreview"));
        BinaryThreshImagePreview->setGeometry(QRect(30, 80, 371, 281));
        BinaryThreshImagePreview->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0);"));
        ContoursImagePreview = new QPushButton(centralWidget);
        ContoursImagePreview->setObjectName(QStringLiteral("ContoursImagePreview"));
        ContoursImagePreview->setGeometry(QRect(430, 80, 371, 281));
        ContoursImagePreview->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0);"));
        ManageMarkerButton = new QPushButton(centralWidget);
        ManageMarkerButton->setObjectName(QStringLiteral("ManageMarkerButton"));
        ManageMarkerButton->setGeometry(QRect(1670, 930, 191, 35));
        ManageMarkerButton->setFont(font);
        ManageMarkerButton->setStyleSheet(QLatin1String("background-color : rgb(25, 118, 210); color : white;\n"
"qproperty-frame : false;"));
        UpdateButton = new QPushButton(centralWidget);
        UpdateButton->setObjectName(QStringLiteral("UpdateButton"));
        UpdateButton->setGeometry(QRect(1230, 930, 191, 35));
        UpdateButton->setFont(font);
        UpdateButton->setStyleSheet(QStringLiteral("background-color : rgb(198, 40, 40); color : white;"));
        LogButton = new QPushButton(centralWidget);
        LogButton->setObjectName(QStringLiteral("LogButton"));
        LogButton->setGeometry(QRect(1450, 930, 191, 35));
        LogButton->setFont(font);
        LogButton->setStyleSheet(QLatin1String("background-color : rgb(106, 27, 154); color : white;\n"
"qproperty-frame : false;"));
        ImagePreview = new QLabel(centralWidget);
        ImagePreview->setObjectName(QStringLiteral("ImagePreview"));
        ImagePreview->setGeometry(QRect(690, 193, 1136, 852));
        ImagePreview->setStyleSheet(QStringLiteral("background-color : rgba(0, 0, 0, 0);"));
        ImagePreview->setScaledContents(true);
        DataCellCoordImageView = new QLabel(centralWidget);
        DataCellCoordImageView->setObjectName(QStringLiteral("DataCellCoordImageView"));
        DataCellCoordImageView->setGeometry(QRect(30, 590, 368, 276));
        DataCellCoordImageView->setMaximumSize(QSize(368, 276));
        DataCellCoordImageView->setAutoFillBackground(false);
        DataCellCoordImageView->setStyleSheet(QStringLiteral("background-color: rgb(0,0,0);"));
        DataCellCoordImageView->setScaledContents(true);
        ContourEpsilonLabel_13 = new QLabel(centralWidget);
        ContourEpsilonLabel_13->setObjectName(QStringLiteral("ContourEpsilonLabel_13"));
        ContourEpsilonLabel_13->setGeometry(QRect(32, 867, 31, 31));
        ContourEpsilonLabel_13->setFont(font4);
        ContourEpsilonLabel_13->setStyleSheet(QStringLiteral("background-color : rgb(198, 40, 40); color : white;"));
        ContourEpsilonLabel_13->setAlignment(Qt::AlignCenter);
        DataCellCoordImagePreview = new QPushButton(centralWidget);
        DataCellCoordImagePreview->setObjectName(QStringLiteral("DataCellCoordImagePreview"));
        DataCellCoordImagePreview->setGeometry(QRect(30, 590, 371, 281));
        DataCellCoordImagePreview->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0);"));
        ContourEpsilonLabel_3 = new QLabel(centralWidget);
        ContourEpsilonLabel_3->setObjectName(QStringLiteral("ContourEpsilonLabel_3"));
        ContourEpsilonLabel_3->setGeometry(QRect(100, 870, 231, 31));
        ContourEpsilonLabel_3->setFont(font4);
        ContourEpsilonLabel_3->setStyleSheet(QStringLiteral("background-color : rgb(33, 33, 33); color : white;"));
        ContourEpsilonLabel_3->setAlignment(Qt::AlignCenter);
        ContourEpsilonLabel_5 = new QLabel(centralWidget);
        ContourEpsilonLabel_5->setObjectName(QStringLiteral("ContourEpsilonLabel_5"));
        ContourEpsilonLabel_5->setGeometry(QRect(430, 867, 31, 31));
        ContourEpsilonLabel_5->setFont(font4);
        ContourEpsilonLabel_5->setStyleSheet(QStringLiteral("background-color : rgb(198, 40, 40); color : white;"));
        ContourEpsilonLabel_5->setAlignment(Qt::AlignCenter);
        GaussianKernelSlider = new QSlider(centralWidget);
        GaussianKernelSlider->setObjectName(QStringLiteral("GaussianKernelSlider"));
        GaussianKernelSlider->setGeometry(QRect(498, 950, 221, 22));
        GaussianKernelSlider->setMinimum(1);
        GaussianKernelSlider->setMaximum(50);
        GaussianKernelSlider->setSingleStep(1);
        GaussianKernelSlider->setPageStep(5);
        GaussianKernelSlider->setValue(3);
        GaussianKernelSlider->setOrientation(Qt::Horizontal);
        BlurImagePreview = new QPushButton(centralWidget);
        BlurImagePreview->setObjectName(QStringLiteral("BlurImagePreview"));
        BlurImagePreview->setGeometry(QRect(428, 590, 371, 281));
        BlurImagePreview->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0);"));
        ContourEpsilonLabel_2 = new QLabel(centralWidget);
        ContourEpsilonLabel_2->setObjectName(QStringLiteral("ContourEpsilonLabel_2"));
        ContourEpsilonLabel_2->setGeometry(QRect(518, 870, 181, 31));
        ContourEpsilonLabel_2->setFont(font4);
        ContourEpsilonLabel_2->setStyleSheet(QStringLiteral("background-color : rgb(33, 33, 33); color : white;"));
        ContourEpsilonLabel_2->setAlignment(Qt::AlignCenter);
        GaussianKernelText = new QLineEdit(centralWidget);
        GaussianKernelText->setObjectName(QStringLiteral("GaussianKernelText"));
        GaussianKernelText->setGeometry(QRect(668, 916, 51, 22));
        GaussianKernelText->setFont(font2);
        GaussianKernelText->setStyleSheet(QLatin1String("border: 1px solid white;\n"
"background-color: rgb(66, 66, 66) ; \n"
"color : white;"));
        GaussianKernelText->setAlignment(Qt::AlignCenter);
        GaussianKernelText->setReadOnly(true);
        BlurImageView = new QLabel(centralWidget);
        BlurImageView->setObjectName(QStringLiteral("BlurImageView"));
        BlurImageView->setGeometry(QRect(428, 590, 368, 276));
        BlurImageView->setMaximumSize(QSize(368, 276));
        BlurImageView->setAutoFillBackground(false);
        BlurImageView->setStyleSheet(QStringLiteral("background-color: rgb(0,0,0);"));
        BlurImageView->setScaledContents(true);
        ContourEpsilonLabel_21 = new QLabel(centralWidget);
        ContourEpsilonLabel_21->setObjectName(QStringLiteral("ContourEpsilonLabel_21"));
        ContourEpsilonLabel_21->setGeometry(QRect(498, 910, 161, 31));
        ContourEpsilonLabel_21->setFont(font3);
        ContourEpsilonLabel_21->setStyleSheet(QStringLiteral("background-color : rgb(33, 33, 33); color : white;"));
        ContourEpsilonLabel_21->setAlignment(Qt::AlignCenter);
        huetagreaderwindowClass->setCentralWidget(centralWidget);
        UpdateButton->raise();
        LogButton->raise();
        ManageMarkerButton->raise();
        BrowseButton->raise();
        MainImageView->raise();
        BinaryThreshImageView->raise();
        ContoursImageView->raise();
        ImagePathText->raise();
        BinaryThreshSlider->raise();
        BinaryThreshText->raise();
        ContourEpsilonLabel_8->raise();
        ContourEpsilonLabel_9->raise();
        ContourEpsilonLabel_10->raise();
        ContourAreaThresholdText->raise();
        ContourEpsilonLabel_15->raise();
        ContourAreaThresholdSlider->raise();
        ContourEpsilonLabel_16->raise();
        ContourEpsilonLabel_17->raise();
        ContourAreaMaxThreshText->raise();
        ContourEpsilonLabel_18->raise();
        ContourAreaMaxThreshSlider->raise();
        ContourEpsilonLabel_19->raise();
        ContourEpsilonLabel_20->raise();
        DataCellCoordImageView->raise();
        ContourEpsilonLabel_13->raise();
        ContourEpsilonLabel_3->raise();
        ContourEpsilonLabel_5->raise();
        GaussianKernelSlider->raise();
        ContourEpsilonLabel_2->raise();
        GaussianKernelText->raise();
        BlurImageView->raise();
        ContourEpsilonLabel_21->raise();
        DataCellCoordImagePreview->raise();
        BlurImagePreview->raise();
        ContoursImagePreview->raise();
        BinaryThreshImagePreview->raise();
        ImagePreview->raise();

        retranslateUi(huetagreaderwindowClass);

        QMetaObject::connectSlotsByName(huetagreaderwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *huetagreaderwindowClass)
    {
        huetagreaderwindowClass->setWindowTitle(QApplication::translate("huetagreaderwindowClass", "huetagreaderwindow", Q_NULLPTR));
        BrowseButton->setText(QApplication::translate("huetagreaderwindowClass", "Browse", Q_NULLPTR));
        MainImageView->setText(QApplication::translate("huetagreaderwindowClass", "TextLabel", Q_NULLPTR));
        BinaryThreshImageView->setText(QApplication::translate("huetagreaderwindowClass", "TextLabel", Q_NULLPTR));
        ContoursImageView->setText(QApplication::translate("huetagreaderwindowClass", "TextLabel", Q_NULLPTR));
        ImagePathText->setText(QString());
        BinaryThreshText->setText(QApplication::translate("huetagreaderwindowClass", "50", Q_NULLPTR));
        ContourEpsilonLabel_8->setText(QApplication::translate("huetagreaderwindowClass", "Threshold:", Q_NULLPTR));
        ContourEpsilonLabel_9->setText(QApplication::translate("huetagreaderwindowClass", "Binary Threshold", Q_NULLPTR));
        ContourEpsilonLabel_10->setText(QApplication::translate("huetagreaderwindowClass", "1", Q_NULLPTR));
        ContourAreaThresholdText->setText(QApplication::translate("huetagreaderwindowClass", "2.5", Q_NULLPTR));
        ContourEpsilonLabel_15->setText(QApplication::translate("huetagreaderwindowClass", "Contour Min Area Threhold:", Q_NULLPTR));
        ContourEpsilonLabel_16->setText(QApplication::translate("huetagreaderwindowClass", "Square Contours", Q_NULLPTR));
        ContourEpsilonLabel_17->setText(QApplication::translate("huetagreaderwindowClass", "2", Q_NULLPTR));
        ContourAreaMaxThreshText->setText(QApplication::translate("huetagreaderwindowClass", "5", Q_NULLPTR));
        ContourEpsilonLabel_18->setText(QApplication::translate("huetagreaderwindowClass", "Contour Max Area Threshold:", Q_NULLPTR));
        ContourEpsilonLabel_19->setText(QApplication::translate("huetagreaderwindowClass", "Decoded Markers", Q_NULLPTR));
        ContourEpsilonLabel_20->setText(QApplication::translate("huetagreaderwindowClass", "5", Q_NULLPTR));
        BinaryThreshImagePreview->setText(QString());
        ContoursImagePreview->setText(QString());
        ManageMarkerButton->setText(QApplication::translate("huetagreaderwindowClass", "Manage Markers", Q_NULLPTR));
        UpdateButton->setText(QApplication::translate("huetagreaderwindowClass", "Update", Q_NULLPTR));
        LogButton->setText(QApplication::translate("huetagreaderwindowClass", "Open Log", Q_NULLPTR));
        ImagePreview->setText(QString());
        DataCellCoordImageView->setText(QApplication::translate("huetagreaderwindowClass", "TextLabel", Q_NULLPTR));
        ContourEpsilonLabel_13->setText(QApplication::translate("huetagreaderwindowClass", "3", Q_NULLPTR));
        DataCellCoordImagePreview->setText(QString());
        ContourEpsilonLabel_3->setText(QApplication::translate("huetagreaderwindowClass", "Data-Cell Coordinates", Q_NULLPTR));
        ContourEpsilonLabel_5->setText(QApplication::translate("huetagreaderwindowClass", "4", Q_NULLPTR));
        BlurImagePreview->setText(QString());
        ContourEpsilonLabel_2->setText(QApplication::translate("huetagreaderwindowClass", "Gaussian Blur", Q_NULLPTR));
        GaussianKernelText->setText(QApplication::translate("huetagreaderwindowClass", "3", Q_NULLPTR));
        BlurImageView->setText(QApplication::translate("huetagreaderwindowClass", "TextLabel", Q_NULLPTR));
        ContourEpsilonLabel_21->setText(QApplication::translate("huetagreaderwindowClass", "Gaussian Kernel Size:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class huetagreaderwindowClass: public Ui_huetagreaderwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUETAGREADERWINDOW_H
