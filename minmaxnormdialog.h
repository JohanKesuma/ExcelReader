#ifndef MINMAXNORMDIALOG_H
#define MINMAXNORMDIALOG_H

#include <QDialog>
#include <QIntValidator>
#include <QModelIndexList>
#include <QStandardItemModel>

namespace Ui {
class MinMaxNormDialog;
}

class MinMaxNormDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MinMaxNormDialog(QStandardItemModel *standarItemModel, QModelIndexList modelIndexList, QWidget *parent = nullptr);
    ~MinMaxNormDialog();

private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::MinMaxNormDialog *ui;
    QStandardItemModel *standardItemModel;
    QModelIndexList modelIndexList;
    QIntValidator *intValidator;

    void minMaxNorm();
    bool validateInput();
};

#endif // MINMAXNORMDIALOG_H
