#include "widget.h"
#include "ui_widget.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QGraphicsItemGroup>

#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QWheelEvent>
#include <QColorDialog>
#include <QRgb>
#include <QTransform>

#include <qmath.h>

#include "jgraphicsscene.h"
#include "jgraohicsitems.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_graphicsScene(new JGraphicsScene(this)),
    m_scale(0.3),
    m_color(QColor("#ffcce8cf"))
{
    ui->setupUi(this);

//    m_graphicsScene->setSelectionArea(0,0, 1920*m_scale*2, 1080*m_scale);
    m_graphicsScene->setSceneRect(0,0, 1920*m_scale*2, 1080*m_scale);
//    m_graphicsScene->setItemIndexMethod(QGraphicsScene::NoIndex);
//    m_graphicsScene;

    m_graphicsView = ui->graphicsView;
    ui->graphicsView->setScene(m_graphicsScene);
//    ui->graphicsView->setTransformationAnchor(QGraphicsView::QGraphicsView::AnchorViewCenter);
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
//    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
//    ui->graphicsView->setFrameShape(QFrame::NoFrame);
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);

    // Prepare background check-board pattern
    QPixmap tilePixmap(200, 200);
    tilePixmap.fill(Qt::white);
    QPainter tilePainter(&tilePixmap);
    QColor color(222,222,222,222);
    tilePainter.fillRect(0, 0, 100, 100, color);
    tilePainter.fillRect(100, 100, 100, 100, color);
    tilePainter.end();
    m_graphicsView->setBackgroundBrush(tilePixmap);
//    m_graphicsScene->setBackgroundBrush(tilePixmap);
//    m_graphicsView->setBackgroundTileWH(20);
//    m_graphicsView->setBackgroundStyle(JGraphicsView::BrushGridStyle, color);
//    m_graphicsView->setBackgroundScale(false);

    //背景块
//    auto pixmapItem = new QGraphicsPixmapItem(tilePixmap);
//    pixmapItem->setTransformationMode(Qt::SmoothTransformation);
//    m_imageItem = pixmapItem;
//    if (!m_imageItem) // failed to load
//        return;
//    m_imageItem->setCacheMode(QGraphicsItem::NoCache);
//    m_imageItem->setZValue(0);
//    //background item
//    m_backgroundItem = new QGraphicsRectItem(m_imageItem->boundingRect());
//    m_backgroundItem->setBrush(Qt::white);
//    m_backgroundItem->setPen(Qt::NoPen);
//    m_backgroundItem->setVisible(true);
//    m_backgroundItem->setZValue(-1);
//    //外边缘虚线
//    m_outlineItem = new QGraphicsRectItem(m_imageItem->boundingRect());
//    QPen outline(Qt::black, 1, Qt::DashLine);
//    outline.setCosmetic(true);
//    m_outlineItem->setPen(outline);
//    m_outlineItem->setBrush(Qt::NoBrush);
//    m_outlineItem->setVisible(true);
//    m_outlineItem->setZValue(1);
//    QGraphicsScene *s = m_graphicsView->scene();
//    s->addItem(m_backgroundItem);
//    s->addItem(m_imageItem);
//    s->addItem(m_outlineItem);

    //矩形
//    QGraphicsRectItem *rectItem1 = (new QGraphicsRectItem(0,0, 1920*m_scale, 1080*m_scale));
//    QPen pen1(QColor(Qt::blue));
//    pen1.setWidth(3);
//    rectItem1->setPen(pen1);
//    rectItem1->setScale(1);
//    rectItem1->setSelected(true);
//    rectItem1->setActive(true);
//    rectItem1->setEnabled(true);
//    rectItem1->setAcceptDrops(true);
//    rectItem1->setAcceptedMouseButtons(Qt::LeftButton);
//    rectItem1->setAcceptHoverEvents(true);
//    rectItem1->setAcceptTouchEvents(true);
//    rectItem1->setFocus(Qt::MouseFocusReason);
//    rectItem1->setFlags(QGraphicsItem::ItemIsSelectable);
//    m_graphicsScene->addItem(rectItem1);
//    QGraphicsRectItem *rectItem2 = (new QGraphicsRectItem(1920*m_scale,0, 1920*m_scale, 1080*m_scale));
//    QPen pen2(QColor(Qt::red));
//    pen2.setWidth(3);
//    rectItem2->setPen(pen2);
//    rectItem2->setScale(1);
//    rectItem2->setFlag(QGraphicsItem::ItemIsSelectable);
//    m_graphicsScene->addItem(rectItem2);
//    m_graphicsScene->setFocusItem(rectItem1);

    //椭圆
//    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(0,0, 1920*m_scale, 1080*m_scale);
//    QPen pen3(QColor(Qt::yellow));
//    pen3.setWidth(2);
//    pen3.setStyle(Qt::DashLine);
//    ellipseItem->setPen(pen3);
//    ellipseItem->setAcceptedMouseButtons(Qt::LeftButton);
//    m_graphicsScene->addItem(ellipseItem);

    //虚线分割
//    QGraphicsLineItem *lineItem = new QGraphicsLineItem(1920*m_scale, 1080*m_scale*0.5, 1920*m_scale*2, 1080*m_scale*0.5);
//    QPen pen4(QColor(Qt::red));
//    pen4.setWidth(1);
//    pen4.setStyle(Qt::DashLine);
//    lineItem->setPen(pen4);
//    m_graphicsScene->addItem(lineItem);
//    QGraphicsLineItem *lineItem2 = new QGraphicsLineItem(1920*m_scale*1.5, 0, 1920*m_scale*1.5, 1080*m_scale);
//    QPen pen5(QColor(Qt::red));
//    pen5.setWidth(1);
//    pen5.setStyle(Qt::DashLine);
//    lineItem2->setPen(pen5);
//    m_graphicsScene->addItem(lineItem2);

    //贝塞尔曲线路径
//    QPainterPath path;
//    path.addRect(20, 20, 60, 60);
//    path.moveTo(0, 0);
//    path.cubicTo(150, 0,  150, 150,  300, 300);
//    path.cubicTo(150, 300,  150, 150,  0, 0);
//    QGraphicsPathItem *pathItem = new QGraphicsPathItem(path);
//    m_graphicsScene->addItem(pathItem);

    //图片
//    QGraphicsPixmapItem *p  = new QGraphicsPixmapItem(QPixmap(":/C:/Users/86176/Desktop/1568944190(1).png"), rectItem1);
//    p->setScale(0.8);
//    p->setPos(0, 50);
//    m_graphicsScene->addItem(p);

    //三角（可画任意多边形）
//    QPolygon polygon;
//    polygon << QPoint(1920*m_scale,0) << QPoint(1920*m_scale+10,100) << QPoint(1920*m_scale+50,100);
//    QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem(polygon,rectItem2);
//    m_graphicsScene->addItem(polygonItem);

//    QGraphicsSimpleTextItem *simpleTextItem = new QGraphicsSimpleTextItem(QString("QGraphicsSimpleTextItem"), rectItem2);
//    simpleTextItem->setAcceptDrops(true);
//    simpleTextItem->setPos(1920*m_scale,150);
//    m_graphicsScene->addItem(simpleTextItem);

//    QGraphicsTextItem *textItem = new QGraphicsTextItem(QString("QGraphicsTextItem"), rectItem2);
//    textItem->setHtml(QString("www.baidu.com"));
//    textItem->setPos(1920*m_scale*1.5,150);
//    textItem->setFlags(QGraphicsItem::ItemIsSelectable);
//    m_graphicsScene->addItem(textItem);


    ui->treeWidget->setAcceptDrops(true);
    ui->treeWidget->setDragDropMode(QAbstractItemView::DragDrop);

    //甚用
//    QGraphicsWidget *gWgt = new QGraphicsWidget(textItem);
////    gWgt->grabMouse();//有Bug
//    gWgt->setGeometry(300,500,200,200);
//    m_graphicsScene->addItem(gWgt);

//    QPushButton *pb = new QPushButton("QGraphicsProxyWidget");
//    connect(pb, &QPushButton::clicked, [this](){
//        qDebug() << "QPushButton::clicked";
//        m_graphicsView->rotate(15);
//    });
//    QGraphicsProxyWidget *gPWgt = m_graphicsScene->addWidget(pb);
//    gPWgt->setAcceptHoverEvents(true);
//    gPWgt->setAcceptTouchEvents(true);
//    gPWgt->setActive(true);
//    gPWgt->setEnabled(true);
//    gPWgt->setSelected(true);
//    gPWgt->setVisible(true);
//    gPWgt->setAcceptedMouseButtons(Qt::LeftButton);
//    gPWgt->setGeometry(QRectF(500,500,300,300));
//    m_graphicsScene->addItem(gPWgt);

    connect(m_graphicsScene, &QGraphicsScene::focusItemChanged, [this](QGraphicsItem* a,QGraphicsItem* b,Qt::FocusReason r){
        qDebug() << "QGraphicsScene::focusItemChanged:" << a << b << r;
    });

//    connect(m_graphicsScene, &QGraphicsScene::changed, [this](/*QList<QRectF> &region*/){
//        qDebug() << "QGraphicsScene::changed:"  /*<<region*/;
//    });

    connect(m_graphicsScene, &QGraphicsScene::selectionChanged, [this](){
        if (m_graphicsScene->selectedItems().size() > 0)
            qDebug() << "QGraphicsScene::selectionChanged:" << m_graphicsScene->selectedItems();
        else
            qDebug() << "QGraphicsScene::selectionChanged:No Selection!";
    });

    m_j = new JGraphicsRectItem(1920*m_scale*0.25,0,1920*m_scale,1080*m_scale);
    m_graphicsScene->addItem(m_j);
    m_j->setGraphicsView(ui->graphicsView);
    m_j->splitScreen(JGraphicsRectItem::OneScreen);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb_clean_clicked()
{
    m_graphicsView->cleanItems();
}

void Widget::on_pb_set_clicked()
{
    m_graphicsView->setBackgroundScale((bool)ui->cb_scale->currentIndex());
    m_graphicsView->setBackgroundTileWH(ui->lineEdit->text().toInt());
    m_graphicsView->setBackgroundStyle((JGraphicsView::BackgroundStyle)ui->cb_style->currentIndex(), m_color);
}

void Widget::on_toolButton_color_clicked()
{
    m_color = QColorDialog::getColor();
    QString str(QString("background:#%1").arg(QString::number(m_color.rgba(), 16)));
    qDebug() << str;
    ui->toolButton_color->setStyleSheet(str);
}

void Widget::on_pb_resert_clicked()
{
    m_graphicsView->resetTransform();
}

void Widget::on_pb_fit_clicked()
{
    m_graphicsView->fitInView(QRectF(0,0,(1920*2)*m_scale,(1080*2)*m_scale), Qt::KeepAspectRatio);
}

void Widget::on_pushButton_clicked()
{
    if (ui->cb_scale->currentIndex() == 0)
        m_graphicsView->rotate(-15);
    else
        m_graphicsView->rotate(15);
}

void Widget::on_pb_1_clicked()
{
    m_j->splitScreen(JGraphicsRectItem::OneScreen);
}

void Widget::on_pb_4_clicked()
{
    m_j->splitScreen(JGraphicsRectItem::FourSplit);
}

void Widget::on_pb_9_clicked()
{
    m_j->splitScreen(JGraphicsRectItem::NineSplit);
}

void Widget::on_pushButton_6_clicked()
{
    m_j->testPlay();
}
