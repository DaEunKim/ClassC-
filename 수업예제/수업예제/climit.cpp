#include <iostream>
#include <climits>
using namespace std;

class Ex{
	public:
	short year = SHRT_MAX;
	int sale = INT_MAX;
	long total_sale = LONG_MAX;
};

int main(){
	Ex ex;
	cout << "short size= " <<sizeof(short)<<endl;
	cout << "int size= " <<sizeof(int) <<endl;
	cout << "long size= " <<sizeof(long) <<endl<<endl;

	cout << "short max= " << ex.year <<endl;
	cout << "int max= "<< ex.sale <<endl;
	cout << "long max= " << ex.total_sale<<endl<<endl;

	cout << "short min= "<<SHRT_MIN<<endl;
	cout << "int min= "<<INT_MIN<<endl;
	cout <<"long min= "<<LONG_MIN<<endl<<endl;

	return 0;
}
