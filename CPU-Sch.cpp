#include<iostream>
#include<cstdlib>
#include<time.h>
#include<algorithm>

using namespace std;

void FCFS(int p[],int n){
	int total_time=0;
    for(int i=n-2 ; i>=0 ;i--){
  		for(int j=i ; j>=0 ; j--){
   			total_time += p[j] ;
  		}
 	}
 	cout << " FCFS \t\t" << total_time << "\t\t\t"  << total_time/n << "\n" ;	
};

void SJF(int p[],int n){
	int total_time=0;
    for(int i=0 ; i<n ; i++){
  			for(int j=0 ; j<n ; j++){
   				int temp = p[j] ;
   				if(p[i] < p[j]){
    				p[j] = p[i] ;
    				p[i] = temp;
   				}
  			}
 		}
 		for(int i=n-2 ; i>=0 ;i--){
  			for(int j=i ; j>=0 ; j--){
   				total_time += p[j] ;
  			}
 		}
 	cout << " SJF \t\t" << total_time << "\t\t\t" << total_time/n << "\n" ;
}

void RR(int pm[],int n,int q_time){
	bool check_loop = false;
	int temp=0,sum=0,total_time=0;
	while(1){
		for(int i=0;i<n;i++){
    		check_loop = 0;
    		if(pm[i]>0){
    			sum = sum+temp;
    			total_time = total_time+sum;
    			if(pm[i]<=q_time){
    				temp = pm[i];
    				pm[i] = 0;
				}
				else{
					temp = q_time;
					pm[i] = pm[i] - q_time;
				}
			}
		}
        for(int i=0;i<n;i++){
			if(pm[i]>0){
				check_loop = true;
				break;
			}
    	}
   		if(check_loop == false) break;
	}
	cout << " RR \t\t" << total_time << "\t\t\t"  << total_time/n << "\n" ;	
}

int main(){
 	int n,n1,n2,n3;
 	while(1){
 		cout << "Enter # process : ";
        cin >> n;
        cout << "% for process that uses time 2-8 millisec for execution : ";
        cin >> n1;
        cout << "% for process that uses time 20-30 millisec for execution : ";
        cin >> n2;
        cout << "% for process that uses time 35-40 millisec for execution : ";
        cin >> n3;
        int p[n],pm[n];
        n1 = (n1 * n) / 100;
        n2 = (n2 * n) / 100;
        n3 = (n3 * n) / 100;
        
 		// initialize time to each process
 		for(int i=0 ; i<n1 ; i++) {
 			p[i] = rand()%7+2 ;
		}
 		for(int i=n1 ; i<n1+n2 ; i++) {
 			p[i] = rand()%11+20 ; 
		}
 		for(int i=(n1+n2) ; i<n ; i++) {
 			p[i] = rand()%6+35 ;
		} 

 		//shuffle order of process
 		random_shuffle(&p[0] , &p[n]);
		
		//copy array
 		for (int i=0; i<n; i++) {
 			int temp;
 			temp = p[i];
 			pm[i] = temp;
		}
		
		//show data set
		cout << endl;
 		cout << "Data set : \n";
 		cout << " | ";
 		for (int i = 0; i < n; i++){
            cout << p[i] << " | ";
        }

		//show result
		cout << "\n\n Algorithm\t" << "Total times (ms)\t" << "Average time (ms)\n" ;
		FCFS(p,n);
 		SJF(pm,n);
 		RR(p,n,50);
 		cout << "\n============================================================== \n";
	}
}
