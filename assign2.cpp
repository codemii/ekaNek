#include<bits/stdc++.h>
using namespace std;

void printCheapestFlights(int *dtm, int *mtd, int k, int n, int m){
	int i, j, temp = n*m;
	vector<int> arr;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			arr.push_back(dtm[i]+mtd[j]);
		}
	}

	vector<int> sarr = arr;
	sort(sarr.begin(), sarr.end());
	
	bool flag[temp];
	memset(flag, false, temp*sizeof(bool));
	for(i=0; i<k; i++){
		for(j=0; j<arr.size(); j++){
			if(arr[j]==sarr[i] && !flag[j]){
				flag[j]=true;
				break;
			}
		}
		cout<<dtm[j/15]<<", "<<mtd[j%15]<<endl;
	}
}

int main(){
	int dtm[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
	int mtd[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75};

	int k;
	cout<<"Enter value of k : ";
	cin>>k;

	int n = sizeof(dtm)/sizeof(dtm[0]);
	int m = sizeof(mtd)/sizeof(mtd[0]);
	printCheapestFlights(dtm, mtd, k, n , m);
	return 0;
}
