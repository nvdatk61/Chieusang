#include <iostream>
using namespace std;

int main(){
	int n, m, k;
	int d;
	int t;
	cin >> n >> m >> k;
	int a[1002];
	for (int i = 0; i < m; i++){
		cin >> a[i];
	}
	for (int i = 0; i < m; i++){
		for (int j = i; j < m; j++){
			if (a[j]<a[i]){	
				t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
	int range = 2 * k + 1;
	int dem;
	dem = (a[0] - 1 - k) / range + (n - a[m-1] - k) / range;
	dem = ((a[0] - 1 - k) % range > 0) ? dem + 1 : dem;
	dem = ((n - a[m-1] - k) % range > 0) ? dem + 1 : dem;
	for (int i = 0; i < m-1; i++){
		d = a[i + 1] - a[i] - 2 * k - 1;
		if (d > 0){
			dem += d / range;	
			if (d % range > 0){
				dem++;
			}
		}
	}
	cout << dem;
}