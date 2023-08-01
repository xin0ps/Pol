#include <iostream>
#include <vector>
using namespace std;


class Car
{
private:
	static int globalid;
	int id;
	int door = 0;
	float engine = 0;
	string color = "";
	string model = "";
	int horsePower = 0;
public:
	Car() = default;
	Car(int _door, float _engine, int _horsePower, const string _model, const string _color) :door(_door), engine(_engine), color(_color), model(_model), horsePower(_horsePower)
	{
		id = ++globalid;
	}
  virtual  void printInfo() const
    {
      cout << "Car Information:" << endl;
      cout << "ID: " << id << endl;
      cout << "Door: " << door << endl;
      cout << "Engine: " << engine << endl;
      cout << "Horsepower: " << horsePower << endl;
      cout << "Model: " << model << endl;
      cout << "Color: " << color << endl;
    }
};
int Car::globalid = 0;
class Manual : public Car
{
public:
    Manual() = default;
    Manual(int door, float engine, int horsePower, const string& model, const string& color)
        : Car(door, engine, horsePower, model, color)
    {
    }


};

class Automatic : public Car
{
public:
    Automatic() = default;
    Automatic(int door, float engine, int horsePower, const string& model, const string& color)
        : Car(door, engine, horsePower, model, color)
    {
    }
};

class Bmw : public Automatic
{
public:
    Bmw() = default;
    Bmw(int door, float engine, int horsePower, const string model, const string color)
        : Automatic(door, engine, horsePower, model, color)
    {
    }

    void printInfo() const
    {
        cout << "BMW - Automatic Car - "<<endl;
        Car::printInfo();
    }
};

class Vaz : public Manual
{
public:
    Vaz() = default;
    Vaz(int door, float engine, int horsePower, const string& model, const string& color)
        : Manual(door, engine, horsePower, model, color)
    {
    }

    void printInfo() const
    {
        cout << "VAZ - Manual Car - "<<endl;
        Car::printInfo();
    }
};


int main()
{
    vector<Car*> cars;

    Bmw* bmwCar = new Bmw(4, 3.0, 300, "M5", "Black");
    Vaz* vazCar = new Vaz(4, 1.6, 120, "2107", "Red");

    cars.push_back(bmwCar);
    cars.push_back(vazCar);

    for (const Car* car : cars) {
        car->printInfo();
        cout << endl;
    }

    for (Car* car : cars) {
        delete car;
    }

}
