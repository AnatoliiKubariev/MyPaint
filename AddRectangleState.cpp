#include "AddRectangleState.h"
#include "GraphicsScene.h"
#include "AddRectangleCommand.h"
#include "GraphicsCommand.h"
#include "Utils.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>

AddRectangleState::AddRectangleState(UndoRedoStack& commands,
                                     QPen& pen,
                                     GraphicsScene& scene)
    : m_commands(commands)
    , m_scene(scene)
    , m_pen(pen)
    , m_graphics_rectangle(nullptr)
{
}

void AddRectangleState::MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    m_start = mouse_event->scenePos().toPoint();

    m_graphics_rectangle = std::make_unique<QGraphicsRectItem>(m_start.x(), m_start.y(), m_start.x(), m_start.y());
    m_graphics_rectangle->setPen(m_pen);

    m_scene.addItem(m_graphics_rectangle.get());
}

void AddRectangleState::MouseMoveEvent(const QGraphicsSceneMouseEvent* mouse_event) //MouseMoveEvent call only after MousePressEvent
{
    if(!m_graphics_rectangle)
    {
        return;
    }
    QPoint end = mouse_event->scenePos().toPoint();
    m_graphics_rectangle->setRect(CalculateRectangle(m_start, end));
}

void AddRectangleState::MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    if(!m_graphics_rectangle)
    {
        return;
    }
    auto temp_rectangle_command = std::make_unique<AddRectangleCommand>(m_scene, std::move(m_graphics_rectangle));
    m_commands.Register(std::move(temp_rectangle_command));
}