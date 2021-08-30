#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
  GameWindow* game = new GameWindow();
  game->resize(1200, 800);
  game->show();
}

MainWindow::~MainWindow()
{
}
