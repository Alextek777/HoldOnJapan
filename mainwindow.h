#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>

#include "gamewindow.h"
#include "DesignerPanel.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private:
  GameWindow* game;
  DesignerPanel* designerPanel;
};
#endif  // MAINWINDOW_H
