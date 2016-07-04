#pragma once

#include "GraphicsCommand.h"

#include <stack>
#include <memory>

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>

class GraphicsScene;

class GraphicState
{
public:
    virtual ~GraphicState() = 0 {};

    virtual void MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event) {}
    virtual void MouseMoveEvent(const QGraphicsSceneMouseEvent* mouse_event) {}
    virtual void MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event) {}
};
///////////////////////////////////////////////////////////////////////////////////////////////////

class AddLineState: public GraphicState
{
public:
    ~AddLineState() {}
    AddLineState(std::stack<std::unique_ptr<GraphicsCommand>>& commands,
                 GraphicsScene& scene);

    void MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event) override;
    void MouseMoveEvent(const QGraphicsSceneMouseEvent* mouse_event) override;
    void MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event) override;

private:
    std::stack<std::unique_ptr<GraphicsCommand>>& m_commands;
    GraphicsScene& m_scene;
    QPoint m_start;
    QPoint m_end;

    QGraphicsLineItem* m_line;
};
///////////////////////////////////////////////////////////////////////////////////////////////////