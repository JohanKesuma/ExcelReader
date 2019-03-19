#ifndef EXCEL_H
#define EXCEL_H

#include <QString>
#include <QStandardItemModel>

#define FILE_FILTER "Excel Workbook (*.xlsx)"

class Excel
{
public:
    virtual ~Excel(){}
    virtual void parseDocument(const QString &fileName) = 0;
    virtual QStandardItemModel* getItemModel() = 0;

protected:
    QStandardItemModel *tableModel;
};

#endif // EXCEL_H
