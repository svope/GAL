#ifndef NODE_H
#define NODE_H

#include <QGraphicsEllipseItem>
#include <QList>

class Edge;

class Node : public QGraphicsEllipseItem
{
public:
    enum { Type = UserType + 15 };
    Node(QGraphicsItem *parent = 0);

    void removeEdge(Edge *edge);
    void removeEdges();
    QRectF rec() const { return rectangle; }
    void addEdge(Edge *edge);
    int type() const { return Type;}
    QRectF boundingRect() const;
    QPainterPath shape() const;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
    QRectF rectangle;
    QList<Edge *> edges;
};

#endif // NODE_H
