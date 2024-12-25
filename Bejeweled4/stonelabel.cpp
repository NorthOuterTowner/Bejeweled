#include "stonelabel.h"
#include<game.h>
#define upSpacer 80
#define leftSpacer 100
std::string StoneLabel::stoneMode = "gemstone";
StoneLabel::StoneLabel(QWidget* parent):QLabel(parent)
{
    this->row=0;
    this->col=0;
}





