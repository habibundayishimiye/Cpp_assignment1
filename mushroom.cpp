/*group members 1.NDAYISHIMIYE Habibu 222005474
                2.UWABABYEYI MBABAZI Aline 222009293
                3.IRADUKUNDA Bonheur 222005615
                */
//This a problem analysis which show us each mushroom and it's
//corresponding properties             
/*
->AGARIC JAUNISSANT:-GILLS->MEADOWS(NO FOREST)->COMVEX CUP ->RING
->AMANITE TUEMOUCHE:-GILLS->FOREST->COMVEX CUP ->RING 
->CEPE DE BORDEAU:-PORES(NO GILLS)->FOREST->(NO COMVEX CUP) ->(NO RING)
->COPRIN CHEVELU:-GILLS->MEADOWS(NO FOREST)->(NO COMVEX CUP) ->RING
->GIROLLE:-GILLS->FORESTS->(NO COMVEX CUP)->(NO RING)
->PIED BLEU:-GILLS->FOREST-> COMVEX CUP->(NO RING)
*/
#include<iostream>
using namespace std;
int main(){
	char gills, forest, ring, comvex_cup;
	cout<<"----- please enter y for yes and n for no ------- \n \n";
	cout<<"does your mushrooom have gills :\n";
	cin>>gills;
	cout<<"does your mushroom grow in forest ?: \n";
	cin>> forest;
	cout<<"does your mushroom have a ring ?: \n";
	cin>> ring;
	

//here program is going to check questions asked
if(gills =='y'&&forest =='y'&&ring =='y'){
		cout<<"your mushroom is: AMANITE TUEMOUCHE";
	}
	else if(gills == 'y'&&forest == 'n'&&ring =='y'){
		cout<<"your mushroom is : AGARIC JAUNISSANT";
	}
	else if(gills =='n'&&forest =='y'&&ring =='n'){
		cout<<"your mushroom is : CEPE DE BORDEAU";
	}
		else if(gills =='y'&&forest =='y'&&ring =='n'){
		cout<<"does your mushroom have comvex cup? : \n";
	cin>> comvex_cup;//here the fouth question can be asked
	if(comvex_cup =='y') cout<<"your mushrooom is: GIROLLE ";
	else if(comvex_cup =='n')
	cout<<" your mushroom is : PIED BLEU";
	}
	
	else if (gills!='y'||gills!='n'||forest!='n'||forest!='y'||
ring!='n'||ring!='y'){
	cout<<" answer must be only either y or n !!\n";
}	
	
	return 0;
}

