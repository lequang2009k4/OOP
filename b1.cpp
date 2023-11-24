#include<bits/stdc++.h>
using namespace std;

class b1{
	private:
		int a;
		int b;
	public:
		int tong(){
			return a+b;
		}
		void set_a(int a){
			this->a=a;
		}
		void set_b(int b){
			this ->b =b;
		}
};
int main(){
	b1 A;
	int x,y;
	cin>>x;A.set_a(x);
	cin>>y;A.set_b(y);
	cout<<A.tong();
	
}


