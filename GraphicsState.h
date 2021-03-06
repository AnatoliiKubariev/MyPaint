#pragma once

class GraphicsScene;
class UndoRedoStack;
class QGraphicsSceneMouseEvent;

class GraphicState
{
public:
    virtual ~GraphicState() {};

    virtual void MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event) {}
    virtual void MouseMoveEvent(const QGraphicsSceneMouseEvent* mouse_event) {}
    virtual void MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event) {}
};