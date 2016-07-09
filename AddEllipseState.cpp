#include "AddEllipseState.h"
#include "GraphicsScene.h"
#include "AddEllipseCommand.h"
#include "GraphicsCommand.h"
#include "Utils.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>

AddEllipseState::~AddEllipseState()
{
}

AddEllipseState::AddEllipseState(UndoRedoStack& commands,
                                 QPen& pen,
                                 GraphicsScene& scene)
    : m_commands(commands)
    , m_scene(scene)
    , m_pen(pen)
    , m_graphics_ellipse(nullptr)
{
}

void AddEllipseState::MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    m_start = mouse_event->scenePos().toPoint();

    m_graphics_ellipse = std::make_unique<QGraphicsEllipseItem>(m_start.x(), m_start.y(), m_start.x(), m_start.y());
    m_graphics_ellipse->setPen(m_pen);

    m_scene.addItem(m_graphics_ellipse.get());
}

void AddEllipseState::MouseMoveEvent(const QGraphicsSceneMouseEvent* mouse_event) //MouseMoveEvent call only after MousePressEvent
{
    if(!m_graphics_ellipse)
    {
        return;
    }
    QPoint end = mouse_event->scenePos().toPoint();
    m_graphics_ellipse->setRect(CalculateRectangle(m_start, end));
}

void AddEllipseState::MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    if(!m_graphics_ellipse)
    {
        return;
    }
    auto temp_rectangle_command = std::make_unique<AddEllipseCommand>(m_scene, m_graphics_ellipse.release());
    m_commands.Register(std::move(temp_rectangle_command));
}