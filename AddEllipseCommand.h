#pragma once

#include "GraphicsCommand.h"

#include <memory>

#include <QPen>
#include <QGraphicsItem>

class GraphicsScene;

class AddEllipseCommand: public GraphicsCommand
{
public:
    ~AddEllipseCommand();
    AddEllipseCommand(GraphicsScene& scene, QGraphicsEllipseItem* graphics_line);

    void ReDo() override;
    void UnDo() override;

private:
    GraphicsScene& m_scene;
    QRectF m_rectangle;
    QPen m_pen;

    QGraphicsEllipseItem* m_graphics_ellipse;
};