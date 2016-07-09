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
    enum class Mode {DrawLine, DrawRectangle, DrawEllipse};

    GraphicsScene(QObject* parent = 0);

    void SetMode(const Mode& mode);

    void SetItemColor(const QColor& color);
    void SetItemBrush(const Qt::PenStyle& style);
    void SetItemWidth(const int width);

    void ReDo();
    void UnDo();

    void Clear();

private:
    void mousePressEvent(QGraphicsSceneMouseEvent* mouse_event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouse_event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse_event) override;

    UndoRedoStack m_commands;
    std::unique_ptr<GraphicState> m_state;
    QPen m_item_pen;
};
