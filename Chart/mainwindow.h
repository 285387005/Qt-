#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValueAxis>
#include <QTimer>
#include <QChart>
#include <QSplineSeries>
#include <QLineSeries>
#include <QVector>
#include <QtCharts>
#include "collectiondata.h"
#include "MyChartView.h"
#include "callout.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotUpdate(QVector<QPointF> data);
    void keepCallout();
    void tooltip(QPointF point, bool state);

protected:
    void wheelEvent(QWheelEvent *e);

private:
    Ui::MainWindow *ui;

    QList<uint16_t> intLine;//存储下位机采集到的数据，用于更新波形

    QLineSeries *series;
    QChart *chart;
    QValueAxis *axisY;
    QValueAxis *axisX;
    CollectionData *m_chart;
    MyChartView *chartView;
    Callout *m_tooltip = nullptr;
    QList<Callout *> m_callouts;
};

#endif // MAINWINDOW_H
