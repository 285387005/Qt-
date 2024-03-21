#ifndef MYCHARTVIEW_H
#define MYCHARTVIEW_H

#include <QObject>
#include <QChartView>
#include <QRubberBand>

QT_CHARTS_USE_NAMESPACE

class MyChartView : public QChartView
{
public:
    MyChartView(QChart *chart, QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

private:
    bool isLeftButtonClicking;

    int xOld;
    int yOld;
};

#endif // MYCHARTVIEW_H
