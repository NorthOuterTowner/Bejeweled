#ifndef STONELABEL_H
#define STONELABEL_H
#include <QLabel>
class StoneLabel:public QLabel
{
public:
    StoneLabel(QWidget* parent,std::string mode="gemstone");
    void setMode(std::string mode);
    std::string getMode();
private:
    std::string mode;
};

#endif // STONELABEL_H
