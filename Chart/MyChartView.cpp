#include "MyChartView.h"
#include <QDebug>

MyChartView::MyChartView(QChart *chart, QWidget *parent) :
    QChartView(chart, parent),
    isLeftButtonClicking(false),
    xOld(0), yOld(0)
{
    setRubberBand(QChartView::RectangleRubberBand);
}

void MyChartView::mousePressEvent(QMouseEvent *e)
{
    //左键按下
    if (e->button() & Qt::LeftButton) {
        isLeftButtonClicking = true;
    } else if (e->button() & Qt::RightButton) {
        //恢复缩放
        chart()->zoomReset();
    }

    QChartView::mousePressEvent(e);
}

void MyChartView::mouseMoveEvent(QMouseEvent *e)
{
    int x, y;
    //如果左键按下，拖动改变chart 的位置
    if (isLeftButtonClicking) {
        if (xOld == 0 && yOld == 0) {

        } else {
            x = e->x() - xOld;
            y = e->y() - yOld;
            chart()->scroll(-x, y);
        }

        xOld = e->x();
        yOld = e->y();

        return;
    }

    QChartView::mouseMoveEvent(e);
}

void MyChartView::mouseReleaseEvent(QMouseEvent *e)
{
    //鼠标左键释放
    if (isLeftButtonClicking) {
        xOld = yOld = 0;
        isLeftButtonClicking = false;
    }

    //禁止鼠标右键点击拖动
    if (!(e->button() & Qt::RightButton)) {
        QChartView::mouseReleaseEvent(e);
    }
}

void MyChartView::keyPressEvent(QKeyEvent *e)
{
    //键盘功能
    switch (e->key()) {
    case Qt::Key_Plus:  //键盘加放大 chart
        chart()->zoomIn();
        break;

    case Qt::Key_Minus: //键盘减缩小 chart
        chart()->zoomOut();
        break;

        //前后左右方向的移动
    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;

    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;

    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;

    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;

    default:
        QChartView::keyPressEvent(e);
        break;
    }
}
