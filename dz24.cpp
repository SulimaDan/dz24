#include <iostream>
#include <string>

class Overcoat {
private:
    std::string type;
    double price;

public:
    Overcoat(const std::string& type = "", double price = 0.0) : type(type), price(price) {}

    bool operator==(const Overcoat& other) const {
        return this->type == other.type;
    }

    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            this->type = other.type;
            this->price = other.price;
        }
        return *this;
    }

    bool operator<(const Overcoat& other) const {
        return this->price < other.price;
    }

    void display() const {
        std::cout << "Type: " << type << ", Price: " << price << std::endl;
    }
};

class Flat {
private:
    double area;
    double price;

public:
    Flat(double area = 0.0, double price = 0.0) : area(area), price(price) {}

    bool operator==(const Flat& other) const {
        return this->area == other.area;
    }

    Flat& operator=(const Flat& other) {
        if (this != &other) {
            this->area = other.area;
            this->price = other.price;
        }
        return *this;
    }

    bool operator<(const Flat& other) const {
        return this->price < other.price;
    }

    void display() const {
        std::cout << "Area: " << area << " sq.m, Price: " << price << " USD" << std::endl;
    }
};

int main() {
    Overcoat coat1("Winter", 150.0);
    Overcoat coat2("Autumn", 120.0);
    Overcoat coat3 = coat1;

    coat1.display();
    coat2.display();
    coat3.display();

    std::cout << "Are coat1 and coat2 of the same type? " << (coat1 == coat2 ? "Yes" : "No") << std::endl;
    std::cout << "Is coat2 cheaper than coat1? " << (coat2 < coat1 ? "Yes" : "No") << std::endl;

    Flat flat1(50.0, 50000.0);
    Flat flat2(60.0, 60000.0);
    Flat flat3 = flat1;

    flat1.display();
    flat2.display();
    flat3.display();

    std::cout << "Do flat1 and flat2 have the same area? " << (flat1 == flat2 ? "Yes" : "No") << std::endl;
    std::cout << "Is flat2 more expensive than flat1? " << (flat2 < flat1 ? "No" : "Yes") << std::endl;

    return 0;
}
