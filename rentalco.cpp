/*group members 1.NDAYISHIMIYE Habibu 222005474
                2.UWABABYEYI MBABAZI Aline 222009293
                3.IRADUKUNDA Bonheur 222005615
                */
#include <iostream>
using namespace std;
int main() {
    int starting_time;  
    int ending_time;    
    int amount = 0;   
    cout<<"Enter the starting time: "; 
    cin>>starting_time;
    cout<< "Enter the returning time: ";   
    cin>>ending_time;

//Define condition to terminate the program (if ending_time  is less than starting time)
  
    if(ending_time< starting_time) {
        cout<<"Invalid! Try again."<<endl;
        return 0;
    }

  //conditions to calculate sum of payment.
    
    while(starting_time < ending_time) {
        if((starting_time >= 0 && starting_time < 7) || (starting_time >= 21 &&starting_time < 24)) {
           amount += 500;
        } else if((starting_time >= 7 && starting_time < 14) || (starting_time>= 19 && starting_time < 21)) {
            amount += 1000;
        } else if(starting_time >= 14 && starting_time < 19) {
            amount += 1500;
        }
        starting_time +=1;
    }

  //the sum of payment  the duration of bicycle rent
  
    cout<<"you should pay: "<<amount<<" Rwf."<<endl;
        
            
        return 0; 
}
