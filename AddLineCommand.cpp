#include "AddLineCommand.h"
#include "GraphicsScene.h"

#include <utility>

AddLineCommand::AddLineCommand(GraphicsScene& scene, std::unique_ptr<QGraphicsLineItem> graphics_line)
    : m_scene(scene)
    , m_line(graphics_line->line())
    , m_pen(graphics_line->pen())
    , m_graphics_line(std::move(graphics_line))
{
}

void AddLineCommand::ReDo()
{
    if(m_graphics_line)
    {
        return;
    }
    m_graphics_line.reset(new QGraphicsLineItem(m_line));
    m_graphics_line->setPen(m_pen);
    m_scene.addItem(m_graphics_line.get());
}

void AddLineCommand::UnDo()
{
    m_scene.removeItem(m_graphics_line.get()); //
    m_graphics_line.reset();
}