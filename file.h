#ifndef FILE_H
#define FILE_H


#include "Date_Time.h"
#include <iostream>
#include "Building.h"
typedef enum {
    northern_villa =0,
    southern_villa =1,
    Apartment =2

}B_kind;
class File
{
protected:
    Building * my_building;
    B_kind building_kind;
    float commission;
    float final_cost;
public:
    File(B_kind _Building_kind, Building * _my_building);
    virtual void count_final_cost() = 0;
    float Final_cost();
    B_kind Building_kind();
    virtual~File();

};
class Rent:public File {
protected:
    float mortgage_cost;
    float rent_cost;
    Date* period;
public:
    Rent(B_kind _Building_kind, Building * _my_building, Date* _period);
//	float Mortgage_cost();
//	float Rent_cost();
    float Mortgage_cost() ;
    float Rent_cost() ;
};
class Sale:public File {
protected:
    QString detail;
public:
    Sale(B_kind _Building_kind, Building * _my_building, QString _detail);
    QString Detail();
};



#endif // FILE_H
