#include "jgraohicsitems.h"

#include <QPen>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QLabel>

#include "jgraphicsscene.h"

JGraphicsRectItem::JGraphicsRectItem(QGraphicsItem *parent):QGraphicsRectItem(parent),
    m_mouseButtonPressed(false),
    m_centerWidget(NULL),
    m_gridLayout(NULL)
{
    init();
}

JGraphicsRectItem::JGraphicsRectItem(const QRectF &rect, QGraphicsItem *parent):
    QGraphicsRectItem(rect, parent),
    m_mouseButtonPressed(false),
    m_centerWidget(NULL),
    m_gridLayout(NULL)
{
    init();
}

JGraphicsRectItem::JGraphicsRectItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):
    QGraphicsRectItem(x, y, w, h, parent),
    m_mouseButtonPressed(false),
    m_centerWidget(NULL),
    m_gridLayout(NULL)
{
    init();
}

void JGraphicsRectItem::init()
{
    m_centerWidget = new QGraphicsWidget(this);
    m_gridLayout = new QGraphicsGridLayout;
    m_centerWidget->setLayout(m_gridLayout);

    setPenBrush();
    // 可选择、可移动
    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void JGraphicsRectItem::setPenBrush()
{
    // 画笔 - 边框色
    QPen sp = pen();
    sp.setWidth(1);
    sp.setColor(Qt::red);
    m_selectPen = sp;

    QPen bp = pen();
    bp.setWidth(1);
    bp.setColor(Qt::gray);
    m_borderPen = bp;
    setPen(m_borderPen);

    // 画刷 - 背景色
    m_backgroundBrush = QBrush(QColor(0, 160, 230));
    setBrush(m_backgroundBrush);
}

void JGraphicsRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QStyleOptionGraphicsItem jOption;
    jOption.init(widget);
    if (option->state & QStyle::State_Selected)
        jOption.state = QStyle::State_None;

    QGraphicsRectItem::paint(painter, &jOption, widget);

    if (option->state & QStyle::State_Selected)
    {
        qreal itemPenWidth = pen().widthF();
        const qreal pad = itemPenWidth / 2;

        // 绘制选中边线
        painter->setPen(m_selectPen);
        painter->drawRect(boundingRect().adjusted(pad, pad, -pad, -pad));
    }
}

void JGraphicsRectItem::splitScreen(JGraphicsRectItem::SplitScreenMode mode)
{
    switch (mode)
    {
    case OneScreen:
    {
        QLabel *label = new QLabel(QString("JYDJYDJYD"));
        label->setAcceptDrops(true);
        QGraphicsProxyWidget *gProxyWidget = scene()->addWidget(label);
        gProxyWidget->setAcceptDrops(true);
        gProxyWidget->setAcceptedMouseButtons(Qt::LeftButton);
        gProxyWidget->setAcceptHoverEvents(true);
        m_gridLayout->addItem(gProxyWidget,0,0);
        gProxyWidget->show();
        break;
    }
    case FourSplit:
    {

        break;
    }
    case NineSplit:
    {

        break;
    }
    //...
    default:
        break;
    }

}

void JGraphicsRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_mouseButtonPressed = true;
    qDebug() << "-=-=-=JGraphicsRectItem::mousePressEvent=-=-=-";
}

void JGraphicsRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "JGraphicsRectItem::mouseMoveEvent";
    QGraphicsRectItem::mouseMoveEvent(event);
}

void JGraphicsRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mouseButtonPressed = false;
    qDebug() << "JGraphicsRectItem::mouseReleaseEvent";
    QGraphicsRectItem::mouseReleaseEvent(event);
}

void JGraphicsRectItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "JGraphicsRectItem::mouseDoubleClickEvent";
    QGraphicsRectItem::mouseDoubleClickEvent(event);
}


