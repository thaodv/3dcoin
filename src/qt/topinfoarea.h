#ifndef TOPINFOAREA_H
#define TOPINFOAREA_H

#include <QWidget>
#include "bitcoinunits.h"

namespace Ui {
class TopInfoArea;
}

class WalletModel;

class TopInfoArea : public QWidget
{
    Q_OBJECT

public:
    explicit TopInfoArea(QWidget *parent = 0);
    ~TopInfoArea();
    void setWalletModel(WalletModel *model);


public Q_SLOTS:	
void setBalance(const CAmount& balance, const CAmount& unconfirmedBalance, const CAmount& immatureBalance, const CAmount& anonymizedBalance, const CAmount& watchOnlyBalance, const CAmount& watchUnconfBalance, const CAmount& watchImmatureBalance);

private:
    Ui::TopInfoArea *ui;
    WalletModel *walletModel;
};

#endif // TOPINFOAREA_H
