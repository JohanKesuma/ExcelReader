#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "minmaxnormdialog.h"

#include <QFileDialog>
#include <QDir>
#include <QMouseEvent>
#include <QDebug>
#include <QLibrary>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    loadLibraries();
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);

    initComponents();
    initConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete appMenu;
}

void MainWindow::actionOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select file", QDir::homePath(), FILE_FILTER);
    if (!fileName.isEmpty()) {
        tableData->parseDocument(fileName);
    }
}

void MainWindow::actionClear()
{
    tableData->getItemModel()->clear();
}

void MainWindow::actionExit()
{
    QApplication::exit();
}

void MainWindow::actionAbout()
{
    AboutDialog aboutDialog(this);
    aboutDialog.exec();
}

void MainWindow::actionMinMaxNorm()
{
    if (ui->excelTable->selectionModel()->hasSelection()) {
        MinMaxNormDialog dialog(tableData->getItemModel(),
                                ui->excelTable->selectionModel()->selectedIndexes(),
                                this);
        dialog.exec();
    } else {
        QMessageBox::warning(this, QString("..."), QString("No Selection"));
    }
}

void MainWindow::initComponents()
{
    // buat mmenu
    appMenu = new AppMenu();
    appMenu->setupMenu(ui);

    // set table model
    ui->excelTable->setModel(tableData->getItemModel());
}

void MainWindow::initConnections()
{
    // clicked action Open
    connect(appMenu->actOpen, SIGNAL(triggered()), this, SLOT(actionOpen()));

    // clicked action Exit
    connect(appMenu->actExit, SIGNAL(triggered()), this, SLOT(actionExit()));

    //clicked action About
    connect(appMenu->actAbout, SIGNAL(triggered()), this, SLOT(actionAbout()));

    // clicked action Clear
    connect(appMenu->actClear, SIGNAL(triggered()), this, SLOT(actionClear()));

    // click action minMaxNorm
    connect(appMenu->actMinMaxNorm, SIGNAL(triggered()), this, SLOT(actionMinMaxNorm()));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mouseX = event->x();
    mouseY = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalX() - mouseX, event->globalY() - mouseY);
}

void MainWindow::loadLibraries()
{
    QLibrary lib("lib/libBacaExcel");
    lib.load();
    if (!lib.isLoaded()) {
        QMessageBox::critical(this, "Error Load", lib.errorString() + ", " + lib.fileName());
        QApplication::exit();
    } else {

        qDebug() << lib.fileName();
        qDebug() << "load lib success";

    }
    CreateObjectInstance = (PEXCEL) lib.resolve("CreateObjectInstance");
    if (!CreateObjectInstance) {
        QMessageBox::critical(this, "Error", "Couldn't load libBacaExcel.dll");
        QApplication::exit();
    } else {
        tableData = CreateObjectInstance();
    }

}
