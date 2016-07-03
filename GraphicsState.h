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
    GraphicState() {}
    GraphicState(std::stack<std::unique_ptr<GraphicsCommand>>& commands,
                 GraphicsScene& scene) {}

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
    void MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event) override;

private:
    void AddsGraphicsCommand();

    std::stack<std::unique_ptr<GraphicsCommand>>& m_commands;
    GraphicsScene& m_scene;
    QPoint m_start;
    QPoint m_end;
    bool m_created = false;
};
///////////////////////////////////////////////////////////////////////////////////////////////////

//class AddRectangleState: public GraphicState
//{
//public:
//    ~AddRectangleState() {}
//    AddRectangleState(const std::stack<std::unique_ptr<GraphicsCommand>>& commands);
//
//    void MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event) override;
//    void MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event) override;
//
//private:
//    void AddsGraphicsCommand();
//
//    std::stack<std::unique_ptr<GraphicsCommand>>& m_commands;
//    QPoint m_start;
//    QPoint m_end;
//    bool m_created = false;
//};
/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//class AddEllipseState: public GraphicState
//{
//public:
//    ~AddEllipseState() {}
//    AddEllipseState(const std::stack<std::unique_ptr<GraphicsCommand>>& commands);
//
//    void MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event) override;
//    void MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event) override;
//
//private:
//    void AddsGraphicsCommand();
//
//    std::stack<std::unique_ptr<GraphicsCommand>>& m_commands;
//
//    QPoint m_start;
//    QPoint m_end;
//    bool m_created = false;
//};
/////////////////////////////////////////////////////////////////////////////////////////////////////