#ifndef DETAILINFODIALOG_H
#define DETAILINFODIALOG_H

#include <QDialog>

namespace Ui {
class DetailInfoDialog;
}

class DetailInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailInfoDialog(QWidget *parent = nullptr);
    ~DetailInfoDialog();

private:
    Ui::DetailInfoDialog *ui;
};

#endif // DETAILINFODIALOG_H
