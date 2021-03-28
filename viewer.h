#ifndef VIEWER_H
#define VIEWER_H

#include <QObject>

class Viewer : public QObject
{
    Q_OBJECT
public:
    explicit Viewer(QObject *parent = nullptr);
    void showImage(QString filename);
    Q_INVOKABLE void nextImage();
signals:
    void newImage(QString filename);
};

#endif // VIEWER_H
