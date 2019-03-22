#include "minmaxnormdialog.h"
#include "ui_minmaxnormdialog.h"

#include <QDebug>
#include <QMessageBox>

MinMaxNormDialog::MinMaxNormDialog(QStandardItemModel *standarItemModel,
                                   QModelIndexList modelIndexList,
                                   QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MinMaxNormDialog),
    standardItemModel(standarItemModel),
    modelIndexList(modelIndexList)
{
    ui->setupUi(this);

    intValidator = new QIntValidator(0, 100, this);
    ui->minRangeEdit->setValidator(intValidator);
    ui->maxRangeEdit->setValidator(intValidator);

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

MinMaxNormDialog::~MinMaxNormDialog()
{
    delete intValidator;
    delete ui;
}

void MinMaxNormDialog::minMaxNorm()
{
    if (!validateInput()) {
        QMessageBox::critical(this, "Error", "Invalid Input");
        return;
    }

    int newMin = ui->minRangeEdit->text().toInt();
    int newMax = ui->maxRangeEdit->text().toInt();

    for (int i = 0; i < modelIndexList.count(); ++i) {
        int row = modelIndexList.at(i).row();
        int column = modelIndexList.at(i).column();
        QModelIndex ind = modelIndexList.at(i);
//        QVariant dataCell = standardItemModel->takeItem(row, column)->data();
//        if (dataCell.type() == QVariant::Int) {
//            qDebug() << dataCell;
//        }
    }

}

bool MinMaxNormDialog::validateInput()
{
    if (ui->minRangeEdit->text() > ui->maxRangeEdit->text()) {
        return false;
    }
    if (ui->maxRangeEdit->text().isEmpty() || ui->minRangeEdit->text().isEmpty()) {
        return false;
    }
    return true;
}

void MinMaxNormDialog::on_cancelButton_clicked()
{
    this->close();
}

void MinMaxNormDialog::on_okButton_clicked()
{
    minMaxNorm();
}
