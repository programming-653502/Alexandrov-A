#ifndef VIDEO_H
#define VIDEO_H

#include <QVideoWidget>

class VideoWidget : public QVideoWidget
{
    Q_OBJECT

public:
    VideoWidget(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif
