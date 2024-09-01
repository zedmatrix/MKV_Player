 
/********************************************************************************
** Form generated from reading UI file 'mainwindowfqzPML.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Play;
    QPushButton *prevTrack;
    QPushButton *Stop;
    QPushButton *nextTrack;
    QPushButton *Quit;
    QTextEdit *rawText;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSlider *volumeSlider;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(363, 557);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 320, 341, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Play = new QPushButton(horizontalLayoutWidget);
        Play->setObjectName("Play");
        Play->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(10);
        font.setBold(true);
        Play->setFont(font);

        horizontalLayout->addWidget(Play);

        prevTrack = new QPushButton(horizontalLayoutWidget);
        prevTrack->setObjectName("prevTrack");
        prevTrack->setMaximumSize(QSize(30, 30));
        prevTrack->setFont(font);

        horizontalLayout->addWidget(prevTrack);

        Stop = new QPushButton(horizontalLayoutWidget);
        Stop->setObjectName("Stop");
        Stop->setMaximumSize(QSize(100, 30));
        Stop->setFont(font);

        horizontalLayout->addWidget(Stop);

        nextTrack = new QPushButton(horizontalLayoutWidget);
        nextTrack->setObjectName("nextTrack");
        nextTrack->setMaximumSize(QSize(30, 30));
        nextTrack->setFont(font);

        horizontalLayout->addWidget(nextTrack);

        Quit = new QPushButton(horizontalLayoutWidget);
        Quit->setObjectName("Quit");
        Quit->setMaximumSize(QSize(100, 30));
        Quit->setFont(font);

        horizontalLayout->addWidget(Quit);

        rawText = new QTextEdit(centralwidget);
        rawText->setObjectName("rawText");
        rawText->setGeometry(QRect(10, 410, 341, 121));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setPointSize(10);
        rawText->setFont(font1);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 341, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(100, 375, 160, 16));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy);
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);
        volumeSlider->setTickPosition(QSlider::TicksBothSides);
        volumeSlider->setTickInterval(10);
        volumeSlider->setSingleStep(1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        prevTrack->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        nextTrack->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        Quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
