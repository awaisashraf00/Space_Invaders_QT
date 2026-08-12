#include "player.h"
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // QCoreApplication app(argc, argv);    
    // ActionTaker* user = new ActionTaker();
    // Datastorage* data = new Datastorage(user);
    // QObject::connect(user,&ActionTaker::data_ready,data,&Datastorage::Write_Data);
    // user->user_in();
    // auto Child = user->findChildren<ActionTaker*>("Awais");
    // if(!Child.isEmpty()) qInfo()<<"Child Found " <<" : ";
    
    qmlRegisterType<PLAYER>("PLayerControls",1,0,"PLAYER");

    // engine.rootContext()->setContextProperty("actionTaker", &player1);
    engine.loadFromModule("Qt_Game", "Main");

    
    if (engine.rootObjects().isEmpty()){return -1;}
    

    
    return app.exec();
}