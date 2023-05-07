#ifndef SINSIGNAL_H
#define SINSIGNAL_H


#include <QMainWindow>
#include <qcustomplot.h>
#include <cmath>
#include <QMainWindow>
#include <QDialog>
#include<QString>
#include <QtCore>
#include <QtGui>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class SINSIGNAL; }
QT_END_NAMESPACE

class SINSIGNAL : public QMainWindow
{
    Q_OBJECT

public:
    SINSIGNAL(QWidget *parent = nullptr);
    ~SINSIGNAL();

private slots:
    void on_vihod_clicked();

    void on_pushButton_clicked();

    void on_doubleSpinBox_valueChanged(const QString &arg1);

    void on_doubleSpinBox_2_valueChanged(const QString &arg1);

    void on_doubleSpinBox_3_valueChanged(const QString &arg1);

    void on_doubleSpinBox_4_valueChanged(const QString &arg1);


    void on_obnv_clicked();

private:
    Ui::SINSIGNAL *ui;
};
#endif // SINSIGNAL_H
