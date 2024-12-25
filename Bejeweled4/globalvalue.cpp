#include "globalvalue.h"
#include "StoneLabel.h"
#include <vector>
#include <memory>
std::vector<std::vector<StoneLabel*>> stones(8,std::vector<StoneLabel*>(8));
int difficulty=6;
double volume=1.0;
std::vector<int> clickDistrict(4,0);
globalValue::globalValue() {}


