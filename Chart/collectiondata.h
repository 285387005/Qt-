#ifndef COLLECTIONDATA_H
#define COLLECTIONDATA_H

#include <QObject>
#include <QVector>
#include <QPointF>

class QTimer;

const int maxValue =1000;//波形数据中的最大值，后面程序会根据波形大小调整
const int maxSize=500;//波形存储数据个数上限

class CollectionData : public QObject
{
    Q_OBJECT
public:
    explicit CollectionData(QObject *parent = nullptr);

signals:
    void startInit();
    void sendSeries(QVector<QPointF>);

public slots:
    void slotStartInit();
    void processData();

private:
    QTimer *timer;
    QVector<QPointF> data;
    QVector<QPointF> data2;
    quint16 count = 0;
};

#endif // COLLECTIONDATA_H
