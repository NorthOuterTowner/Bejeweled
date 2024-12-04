#include "stonelabel.h"

StoneLabel::StoneLabel(QWidget* parent,std::string mode):QLabel(parent)
{
    this->mode=mode;
}
void StoneLabel::setMode(std::string mode){
    this->mode=mode;
}
std::string StoneLabel::getMode(){
    return this->mode;
}
int StoneLabel::getType(){
    return this->type;
}
void StoneLabel::setType(int type){
    this->type=type;
}
