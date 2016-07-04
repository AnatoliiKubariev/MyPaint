#include "GraphicsScene.h"

GraphicsScene::GraphicsScene(QObject* parent)
    : QGraphicsScene(parent)
{
    m_state.reset(new AddLineState(m_commands, *this));
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


    m_commands.top()->Do();
}