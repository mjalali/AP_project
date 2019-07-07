#include "building.h"

Building::Building(){}
Building::Building(float _base_price, float _hole_area, QString add, Image* _image_address) {
    base_price = _base_price;
    hole_area = _hole_area;
    address = add;
    picture=_image_address;

}
float Building::Price() {
    return price;
}
Building::~ Building(){};
//////////////////house
House::House(int _floor_number, int _houseID, int _rooms, float _built_area, Image* _image) {
    floor_number = _floor_number;
    houseID = _houseID;
    rooms = _rooms;
    built_area = _built_area;
    image = _image;
}
/////////////////apartment
Apartment::Apartment(float _base_price, float _hole_area, QString add, Image* _image_address, bool ele, int _floors) :Building(_base_price,_hole_area,add, _image_address){
    elevator = ele;
    floors = _floors;
}
