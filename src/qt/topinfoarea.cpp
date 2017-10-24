#include "topinfoarea.h"
#include "ui_topinfoarea.h"

TopInfoArea::TopInfoArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopInfoArea)
{
    ui->setupUi(this);

    
}

TopInfoArea::~TopInfoArea()
{
    delete ui;
}
