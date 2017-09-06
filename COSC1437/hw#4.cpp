/*Robert Gibler  COSC1437
*
* This program calculates the surface area and volume of cylindrical
* containers and also calculates shipping costs and costs for painting 
* the container based on user input */

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

//Defining global constants
double const LITER_PER_FEET = 28.32;
double const PI = 3.14159265358;

//Definig the cylinderType Class
class cylinderType {
    private:
        double height, radius; //feet
        double costPerLiter;
        double costSqFt;
    public:
        void SetPrices(double, double);
        void SetSize(double, double);
        double CalcVolume();
        double CalcSurfArea();
        double CalcCost2Paint();
        double CalcCost2Ship();
        cylinderType();
};

//Constructor initializes all member variables to 0
cylinderType::cylinderType(){
    height = 0;
    radius = 0;
    costPerLiter = 0;
    costSqFt = 0;
}

//Sets member variables to usr defined values
void cylinderType::SetSize(double usrHeight, double usrRadius){
    height = usrHeight;
    radius = usrRadius;
}

void cylinderType::SetPrices(double usrLiter, double usrSqFt){
    costPerLiter = usrLiter;
    costSqFt = usrSqFt;
}

double cylinderType::CalcVolume(){
    double volume = PI * radius * radius * height;
    return volume;
}

double cylinderType::CalcSurfArea(){
    double surfArea = 2 * PI * radius * height + 2 * PI * radius * radius;
    return surfArea;
}

double cylinderType::CalcCost2Paint(){
    double totalCost2Paint = CalcSurfArea() * costSqFt;
    return totalCost2Paint;
}

double cylinderType::CalcCost2Ship(){
    double totalCost2Ship = CalcVolume() * LITER_PER_FEET * costPerLiter;
    return totalCost2Ship;
}

void PrintUsrPrompt();

int main(){

    cylinderType container1;
    double usrHeight, usrRadius;
    double usrCostPerLiter, usrCostSqFt;

    cout << "Please enter a height and radius for your container(ft): ";
    cin >> usrHeight >> usrRadius;
    while (usrHeight < 0 ||  usrRadius < 0){
        cout << "!!!Invalid Input!! Height and radius must be positive values!\n";
        cout << "Please re-enter a height and radius for your container(ft): ";
        cin >> usrHeight >> usrRadius;
    }
    cout << endl;

    container1.SetSize(usrHeight, usrRadius);
    cout << "The volume of your container is " << container1.CalcVolume();
    cout << " cubic feet\n";
    cout << "and its surface area is " << container1.CalcSurfArea() <<  " square feet\n\n";
    
    cout << "Please enter the cost of shipping per liter volume of container and \n";
    cout << "the cost per square foot to paint the container: ";
    cin >> usrCostPerLiter >> usrCostSqFt;
    while (usrCostPerLiter < 0 ||  usrCostSqFt < 0){
        cout << "!!!Invalid Input!! Costs must be positive values!\n";
        cout << "Please re-enter the cost per square foot to paint the container: ";
        cin >> usrCostPerLiter >> usrCostSqFt;
    }
    cout << endl;
    
    container1.SetPrices(usrCostPerLiter, usrCostSqFt);
    cout << fixed << setprecision(2);
    cout << "The total cost to ship this container will be " << container1.CalcCost2Ship() << " dollars\n";
    cout << "and the total cost to paint the conatiner will be " << container1.CalcCost2Paint() << " dollars\n";

    
}

        
