#include "video.h"

#include <QKeyEvent>
#include <QMouseEvent>

VideoWidget::VideoWidget(QWidget *parent)
    : QVideoWidget(parent)
{


    QPalette palet = palette();
    palet.setColor(QPalette::Window, Qt::white);
    setPalette(palet);

    setAttribute(Qt::WA_OpaquePaintEvent);

    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

void VideoWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape && isFullScreen()) {
        setFullScreen(false);
        event->accept();
    } else if (event->key() == Qt::Key_Enter && event->modifiers() & Qt::Key_Alt) {
        setFullScreen(!isFullScreen());
        event->accept();
    } else {
        QVideoWidget::keyPressEvent(event);
    }
}

void VideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    setFullScreen(!isFullScreen());
    event->accept();
}

void VideoWidget::mousePressEvent(QMouseEvent *event)
{
    QVideoWidget::mousePressEvent(event);
}

