#include "trackbars.h"
#include "ui_trackbars.h"
#include "qdir.h"
#include "QDebug"
#include "globals.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "cv.h"
#include "QHBoxLayout"
#include <QLabel>
#include <QFileDialog>
#include "mat_and_qimage.hpp"

Trackbars::Trackbars(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Trackbars)
{
    ui->setupUi(this);
}

Trackbars::~Trackbars()
{
    delete ui;
}

void Trackbars::on_horizontalSlider_5_valueChanged(int value)
{
    lowh=value;
    ui->label->setText(QString("%1%").arg(value));
}

void Trackbars::on_horizontalSlider_4_valueChanged(int value)
{
    highh=value;
    ui->label_2->setText(QString("%1%").arg(value));
}

void Trackbars::on_horizontalSlider_3_valueChanged(int value)
{
    lows=value;
    ui->label_3->setText(QString("%1%").arg(value));
}

void Trackbars::on_horizontalSlider_valueChanged(int value)
{
    highs=value;
    ui->label_4->setText(QString("%1%").arg(value));
}

void Trackbars::on_horizontalSlider_2_valueChanged(int value)
{
   lowv=value;
   ui->label_11->setText(QString("%1%").arg(value));
}

void Trackbars::on_horizontalSlider_6_valueChanged(int value)
{
    highv=value;
    ui->label_12->setText(QString("%1%").arg(value));
}


void Trackbars::on_pushButton_2_clicked() //CLOSE Button ✓
{
    close();
}


void Trackbars::on_pushButton_clicked()   //SAVE Button  ✓
{
    lowh  = ui->horizontalSlider_5->value();
    highh = ui->horizontalSlider_4->value();
    lows =  ui->horizontalSlider_3->value();
    highs = ui->horizontalSlider->value();
    lowv  = ui->horizontalSlider_2->value();
    highv = ui->horizontalSlider_6->value();
    QString str = QDir::homePath();
    str = str + "/HSV_THRESHOLD_VALUES.txt";
    //qDebug()<<str;
    QFile valueHSV(str);
    if(!valueHSV.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug() << "Cannot Open File for Writing"<<endl;
        return;
    }
    QTextStream HSV(&valueHSV);
    HSV <<lowh<<endl;
    HSV <<highh<<endl;
    HSV <<lows<<endl;
    HSV <<highs<<endl;
    HSV <<lowv<<endl;
    HSV <<highv<<endl;
}
void Trackbars::on_pushButton_3_clicked() //LOAD Button  ✓
    {
        QStringList list;
        QString str = QDir::homePath();
        str = str + "/HSV_THRESHOLD_VALUES.txt";
        QFile valueHSV(str);
        if(!valueHSV.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            qDebug() << "Cannot Open File for Reading"<<endl;
            return;
        }
        int S[6]; int i=0;
        QTextStream HSV(&valueHSV);
        while (!HSV.atEnd())
             HSV>>S[i++];
        lowh = S[0];
        highh = S[1];
        lows = S[2];
        highs = S[3];
        lowv = S[4];
        highv = S[5];

        ui->label->setText(QString("%1%").arg(S[0]));
        ui->label_2->setText(QString("%1%").arg(S[1]));
        ui->label_3->setText(QString("%1%").arg(S[2]));
        ui->label_4->setText(QString("%1%").arg(S[3]));
        ui->label_11->setText(QString("%1%").arg(S[4]));
        ui->label_12->setText(QString("%1%").arg(S[5]));

        ui->horizontalSlider_5->setValue(S[0]);
        ui->horizontalSlider_4->setValue(S[1]);
        ui->horizontalSlider_3->setValue(S[2]);
        ui->horizontalSlider->setValue(S[3]);
        ui->horizontalSlider_2->setValue(S[4]);
        ui->horizontalSlider_6->setValue(S[5]);
}
