#include "GraphicsCommand.h"

#include "GraphicsScene.h"

#include <QGraphicsItem>

AddLineCommand::AddLineCommand(GraphicsScene& scene, QGraphicsItem* graphics_item)
    : m_scene(scene)
    , m_graphics_item(graphics_item)
{
    m_scene.addItem(m_graphics_item);
}

void AddLineCommand::UnDo()
{
    m_scene.removeItem(m_graphics_item); //
    std::unique_ptr<QGraphicsItem> item_holder(m_graphics_item);
}