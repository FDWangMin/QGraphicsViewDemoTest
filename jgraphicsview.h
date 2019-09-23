#ifndef JGRAPHICSVIEW_H
#define JGRAPHICSVIEW_H

#include <QGraphicsView>

class JGraphicsView : public QGraphicsView
{
public:
    JGraphicsView(QWidget *parent = Q_NULLPTR);
    JGraphicsView(QGraphicsScene *scene, QWidget *parent = Q_NULLPTR);
    ~JGraphicsView();

    void init();

private:

};

#endif // JGRAPHICSVIEW_H
