#include <iostream>

using namespace std;

/**
 * This is class Product
 * it has a constructor with parameters, so
 * every class that extends Product must call its constructor
 * */
class Product {
private:
    string name;
    double quantity;
    string unit;
    double price;

public:

    //constructor with parameters
    Product(string name, double quantity, string unit, double price) {
        this->name = name;
        this->quantity = quantity;
        this->unit = unit;
        this->price = price;
    }


    string getName() {
        return name;
    }

    void setName(string name) {
        Product::name = name;
    }

    double getQuantity() {
        return quantity;
    }

    void setQuantity(double quantity) {
        Product::quantity = quantity;
    }

    string getUnit() {
        return unit;
    }

    void setUnit(string unit) {
        Product::unit = unit;
    }

    double getPrice() {
        return price;
    }

    void setPrice(double price) {
        Product::price = price;
    }

    void printInfo() const {
        cout << name << " " << quantity << " " << unit << " price: " << price << endl;
    }
};


/*
 * class Beverage extends class Product
 * it must call the constructor of Product
 * */
class Beverage : public Product {
private:
    double alcoholPercentage;

public:

    /*
     * constructor of Beverage - it has parameters that will be passed to the Product constructor
     * and one parameter (alcoholPercentage) for a field in the Beverage class
     * */
    Beverage(string name, double quantity, string unit, double price, double alcoholPercentage) : Product(
            name, quantity, unit, price) {
        this->alcoholPercentage = alcoholPercentage;
    }

    double getAlcoholPercentage() {
        return alcoholPercentage;
    }

    void setAlcoholPercentage(double alcoholPercentage) {
        Beverage::alcoholPercentage = alcoholPercentage;
    }

    /*
     * This method overrides the printInfo method from Product,
     * when a Beverage object is created and printInfo method
     * is called, the printInfo from Beverage will be called.
     * */
    void printInfo() const {
        cout << "beverage info " << alcoholPercentage << endl;
    }
};

int main() {
    //creating a Beverage object
    Beverage b1("Beer", 10.0, "liter", 2.4, 5.8);
    b1.printInfo();

    //the public methods of the class Product are now accessible from the Beverage object:
    b1.setName("Dark beer");
    b1.setQuantity(20);

    return 0;
}
