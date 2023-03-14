// محمد ناصر محمد كمال _ 3 _ 47
// مينا صبحي كامل السيد _ 4 _ 22
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

//class construction
class Event {
private:
    char EventName[250];
    char CustomerName[250];
    char GuestCount[12];
    int EventDuration;
    int NumberOfWaiters;
    float CostPerWaiter;
    float FoodCost;
    float TotalCost;
    float DepositAmount;

public:
    Event();
    void getEventName();
    void getCustomerName();
    void getGuestCount();
    void getEventDuration();
    void CalculateCost();
    void PrintInfo();
};

// constructor implementation
Event::Event()
{
    strcpy(EventName, "\0");
    strcpy(CustomerName, "\0");
    strcpy(GuestCount, "\0");
    EventDuration = 0;
    NumberOfWaiters = 0;
    CostPerWaiter = 0;
    FoodCost = 0;
    TotalCost = 0;
    DepositAmount = 0;
}

// getting event name function implementation
void Event::getEventName()
{
    cout << "Enter The Name Of The Event\n";
    cin.getline(EventName, 250);
}

//getting customer name function implementation
void Event::getCustomerName()
{
    cout << "\nEnter The Customer's First And Last Name\n";
    cin.getline(CustomerName, 250);

    //Numbers Not Allowed To Be Used In Personal Names
    for (int i = 0; i < strlen(CustomerName); i++)
        if (CustomerName[i] == '0' || CustomerName[i] == '1' || CustomerName[i] == '2' || CustomerName[i] == '3' || CustomerName[i] == '4' || CustomerName[i] == '5' || CustomerName[i] == '6' || CustomerName[i] == '7' || CustomerName[i] == '8' || CustomerName[i] == '9')
        {
            cout << "No Numerical Values Allowed In The Personal Name\nPlease Enter The Name Again";
            getCustomerName();
        }
}

//getting number of guests function implementation
//For that we will use 2 main function stoi which means string to integer and stof which means string to float
void Event::getGuestCount()
{
    cout << "\nEnter The Number Of Guests\n";
    cin.getline(GuestCount, 12);

    for (int i = 0; i < 11; i++)
        if (GuestCount[i] == '/' || GuestCount[i] == '*' || GuestCount[i] == '+' || GuestCount[i] == '-')
        {
            cout << "Please Enter Only A Positive Integer Number\n";
            getGuestCount();
        }

    //GuestCount was chosen as a string to catch if the input is a letter or not using try and catch functions
    try
    {
        stof(GuestCount);
    }
    catch (...)
    {
        cout << "Please Enter Only A Number\n";
        getGuestCount();
    }

    //stof function used to convert GuestCount from string to float to apply the operation that makes sure the user did not enter a fraction nor a negative number
    if (stof(GuestCount) <= 0 || fmod(stof(GuestCount), floor(stof(GuestCount)) != 0))
    {
        cout << "Please Enter Only A Positive Integer Number\n";
        getGuestCount();
    }
    if (stoi(GuestCount) > 100000)
    {
        cout << "The Number Of Guests Makes No Sense For The Event\n";
        cout << "Please Enter A Number Less Than 100000\n";
        getGuestCount();
    }
}

//getting event duration function implementation
void Event::getEventDuration()
{
    //The array is static to not allow the program to redeclare the array in each time an error occurs and recall the function
    static char st[12];
    cout << "\nEnter The Number Of Minutes In The Event\n";
    cin.getline(st, 12);

    for (int i = 0; i < 11; i++)
        if (st[i] == '/' || st[i] == '*' || st[i] == '+' || st[i] == '-')
        {
            cout << "Please Enter Only A Positive Number\n";
            getEventDuration();
            return;
        }

    try
    {
        stof(st);
    }
    catch (...)
    {
        cout << "Please Enter Only A Number\n";
        getEventDuration();
        return;
    }


    if (stof(st) <= 0)
    {
        cout << "Please Enter Only A Positive Number\n";
        getEventDuration();
        return;
    }

    //to notify the user that if he enters a fraction it will cost a new extra minute
    EventDuration = (int)ceil(stof(st));
    if (EventDuration > 100000)
    {
        cout << "The Duration Time Makes No Sense For The Event\n";
        cout << "Please Enter A Number Less Than 100000\n";
        getEventDuration();
        return;
    }
    if (fmod(stof(st), floor(stof(st)) != 0))
    {
        cout << "Note: A fraction of a minute costs 1 new extra minute, ";
        cout << "Event duration reserved is " << EventDuration << " minutes\n";
    }
}

//calculations function implementation
void Event::CalculateCost()
{
    NumberOfWaiters = (int)ceil(stof(GuestCount) / 20);

    if (EventDuration <= 60 && EventDuration > 46)
    {
        cout << "Note: You will pay for a complete hour/n";
        CostPerWaiter = 46.5;
    }
    else if (EventDuration > 0 && EventDuration <= 46)
    {
        cout << "Note: You will pay 1 EGP for each minute\n";
        CostPerWaiter = EventDuration;
    }
    else
        CostPerWaiter = ((EventDuration / 60) * 46.5) + ((EventDuration % 60) * 1);

    FoodCost = stoi(GuestCount) * 54.5;
    TotalCost = FoodCost + (NumberOfWaiters * CostPerWaiter);
    DepositAmount = (.25 * TotalCost);
}

//printing function implementation
void Event::PrintInfo()
{
    cout << endl << "----------------------------------" << endl;
    cout << EventName << " Event" << endl;
    cout << "Event Estimate For " << CustomerName << endl;
    cout << "----------------------------------" << endl;
    cout << "Number Of Waiters:  " << NumberOfWaiters << endl;
    cout << "The Cost Per Waiter:  " << CostPerWaiter << endl;
    cout << "The Cost For Food Is:  " << FoodCost << endl;
    cout << "Total Cost Is:  " << TotalCost << endl;
    cout << "Please Provide A 25% Deposit To Reserve The Event" << endl;
    cout << "The Deposit Needed Is:  " << DepositAmount << endl;
}

int main()
{
    Event E1;
    E1.getEventName();
    E1.getCustomerName();
    E1.getGuestCount();
    E1.getEventDuration();
    E1.CalculateCost();
    E1.PrintInfo();
    return 0;
}