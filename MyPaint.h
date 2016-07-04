#pragma once

#include "GraphicsScene.h"

#include <QColorDialog>
#include <QMainWindow>
#include "ui_MyPaint.h"

class MyPaint: public QMainWindow
{
    Q_OBJECT

public:
    MyPaint(QWidget *parent = 0);

private:
    void InitializeColorsBox();
    void InitializeBrushBox();
    void InitializeWidthBox();

    Ui::MyPaintClass m_ui;

    GraphicsScene m_scene;
    QColorDialog m_color_dialog;
};
