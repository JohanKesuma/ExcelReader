#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

#include "appmenu.h"
#include "libbacaexcel.h"
#include "excel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void actionOpen();
    void actionClear();
    void actionExit();
    void actionAbout();
    void actionMinMaxNorm();

private:
    int mouseX;
    int mouseY;
    AppMenu *appMenu;
    Excel *tableData;
    Ui::MainWindow *ui;

    void initComponents();
    void initConnections();
    void createMenus();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *Event);
    void loadLibraries();
    PEXCEL CreateObjectInstance;
};

#endif // MAINWINDOW_H
