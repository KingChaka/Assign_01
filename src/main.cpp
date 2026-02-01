
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring> // for strcpy
#include <iomanip> //to pretify the output
using namespace std;

// Typedef
typedef char VIN[20];

// Enumeration
enum Color { RED, BLUE, GREEN, BLACK, WHITE };
enum PurchaseMonth { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

char strColor[][10] = { "Red", "Blue", "Green", "Black", "White" };

//Class
class Vehicle {
private:
    string maker;
    string model;
    int year;
    Color color;
    double weight;
    VIN vin;
    PurchaseMonth purchaseMonth;
    double engineSize; // NEW ATTRIBUTE

public:
    // Constructor
    Vehicle(string m, string mo, int y, Color c, double w, const char* v, PurchaseMonth pm, double es) {
        maker = m;
        model = mo;
        year = y;
        color = c;
        weight = w;
        strcpy(vin, v);
        purchaseMonth = pm;
        engineSize = es;
    }

    // Getters/Setters
    string getMaker() const { return maker; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    int getColor() const { return color; }
    double getWeight() const { return weight; }
    double getEngineSize() const { return engineSize; }
    void setEngineSize(double es) { engineSize = es; }

    // Display
    void display() const {
        cout.width(8);
        cout << "Maker:"<< setw(9) << maker
             << " | Model: "<< setw(9) << model
             << " | Year: "<< setw(4) << year
             << " | Color: "<< setw(5) << strColor[color]
             << " | Weight: "<< setw(4) << weight
             << " | Engine: "<< setw(2) << engineSize << "L"
             << endl;
    }
};

// Sorting comparator example
bool compareByWeight(Vehicle* a, Vehicle* b) {
    return a->getWeight() < b->getWeight();
}

bool compareByYear(Vehicle* a, Vehicle* b) {
    return a->getYear() < b->getYear();
}

bool compareByColor(Vehicle* a, Vehicle* b) {
    bool isless = false;
    if (strcmp(strColor[a->getColor()],strColor[b->getColor()]) < 0){
        isless = true;
    }
    return isless;
}

bool compareByMaker(Vehicle* a, Vehicle* b) {
    //return a->getMaker() < b->getMaker();
    bool isless = false;
    if(a->getMaker().compare(b->getMaker())<0){
        isless = true;
    }

    return isless;
}

int main() {
    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    Vehicle** vehicles = new Vehicle*[n];

    // Dynamically Creates Vehicle Instances
    /*
    for(short int i=0; i<n; i++){
        vehicles[i] = new Vehicle("M",2010Toyota","Corolla",2020-i,RED,3000-100*i,"VIN_",MAR,1.8);
    }
    */

    // hard-wired Vehicles
    vehicles[0] = new Vehicle("Toyota","Corolla",2025,WHITE,3000,"VIN_009",MAR,1.8);
    vehicles[1] = new Vehicle("Dodge","Avenger",1999,RED,2900,"VIN_007",MAR,1.8);
    vehicles[2] = new Vehicle("Hyundai","Accent",2016,BLACK,2800,"VIN_005",MAR,1.8);
    vehicles[3] = new Vehicle("Chevy","Cruze",2020,GREEN,2700,"VIN_004",MAR,1.8);
    vehicles[4] = new Vehicle("Tesla","Model T",2010,BLUE,2600,"VIN_006",MAR,1.8);

    cout << "\nHow do you wish to sort your vehicles?" << endl;
    cout << "   1. Sort by maker.\n"
    << "   2. Sort by year.\n"
    << "   3. Sort by color.\n"
    << "   4. Sort by weight.\n   ------------------> ";
    
    short int sortType; //consider changing to an enum later.
    cin >> sortType;
    cout << endl;
    
    //Sort
    switch(sortType) {
        case 1:
            sort(vehicles, vehicles+n, compareByMaker);
            break;
        case 2:
            sort(vehicles, vehicles+n, compareByYear);
            break;
        case 3:
            sort(vehicles, vehicles+n, compareByColor);
            break;
        default:
            sort(vehicles, vehicles+n, compareByWeight);
    }

    // Display
    for(int i=0;i<n;i++) {
        vehicles[i]->display();
    }
    cout << endl;

    // Cleanup
    for(int i=0;i<n;i++) delete vehicles[i];
    delete[] vehicles;

    return 0;
}
