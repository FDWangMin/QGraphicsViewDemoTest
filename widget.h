#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QPainter>
#include <QDebug>

namespace Ui {
class Widget;
}

class QGraphicsScene;
class QGraphicsView;
class QGraphicsItem;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;
    QGraphicsScene *m_graphicsScene;
    QGraphicsView *m_graphicsView;
    QList<QGraphicsItem *> m_itemList;

    qreal m_scale;
};

class Window_ViewPortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit Window_ViewPortWidget(QWidget *parent = 0)
    {

    }
protected:
    void paintEvent(QPaintEvent *e)
    {
        QPainter p(this);
        qDebug() << "---" << "window()->rect()" << p.window() << "Viewport->rect()" << p.viewport();
        p.setWindow(-50,-50,200,200);
//        p.setViewport(0,0,200,200);
        p.setViewTransformEnabled(false);
        p.setPen(QPen(QColor(Qt::black), 3));
        p.drawLine(0, 0, 100, 100);
        qDebug() << "===" << "window()->rect()" << p.window() << "Viewport->rect()" << p.viewport();
    }

};

#endif // WIDGET_H
