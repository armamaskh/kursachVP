#include "sinsignal.h"
#include "ui_sinsignal.h"
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include <QIntValidator>

SINSIGNAL::SINSIGNAL(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SINSIGNAL)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator( new QIntValidator(0, 10000, this) );
    ui->statusbar->showMessage("ВВЕДИТЕ ВЕРВОНОЧАЛЬНУЮ ДЛИННУ ВОЛНЫ");
}

SINSIGNAL::~SINSIGNAL()
{
    delete ui;
}


void SINSIGNAL::on_vihod_clicked()
{
    ui->statusbar->showMessage("ДО СКОРОЙ ВСТРЕЧИ!");
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Выход из приложения.","Вы уверены, что хотите выйти из приложения?");
    if(reply == QMessageBox::Yes) {
        QApplication::quit();
    }
    else
    qDebug("/q");
    ui->statusbar->showMessage(" ");
}


void SINSIGNAL::on_pushButton_clicked()
{
    ui->statusbar->showMessage(" ");
    double dl =  ui->doubleSpinBox_4->value();
    double a = 0;
    double b = ui->lineEdit->text().toDouble();
    double h = 0.01;
    int N = (b+dl - a) / h + 2;
    double amp = ui->doubleSpinBox->value();
    double chas =  ui->doubleSpinBox_2->value();
    double fsdvig =  ui->doubleSpinBox_3->value();
    QVector<double> x(N), y(N);
    int i=0;

    for (double X = a; X <= b+dl; X += h) {
      x[i] = X + fsdvig ;
      y[i] = amp  * sin(chas * X + fsdvig );
      i++;
    }
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    ui->widget->xAxis->setLabel("X");
    ui->widget->yAxis->setLabel("Y");

    ui->widget->xAxis->setRange(-3, b+dl+10);


    double minY = y[0], maxY = y[0];
    for (int i = 1; i < N; i++) {
      if (y[i] < minY) minY = y[i];
      if (y[i] > maxY) maxY = y[i];
    }
    if ((maxY < 7 && maxY > -7) && (minY < 7 && minY > -7))
        ui->widget->yAxis->setRange(-7, 7);
    else
        ui->widget->yAxis->setRange(minY, maxY);

    ui->widget->replot();
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
}


void SINSIGNAL::on_doubleSpinBox_valueChanged(const QString &arg1)
{on_pushButton_clicked();}
void SINSIGNAL::on_doubleSpinBox_2_valueChanged(const QString &arg1)
{on_pushButton_clicked();}
void SINSIGNAL::on_doubleSpinBox_3_valueChanged(const QString &arg1)
{on_pushButton_clicked();}
void SINSIGNAL::on_doubleSpinBox_4_valueChanged(const QString &arg1)
{on_pushButton_clicked();}


void SINSIGNAL::on_obnv_clicked()
{
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    qApp->quit();
}




