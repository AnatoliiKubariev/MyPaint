#include "MyPaint.h"

MyPaint::MyPaint(QWidget* parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);

    m_ui.m_graphics_view->setScene(&m_scene);
}

MyPaint::~MyPaint()
{

}
