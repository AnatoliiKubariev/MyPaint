#pragma once

#include "GraphicsState.h"
#include "GraphicsCommand.h"
#include "UndoRedoStack.h"

#include <memory>
#include <stack>

#include <QGraphicsScene>

class GraphicsScene: public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene(QObject* parent = 0);

    void SetItemColor(const QString& color_name);
    void SetItemBrush(const QString& style_value);
    void SetItemWidth(const QString& width);

    void ReDo();
    void UnDo();

private:
    void mousePressEvent(QGraphicsSceneMouseEvent* mouse_event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouse_event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse_event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* mouse_event) override {}

    std::unique_ptr<GraphicState> m_state;
    UndoRedoStack m_commands;

    QPen m_item_pen;
};
