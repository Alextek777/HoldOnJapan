#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
  QDockWidget* dockPanel = new QDockWidget(this);
  designerPanel = new DesignerPanel(dockPanel);
  dockPanel->setWidget(designerPanel);
  addDockWidget(Qt::BottomDockWidgetArea, dockPanel);

  game = new GameWindow(this);
  setCentralWidget(game);

  connect(designerPanel, &DesignerPanel::itemClicked, game, &GameWindow::setCurrentItemId);

  resize(1200, 800);
}

MainWindow::~MainWindow()
{
}
