#include "widget.h"
#include "ui_widget.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsSimpleTextItem>
//#include <<QGraphics

#include <QFileDialog>
#include <QDebug>
#include <QWheelEvent>

#include <qmath.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_graphicsScene(new QGraphicsScene(this)),
    m_scale(0.3)
{
    ui->setupUi(this);

    m_graphicsView = ui->graphicsView;
    ui->graphicsView->setScene(m_graphicsScene);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView->setFrameShape(QFrame::NoFrame);
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);
    m_graphicsView->installEventFilter(this);

    // Prepare background check-board pattern
    QPixmap tilePixmap(200, 200);
    tilePixmap.fill(Qt::white);
    QPainter tilePainter(&tilePixmap);
    QColor color(222,222,222,222);
    tilePainter.fillRect(0, 0, 100, 100, color);
    tilePainter.fillRect(100, 100, 100, 100, color);
    tilePainter.end();
    m_graphicsView->setBackgroundBrush(tilePixmap);

    QGraphicsRectItem *rectItem1 = (new QGraphicsRectItem(0,0, 1920*m_scale, 1080*m_scale));
    QPen pen1(QColor("blue"));
    pen1.setWidth(3);
    rectItem1->setPen(pen1);
    rectItem1->setScale(1);
    rectItem1->setSelected(true);
    rectItem1->setActive(true);
    rectItem1->setEnabled(true);
    m_graphicsScene->addItem(rectItem1);

    QGraphicsRectItem *rectItem2 = (new QGraphicsRectItem(1920*m_scale,0, 1920*m_scale, 1080*m_scale));
    QPen pen2(QColor("red"));
    pen2.setWidth(3);
    rectItem2->setPen(pen2);
    rectItem2->setScale(1);
    rectItem2->setSelected(true);
    rectItem2->setActive(true);
    rectItem2->setEnabled(true);
    m_graphicsScene->addItem(rectItem2);

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_graphicsView)
    {
        qDebug() << "Widget::eventFilter";
        if (event->type() == QEvent::Wheel)
        {
            qDebug() << "event->type() == QEvent::Wheel";
            QWheelEvent * we = dynamic_cast<QWheelEvent *>(event);
            qDebug() << "we->delta() ：" << we->delta();
            qDebug() << "we->angleDelta()" << we->angleDelta();
            qDebug() << "we->pixelDelta()" << we->pixelDelta();
            qreal factor = qPow(1.1, we->delta() / 240.0);
            qDebug() << "factor = qPow(1.1, we->delta() / 240.0);" << qPow(1.1, we->delta() / 240.0);
            qreal currentScale = m_graphicsView->transform().m11();
            qDebug() << "currentScale=m_graphicsView->transform().m11()" << m_graphicsView->transform().m11();
            qreal newScale = currentScale * factor;
             qDebug() << "newScale = currentScale * factor;" << currentScale * factor;;
            qreal actualFactor = factor;
            // cap to 0.001 - 1000
            if (newScale > 1000)
                actualFactor = 1000./currentScale;
            else if (newScale < 0.001)
                actualFactor = 0.001/currentScale;
//            m_graphicsView->scale(actualFactor, actualFactor);
            qDebug() << "actualFactor" << actualFactor;
            m_graphicsScene->items().at(0)->setScale(actualFactor);
            m_graphicsScene->items().at(1)->setScale(actualFactor);
            event->accept();
            return true;
        }
    }

    return QWidget::eventFilter(watched, event);

}
