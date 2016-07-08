#include "MyPaint.h"

MyPaint::MyPaint(QWidget* parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);

    m_ui.m_graphics_view->setScene(&m_scene);

    connect(m_ui.m_color_push_button, &QPushButton::pressed, this, &MyPaint::SetColor);

    InitializeUndoRedo();

    InitializeBrushBox();
    connect(m_ui.m_brush_combo_box, static_cast<void (QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged),
            this, &MyPaint::SetBrush);
    InitializeWidthBox();
    connect(m_ui.m_width_combo_box, static_cast<void (QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged),
            this, &MyPaint::SetWidth);
}

void MyPaint::InitializeBrushBox()
{
    const std::vector<int> brush_numbers = {1, 2, 3, 4, 5}; //Qt::SolidLine values
    for(auto i : brush_numbers)
    {
        m_ui.m_brush_combo_box->insertItem(i, QString::number(i));
    }
    m_ui.m_brush_combo_box->setCurrentText(QString::number(brush_numbers[0])); //NoPen
}

void MyPaint::InitializeWidthBox()
{
    const int min_width = 1;
    const int max_width = 10;
    for(auto i = min_width; i <= max_width; ++i)
    {
        m_ui.m_width_combo_box->insertItem(i, QString::number(i));
    }
    m_ui.m_width_combo_box->setCurrentText(QString::number(min_width));
}

void MyPaint::InitializeUndoRedo()
{
    QAction* undo_action = new QAction(this);
    undo_action->setShortcut(QKeySequence::Undo);
    connect(undo_action, &QAction::triggered, &m_scene, &GraphicsScene::UnDo);
    addAction(undo_action);
    QAction* redo_action = new QAction(this);
    redo_action->setShortcut(QKeySequence::Redo);
    connect(redo_action, &QAction::triggered, &m_scene, &GraphicsScene::ReDo);
    addAction(redo_action);
}

void MyPaint::SetColor()
{
    QColorDialog color_dialog;
    m_scene.SetItemColor(color_dialog.getColor());
}

void MyPaint::SetBrush(const QString& brush_name)
{
    m_scene.SetItemBrush(Qt::PenStyle(brush_name.toInt()));
}

void MyPaint::SetWidth(const QString& width)
{
    m_scene.SetItemWidth(width.toInt());
}