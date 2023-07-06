/*group members 1.NDAYISHIMIYE Habibu 222005474
                2.UWABABYEYI MBABAZI Aline 222009293
                3.IRADUKUNDA Bonheur 222005615
                */
#include<iostream>
using namespace std;
int main(){
	int start_time,end_time,used_time,sum;
	cout<<"please enter start time and end time respectivery"<<endl;
	cin>>start_time>>end_time;
	used_time = end_time - start_time;
	
	if(0 <=start_time && start_time < 24 && 0 < end_time && end_time <= 24 && start_time < end_time){
		if(start_time >= 0 && end_time < 7){
			sum+= (end_time - start_time) * 500;
		}
		if(start_time>=0 && start_time < 7 && end_time >=7){
			sum+= (7 - start_time)*500;
		}
		
		
		
		
		
		if(start_time >= 7 && end_time < 14){
			sum+= (end_time - start_time) * 1000;
		}
		if(start_time<=7 && end_time >14){
			sum+= 1000*7;
		}
		if(start_time>=7 && start_time < 14 && end_time >=14){
			sum+= (14 - start_time)*1000;
		}
		
		if(start_time<7 && end_time > 7 && end_time <14){
			sum+= (end_time - 7)*1000;
		}
		
		
		
		
		
		
		
		if(start_time >= 14 && end_time < 19){
			sum+= (end_time - start_time) * 1500;
		}
		if(start_time<=14 && end_time >19){
			sum+= 1500*5;
		}
		if(start_time>=14 && start_time < 19 && end_time >=19){
			sum+= (19 - start_time)*1500;
		}
		
		if(start_time<14 && end_time > 14 && end_time <19){
			sum+= (end_time - 14)*1500;
		}
		
		
		
		
		
		
		
		
		if(start_time >= 19 && end_time < 21){
			sum+= (end_time - start_time) * 1000;
		}
		if(start_time<=19 && end_time >21){
			sum+= 1000*2;
		}
		if(start_time>=19 && start_time < 21 && end_time >=21){
			sum+= (21 - start_time)*1000;
		}
		
		if(start_time<19 && end_time > 19 && end_time <21){
			sum+= (end_time - 19)*1000;
		}
		
		
		
		
		
		
		
		
	if(start_time >= 21 && end_time < 24){
			sum+= (end_time - start_time) * 500;
		}
//		if(start_time<=21 && end_time >24){
//			sum+= 500*7;
//		}
		if(start_time>=21 && start_time < 24 && end_time >=24){
			sum+= (24 - start_time)*500;
		}
		
		if(start_time<21 && end_time > 21 && end_time <24){
			sum+= (end_time - 21)*500;
		}
		
		
		
		cout<<"you should pay "<<sum<<" rwf"<<endl;
	}else{
		cout<<"INVARID INPUT, try again."<<endl;
	}
}
