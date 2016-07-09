#include "AddEllipseCommand.h"
#include "GraphicsScene.h"

#include <utility>

AddEllipseCommand::AddEllipseCommand(GraphicsScene& scene, std::unique_ptr<QGraphicsEllipseItem> graphics_line)
    : m_scene(scene)
    , m_rectangle(graphics_line->rect())
    , m_pen(graphics_line->pen())
    , m_graphics_ellipse(std::move(graphics_line))
{
}

void AddEllipseCommand::ReDo()
{
    if(m_graphics_ellipse)
    {
        return;
    }
    m_graphics_ellipse.reset(new QGraphicsEllipseItem(m_rectangle));
    m_graphics_ellipse->setPen(m_pen);
    m_scene.addItem(m_graphics_ellipse.get());
}

void AddEllipseCommand::UnDo()
{
    m_scene.removeItem(m_graphics_ellipse.get());
    m_graphics_ellipse.reset();
}