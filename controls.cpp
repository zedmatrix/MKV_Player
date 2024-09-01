void MainWindow::Track(bool direction) {
    MusicIndex += direction ? 1 : -1;
    MusicIndex = std::clamp(MusicIndex, 0, static_cast<int>(MusicMap.size()) - 1);
    qDebug() << "New Track" << MusicIndex;
    if (player->isPlaying()) { player->stop(); }
    Player();
}

void MainWindow::updateVolume() {
    int value = ui->volumeSlider->value();
    trackVolume = value / 100.0; // Convert 0–100 back to 0.0–1.0
    // Here you would apply `trackVolume` to your audio player
    audioOutput->setVolume(trackVolume); // Volume is from 0.0 to 1.0
    qDebug() << "Track Volume: " << trackVolume;
}

void MainWindow::Player()
{
    if (MusicIndex >= MusicMap.size()) {
        MusicIndex = 0;  // Reset to the beginning if out of bounds
    }

    QString filePath = MusicMap[MusicIndex]["FullPath"];
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    player->setSource(fileUrl);
    Play();
}

void MainWindow::Play () {
    if (player->isPlaying()) {
        player->pause();
    } else {
        qDebug() << "Player Track Volume: " << trackVolume;
        audioOutput->setVolume(trackVolume); // Volume is from 0.0 to 1.0
        player->setVideoOutput(videoWidget);
        player->setAudioOutput(audioOutput);
        player->play();
    }
}

void MainWindow::Stop () {
    if (player->isPlaying()) {
        player->stop();
    }
}

void MainWindow::Quit () {
    QCoreApplication::quit();
}
