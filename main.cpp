#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (argc > 1) {
        MainWindow::MusicFile = argv[1];
        qDebug() << "Filename is:" << MainWindow::MusicFile;
        std::ifstream file(MainWindow::MusicFile.toStdString());
        if (!file) {
            qDebug() << "Filename Doesn't Exist... Exiting...";
            exit(1);
        }
    } else {
        qDebug() << " Usage: " << argv[0] << " {Music File}";
        exit(1);
    }

    MainWindow window;
    window.show();
    return app.exec();
}
