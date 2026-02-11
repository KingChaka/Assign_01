/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #1 C++ Review : VehicleManageSys
*  Purpose: Contains a Vehicle class and main function.
*           The code demonstrates a functional 
*		    understanding of OOP.
*
************************************************* */

#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>                          // for strcpy
#include <iomanip>                          // to prettify the display
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
    int year;
    string maker;
    string model;
    double weight;
    double engineSize;
    Color color;
    VIN vin;
    PurchaseMonth purchaseMonth;  

public:
    Vehicle(string m, string mo, int y, Color c, double w, const char* v, PurchaseMonth pm, double es) {
    /* *********************************************************************
    * Class Constructor
    *
    * @param string m         : The maker/manufacturer of the vehicle
    * @param string mo        : The specific model of the vehicle
    * @param int y            : The year the vehicle was released
    * @param Color c          : The primary color of the vehicle
    * @param double w         : The weight of the car in pounds      
    * @param char* v          : The vehicle identification number
    * @param PurchaseMonth pm : The month the vehicle was purchased
    * @param double es        : The size of the of vehicle's engine in liters
    * @return na              : na
    * @exception na           : na
    * @note                     na
    **********************************************************************/
        maker = m;
        model = mo;
        year = y;
        color = c;
        weight = w;
        strcpy(vin, v);
        purchaseMonth = pm;
        engineSize = es;
    }

    /**********************
    Accessors
    ***********************/
    string getMaker() const {return maker; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    int getColor() const { return color; }
    double getWeight() const { return weight; }
    double getEngineSize() const { return engineSize; }
    PurchaseMonth getPurchMo() const {return purchaseMonth;}
    char* getVIN() { return vin; }
    
    /**********************
    Mutators
    ***********************/
    void setMaker(string mkr) { maker = mkr; }
    void setModel(string mdl) { model = mdl; }
    void setYear(int yr) { year = yr; }
    void setColor(Color hue) { color = hue; }
    void setWeight(double wt) { weight = wt; }
    void setEngineSize(double engSz) { engineSize = engSz; }
    void setPurchMo(PurchaseMonth pMon) {purchaseMonth = pMon; }
    void setWeight(VIN vNum) { strcpy(vin, vNum); }
        

    void display() const {
    /* *********************************************************************
    * Prints all the attributes of the class instance to console.
    *
    * @param      na : na
    * @return (void) : There is no return for this function
    * @exception  na : na
    * @note            na
    **********************************************************************/
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


/*********************** MAIN FUNCTION ***********************/

int main() {
/* **********************************
 * This function is the application driver. It
 * makes use of the Vehicle Class and sorting
 * functions to define and sort vehicle
 * instances.
 *
 * @param na : na
 * @return (int) : application exit code
 * @exception na : na
 * @note na
 * **********************************/
     
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

    //Sort (using non-class functions)
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
