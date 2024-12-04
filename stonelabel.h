#ifndef STONELABEL_H
#define STONELABEL_H
#include <QLabel>
class StoneLabel:public QLabel
{
    Q_OBJECT
public:
    StoneLabel(QWidget* parent,std::string mode="gemstone");
    void setMode(std::string mode);
    std::string getMode();
private:
    std::string mode;
    std::string color;
};

#endif // STONELABEL_H
