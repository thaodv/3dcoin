#include "topinfoarea.h"
#include "ui_topinfoarea.h"

#include "bitcoinunits.h"
#include "walletmodel.h"
#include "optionsmodel.h"

TopInfoArea::TopInfoArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopInfoArea)
{
    ui->setupUi(this);
    walletModel = 0;

    
}

TopInfoArea::~TopInfoArea()
{
    delete ui;
}


void TopInfoArea::setBalance(const CAmount& balance, const CAmount& unconfirmedBalance, const CAmount& immatureBalance, const CAmount& anonymizedBalance, const CAmount& watchOnlyBalance, const CAmount& watchUnconfBalance, const CAmount& watchImmatureBalance)
{
    int nDisplayUnit = walletModel->getOptionsModel()->getDisplayUnit();

    ui->labelAvailable->setText(BitcoinUnits::floorHtmlWithUnit(nDisplayUnit, balance, false, BitcoinUnits::separatorAlways));
    ui->labelPending->setText(BitcoinUnits::floorHtmlWithUnit(nDisplayUnit, watchUnconfBalance, false, BitcoinUnits::separatorAlways));
    ui->labelImmature->setText(BitcoinUnits::floorHtmlWithUnit(nDisplayUnit, immatureBalance, false, BitcoinUnits::separatorAlways));

    ui->labelTotal->setText(BitcoinUnits::floorHtmlWithUnit(nDisplayUnit, balance + unconfirmedBalance + immatureBalance, false, BitcoinUnits::separatorAlways));

}

//TODO: change units here test

// void TopInfoArea::updateDisplayUnit()
// {
//     if(walletModel && walletModel->getOptionsModel())
//     {
//         auto nDisplayUnit = walletModel->getOptionsModel()->getDisplayUnit();
//         if(currentBalance != -1)
//             setBalance(currentBalance, currentUnconfirmedBalance, currentImmatureBalance, currentAnonymizedBalance,
//                        currentWatchOnlyBalance, currentWatchUnconfBalance, currentWatchImmatureBalance);
 
//     }
// }


void TopInfoArea::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
    //if(model && model->getOptionsModel())
    //{
        // update the display unit, to not use the default ("3DC")
        //updateDisplayUnit();

        // Keep up to date with wallet
        // setBalance(model->getBalance(), model->getUnconfirmedBalance(), model->getImmatureBalance(), model->getAnonymizedBalance(),
        //            model->getWatchBalance(), model->getWatchUnconfirmedBalance(), model->getWatchImmatureBalance());
        // connect(model, SIGNAL(balanceChanged(CAmount,CAmount,CAmount,CAmount,CAmount,CAmount,CAmount)), this, SLOT(setBalance(CAmount,CAmount,CAmount,CAmount,CAmount,CAmount,CAmount)));

   // }
}