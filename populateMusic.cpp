void MainWindow::populateMusic() {
    QFile file(MusicFile);  // Use the QString directly

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File opening failed";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        if (!line.isEmpty()) {
            QFileInfo fileInfo(line);
            if (fileInfo.exists()) {
                Music["Filename"] = fileInfo.fileName(); // "Broken Wings.mkv"
                Music["FullPath"] = fileInfo.absoluteFilePath();
                MusicMap.push_back(Music);
            } else {
                qDebug() << "File doesn't exist: " << line;
            }
        }
    }
}
