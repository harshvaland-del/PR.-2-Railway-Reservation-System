#include <iostream>
#include <string.h>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    Train(int tr_number, char tr_name[50], char tr_source[50], char tr_destination[50], char tr_time[10])
    {
        trainNumber = tr_number;
        strcpy(trainName, tr_name);
        strcpy(source, tr_source);
        strcpy(destination, tr_destination);
        strcpy(trainTime, tr_time);
        trainCount++;
    }

    ~Train()
    {
        trainCount--;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);

        cout << endl;
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl
             << endl;
    }

    static int getTrainCount()
    {
        return trainCount;
    }

    int Get_Current_Train_Number()
    {
        return trainNumber;
    }
};

int Train::trainCount = 0;
class RailwaySystem
{

private:
    Train trains[100];
    int totalTrains = 0;

public:
    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        }
        else
        {
            cout << "The limit has been reached\n";
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No train records found.\n";
        }
        else
        {
            for (int i = 0; i < totalTrains; i++)
            {
                cout << "\nTrain " << i + 1 << " details:" << endl;
                trains[i].displayTrainDetails();
                cout << endl;
            }
        }
    }

    void searchTrainByNumber(int number)
    {
        int checkrecord = 0;
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].Get_Current_Train_Number() == number)
            {
                trains[i].displayTrainDetails();
                checkrecord = 1;
                break;
            }
        }
        if (checkrecord == 0)
        {
            cout << "Record was not found \n";
        }
    }
};
int main()
{
    RailwaySystem railway;

    int choice;
    do
    {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            railway.addTrain();
            break;

        case 2:
            railway.displayAllTrains();
            break;

        case 3:
            int number;

            cout << "Enter Train Number to search: ";
            cin >> number;

            railway.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Exiting the system. Goodbye!";
            break;
            
        default:
            cout << "Invalid choice! Try again.";
            break;
        }

    } while (choice != 4);
}