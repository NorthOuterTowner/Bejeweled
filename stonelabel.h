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
    int getType();
    void setType(int);
private:
    std::string mode;
    int type;
};

#endif // STONELABEL_H
