#include "MyPaint.h"

MyPaint::MyPaint(QWidget* parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);

    m_ui.m_graphics_view->setScene(&m_scene);

    InitializeColorsBox();
    connect(m_ui.m_colors_combo_box, static_cast<void (QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged),
            &m_scene, &GraphicsScene::SetItemColor);
    InitializeWidthBox();
    connect(m_ui.m_width_combo_box, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            &m_scene, &GraphicsScene::SetItemWidth);
    InitializeBrushBox();
    connect(m_ui.m_brush_combo_box, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            &m_scene, &GraphicsScene::SetItemBrush);
}


void MyPaint::InitializeColorsBox()
{
    QStringList color_names = QColor::colorNames();

    for(auto i = 0; i < color_names.size(); ++i)
    {
        QColor color(color_names[i]);

        m_ui.m_colors_combo_box->insertItem(i, color_names[i]);
        m_ui.m_colors_combo_box->setItemData(i, color, Qt::DecorationRole);
    }
    m_ui.m_colors_combo_box->setCurrentText("black");
}

void MyPaint::InitializeBrushBox()
{
    const std::vector<int> brush_numbers = {1, 2, 3, 4, 5}; //Qt::SolidLine values
    for(auto i : brush_numbers)
    {
        m_ui.m_brush_combo_box->insertItem(i, QString::number(i));
    }
    m_ui.m_width_combo_box->setCurrentIndex(brush_numbers[0]); //NoPen
}

void MyPaint::InitializeWidthBox()
{
    const int min_width = 1;
    const int max_width = 10;
    for(auto i = min_width; i <= max_width; ++i)
    {
        m_ui.m_width_combo_box->insertItem(i, QString::number(i));
    }
    m_ui.m_width_combo_box->setCurrentIndex(min_width);
}
