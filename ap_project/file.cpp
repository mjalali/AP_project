#include "File.h"

File::File(B_kind _Building_kind, Building * _my_building) {
    building_kind = _Building_kind;
    my_building = _my_building;
}
float File::Final_cost() {
    return final_cost;
}
B_kind File::Building_kind() {
    return building_kind;
}
File::~File(){};
///////////////Rent:
Rent::Rent(B_kind _Building_kind, Building* _my_building, Date* _period) :File( _Building_kind, _my_building) {
    period = _period;
}

float Rent::Mortgage_cost() {
    mortgage_cost =(my_building-> Price())*((float)0.05);
    return mortgage_cost;
}
float Rent::Rent_cost() {
    rent_cost = my_building->Price()*((float)0.01);
    return rent_cost;
}
///////////////
Sale::Sale(B_kind _Building_kind, Building * _my_building, QString _detail) :File(_Building_kind,_my_building) {
    detail = _detail;
}
QString Sale::Detail() {
    return detail;
}
