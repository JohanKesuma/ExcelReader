#ifndef APPMENU_H
#define APPMENU_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QMenuBar>

class AppMenu
{
public:
    QMenuBar *mainMenuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuData;
    QMenu *menuHelp;
    QAction *actExit;
    QAction *actOpen;
    QAction *actClear;
    QAction *actAbout;
    QAction *actMinMaxNorm;
    AppMenu();
    ~AppMenu();
    void setupMenu(Ui::MainWindow *ui);
};

#endif // APPMENU_H
