#ifndef BUILDING_H
#define BUILDING_H


#include "Image.h"
#include <vector>
using namespace std;
class Building
{
protected:
    float base_price;
    float hole_area;
    QString address;
    float price;
    Image* picture;
public:
    Building();
    virtual ~ Building();
    Building(float _base_price, float _hole_area, QString add, Image* _image_address);
    virtual void calculate_value() = 0;
    float Price();
};

class Villa :public Building {
protected:
    float built_area;
    int rooms;//number of rooms
public:

};

class Northern_villa :public Villa {
protected:
    float front_yard_area;
    float back_yard_area;
public:

};

class Southern_villa :public Villa {
protected:
    float yard_area;
    float parking_area;
public:

};
class House {
protected:
    int floor_number;
    int houseID;
    int rooms;
    float built_area;
    Image *image;
public:
    House(int floor_number, int _houseID, int _rooms, float _built_area, Image* _image);
};
class Apartment :public Building {
protected:
    bool elevator;
    int floors;
    vector<House> houses;
public:
    Apartment(float _base_price, float _hole_area, QString add, Image* _image_address,bool ele, int _floors);
};


#endif // BUILDING_H
