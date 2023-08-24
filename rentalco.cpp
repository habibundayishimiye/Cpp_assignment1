#include <iostream>
using namespace std;
//Enter the main() function
int main() {
    int start;  //declare variable to account for the starting time
    int end;    //declare variable to account for the returning time
    int amount = 0;   //declare variable to account for the total cost to be paid
    cout<<"Enter the starting time: "; // Ask for input from the user for the starting time
    cin>>start;
    cout<< "Enter the returning time: ";    // Ask for input from the user for the returning time
    cin>>end;

//Define condition to terminate the program (if end input is less than starting time)
  
    if(end < start) {
        cout<<"Invalid! Try again."<<endl;
        return 0;
    }

  //conditions to calculate sum of payment.
    
    while(start < end) {
        if((start >= 0 && start < 7) || (start >= 21 && start < 24)) {
           amount += 500;
        } else if((start >= 7 && start < 14) || (start>= 19 && start < 21)) {
            amount += 1000;
        } else if(start >= 14 && start < 19) {
            amount += 1500;
        }
        start +=1;
    }

  //the sum of payment  the duration of bicycle rent
  
    cout<<"you should pay: "<<amount<<" Rwf."<<endl;
        
            
        return 0; //Existing the program.....
}