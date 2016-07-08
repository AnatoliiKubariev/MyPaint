#pragma once

#include "GraphicsCommand.h"

#include <memory>

#include <QPen>
#include <QGraphicsItem>

class GraphicsScene;

class AddLineCommand: public GraphicsCommand
{
public:
    ~AddLineCommand() {}
    AddLineCommand(GraphicsScene& scene, std::unique_ptr<QGraphicsLineItem> graphics_line);

    void ReDo() override;
    void UnDo() override;

private:
    GraphicsScene& m_scene;
    QLineF m_line;
    QPen m_pen;

    std::unique_ptr<QGraphicsLineItem> m_graphics_line;
};