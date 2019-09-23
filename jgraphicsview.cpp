#include "jgraphicsview.h"

JGraphicsView::JGraphicsView(QWidget *parent):QGraphicsView(parent)
{
    init();
}

JGraphicsView::JGraphicsView(QGraphicsScene *scene, QWidget *parent)
{
    init();
}

JGraphicsView::~JGraphicsView()
{

}

void JGraphicsView::init()
{
    setTransformationAnchor(QGraphicsView::QGraphicsView::AnchorViewCenter);
    setDragMode(QGraphicsView::RubberBandDrag);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setFrameShape(QFrame::NoFrame);
    setRenderHint(QPainter::SmoothPixmapTransform);
}
