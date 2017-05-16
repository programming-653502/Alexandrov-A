#include "videoplayer.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    QCommandLineParser testparser;

    Player player;

    if (!testparser.positionalArguments().isEmpty() && player.isPlayerAvailable()) {
        QList<QUrl> urls;
        foreach (const QString &a, testparser.positionalArguments())
            urls.append(QUrl::fromUserInput(a, QDir::currentPath(), QUrl::AssumeLocalFile));
        player.addToPlaylist(urls);
    }
        QPalette plt = app.palette();
        plt.setColor(QPalette::Background, QColor(238,144,134,200));
        app.setPalette(plt);


#if defined(Q_WS_SIMULATOR)
    player.setAttribute(Qt::WA_LockLandscapeOrientation);
    player.showMaximized();
#else
    player.show();
#endif
    return app.exec();
}
