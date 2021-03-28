#include "viewer.h"
#include <QDebug>

Viewer::Viewer(QObject *parent) : QObject(parent)
{

}

void Viewer::showImage(QString filename)
{
    emit newImage(filename.prepend("file:///"));
}

void Viewer::nextImage()
{
    qDebug()<<"NEXT";
}
