#pragma once

#include "GraphicsScene.h"

#include <QMainWindow>
#include "ui_MyPaint.h"

class MyPaint : public QMainWindow
{
    Q_OBJECT

public:
    MyPaint(QWidget *parent = 0);
    ~MyPaint();

private:
    Ui::MyPaintClass m_ui;

    GraphicsScene m_scene;
};
