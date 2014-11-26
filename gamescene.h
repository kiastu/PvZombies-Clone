#ifndef GAMESCENE_H
#define GAMESCENE_H

#include<QGraphicsScene>

//This class handles mouse click events for the graphicsview.
class GameScene: public QGraphicsScene
{
public:
    GameScene();
    GameScene( const QRectF & sceneRect, QObject * parent = 0 );
    virtual void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    virtual void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
};

#endif // GAMESCENE_H
