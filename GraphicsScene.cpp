#include "GraphicsScene.h"

GraphicsScene::GraphicsScene(QObject* parent)
    : QGraphicsScene(parent)
{
    m_state.reset(new AddLineState(m_commands, m_item_pen, *this));
}

void GraphicsScene::SetItemColor(const QString& color_name)
{
    m_item_pen.setColor(QColor(color_name));
}

void GraphicsScene::SetItemBrush(const int style_value)
{
    m_item_pen.setStyle(Qt::PenStyle(style_value));
}

void GraphicsScene::SetItemWidth(const int width)
{
    m_item_pen.setWidth(width);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* mouse_event)
{
    m_state->MousePressEvent(mouse_event);
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent* mouse_event)
{
    m_state->MouseMoveEvent(mouse_event);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse_event)
{
    m_state->MouseReleaseEvent(mouse_event);
}