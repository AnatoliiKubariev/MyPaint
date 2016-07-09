#include "AddLineCommand.h"
#include "GraphicsScene.h"

#include <utility>

AddLineCommand::~AddLineCommand()
{
}

AddLineCommand::AddLineCommand(GraphicsScene& scene, QGraphicsLineItem* graphics_line)
    : m_scene(scene)
    , m_line(graphics_line->line())
    , m_pen(graphics_line->pen())
    , m_graphics_line(graphics_line)
{
}

void AddLineCommand::ReDo()
{
    if(m_graphics_line)
    {
        return;
    }
    m_graphics_line = new QGraphicsLineItem(m_line);
    m_graphics_line->setPen(m_pen);
    m_scene.addItem(m_graphics_line);
}

void AddLineCommand::UnDo()
{
    m_scene.removeItem(m_graphics_line); // removeItem dont delete data - the ownership of item is passed on to the caller 
    std::unique_ptr<QGraphicsLineItem> to_del(m_graphics_line);
    m_graphics_line = nullptr;
}