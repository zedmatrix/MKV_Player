void MainWindow::MediaError(QMediaPlayer::Error error, const QString &errorString) {
    errorMessage.clear();
    switch (error) {
        case QMediaPlayer::NoError:
            errorMessage = "OK";
            break;
        case QMediaPlayer::ResourceError:
            errorMessage = "Resource Error:";
            // Handle the error, e.g., prompt the user, try to reload the media, etc.
            break;
        case QMediaPlayer::FormatError:
            errorMessage = "Format Error:";
            // Handle format issues, e.g., notify the user that the file format is unsupported
            break;
        case QMediaPlayer::NetworkError:
            errorMessage = "Network Error:";
            // Handle network issues, perhaps retry loading or inform the user
            break;
        case QMediaPlayer::AccessDeniedError:
            errorMessage = "Access Denied:";
            // Handle access permission issues
            break;
        default:
            errorMessage = "Unknown Error:";
            // Handle unknown errors
            break;
    }
    errorMessage += errorString;
    updateStatusBar();
}
