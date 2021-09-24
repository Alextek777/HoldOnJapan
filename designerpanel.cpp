#include "designerpanel.h"

GameItem::GameItem(int itemID, QWidget* parent) : QPushButton(parent)
{
  this->itemID = itemID;
  setFixedSize(50, 50);
  QPixmap pixmap = GameHelper::getPixmapByID(itemID);
  setIcon(pixmap);
  setIconSize(QSize(width() * 0.7, height() * 0.7));
}

unsigned int GameItem::getItemId()
{
  return itemID;
}

DesignerPanel::DesignerPanel(QWidget* parent) : QWidget(parent)
{
  layout = new QGridLayout(this);

  for (int i = 0; i < 10; i++)
  {
    GameItem* item = new GameItem(i, this);
    connect(item, &GameItem::clicked, this,
            [&]() { emit itemClicked(dynamic_cast<GameItem*>(sender())->getItemId()); });
    layout->addWidget(item, 0, i, Qt::AlignCenter);
  }

  setLayout(layout);
}
