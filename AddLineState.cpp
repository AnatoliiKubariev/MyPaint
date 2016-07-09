#include "AddLineState.h"
#include "GraphicsScene.h"
#include "AddLineCommand.h"
#include "GraphicsCommand.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>

AddLineState::AddLineState(UndoRedoStack& commands,
                           QPen& pen,
                           GraphicsScene& scene)
    : m_commands(commands)
    , m_scene(scene)
    , m_pen(pen)
    , m_graphics_line(nullptr)
{
}

void AddLineState::MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    m_start = mouse_event->scenePos().toPoint();

    m_graphics_line = std::make_unique<QGraphicsLineItem>(m_start.x(), m_start.y(), m_start.x(), m_start.y());
    m_graphics_line->setPen(m_pen);

    m_scene.addItem(m_graphics_line.get());
}

void AddLineState::MouseMoveEvent(const QGraphicsSceneMouseEvent* mouse_event) //MouseMoveEvent call only after MousePressEvent
{
    if(!m_graphics_line)
    {
        return;
    }
    QPoint end = mouse_event->scenePos().toPoint();
    m_graphics_line->setLine(m_start.x(), m_start.y(), end.x(), end.y());
}

void AddLineState::MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    if(!m_graphics_line)
    {
        return;
    }
    auto temp_line_command = std::make_unique<AddLineCommand>(m_scene, std::move(m_graphics_line));
    m_commands.Register(std::move(temp_line_command));
}