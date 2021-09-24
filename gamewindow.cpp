#include "gamewindow.h"

GameWindow::GameWindow(QWidget* parent) : QWidget(parent)
{
  setFocus();
  for (int i = 0; i < MAPHEIGHT; i++)
    for (int j = 0; j < MAPWIDTH; j++)
    {
      gameMap[i][j].backgroundId = 8;
    }
  camera.x = 5;
  camera.y = 1;

  setMouseTracking(true);
}

void GameWindow::drawCell(const unsigned int xPos, const unsigned int yPos)
{
}

void GameWindow::setCurrentItemId(unsigned int id)
{
  currentItemId = id;
}

QPixmap GameWindow::getBackgroundPixmap(const unsigned int backgroundId)
{
  GameHelper::getPixmapByID(backgroundId);
  return GameHelper::getPixmapByID(backgroundId);
}

void GameWindow::paintEvent(QPaintEvent* event)
{
  QPainter painter(this);

  for (int y = 0; y < MAPHEIGHT; y++)
    for (int x = 0; x < MAPWIDTH; x++)
    {
      QPixmap backgroundPixmap = getBackgroundPixmap(gameMap[y][x].backgroundId);

      backgroundPixmap =
          backgroundPixmap.scaled(backgroundPixmap.width() * camera.size, backgroundPixmap.height() * camera.size);

      unsigned int xBeg = camera.x * CELL_WIDTH * camera.size + (x - y) * (CELL_WIDTH * camera.size / 2);
      unsigned int yBeg = camera.y * CELL_HEIGHT * camera.size + (x + y) * (CELL_HEIGHT * camera.size / 2);

      painter.drawPixmap(xBeg, yBeg - ((backgroundPixmap.height() / CELL_HEIGHT - 1) * CELL_HEIGHT),
                         backgroundPixmap.width(), backgroundPixmap.height(), backgroundPixmap);
    }

  // position on screen squared coordinates 0,1,2,3...
  int cellX = mousePos.x() / CELL_WIDTH;
  int cellY = mousePos.y() / CELL_HEIGHT;

  // position in array GameMap
  selected.setX(mousePos.x() / CELL_WIDTH - camera.x + mousePos.y() / CELL_HEIGHT - camera.y);
  selected.setY(mousePos.y() / CELL_HEIGHT - camera.y - (mousePos.x() / CELL_WIDTH - camera.x));

  int cellLocalX = mousePos.x() % CELL_WIDTH;
  int cellLocalY = mousePos.y() % CELL_HEIGHT;

  int leftBoarder = (CELL_HEIGHT / 2 - cellLocalY) * 2;
  if (leftBoarder < 0)
    leftBoarder *= -1;
  int rightBoarder = CELL_WIDTH / 2 + CELL_WIDTH / 2 - leftBoarder;

  // position on screen in pixels
  int screenX = cellX * CELL_WIDTH;
  int screenY = cellY * CELL_HEIGHT;

  if (cellLocalY < (CELL_HEIGHT / 2))
  {
    if (cellLocalX < leftBoarder)
    {
      selected.setX(selected.x() - 1);
      screenX -= CELL_WIDTH / 2;
      screenY -= CELL_HEIGHT / 2;
    }
    else if (cellLocalX > rightBoarder)
    {
      selected.setY(selected.y() - 1);
      screenX += CELL_WIDTH / 2;
      screenY -= CELL_HEIGHT / 2;
    }
  }
  else if (cellLocalY > (CELL_HEIGHT / 2))
  {
    if (cellLocalX < leftBoarder)
    {
      selected.setY(selected.y() + 1);
      screenX -= CELL_WIDTH / 2;
      screenY += CELL_HEIGHT / 2;
    }
    else if (cellLocalX > rightBoarder)
    {
      selected.setX(selected.x() + 1);
      screenX += CELL_WIDTH / 2;
      screenY += CELL_HEIGHT / 2;
    };
  }

  qDebug() << "Selected x : " << selected.x() << " y : " << selected.y();
  // draw a rect
  if (selected.x() >= 0 && selected.y() >= 0 && selected.x() < MAPWIDTH && selected.y() < MAPHEIGHT)
    painter.drawRect(screenX, screenY, CELL_WIDTH, CELL_HEIGHT);
}
void GameWindow::keyPressEvent(QKeyEvent* event)
{
  switch (event->key())
  {
    case Qt::Key_A:
      camera.x += 1;
      break;
    case Qt::Key_S:
      camera.y -= 1;
      break;
    case Qt::Key_D:
      camera.x -= 1;
      break;
    case Qt::Key_W:
      camera.y += 1;
      break;
  }
  repaint();
}

void GameWindow::wheelEvent(QWheelEvent* event)
{
  if (camera.size <= 1 && event->angleDelta().y() < 0)
    camera.size = 1;
  else if (camera.size >= 3 && event->angleDelta().y() > 0)
    camera.size = 3;
  else if (event->angleDelta().y() > 0)
    camera.size += 1;
  else if (event->angleDelta().y() < 0)
    camera.size -= 1;

  repaint();
}

void GameWindow::mouseMoveEvent(QMouseEvent* event)
{
  setFocus();
  mousePos = event->pos();
  repaint();
}
void GameWindow::mousePressEvent(QMouseEvent* event)
{
  try
  {
    if (selected.x() >= MAPWIDTH || selected.x() < 0 || selected.y() >= MAPHEIGHT || selected.y() < 0)
      throw("out of range");
    if (event->button() == Qt::LeftButton)
      gameMap[selected.y()][selected.x()].backgroundId = currentItemId;
    else
      gameMap[selected.y()][selected.x()].backgroundId = 8;
  }
  catch (...)
  {
    qDebug() << "out of range";
  }

  repaint();
}
