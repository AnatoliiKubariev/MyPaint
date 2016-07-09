#pragma once

#include "GraphicsCommand.h"

#include <memory>

#include <QPen>
#include <QGraphicsItem>

class GraphicsScene;

class AddLineCommand: public GraphicsCommand
{
public:
    ~AddLineCommand();
    AddLineCommand(GraphicsScene& scene, QGraphicsLineItem* graphics_line);

    void ReDo() override;
    void UnDo() override;

private:
    GraphicsScene& m_scene;
    QLineF m_line;
    QPen m_pen;

    QGraphicsLineItem* m_graphics_line;
};