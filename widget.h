#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QPainter>
#include <QDebug>

namespace Ui {
class Widget;
}

class JGraphicsScene;
class JGraphicsView;
class QGraphicsItem;
class QGraphicsPixmapItem;
class QGraphicsRectItem;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_pb_clean_clicked();

    void on_pb_set_clicked();

    void on_toolButton_color_clicked();

    void on_pb_resert_clicked();

    void on_pb_fit_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    JGraphicsScene *m_graphicsScene;
    JGraphicsView *m_graphicsView;
    QList<QGraphicsItem *> m_itemList;

    QGraphicsPixmapItem *m_imageItem;
    QGraphicsRectItem *m_backgroundItem;
    QGraphicsRectItem *m_outlineItem;

    qreal m_scale;
    QColor m_color;
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
