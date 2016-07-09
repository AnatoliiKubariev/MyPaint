#pragma once

#include "GraphicsState.h"

#include <memory>

#include <QGraphicsItem>

class QGraphicsSceneMouseEvent;
class QPen;
class UndoRedoStack;
class GraphicsScene;

class AddLineState: public GraphicState
{
public:
    ~AddLineState() {}
    AddLineState(UndoRedoStack& commands,
                 QPen& pen,
                 GraphicsScene& scene);

    void MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event) override;
    void MouseMoveEvent(const QGraphicsSceneMouseEvent* mouse_event) override;
    void MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event) override;

private:
    UndoRedoStack& m_commands;
    GraphicsScene& m_scene;
    QPoint m_start;
    QPen& m_pen;

    std::unique_ptr<QGraphicsLineItem> m_graphics_line;
};