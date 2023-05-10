#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	freopen("output.txt", "w", stdout);
	int n;
	double d1, d2, ad1, ad2, hp1, hp2, ahp1, ahp2, m1, m2, um1, um2;
	string c1, c2, a1, a2;
	cin >> n;
	cout << fixed << setprecision(4);
	while(n--){
		cin >> c1;
		cin >> d1 >> hp1 >> m1;
		cin >> a1;
		cin >> ad1 >> ahp1 >> um1;
		cin >> c2;
		cin >> d2 >> hp2 >> m2;
		cin >> a2;
		cin >> ad2 >> ahp2 >> um2;
		
		if(um1 <= m1){
			d1 = d1 + d1*ad1;
			hp1 = hp1 - hp1*ahp1;
			m1 = m1 - um1;
		}
		hp2 = hp2 - d1;
		if(hp2 > 0){
			if(um2 <= m2){
				d2 = d2 + d2*ad2;
				hp2 = hp2 - hp2*ahp2;
				m2 = m2 - um2;
			}
			hp1 = hp1 - d2;
			if(hp1 <=0)
				hp1 = 0;
		}
		else{
			hp2 = 0;
		}
		cout << c1 << "\nDano=" << d1 
			 << "\nHP=" << hp1
			 << "\nMana=" << m1 << '\n';
			 
		cout << c2 << "\nDano=" << d2 
			 << "\nHP=" << hp2
			 << "\nMana=" << m2 << '\n';
	}
}
