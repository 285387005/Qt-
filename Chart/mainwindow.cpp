#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    series = new QLineSeries();
    //开启openGL，但开启opengl 以后，工具提示工功能便没有了，有时间再解决这个问题
    //series->setUseOpenGL(true);

    //隐藏坐标可见
    series->setPointLabelsVisible(false);

    chart = new QChart();
    //添加线条
    chart->addSeries(series);
    //自动缩放
    chart->createDefaultAxes();
    //设置范围
    chart->axisY()->setRange(-10, 10);
    chart->axisX()->setRange(0, maxSize);
    //设置轴上字体
    chart->axisX()->setTitleText("Time/sec");
    chart->axisY()->setTitleText("Speed/m");
    //栅格不可见
    chart->axisX()->setGridLineVisible(false);
    chart->axisY()->setGridLineVisible(false);
    //隐藏图例
    chart->legend()->hide();
    //添加chart 入view
    chartView = new MyChartView(chart, this);
    ui->gridLayout->addWidget(chartView);
    //反走样
    chartView->setRenderHint(QPainter::Antialiasing);

    m_chart = new CollectionData();

    connect(m_chart, &CollectionData::sendSeries, this, &MainWindow::slotUpdate);

    connect(series, &QLineSeries::clicked, this, &MainWindow::keepCallout);
    connect(series, &QLineSeries::hovered, this, &MainWindow::tooltip);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotUpdate(QVector<QPointF> data)
{
    series->replace(data);
}

void MainWindow::wheelEvent(QWheelEvent *e)
{
    if (e->delta() > 0) {
        chart->zoom(1.1);
    } else {
        chart->zoom(10.0/11);
    }

    QWidget::wheelEvent(e);
}

//点击固定提示，最多保存3个
void MainWindow::keepCallout()
{
    m_callouts.append(m_tooltip);
    m_tooltip = new Callout(chart);

    if (m_callouts.count() > 3) {
        delete m_callouts.at(0);
        m_callouts.removeFirst();
    }
}

//工具提示
void MainWindow::tooltip(QPointF point, bool state)
{
    if (m_tooltip == 0)
        m_tooltip = new Callout(chart);

    if (state) {
        m_tooltip->setText(QString("X: %1 \nY: %2 ").arg(point.x()).arg(point.y()));
        m_tooltip->setAnchor(point);
        m_tooltip->setZValue(11);
        m_tooltip->updateGeometry();
        m_tooltip->show();
    } else {
        m_tooltip->hide();
    }
}
