#include "GraphicsScene.h"
#include "GraphicsState.h"
#include "AddLineState.h"
#include "AddEllipseState.h"
#include "AddRectangleState.h"

GraphicsScene::GraphicsScene(QObject* parent)
    : QGraphicsScene(parent)
    , m_state(new GraphicState)
{
    setBackgroundBrush(QBrush(Qt::white));
}

void GraphicsScene::SetMode(const Mode& mode)
{
    if(mode == Mode::DrawLine)
    {
        m_state.reset(new AddLineState(m_commands, m_item_pen, *this));
    }
    else if(mode == Mode::DrawRectangle)
    {
        m_state.reset(new AddRectangleState(m_commands, m_item_pen, *this));
    }
    else if(mode == Mode::DrawEllipse)
    {
        m_state.reset(new AddEllipseState(m_commands, m_item_pen, *this));
    }
}

void GraphicsScene::SetItemColor(const QColor& color)
{
    m_item_pen.setColor(color);
}

void GraphicsScene::SetItemBrush(const Qt::PenStyle& style)
{
    m_item_pen.setStyle(style);
}

void GraphicsScene::SetItemWidth(const int width)
{
    m_item_pen.setWidth(width);
}

void GraphicsScene::ReDo()
{
    m_commands.ReDo();
}

void GraphicsScene::UnDo()
{
    m_commands.UnDo();
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

void GraphicsScene::Clear()
{
    this->clear();
    m_commands.Clear();
}