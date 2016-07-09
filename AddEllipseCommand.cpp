#include "AddEllipseCommand.h"
#include "GraphicsScene.h"

#include <utility>

AddEllipseCommand::~AddEllipseCommand()
{
}

AddEllipseCommand::AddEllipseCommand(GraphicsScene& scene, QGraphicsEllipseItem* graphics_line)
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
    m_graphics_ellipse = new QGraphicsEllipseItem(m_rectangle);
    m_graphics_ellipse->setPen(m_pen);
    m_scene.addItem(m_graphics_ellipse);
}

void AddEllipseCommand::UnDo()
{
    m_scene.removeItem(m_graphics_ellipse); // removeItem dont delete data - the ownership of item is passed on to the caller 
    std::unique_ptr<QGraphicsEllipseItem> to_del(m_graphics_ellipse);
    m_graphics_ellipse = nullptr;
}
