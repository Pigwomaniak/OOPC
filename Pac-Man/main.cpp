

#include <QApplication>
#include <QTranslator>
#include <QLocale>

#include "gameboard.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("app_") + locale);
    app.installTranslator(&translator);

    GameBoard board;
    board.setGeometry(200, 200, 800, 900);
    board.show();
    return app.exec();
}

