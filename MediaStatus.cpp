void MainWindow::updateStatusBar() {
    ui->statusbar->showMessage(stateMessage + " | " + statusMessage + " | "+ statusPosition);
}

void MainWindow::MetaDataChanged() {
    QMediaMetaData metaData = player->metaData(); // Retrieve the metadata object
    outputText.clear();

    if (!metaData.isEmpty()) {
        QMediaMetaData metaData = player->metaData();
        QList<QMediaMetaData::Key> metadataKeys = metaData.keys();

        for (const auto &key : metadataKeys) {
            QString keyName = QMediaMetaData::metaDataKeyToString(key);
            QVariant value = metaData.value(key);
            outputText += QString("Key: %1 => %2 \n").arg(keyName).arg(value.toString());
        }
        ui->rawText->setText(outputText);
    } else {
        qDebug() << "No Metadata";
    }
}

void MainWindow::updatePosition() {
    qint64 currentPosition = player->position(); // Get current position in milliseconds
    qint64 duration = player->duration(); // Get total duration in milliseconds

        // Format the position and duration for display (e.g., mm:ss)
    QString positionText = QString("%1:%2")
            .arg(currentPosition / 60000) // Minutes
            .arg((currentPosition % 60000) / 1000, 2, 10, QChar('0')); // Seconds
    QString durationText = QString("%1:%2")
            .arg(duration / 60000) // Minutes
            .arg((duration % 60000) / 1000, 2, 10, QChar('0')); // Seconds

    statusPosition = QString("Position: %1 / %2").arg(positionText).arg(durationText);
    updateStatusBar();
}

void MainWindow::StateChanged(QMediaPlayer::PlaybackState state) {
    switch (state) {
        case QMediaPlayer::PlayingState:
            stateMessage = "Media is playing";
            // Additional logic for when media is playing
            break;
        case QMediaPlayer::PausedState:
            stateMessage = "Media is paused";
            // Additional logic for when media is paused
            break;
        case QMediaPlayer::StoppedState:
            stateMessage = "Media is stopped";
            // Additional logic for when media is stopped
            break;
    }
    updateStatusBar();
}

void MainWindow::MediaStatus(QMediaPlayer::MediaStatus status) {
    switch (status) {
        case QMediaPlayer::NoMedia:
            statusMessage = "No media loaded.";
            break;
        case QMediaPlayer::LoadingMedia:
            statusMessage = "Loading media.";
            break;
        case QMediaPlayer::LoadedMedia:
            statusMessage = "Media loaded." + QString::number(MusicIndex);
            MetaDataChanged();
            break;
        case QMediaPlayer::StalledMedia:
            statusMessage = "Media playback stalled.";
            break;
        case QMediaPlayer::BufferingMedia:
            statusMessage = "Buffering media.";
            break;
        case QMediaPlayer::BufferedMedia:
            statusMessage = "Media buffered.";
            break;
        case QMediaPlayer::EndOfMedia:
            MusicIndex += 1;
            statusMessage = "End of media." + QString::number(MusicIndex);
            Player();
            break;
        case QMediaPlayer::InvalidMedia:
            statusMessage = "Invalid media.";
            break;
        default:
            statusMessage = "";
            break;
    }
    updateStatusBar();
}
