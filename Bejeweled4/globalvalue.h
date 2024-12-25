#ifndef GLOBALVALUE_H
#define GLOBALVALUE_H
#include <vector>
#include "stonelabel.h"
extern std::vector<std::vector<StoneLabel*>> stones;
extern int difficulty;
extern double volume;
extern std::vector<int> clickDistrict;

class globalValue
{
public:
    globalValue();
};

#endif // GLOBALVALUE_H
