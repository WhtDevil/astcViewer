#include <QGuiApplication>
#include <QCommandLineParser>
#include "viewer.h"
#include <QDebug>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    Viewer v;
    QCommandLineParser parser;
    parser.setApplicationDescription("Astc viewer");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOptions({
                          {{"f", "folder"}, "Path to folder with images. Default is :/images", "folder", ":/images"}
                      });
    parser.process(app);
    v.createWindow();
    v.showImage( QString::fromUtf8((const char *)argv[1],strlen(argv[1])));
    return app.exec();
}
