#include "GraphicsState.h"

#include "GraphicsCommand.h"
#include "GraphicsScene.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//AddLineState
///////////////////////////////////////////////////////////////////////////////////////////////////

AddLineState::AddLineState(std::stack<std::unique_ptr<GraphicsCommand>>& commands, 
                           GraphicsScene& scene)
    : m_commands(commands)
    , m_scene(scene)
{
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void AddLineState::MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    m_start = mouse_event->scenePos().toPoint();
    m_created = false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void AddLineState::MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event)
{
    m_end = mouse_event->scenePos().toPoint();
    m_created = true;

    AddsGraphicsCommand();
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void AddLineState::AddsGraphicsCommand()
{
    QGraphicsLineItem* line = new QGraphicsLineItem(m_start.x(), m_start.y(), m_end.x(), m_end.y());
    m_commands.push(std::make_unique<AddLineCommand>(m_scene, line));
}
///////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
////AddRectangleState
/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//void AddRectangleState::AddsGraphicsCommand()
//{
//
//}
//
//void AddRectangleState::MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event)
//{
//    m_start = mouse_event->scenePos().toPoint();
//    m_created = false;
//}
//
//void AddRectangleState::MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event)
//{
//    m_end = mouse_event->scenePos().toPoint();
//    m_created = true;
//}
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
////AddEllipseState
/////////////////////////////////////////////////////////////////////////////////////////////////////
//
////QGraphicsItem* AddEllipseState::CreateQGraphicsItem()
////{
////    int hight = m_end.x() - m_start.x();
////    int width = m_end.y() - m_start.y();
////    QGraphicsEllipseItem* qgraphics_ellipse = new QGraphicsEllipseItem(m_start.x(), m_start.y(), hight, width);
////
////    return dynamic_cast<QGraphicsItem*>(qgraphics_ellipse);
////}
//
//void AddEllipseState::AddsGraphicsCommand()
//{
//
//}
//
//void AddEllipseState::MousePressEvent(const QGraphicsSceneMouseEvent* mouse_event)
//{
//    m_start = mouse_event->scenePos().toPoint();
//    m_created = false;
//}
//
//void AddEllipseState::MouseReleaseEvent(const QGraphicsSceneMouseEvent* mouse_event)
//{
//    m_end = mouse_event->scenePos().toPoint();
//    m_created = true;
//}