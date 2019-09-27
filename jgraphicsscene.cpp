#include "jgraphicsscene.h"

#include <QEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

JGraphicsScene::JGraphicsScene(QObject *parent):QGraphicsScene(parent)
{

}

JGraphicsScene::JGraphicsScene(const QRectF &sceneRect, QObject *parent):
    QGraphicsScene(sceneRect, parent)
{

}

JGraphicsScene::JGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent):
    QGraphicsScene(x, y, width, height, parent)
{

}

bool JGraphicsScene::event(QEvent *event)
{
//    qDebug() << "JGraphicsScene::event(QEvent *event)" << event->type();
    return QGraphicsScene::event(event);
}

void JGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "===JGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)===\n"
             << event->button()
             << event->buttonDownPos(event->button())
             << event->buttonDownScenePos(event->button())
             << event->buttonDownScreenPos(event->button());

    QGraphicsScene::mousePressEvent(event);

    if (event->button() == Qt::LeftButton && items(event->scenePos()).count() > 0)
    {
        QGraphicsItem *selectItem = items(event->scenePos()).first();
        foreach (QGraphicsItem *item, selectedItems())
        {
            if (item == selectItem)
                continue;
            item->setSelected(false);
        }
        selectItem->setSelected(!selectItem->isSelected());
//        event->accept();
    }
}

void JGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter, rect);
}

void JGraphicsScene::drawForeground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawForeground(painter, rect);
}

void JGraphicsScene::drawItems(QPainter *painter, int numItems, QGraphicsItem *items[], const QStyleOptionGraphicsItem options[], QWidget *widget)
{
    QGraphicsScene::drawItems(painter, numItems, items, options, widget);
}
