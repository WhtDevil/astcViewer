#include "viewer.h"
#include <QDebug>

Viewer::Viewer(QObject *parent) : QObject(parent)
{

}

void Viewer::showImage(QString filename)
{
    emit newImage(filename.prepend("file:///"));
}

void Viewer::createWindow()
{
    context = engine.rootContext();
    context->setContextProperty("control", this);
    rootComponent = new QQmlComponent(&engine, QUrl("qrc:///main.qml"));
    qmlWindow = qobject_cast<QQuickWindow *>(rootComponent->create());
    if (qmlWindow == nullptr)
        return;
    qDebug()<<"Icon";
    qmlWindow->setTitle("Viewer");
    qmlWindow->setIcon(QIcon("qrc:/icon.ico"));
}

void Viewer::nextImage()
{
    qDebug()<<"NEXT";
}

void Viewer::prevImage()
{
    qDebug()<<"Previous";
}
