#ifndef VIEWER_H
#define VIEWER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickWindow>

class Viewer : public QObject
{
    Q_OBJECT
public:
    explicit Viewer(QObject *parent = nullptr);
    void showImage(QString filename);
    void createWindow();

    Q_INVOKABLE void nextImage();
     Q_INVOKABLE void prevImage();
private:
    QQuickWindow *qmlWindow; //QML window
    QQmlEngine engine;
    QQmlContext *context;
    QQmlComponent *rootComponent;
signals:
    void newImage(QString filename);
};

#endif // VIEWER_H
