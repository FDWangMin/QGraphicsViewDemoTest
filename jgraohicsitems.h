#ifndef JGRAOHICSITEMS_H
#define JGRAOHICSITEMS_H

#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>
#include <QPen>
#include <QBrush>
#include <QGraphicsGridLayout>
#include <QGraphicsProxyWidget>

class JGraphicsRectItem : public QGraphicsRectItem
{
public:
    JGraphicsRectItem(QGraphicsItem *parent = Q_NULLPTR);
    JGraphicsRectItem(const QRectF &rect, QGraphicsItem *parent = Q_NULLPTR);
    JGraphicsRectItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = Q_NULLPTR);

    enum SplitScreenMode
    {
        //...
        OneScreen,
        FourSplit,
        NineSplit
        //...
    };

    enum
    {
        JydSplitType = UserType+1
    };

    void init();
    void setPenBrush();
    void splitScreen(SplitScreenMode mode);

    int type()
    {
        return JydSplitType;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    bool m_mouseButtonPressed;
    QPen m_selectPen;
    QPen m_borderPen;
    QBrush m_backgroundBrush;

    QGraphicsGridLayout *m_gridLayout;
    QGraphicsWidget *m_centerWidget;
    QMap<int, QGraphicsProxyWidget*> m_widgetsMap;
};

#endif // JGRAOHICSITEMS_H
