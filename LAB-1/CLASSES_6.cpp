#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string make;
    string model;
    int year;
    int mileage; // Added mileage attribute

public:
    Vehicle(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr), mileage(0) {}

    void setMake(string mk) {
        make = mk;
    }

    // TASK: Implement setModel method
    void setModel(string mdl) {
        model = mdl;
    }

    // TASK: Implement setYear method
    void setYear(int yr) {
        year = yr;
    }

    // TASK: Implement setMileage method
    void setMileage(int miles) {
        mileage = miles;
    }

    bool needsServicing() {
        // Assuming servicing is needed after 10,000 miles
        return mileage >= 10000;
    }

    void displayVehicleInfo() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Mileage: " << mileage << " miles" << endl;
    }
};

int main() {
    Vehicle myVehicle("Toyota", "Corolla", 2020);

    // Display initial vehicle info
    myVehicle.displayVehicleInfo();

    // Modify and display new details using setModel, setYear, and setMileage
    myVehicle.setModel("Camry");
    myVehicle.setYear(2022);
    myVehicle.setMileage(8000);

    // Display modified vehicle info
    myVehicle.displayVehicleInfo();

    // Check if the car needs servicing
    if (myVehicle.needsServicing()) {
        cout << "Car needs servicing." << endl;
    } else {
        cout << "Car is in good condition." << endl;
    }

    return 0;
}