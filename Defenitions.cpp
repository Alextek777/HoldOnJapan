#include "Defenitions.h"

QPixmap GameHelper::getPixmapByID(unsigned int itemID)
{
  QPixmap pixmap;
  switch (itemID)
  {
    case 0:
      pixmap.load(":/img/images/emptyCell.png");
      break;
    case 1:
      pixmap.load(":/img/images/grass.png");
      break;
    case 2:
      pixmap.load(":/img/images/tree1.png");
      break;
    case 3:
      pixmap.load(":/img/images/tree2.png");
      break;
    case 4:
      pixmap.load(":/img/images/tree3.png");
      break;
    case 5:
      pixmap.load(":/img/images/grassCube.png");
      break;
    case 6:
      pixmap.load(":/img/images/treeCube1.png");
      break;
    case 7:
      pixmap.load(":/img/images/house1.png");
      break;
    case 8:
      pixmap.load(":/img/images/GrassNoMargins.png");
      break;
    case 9:
      pixmap.load(":/img/images/towerWithGrass.png");
      break;
    default:
      pixmap.load(":/img/images/emptyCell.png");
      break;
  }
  return pixmap;
}
