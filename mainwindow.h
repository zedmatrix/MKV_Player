#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QRandomGenerator>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QSlider>
#include <QStatusBar>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QWidget>
#include <QVector>
#include <QMap>
#include <iostream>
#include <algorithm> // For std::clamp
#include <fstream>  // For checking if the file exists
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QString MusicFile;  // Declare as static
    QString statusMessage, stateMessage, statusPosition, outputText;
    QVector<QMap<QString, QString>> MusicMap;
    QMap<QString, QString> Music;
    int MusicIndex;
    float trackVolume;
    void populateMusic();

private slots:
    void MediaStatus(QMediaPlayer::MediaStatus status); // Get Media Status
    void StateChanged(QMediaPlayer::PlaybackState state);
    void Track(bool direction);
    void Quit();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QVideoWidget *videoWidget;
    void updateStatusBar();
    void MetaDataChanged();
    void updatePosition();
    void Player();
    void updateVolume();
    void Play();
    void Stop();

};

#endif // MAINWINDOW_H
