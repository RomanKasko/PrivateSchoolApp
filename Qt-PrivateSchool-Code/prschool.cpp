#include "prschool.h"

class PrSchoolData : public QSharedData
{
public:

};

PrSchool::PrSchool() : data(new PrSchoolData)
{

}

PrSchool::PrSchool(const PrSchool &rhs) : data(rhs.data)
{

}

PrSchool &PrSchool::operator=(const PrSchool &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

PrSchool::~PrSchool()
{

}
