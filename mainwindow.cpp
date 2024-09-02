#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controls.cpp"
#include "MediaStatus.cpp"
#include "MediaError.cpp"
#include "populateMusic.cpp"

QString MainWindow::MusicFile = "";  // Define the static member variable

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)                        // Call the base class constructor
    , ui(new Ui::MainWindow)                     // Initialize the Ui pointer
    , player(new QMediaPlayer(this))             // Initialize the QMediaPlayer with 'this' as the parent
    , videoWidget(new QVideoWidget(this))        // Initialize the QVideoWidget with 'this' as the parent
    , audioOutput(new QAudioOutput(this))        // Initialize the QAudioOutput with 'this' as the parent
{

    // Setup the Ui:: MainWindow
    ui->setupUi(this);
    ui->verticalLayout->addWidget(videoWidget);
    //Qt::IgnoreAspectRatio
    //Qt::KeepAspectRatio
    videoWidget->setAspectRatioMode(Qt::KeepAspectRatioByExpanding);

    // Setup External Variables from "global.cpp"
    this->setWindowTitle("MKV Media Player");

    // connect the buttons to routines
    connect(ui->Quit, &QPushButton::clicked, this, &MainWindow::Quit);
    connect(ui->Play, &QPushButton::clicked, this, &MainWindow::Play);
    connect(ui->Stop, &QPushButton::clicked, this, &MainWindow::Stop);
    connect(ui->prevTrack, &QPushButton::clicked, this, [this]() { Track(false); });
    connect(ui->nextTrack, &QPushButton::clicked, this, [this]() { Track(true); });
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::MediaStatus);
    connect(player, &QMediaPlayer::playbackStateChanged, this, &MainWindow::StateChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::updatePosition);
    connect(player, &QMediaPlayer::errorOccurred, this, &MainWindow::MediaError);

    trackVolume = 0.3;
    ui->volumeSlider->setRange(0, 100);
    ui->volumeSlider->setValue(static_cast<int>(trackVolume * 100)); // Convert 0.0–1.0 to 0–100
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &MainWindow::updateVolume);

    // Populate Music Map
    populateMusic();
    MusicIndex = 0;
    Player();
}

MainWindow::~MainWindow()
{
    // Stop the media player if it's playing
    if (player->isPlaying()) {
        player->stop();
    }
    // Delete the media player
    delete player;
    delete ui;
}

