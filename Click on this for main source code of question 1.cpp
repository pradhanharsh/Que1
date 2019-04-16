#include<iostream> 
using namespace std; 
int pro = 5; 
int process[5] = {0, 1, 2, 3, 4};
int available[4] = {1,5,2,0}; 
int res = 4; 
int main() 
{  
	int maxm[][res] = {{0,0,1,2}, 
					{1,7,5,0}, 
					{2,3,5,6}, 
					{0,6,5,2}, 
					{0,6,5,6}}; 
 
	int allot[][res] = {{0,0,1,2}, 
					{1,0,0,0}, 
					{1,3,5,4}, 
					{0,6,3,2}, 
					{0, 0,1,4}}; 
	
	int need[pro][res];
	for (int i = 0 ; i < pro ; i++) 
		for (int j = 0 ; j < res ; j++) 

			need[i][j] = maxm[i][j] - allot[i][j];
						
				bool finish[pro] = {0}; 

	int safeSeq[pro]; 

	int work[res]; 
	for (int i = 0; i < res ; i++) 
		work[i] = available[i]; 

	int count = 0; 
	while (count < pro) 
	{ 	bool found = false; 
		for (int p = 0; p < pro; p++) 
		{ 	
			if (finish[p] == 0) 
			{ 	
				int j; 
				for (j = 0; j < res; j++) 
					if (need[p][j] > work[j]) 
						break; 
				if (j == res) 
				{	for (int k = 0 ; k < res ; k++) 
						work[k] += allot[p][k]; 
						safeSeq[count++] = p; 	
						finish[p] = 1;
						found = true; 
				} 
			} 
		} 	
		if (found == false) 
		{ 
			cout << "System is not in safe state"; 
			return false;
		} 
	} 
	cout << "System is in safe state.\nSafe sequence is: "; 
	for (int i = 0; i < pro ; i++) 
		cout << safeSeq[i] << " "; 	
	return 0; 
}
