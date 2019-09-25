#ifndef JGRAPHICSVIEW_H
#define JGRAPHICSVIEW_H

#include <QGraphicsView>

class JGraphicsView : public QGraphicsView
{
public:
    enum BackgroundStyle
    {
        NoStyle,
        ColorGridStyle,
        BrushGridStyle,
        PureColorStyle
    };

    JGraphicsView(QWidget *parent = Q_NULLPTR);
    JGraphicsView(QGraphicsScene *scene, QWidget *parent = Q_NULLPTR);
    ~JGraphicsView();

    void init();
    void cleanItems();

    void setBackgroundStyle(BackgroundStyle style=NoStyle, QColor color=QColor(Qt::white));
    void setBackgroundTileWH(int wh);
    void setBackgroundScale(bool scale);

    void wheelEvent(QWheelEvent *event);
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    int m_tileWH;
    bool m_backgroundScale;

};

#endif // JGRAPHICSVIEW_H
