
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
char strMonth[][10] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };

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
             << " | Model: " << setw(6) << model
             << " | Year: " << setw(4) << year
             << " | Color: " << setw(5) << strColor[color]
             << " | Weight: " << fixed << setprecision(0) << setw(4) << weight
             << " | Engine: " << fixed << setprecision(1) << engineSize << "L"
             << " | Month: " << setw(3) << strMonth[purchaseMonth]
             << " | VIN: " << vin
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
    int index;

    string maker_input;
    string model_input;
    int year_input;
    Color color_input;
    double weight_input;
    VIN vin_input;
    PurchaseMonth month_input;
    double size_input;
    short int sortType = 0; //consider changing to an enum later.


    cout << "Enter number of vehicles: ";
    cin >> n;

    Vehicle** vehicles = new Vehicle*[n];

    // Dynamically Creates Vehicle Instances
    for(short int i=0; i<n; i++){
        //prompting
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << "Who is the maker for vehicle #" << i+1 << " ?  ";
        cin >> maker_input;

        cout << "What model is the vehicle?  ";
        cin >> model_input;

        cout << "What year is vehicle?  ";
        cin >> year_input;

        cout << "What color is vehicle?";
        cout << "\n   1) Red?\n   2) Blue?";
        cout << "\n   3) Green?\n   4) Black?";
        cout << "\n   5) White?    ---------->  ";
        cin >> index;
        color_input = static_cast<Color>(index - 1);

        cout << "How much does it weight (lbs)?  ";
        cin >> weight_input;

        cout << "Vin number:  ";
        cin >> vin_input;

        cout << "Purchase Month by # (ex: JAN = 1)?  ";
        cin >> index;
        month_input = static_cast<PurchaseMonth>(index);

        cout << "Engine Size (L)?  ";
        cin >> size_input;

        vehicles[i] = new Vehicle(maker_input, model_input, year_input, color_input, weight_input, vin_input, month_input, size_input);
    }

    if (n > 1){                                                                 // Sorting unneeded if only one vehicle entered
    cout << "\nHow do you wish to sort your vehicles?" << endl;
    cout << "   1. Sort by maker.\n"
    << "   2. Sort by year.\n"
    << "   3. Sort by color.\n"
    << "   4. Sort by weight.   ------------------> ";

    cin >> sortType;
    cout << endl;
}

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
