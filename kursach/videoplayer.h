#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include "video.h"

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
class QAbstractItemView;
class QLabel;
class QMediaPlayer;
class QModelIndex;
class QPushButton;
class QSlider;
class QVideoProbe;
class QVideoWidget;
QT_END_NAMESPACE

class ListModel;

class Player : public QWidget
{
    Q_OBJECT

private slots:

    void statusChanged(QMediaPlayer::MediaStatus status);
    void bufferingProgress(int progress);

    void seek(int seconds);
    void jump(const QModelIndex &index);
    void playlistPositionChanged(int);


    void videoAvailableChanged(bool available);

    void displayError();

    void showColorD();
    void open();
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);
    void metaDataChanged();

    void previousClicked();


public:
    Player(QWidget *parent = 0);
    ~Player();

    bool isPlayerAvailable() const;

    void addToPlaylist(const QList<QUrl> urls);

signals:
    void fullScreenChanged(bool fullScreen);

private:
    void setTrackInfo(const QString &info);
    void setStatusInfo(const QString &info);
    void handleCursor(QMediaPlayer::MediaStatus status);
    void updateDurationInfo(qint64 currentInfo);

    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    VideoWidget *videoWidget;
    QLabel *coverLabel;
    QSlider *slider;
    QLabel *labelDuration;
    QPushButton *fullScreenButton;
    QPushButton *colorButton;
    QDialog *colorDialog;

    QVideoProbe *probe;

    ListModel *listModel;
    QAbstractItemView *playlistView;
    QString trackInfo;
    QString statusInfo;
    qint64 duration;



};


#endif
