#include "player.h"
#include "control.h"
#include <cstdlib>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTextStream>


int main(int argc, char *argv[])
{
    
    
    // QCoreApplication app(argc, argv);    
    // ActionTaker* user = new ActionTaker();
    // Datastorage* data = new Datastorage(user);
    // QObject::connect(user,&ActionTaker::data_ready,data,&Datastorage::Write_Data);
    // user->user_in();
    // auto Child = user->findChildren<ActionTaker*>("Awais");
    // engine.rootContext()->setContextProperty("actionTaker", &player1);
    // if(!Child.isEmpty()) qInfo()<<"Child Found " <<" : ";
    // qmlRegisterType<BULLET>("BulletControls",1,0,"BULLET");
    

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    
    qmlRegisterType<PLAYER>("PLayerControls",1,0,"PLAYER");
    engine.loadFromModule("Qt_Game", "Main");

    
    if (engine.rootObjects().isEmpty()){return -1;}
    

    
    return app.exec();
}