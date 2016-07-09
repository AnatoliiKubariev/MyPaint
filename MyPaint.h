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
    void InitializePrimitiveBox();
    void InitializeBrushBox();
    void InitializeWidthBox();
    void InitializeToolBar();
    void InitializeUndoRedo();
    void SetPrimitive(const QString& primitiv_name);
    void SetColor();
    void SetBrush(const QString& brush_name);
    void SetWidth(const QString& width);
    void NewEvent();
    void OpenEvent();
    void SaveEvent();


    Ui::MyPaintClass m_ui;

    GraphicsScene m_scene;
    QColorDialog m_color_dialog;
};
