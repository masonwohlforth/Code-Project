/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Week 3 Assignment 4
** File: 	source.cpp
** Description: This code takes user input for a set of numerical values, and will output which numbers occur with the most frequency
**              additionally this also contains user validation to ensure only numerical values are accepted.
**
** Author: 	Mason Wohlforth
** Date: 	August 22nd 2025
** -------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

// Prior to this section, remember the first step is just to get the maxcount, the second half is to see what values match that maxcount and record them in the output vector.
vector<int> findmostfrequent(int a[], int n) // A is the array of user inputs, n is the amount of numbers
{
    int maxcount = 0; // This will be used as the minimum value for the numbers that match for max occurrence.

    // First, find the highest count
    for (int i = 0; i < n; i++) // Goes through each of the user inputs
    {
        int count = 0;
        for (int j = 0; j < n; j++) //counter for innner loop, kinda like a search engine for any duplicate numbers
        {
            if (a[j] == a[i])
            {
                count++; // the counts each time a[i] will appear, (duplicate numbers)
            }
        }
        if (count > maxcount)
        {
            maxcount = count; // will remember the highest frequency
        }
    }

    // Second, this section is how we can add multiple values to the output. Ex: if there was 2 of both 5 and 6, it would display each instead of just one.
    vector<int> outputs; // this vector will be used to store all of the results
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == a[i])
            {
                count++;
            }
        }
        if (count == maxcount)
        {
            // Avoid duplicates in the modes vector
            bool alreadyadded = false; // used to check for if value is there (true) or not (false)
            for (int k = 0; k < outputs.size(); k++)
            {
                if (outputs[k] == a[i])
                {
                    alreadyadded = true; // Number was already in vector
                    break; // exits the loop if number was in the vector
                }
            }
            if (!alreadyadded)
            {
                outputs.push_back(a[i]); // this will add the number to the vector if not there
            }
        }
    }

    return outputs;
}

int main()
{
    const int max_size = 100; //limit for user input
    int numbers[max_size]; // Array with the max size limit
    int n; // User input for the size

    // Step 1: Get size with validation
    while (true)
    {
        // Prompts user for input, Ensures value is within range
        cout << "How many numbers (1 to " << max_size << ")? ";
        cin >> n;

        // User validation
        if (cin.fail() || n < 1 || n > max_size)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again.\n";
        }
        else {
            break; // If the user input is valid this will break the loop
        }
    }

    // Step 2: Get numbers with validation
    for (int i = 0; i < n; i++)
    {
        // Loop that, will prompt user for the numbers they want to enter
        while (true) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> numbers[i];

            // User validation that they are integers
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter an integer.\n";
            }
            else {
                break; // If the user input is valid, this will break the loop
            }
        }
    }

    // Step 3: Find most frequent value(s). Calls out the function to execut
    vector<int> mostfrequent = findmostfrequent(numbers, n);

    // Step 4: Output results, this just displays the results back to end user
    cout << "The most frequently occurring value(s): ";
    for (int display_output_values : mostfrequent) //
    {
        cout << display_output_values << " "; // This one is tricky, this creates the display_output_varibles so that it can print out all of data that mostFrequent holds
        // for example if there are 2 of both the number 5 and 6 it will print 5, clear the value then go back and print the 6
        // The source for this code is, https://en.cppreference.com/w/cpp/language/range-for.html
    }
    cout << endl;

    return 0;
}