#ifndef DEFENITIONS_H
#define DEFENITIONS_H

const unsigned int MAPWIDTH = 40;
const unsigned int MAPHEIGHT = 40;

const unsigned int CELL_WIDTH = 64;
const unsigned int CELL_HEIGHT = 32;

#include <QPixmap>

class GameHelper
{
public:
  static QPixmap getPixmapByID(unsigned int itemID);
};

#endif  // DEFENITIONS_H
