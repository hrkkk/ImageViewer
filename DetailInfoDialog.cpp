#include "DetailInfoDialog.h"
#include "ui_DetailInfoDialog.h"

DetailInfoDialog::DetailInfoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DetailInfoDialog)
{
    ui->setupUi(this);
}

DetailInfoDialog::~DetailInfoDialog()
{
    delete ui;
}
