    #include "controls.h"

    #include <QBoxLayout>
    #include <QSlider>
    #include <QStyle>
    #include <QToolButton>
    #include <QComboBox>
    #include <QAudio>


    QMediaPlayer::State PlayerControls::state() const
    {
        return playerState;
    }

    void PlayerControls::setState(QMediaPlayer::State state)
    {
        if (state != playerState) {
            playerState = state;

            switch (state) {
            case QMediaPlayer::StoppedState:
                sButton->setEnabled(false);
                pButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
                break;
            case QMediaPlayer::PlayingState:
                sButton->setEnabled(true);
                pButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
                break;
            case QMediaPlayer::PausedState:
                sButton->setEnabled(true);
                pButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
                break;
            }
        }
}

int PlayerControls::volume() const
{
    qreal linearVolume =  QAudio::convertVolume(volumeSlider->value() / qreal(100),QAudio::LogarithmicVolumeScale,QAudio::LinearVolumeScale);

    return qRound(linearVolume * 100);
}

void PlayerControls::setVolume(int volume)
{
    qreal logarithmicVolume = QAudio::convertVolume(volume / qreal(100),QAudio::LinearVolumeScale,QAudio::LogarithmicVolumeScale);

    volumeSlider->setValue(qRound(logarithmicVolume * 100));
}

bool PlayerControls::isMuted() const
{
    return playerMuted;
}

void PlayerControls::setMuted(bool muted)
{
    if (muted != playerMuted) {
        playerMuted = muted;

        muteButton->setIcon(style()->standardIcon(muted
                ? QStyle::SP_MediaVolumeMuted
                : QStyle::SP_MediaVolume));
    }
}

void PlayerControls::playClicked()
{
    switch (playerState) {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        emit play();
        break;
    case QMediaPlayer::PlayingState:
        emit pause();
        break;
    }
}

void PlayerControls::muteClicked()
{
    emit changeMuting(!playerMuted);
}



qreal PlayerControls::playbackRate() const
{
    return rateBox->itemData(rateBox->currentIndex()).toDouble();
}

void PlayerControls::setRate(float rate)
{
    for (int i = 0; i < rateBox->count(); ++i) {
        if (qFuzzyCompare(rate, float(rateBox->itemData(i).toDouble()))) {
            rateBox->setCurrentIndex(i);
            return;
        }
    }

    rateBox->addItem(QString("%1x").arg(rate), QVariant(rate));
    rateBox->setCurrentIndex(rateBox->count() - 1);
}


PlayerControls::PlayerControls(QWidget *parent)
    : QWidget(parent)
    , playerState(QMediaPlayer::StoppedState)
    , playerMuted(false)
    , pButton(0)
    , sButton(0)
    , nButton(0)
    , preButton(0)
    , muteButton(0)
    , volumeSlider(0)
    , rateBox(0)
{
    pButton = new QToolButton(this);
    pButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    connect(pButton, SIGNAL(clicked()), this, SLOT(playClicked()));

    sButton = new QToolButton(this);
    sButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    sButton->setEnabled(false);

    connect(sButton, SIGNAL(clicked()), this, SIGNAL(stop()));

    nButton = new QToolButton(this);
    nButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

    connect(nButton, SIGNAL(clicked()), this, SIGNAL(next()));

    preButton = new QToolButton(this);
    preButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));

    connect(preButton, SIGNAL(clicked()), this, SIGNAL(previous()));

    muteButton = new QToolButton(this);
    muteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    connect(muteButton, SIGNAL(clicked()), this, SLOT(muteClicked()));

    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);

    connect(volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(SliderValueChanged()));

    rateBox = new QComboBox(this);
    rateBox->addItem("0.5x", QVariant(0.5));
    rateBox->addItem("1.0x", QVariant(1.0));
    rateBox->addItem("2.0x", QVariant(2.0));
    rateBox->setCurrentIndex(1);

    connect(rateBox, SIGNAL(activated(int)), SLOT(updateRate()));

    QBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(sButton);
    layout->addWidget(preButton);
    layout->addWidget(pButton);
    layout->addWidget(nButton);
    layout->addWidget(muteButton);
    layout->addWidget(volumeSlider);
    layout->addWidget(rateBox);
    setLayout(layout);
}



void PlayerControls::updateRate()
{
    emit changeRate(playbackRate());
}

void PlayerControls::SliderValueChanged()
{
    emit changeVolume(volume());
}
