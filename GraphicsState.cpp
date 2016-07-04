#include "GraphicsState.h"

#include "GraphicsCommand.h"
#include "GraphicsScene.h"

AddLineState::AddLineState(std::stack<std::unique_ptr<GraphicsCommand>>& commands, 
                           QPen& pen,
                           GraphicsScene& scene)
    : m_commands(commands)
    , m_scene(scene)
    , m_pen(pen)
{
}

void AddLineState::MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    m_start = mouse_event->scenePos().toPoint();

    m_line = new QGraphicsLineItem(m_start.x(), m_start.y(), m_start.x(), m_start.y());
    m_line->setPen(m_pen);

    m_commands.push(std::make_unique<AddLineCommand>(m_scene, m_line));
}

void AddLineState::MouseMoveEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    QPoint end = mouse_event->scenePos().toPoint();
    m_line->setLine(m_start.x(), m_start.y(), end.x(), end.y());
}

void AddLineState::MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event)
{

}