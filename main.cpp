//Travel Expenses
//Date: 4/28/2010
//CSE - 110
//This program calculates and displays
//the total travel expenses of a business trip. The program will have several
//functions developed by the team that ask the user questions about travel
//expenditures.

#include <iostream>
using namespace std;

//Prompt user to enter the total number of days
int noOfDays()
{
int days;
cout<<"Please enter the total number of days spent on your trip: \n";
cin>>days;

if(days<1)

{
cout<<"Invalid number of days. Please enter the total number of days: \n";
noOfDays();
}

return days;

}


//Prompt user to enter the departure time
float timeOfDept()
{
float time;

cout<<"Enter the time of departure in 24 hours format: \n";
cin>>time;

if(!(time>=0.0 && time<25.00)){

cout<<"Invalid input \n";
timeOfDept();
}

return time;
}

//Prompt user to enter arrival time
float timeOfArrival()
{
float time;

cout<<"Enter the time of arrival in 24 hours format: \n";
cin>>time;

if(!(time>=0.0 && time<25.00)){
cout<<"Invalid input \n";
timeOfArrival();
}

return time;
}

//Prompt user to enter the air fare
double airfare()
{
double fare;
cout<<"Enter the round trip airfare: \n";
cin>>fare;

if(!(fare>0.0) )
{
cout<<"Invalid input \n";
airfare();
}

return fare;
}

//Prompt user to enter the car rent, if own vehicle get the miles driven
double carRent()
{
double rent, miles;

cout<<"Enter the amount of car rent, if private vehicle used enter 0: \n";
cin>>rent;

if(rent<0)
{
cout<<"Invalid input \n";
carRent();
}
if(rent==0)
{
cout<<"Enter the miles driven: \n";
cin>>miles;

if(miles<1)
{
cout<<"Invalid input \n";
carRent();
}
rent=miles * 0.27;
}

return rent;

}

//Prompt user to enter the parking fee
double parkingFee(int days)
{
double fee;
cout<<"Enter the parking fee: \n";
cin>>fee;

if(fee<1) {
cout<<"Invalid input \n";
parkingFee(days);
}

return fee-(6*days);
}

//Prompt user to enter the taxi fee
double taxiFee(int days)
{
double fee;
cout<<"Enter the taxi fee: \n";
cin>>fee;

if(fee<0)
{
cout<<"Invalid input \n";
taxiFee(days);
}

return fee-(days*10);
}

//Prompt user to enter the registration fee
double regFee()
{
double fee;
cout<<"Enter the registration fee: \n";
cin>>fee;

if(fee<1) {
cout<<"Invalid input \n";
regFee();
}

return fee;
}

//Prompt user to enter the hotel expenses

double hotelExpense(int days)
{
double fee;
cout<<"Enter the hotel expense: \n";
cin>>fee;

if(fee<1) {
cout<<"Invalid input \n";
hotelExpense(days);
}

return fee-(days*90);
}

//Prompt user to enter the allowable meal cost
double mealCost(int days,float arr, float dept)
{
double cost;
cout<<"Enter the amount of allowable meals: \n";
cin>>cost;

if(cost<1)
{
cout<<"Invalid input \n";
mealCost(days,arr,dept);
}
if(dept<=7)
cost-=9;
else if (dept>7 && dept<=12)
cost-=12;
else if(dept>12 && dept<=18)
cost-=16;
if(arr<=8)
cost-=9;
else if(arr>8 &&arr<=13)
cost-=12;
else if(arr>13 &&arr<=19)
cost-=16;

cost-=(days*(9+12+16));


return cost;
}

//Main function
int main()
{
cout << "Enter the details" << endl;

//Declare Variables
int days;
float arr,dept;
double air,rent,taxi,park,reg,hotel,meal,total;

//Call the function and get the values
days=noOfDays();
dept=timeOfDept();;
arr=timeOfArrival();
air=airfare();
rent=carRent();
taxi=taxiFee(days);
park=parkingFee(days);
reg=regFee();
hotel=hotelExpense(days);
meal=mealCost(days,arr,dept);

//Calculate the total cost
total=air+rent+taxi+park+reg+hotel+meal;

//Display the cost
cout<<"\nTotal expenses = $"<<total<<"\n";

return 0;
}


