#include "collectiondata.h"
#include <QThread>
#include <QTimer>

CollectionData::CollectionData(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
    connect(this, &CollectionData::startInit, this, &CollectionData::slotStartInit);

    QThread *thread = new QThread();
    this->moveToThread(thread);
    thread->start();

    this->startInit();
}

void CollectionData::slotStartInit()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CollectionData::processData);
    timer->start(5);
}

void CollectionData::processData()
{
    data.append(QPointF(count , 10 * sin(M_PI * count * 4 / 180)));

    if (data.size() >= maxSize) {
        data.removeFirst();
        timer->stop();
    }
    //将所有点往x轴左移一个距离
    QVector<QPointF> _data;
    for(int x = 0; x < data.count(); x++) {
        _data.append(QPointF(x, data.at(x).y()));
    }

    count++;
    emit sendSeries(_data);
}
