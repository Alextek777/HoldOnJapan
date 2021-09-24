#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QPixmap>
#include <QPainter>

#include <QKeyEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QtMath>

#include <QDebug>

#include "Defenitions.h"

struct Cell
{
  unsigned int backgroundId;
};

struct Camera
{
  unsigned int x, y;
  int size = 1;
};

class GameWindow : public QWidget
{
  Q_OBJECT
public:
  explicit GameWindow(QWidget* parent = nullptr);

  void drawCell(const unsigned int xPos, const unsigned int yPos);
  QPixmap getBackgroundPixmap(const unsigned int backgroundId);

protected:
  void paintEvent(QPaintEvent* event) override;
  void keyPressEvent(QKeyEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;

private:
  Cell gameMap[MAPHEIGHT][MAPWIDTH];
  Camera camera;
  QPoint mousePos;
  QPoint selected;
  unsigned int currentItemId = 0;

public slots:
  void setCurrentItemId(unsigned int id);

signals:
};

#endif  // GAMEWINDOW_H
