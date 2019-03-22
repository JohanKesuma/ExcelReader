#include "appmenu.h"

AppMenu::AppMenu()
{

}

AppMenu::~AppMenu()
{
    delete actExit;
    delete actOpen;
    delete actClear;
    delete actAbout;
    delete actMinMaxNorm;
    delete menuFile;
    delete menuEdit;
    delete menuHelp;
    delete menuData;
    delete mainMenuBar;
}

void AppMenu::setupMenu(Ui::MainWindow *ui)
{

    // create menubar
    mainMenuBar = new QMenuBar();

    // add menu File
    menuFile = new QMenu(mainMenuBar);
    menuFile->setTitle("File");
    mainMenuBar->addAction(menuFile->menuAction());
    // add action open
    actOpen = new QAction(ui->menuWidget);
    actOpen->setText(QString("Open"));
    menuFile->addAction(actOpen);
    // add action exit
    actExit = new QAction(ui->menuWidget);
    actExit->setText("Exit");
    menuFile->addAction(actExit);
    // end menu File

    // add Data menu
    menuData = new QMenu(mainMenuBar);
    menuData->setTitle("Data");
    mainMenuBar->addAction(menuData->menuAction());
    // add action minmaxnorm
    actMinMaxNorm = new QAction(ui->menuWidget);
    actMinMaxNorm->setText("Min-Max Normalization");
    menuData->addAction(actMinMaxNorm);
    // end Data menu

    // add Edit menu
    menuEdit = new QMenu(mainMenuBar);
    menuEdit->setTitle("Edit");
    mainMenuBar->addAction(menuEdit->menuAction());
    // add action Clear
    actClear = new QAction(ui->menuWidget);
    actClear->setText("Clear");
    menuEdit->addAction(actClear);
    // end Edit menu;

    // add Help menu
    menuHelp = new QMenu(mainMenuBar);
    menuHelp->setTitle("Help");
    mainMenuBar->addAction(menuHelp->menuAction());
    // add action about
    actAbout = new QAction(ui->menuWidget);
    actAbout->setText("About");
    menuHelp->addAction(actAbout);
    // end menu Help

    ui->menuWidgetVLayout->addWidget(mainMenuBar);
    mainMenuBar->setStyleSheet(QString::fromUtf8("QMenuBar::item:selected {\n"
                                                 "background-color: rgb(204, 204, 205);\n"
                                                 "}\n"
                                                 "QMenuBar {\n"
                                                 "background-color: rgb(64, 66, 68);\n"
                                                 "	color: rgb(255, 255, 255);\n"
                                                 "	\n"
                                                 "}\n"
                                                 "QMenu{\n"
                                                 "background-color: rgb(64, 66, 68);\n"
                                                 "	color: rgb(255, 255, 255);\n"
                                                 "	selection-background-color: rgb(205, 205, 206);\n"
                                                 "}"));
}
