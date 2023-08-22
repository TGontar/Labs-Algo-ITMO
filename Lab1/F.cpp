#include "iostream"
#include "string"

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Fridge {
    float milk;
    float meat;
    int cheese;
    int bread;

};

int main() {
    Fridge fridge1;
    fridge1.milk = 2.5;
    fridge1.meat = 5.4;
    fridge1.cheese = 9;
    fridge1.bread = 150;

    Fridge fridge2;
    fridge2 = {4.5, 110, 432, 2};

    cout << "How many pieces of bread do you want to put into fridge1?" << endl;
    int putbread;
    cin >> putbread;
    fridge1.bread += putbread;

    cout << "How many kilos of meat do you want to take from fridge2?" << endl;
    float takemeat;
    cin >> takemeat;
    fridge2.meat -= takemeat;

    cout << "How many liters of milk do you want to transfer from fridge1 to fridge2?" << endl;
    float transfermilk;
    cin >> transfermilk;
    fridge1.milk -= transfermilk;
    fridge2.milk += transfermilk;

    cout << "fridge1: " << fridge1.milk << " " << fridge1.meat << " "<< fridge1.cheese << " " << fridge1.bread << endl;
    cout << "fridge2: " << fridge2.milk << " " << fridge2.meat << " "<< fridge2.cheese << " " << fridge2.bread << endl;



    return 0;
}