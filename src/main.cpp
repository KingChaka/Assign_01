/* *************************************************
*  Name: Brandon Crenshaw
*  Assignment: #1 C++ Review : VehicleManageSys
*  Purpose: Contains a Vehicle class and main function.
*           The code demonstrates a functional
*           understanding of OOP.
*
************************************************* */

#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>                                  // for strcpy
#include <cctype>                                   // for data validation
#include <iomanip>                                  // to prettify the display
using namespace std;

#define WRDLEN 10
#define VINLEN 20
#define RESET 1


//CONSTANTS
const string EMPTY = "\0";
const char *NOT_FOUND = "Not found";
const int YR_MIN = 1000;
const int SORT_CNT = 4;
const int COLOR_CNT = 5;
const int MONTH_CNT = 12;

// Typedef
typedef char VIN[VINLEN];

// Enumeration
enum Color { RED, BLUE, GREEN, BLACK, WHITE };
enum PurchaseMonth { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

//Variables
char monthStr[][WRDLEN] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
char colorStr[WRDLEN];

//CLASS DEFINTION ---------------------------------------------------------
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
    Vehicle(string mkr, string mo, int yr, Color clr, double wt,
            const char* vnum, PurchaseMonth pm, double es) {
    /* *********************************************************************
    * Class Constructor
    *
    * @param string mkr       : The maker/strColor[manufacturer of the vehicle
    * @param string mo        : The specific model of the vehicle
    * @param int yr           : The year the vehicle was released
    * @param Color clr        : The primary color of the vehicle
    * @param double wt        : The weight of the car in pounds
    * @param char* vnum       : The vehicle identification number
    * @param PurchaseMonth pm : The month the vehicle was purchased
    * @param double es        : The size of the of vehicle's engine in liters
    * @return na              : na
    * @exception na           : na
    * @note                     na
    **********************************************************************/
        maker = mkr;
        model = mo;
        year = yr;
        color = clr;
        weight = wt;
        strcpy(vin, vnum);
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
    char *getVIN() { return vin; }

    char *getColorStr(int colorSelect) const {
    /* *********************************************************************
    * Prints all the attributes of the class instance to console.
    *
    * @param int colorSelect : Selects the vehicle color by enumeration index
    * @return (string)       : Returns the string value of the selected color
    * @exception  na         : na
    * @note                    Out-of-range or invalid entries return 'invalid'
    **********************************************************************/
        switch(colorSelect) {
            case (Color::RED):
                strcpy(colorStr,"Red");
                break;
            case (Color::BLUE):
                strcpy(colorStr,"Blue");
                break;
            case (Color::GREEN):
                strcpy(colorStr,"Green");
                break;
            case (Color::BLACK):
                strcpy(colorStr,"Black");
                break;
            case (Color::WHITE):
                strcpy(colorStr,"White");
                break;
            default:                                // Data validation makes this impossible
                strcpy(colorStr,NOT_FOUND);
        }
        return colorStr;
    }


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
        // Magic numbers only used for display astetics
        cout << "Maker:"<< setw(9) << maker
             << " | Model: " << setw(7) << model
             << " | Year: " << setw(4) << year
             << " | Color: " << setw(5) << getColorStr(color)
             << " | Weight: " << fixed << setprecision(0) << setw(4) << weight
             << " | Engine: " << fixed << setprecision(1) << engineSize << "L"
             << " | Month: " << setw(3) << monthStr[purchaseMonth]
             << " | VIN: " << vin
             << endl;
    }
};
//END OF CLASS DEFINTION --------------------------------------------------

// SORT FUNCTIONS
bool compareByWeight(Vehicle* veh1, Vehicle* veh2) {
    /* *********************************************************************
    * Determines if weight #1 is less than weight #2
    *
    * @param  Vehicle* veh1 : 1st vehicle being compared
    * @param  Vehicle* veh2 : 2nd vehicle being compared
    * @return (bool)        : Returns true if veh1 is less than veh2.
    * @exception  na        : na
    * @note                   na
    **********************************************************************/
    return veh1->getWeight() < veh2->getWeight();
}

bool compareByYear(Vehicle* veh1, Vehicle* veh2) {
    /* *********************************************************************
    * Determines if year #1 is less than year #2
    *
    * @param  Vehicle* veh1 : 1st vehicle being compared
    * @param  Vehicle* veh2 : 2nd vehicle being compared
    * @return (bool)        : Returns true if veh1 is less than veh2.
    * @exception  na        : na
    * @note                   na
    **********************************************************************/
    return veh1->getYear() < veh2->getYear();
}

bool compareByColor(Vehicle* veh1, Vehicle* veh2) {
    /* *********************************************************************
    * Determines if color #1 comes before color #2 (alphabetically)
    *
    * @param  Vehicle* veh1 : 1st vehicle being compared
    * @param  Vehicle* veh2 : 2nd vehicle being compared
    * @return (bool)        : Returns true if veh1 is earlier than veh2.
    * @exception  na        : na
    * @note                   na
    **********************************************************************/
    bool isLess = false;
    char color1[WRDLEN];
    char color2[WRDLEN];

    strcpy(color1, veh1->getColorStr(veh1->getColor()));
    strcpy(color2, veh2->getColorStr(veh2->getColor()));

    if (strcmp(color1,color2) < 0){
        isLess = true;
    }

    return isLess;
}

bool compareByMaker(Vehicle* veh1, Vehicle* veh2) {
    /* *********************************************************************
    * Determines if maker #1 comes before maker #2 (alphabetically)
    *
    * @param  Vehicle* veh1 : 1st vehicle being compared
    * @param  Vehicle* veh2 : 2nd vehicle being compared
    * @return (bool)        : Returns true if veh1 is earlier than veh2.
    * @exception  na        : na
    * @note                   na
    **********************************************************************/
    bool isLess = false;
    if(veh1->getMaker().compare(veh2->getMaker())<0){
        isLess = true;
    }
    return isLess;
}


/*************************************************************/
/*********************** MAIN FUNCTION ***********************/
/*************************************************************/

int main() {
/* **********************************
 * This function is the application driver. It makes use of the
 * Vehicle Class and sorting functions to define and sort
 * vehicle instances stored in memory.
 *
 * @param na : na
 * @return (int) : application exit code
 * @exception na : na
 * @note na
 * **********************************/

    int vehCnt = RESET;
    int usrChoice = RESET;
    int yearIn = YR_MIN;
    int sortType = RESET;                               // Could be updated to an enum later.
    double weightIn = RESET;
    double engSizeIn = RESET;
    string makerIn = EMPTY;
    string modelIn = EMPTY;
    VIN vinIn;
    Color colorIn;
    PurchaseMonth monthIn;

    // Enters Total Number of Vehicles
    do{
         if (cin.fail() || vehCnt < 1) {
            cout << "    ERROR -- Please enter a positive integer.\n\n";
            cin.clear();
            cin.ignore(VINLEN,'\n');
        }
        cout << "Enter the number of vehicles: ";
    } while (!(cin >> vehCnt) || vehCnt < 1);


    Vehicle** vehicles = new Vehicle*[vehCnt];

    // Prompting and Dynamically Created Vehicle Instances
    for(short int i=0; i<vehCnt; i++){
        //VARIABLE RESETS
        usrChoice = RESET;
        yearIn = YR_MIN;
        weightIn = RESET;
        engSizeIn = RESET;

        // VEHICLE MAKER
        cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << "Who is the maker for vehicle #" << i+1 << " ?  ";
        cin >> makerIn;

        // VEHICLE MODEL
        cout << "What model is the vehicle?  ";
        cin >> modelIn;

        // RELEASE YEAR
        do{
            if (cin.fail() || yearIn < YR_MIN) {
                cout << "    ERROR -- Enter a 4-digit year.\n\n";
                cin.clear();
                cin.ignore(VINLEN,'\n');
            }
            cout << "What year is vehicle?  ";
        } while ( !(cin >> yearIn) || yearIn < YR_MIN);

        // VEHICLE COLOR
        do {
            if (cin.fail() || usrChoice < 1 || usrChoice > COLOR_CNT) {
                cout << "    ERROR -- Enter an integer from the menu.\n\n";
                cin.clear();
                cin.ignore(VINLEN,'\n');
            }
            cout << "What is the vehicle's primary color?\n"
                 << "Enter one of the numbers below...\n"
                 << "   1) Red\n"
                 << "   2) Blue\n"
                 << "   3) Green\n"
                 << "   4) Black\n"
                 << "   5) White\n"
                 << "   ---------->  ";
        } while (!(cin >> usrChoice) || usrChoice < 1 || usrChoice > COLOR_CNT);

        colorIn = static_cast<Color>(usrChoice - 1);
        usrChoice = RESET;

        //VEHICLE WEIGHT
        do {
            if (cin.fail() || weightIn < 1) {
                cout << "    ERROR -- Enter a positive integer.\n\n";
                cin.clear();
                cin.ignore(VINLEN,'\n');
            }
            cout << "How much does it weight (lbs)?  ";
        } while (!(cin >> weightIn) || weightIn < 1);

        // VEHICLE IDENTIFICATION NUMBER
        cout << "Vin number:  ";
        cin >> vinIn;

        // MONTH OF PURCHASE
        usrChoice = RESET;
        do {
            if (cin.fail() || usrChoice < 1 || usrChoice > MONTH_CNT) {
                cout << "    ERROR -- Enter an integer from 1 to 12.\n\n";
                cin.clear();
                cin.ignore(VINLEN,'\n');
            }
            cout << "Purchase Month by # (ex: JAN = 1)?  ";
        } while(!(cin >> usrChoice) || usrChoice < 1 || usrChoice > MONTH_CNT);

        monthIn = static_cast<PurchaseMonth>(usrChoice - 1);

        // SIZE OF VEHICLE ENGINE
        do {
            if (cin.fail() || engSizeIn < 0) {
                cout << "    ERROR -- Enter a positive number.\n\n";
                cin.clear();
                cin.ignore(VINLEN,'\n');
            }
            cout << "Engine Size (L)?  ";
        } while(!(cin >> engSizeIn) || engSizeIn < 0);

        // VEHICLE INSTANTIATION
        vehicles[i] = new Vehicle(makerIn, modelIn, yearIn,
                      colorIn, weightIn, vinIn, monthIn, engSizeIn);
    }

    // VEHICLE SORTING
    if (vehCnt > 1){ // Sorting only needed if more than one vehicle.
        do {
            if (cin.fail() || sortType < 1 || sortType > SORT_CNT) {
                cout << "    ERROR -- Enter an integer from the menu.\n\n";
                cin.clear();
                cin.ignore(VINLEN,'\n');
            }                                       // end of if statement

            cout << "How do you wish to sort your vehicles?" << endl;
            cout << "   1. Sort by maker.\n"
                 << "   2. Sort by year.\n"
                 << "   3. Sort by color.\n"
                 << "   4. Sort by weight.\n"
                 << "   ------------------> ";
        } while( !(cin >> sortType) || sortType < 1 || sortType > SORT_CNT);
    }                                               // end of if statement

    switch(sortType) {                              // Sort implemented here
        case 1:
            sort(vehicles, vehicles+vehCnt, compareByMaker);
            break;
        case 2:
            sort(vehicles, vehicles+vehCnt, compareByYear);
            break;
        case 3:
            sort(vehicles, vehicles+vehCnt, compareByColor);
            break;
        case 4:
            sort(vehicles, vehicles+vehCnt, compareByWeight);
            break;
        default:                                    // Data validation makes this impossible
            cout << "Sort by year has been selected by default.\n";
            sort(vehicles, vehicles+vehCnt, compareByWeight);
    }

    // Display
    cout << endl;
    for(int i=0;i<vehCnt;i++) {
        vehicles[i]->display();
    }
    cout << endl;

    // Cleanup
    for(int i=0;i<vehCnt;i++) delete vehicles[i];
    delete[] vehicles;

    return 0;
}
