#ifndef CONTROLS_H
#define CONTROLS_H

#include <QMediaPlayer>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QAbstractButton;
class QAbstractSlider;
class QComboBox;
QT_END_NAMESPACE

class PlayerControls : public QWidget
{
    Q_OBJECT

private:
    QMediaPlayer::State playerState;
    bool playerMuted;
    QAbstractButton *pButton;
    QAbstractButton *sButton;
    QAbstractButton *nButton;
    QAbstractButton *preButton;
    QAbstractButton *muteButton;
    QAbstractSlider *volumeSlider;
    QComboBox *rateBox;

signals:
    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void changeVolume(int volume);
    void changeMuting(bool muting);
    void changeRate(qreal rate);

public:
    PlayerControls(QWidget *parent = 0);

    QMediaPlayer::State state() const;
    int volume() const;
    bool isMuted() const;
    qreal playbackRate() const;

public slots:
    void setState(QMediaPlayer::State state);
    void setVolume(int volume);
    void setMuted(bool muted);
    void setRate(float rate);



private slots:
    void playClicked();
    void muteClicked();
    void updateRate();
    void SliderValueChanged();


};

#endif
