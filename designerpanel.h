#ifndef DESIGNERPANEL_H
#define DESIGNERPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

#include "Defenitions.h"

class GameItem : public QPushButton
{
  Q_OBJECT
public:
  GameItem(int itemID = 0, QWidget* parent = nullptr);
  unsigned int getItemId();

private:
  int itemID;
};

class DesignerPanel : public QWidget
{
  Q_OBJECT
public:
  DesignerPanel(QWidget* parent = nullptr);

signals:
  void itemClicked(unsigned int val);

private:
  QGridLayout* layout;
};

#endif  // DESIGNERPANEL_H
