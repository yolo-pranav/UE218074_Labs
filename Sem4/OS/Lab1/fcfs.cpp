/*
 * 25/01/2023
 * First Cum First Serve CPU Scheduling Algorithm
 * Requirements: The processes should be added in increasing order of arrival times.
 */

// Including Libraries
#include <iostream>
#include <string.h>
#include <conio.h>
#include "TextTable.h" // Displays the content as tables. (Input the library form the file "TextTable.h")
using namespace std;

int startIndex = 1;     // Define a number from where the process numbers will start counting
int n = 0;              // Default number of processes

// Creating a structure for each process
struct process {
    int id;     // Process ID (The identity of process)
    int at;     // Arrival Time (Time at which the process arrives in the queue)
    int bt;     // Burst Time (Time required for the process to run)
    int st;     // Start Time (Time at which the process starts) (Sum of burst time of previous processes)
    int wt;     // Waiting Time (Time for which the process has to wait in queue) (Start Time - Arrival Time)
    int tat;    // Turn Around Time (Time for which the process remains in processor) (Wait Time + Burst Time)
};

int main() {
    // Getting total number of processes from the user
    cout << "Enter the total number of processes: ";
    cin >> n;
    cout << endl;

    // Declaring an array of processes
    process arr[n];

    // Assigning IDs to each process starting from '0'
    for (int i=0; i<n; i++){
        arr[i].id = startIndex++;
    }

    // Getting user input for arrival time of each process
    for (int i=0; i<n; i++){
        cout << "Enter the arrival time for process" << arr[i].id << ": ";
        cin >> arr[i].at;
    }
    cout << endl;

    // Getting user input for burst time of each process
    for (int i=0; i<n; i++){
        cout << "Enter the burst time for process" << arr[i].id << ": ";
        cin >> arr[i].bt;
    }
    cout << endl;

    // Displaying 'ID', 'Arrival Time', 'Burst Time' of processes as table
    TextTable inp('-', '|', '+');
    inp.add("ID");
    inp.add("Arrival");
    inp.add("Burst");
    inp.endOfRow();
    for (int i=0; i<n; i++) {
        inp.add(to_string(arr[i].id));
        inp.add(to_string(arr[i].at));
        inp.add(to_string(arr[i].bt));
        inp.endOfRow();
    }
    inp.setAlignment( 1, TextTable::Alignment::RIGHT );
    inp.setAlignment( 2, TextTable::Alignment::RIGHT );
    cout << inp << endl;

    // Calculating other process properties
    for (int i=0; i<n; i++) {
        arr[i].st = 0;
        for (int j=0; j<i; j++) {
            arr[i].st += arr[j].bt;             // Start time of each process
        }
        arr[i].wt = arr[i].st - arr[i].at;      // Waiting Time for each process
        arr[i].tat = arr[i].wt + arr[i].bt;     // Turn Around Time for each process
    }

    // Displaying 'ID', 'Arrival Time', 'Burst Time', 'Waiting Time', 'Turn Around Time' of processes as table
    TextTable out('-', '|', '+');
    out.add("ID");
    out.add("Arrival");
    out.add("Burst");
    out.add("Wait");
    out.add("TurnAround");
    out.endOfRow();
    for (int i=0; i<n; i++) {
        out.add(to_string(arr[i].id));
        out.add(to_string(arr[i].at));
        out.add(to_string(arr[i].bt));
        out.add(to_string(arr[i].wt));
        out.add(to_string(arr[i].tat));
        out.endOfRow();
    }
    out.setAlignment( 1, TextTable::Alignment::RIGHT );
    out.setAlignment( 2, TextTable::Alignment::RIGHT );
    out.setAlignment( 3, TextTable::Alignment::RIGHT );
    out.setAlignment( 4, TextTable::Alignment::RIGHT );
    cout << out << endl;

    // Waiting for user to end the program
    cout << "Press a key to continue...";
    getch();

    return 0;
}