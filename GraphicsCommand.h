#pragma once

#include <QPen>

class GraphicsScene;
class QGraphicsItem;

class GraphicsCommand
{
public:
    virtual ~GraphicsCommand() = 0 {}

    virtual void UnDo() = 0 {};
};

class AddLineCommand: public GraphicsCommand
{
public:
    ~AddLineCommand() {}
    AddLineCommand(GraphicsScene& scene, QGraphicsItem* graphics_item);

    void UnDo() override;

private:
    GraphicsScene& m_scene;
    QGraphicsItem* m_graphics_item;
};