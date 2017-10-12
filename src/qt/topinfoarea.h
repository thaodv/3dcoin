#ifndef TOPINFOAREA_H
#define TOPINFOAREA_H

#include <QWidget>

namespace Ui {
class TopInfoArea;
}

class TopInfoArea : public QWidget
{
    Q_OBJECT

public:
    explicit TopInfoArea(QWidget *parent = 0);
    ~TopInfoArea();

private:
    Ui::TopInfoArea *ui;
};

#endif // TOPINFOAREA_H
