/********************************************************************************
** Form generated from reading UI file 'topinfoarea.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPINFOAREA_H
#define UI_TOPINFOAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopInfoArea
{
public:
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelAvailableText;
    QLabel *labelAvailable;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPendingText;
    QLabel *labelPending;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout;
    QLabel *labelImmatureText;
    QLabel *labelImmature;
    QFrame *line_4;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelTotalText;
    QLabel *labelTotal;
    QFrame *frameChartMarket;
    QHBoxLayout *horizontalLayout_8;
    QFrame *line_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_17;
    QFrame *frame;
    QFrame *line_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QLabel *label_23;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;

    void setupUi(QWidget *TopInfoArea)
    {
        if (TopInfoArea->objectName().isEmpty())
            TopInfoArea->setObjectName(QStringLiteral("TopInfoArea"));
        TopInfoArea->resize(1203, 192);
        TopInfoArea->setStyleSheet(QStringLiteral(""));
        horizontalLayout_7 = new QHBoxLayout(TopInfoArea);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(TopInfoArea);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(150, 150));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/res/icons/logo.png")));
        label->setScaledContents(true);
        label->setMargin(20);

        horizontalLayout_6->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, -1, 9, -1);
        label_2 = new QLabel(TopInfoArea);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(TopInfoArea);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(TopInfoArea);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(TopInfoArea);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(TopInfoArea);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);


        horizontalLayout_6->addLayout(verticalLayout_2);

        line = new QFrame(TopInfoArea);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QStringLiteral("background-color: none;"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, -1, 9, -1);
        label_7 = new QLabel(TopInfoArea);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        label_8 = new QLabel(TopInfoArea);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);


        verticalLayout_4->addLayout(horizontalLayout_3);

        line_3 = new QFrame(TopInfoArea);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(9, -1, 9, -1);
        labelAvailableText = new QLabel(TopInfoArea);
        labelAvailableText->setObjectName(QStringLiteral("labelAvailableText"));

        horizontalLayout_4->addWidget(labelAvailableText);

        labelAvailable = new QLabel(TopInfoArea);
        labelAvailable->setObjectName(QStringLiteral("labelAvailable"));

        horizontalLayout_4->addWidget(labelAvailable);


        verticalLayout->addLayout(horizontalLayout_4);

        line_5 = new QFrame(TopInfoArea);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, -1, 9, -1);
        labelPendingText = new QLabel(TopInfoArea);
        labelPendingText->setObjectName(QStringLiteral("labelPendingText"));

        horizontalLayout_2->addWidget(labelPendingText);

        labelPending = new QLabel(TopInfoArea);
        labelPending->setObjectName(QStringLiteral("labelPending"));

        horizontalLayout_2->addWidget(labelPending);


        verticalLayout->addLayout(horizontalLayout_2);

        line_7 = new QFrame(TopInfoArea);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, -1, 9, -1);
        labelImmatureText = new QLabel(TopInfoArea);
        labelImmatureText->setObjectName(QStringLiteral("labelImmatureText"));

        horizontalLayout->addWidget(labelImmatureText);

        labelImmature = new QLabel(TopInfoArea);
        labelImmature->setObjectName(QStringLiteral("labelImmature"));

        horizontalLayout->addWidget(labelImmature);


        verticalLayout->addLayout(horizontalLayout);

        line_4 = new QFrame(TopInfoArea);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);


        horizontalLayout_5->addLayout(verticalLayout);

        line_2 = new QFrame(TopInfoArea);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelTotalText = new QLabel(TopInfoArea);
        labelTotalText->setObjectName(QStringLiteral("labelTotalText"));

        verticalLayout_3->addWidget(labelTotalText);

        labelTotal = new QLabel(TopInfoArea);
        labelTotal->setObjectName(QStringLiteral("labelTotal"));
        labelTotal->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelTotal);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_4);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        frameChartMarket = new QFrame(TopInfoArea);
        frameChartMarket->setObjectName(QStringLiteral("frameChartMarket"));
        frameChartMarket->setFrameShape(QFrame::StyledPanel);
        frameChartMarket->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frameChartMarket);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 6, 9);
        line_6 = new QFrame(frameChartMarket);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_6);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, -1, 2, -1);
        label_17 = new QLabel(frameChartMarket);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(16777215, 30));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_17);

        frame = new QFrame(frameChartMarket);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(150, 50));
        frame->setBaseSize(QSize(150, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(frame);


        horizontalLayout_8->addLayout(verticalLayout_6);

        line_8 = new QFrame(frameChartMarket);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_8);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(9, 9, 9, 9);
        label_18 = new QLabel(frameChartMarket);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(150, 0));
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_18);

        label_23 = new QLabel(frameChartMarket);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFrameShape(QFrame::StyledPanel);
        label_23->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_23);

        label_19 = new QLabel(frameChartMarket);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_19);

        label_20 = new QLabel(frameChartMarket);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_20);

        label_21 = new QLabel(frameChartMarket);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_21);

        label_22 = new QLabel(frameChartMarket);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_22);


        horizontalLayout_8->addLayout(verticalLayout_5);


        horizontalLayout_7->addWidget(frameChartMarket);


        retranslateUi(TopInfoArea);

        QMetaObject::connectSlotsByName(TopInfoArea);
    } // setupUi

    void retranslateUi(QWidget *TopInfoArea)
    {
        TopInfoArea->setWindowTitle(QApplication::translate("TopInfoArea", "TopInfoArea", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("TopInfoArea", "Main Net", 0));
        label_3->setText(QApplication::translate("TopInfoArea", "Block Number", 0));
        label_4->setText(QApplication::translate("TopInfoArea", "Version: v0.12.1.5-0a64a77", 0));
        label_5->setText(QApplication::translate("TopInfoArea", "www.districts.io", 0));
        label_6->setText(QApplication::translate("TopInfoArea", "Build", 0));
        label_7->setText(QApplication::translate("TopInfoArea", "Address:", 0));
        label_8->setText(QApplication::translate("TopInfoArea", "1212316548789784", 0));
        labelAvailableText->setText(QApplication::translate("TopInfoArea", "Available:", 0));
        labelAvailable->setText(QApplication::translate("TopInfoArea", "00.000", 0));
        labelPendingText->setText(QApplication::translate("TopInfoArea", "Pending:", 0));
        labelPending->setText(QApplication::translate("TopInfoArea", "00.000", 0));
        labelImmatureText->setText(QApplication::translate("TopInfoArea", "Immature:", 0));
        labelImmature->setText(QApplication::translate("TopInfoArea", "00.000", 0));
        labelTotalText->setText(QApplication::translate("TopInfoArea", "TOTAL Balance :", 0));
        labelTotal->setText(QApplication::translate("TopInfoArea", "0.00 USD", 0));
        label_17->setText(QApplication::translate("TopInfoArea", "3DC Chart", 0));
        label_18->setText(QApplication::translate("TopInfoArea", "Market Price", 0));
        label_23->setText(QApplication::translate("TopInfoArea", "0.00 usd", 0));
        label_19->setText(QApplication::translate("TopInfoArea", "Exchange link", 0));
        label_20->setText(QApplication::translate("TopInfoArea", "Exchange link", 0));
        label_21->setText(QApplication::translate("TopInfoArea", "Exchange link", 0));
        label_22->setText(QApplication::translate("TopInfoArea", "Exchange link", 0));
    } // retranslateUi

};

namespace Ui {
    class TopInfoArea: public Ui_TopInfoArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPINFOAREA_H
