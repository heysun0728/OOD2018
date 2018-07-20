#include "TriangularMatrix.h"
#include <bits/stdc++.h>
using namespace std;
int main(){
	Matrix M1, M2;
	cout << "* Assign values for matrix M1 *" << endl;
	M1.readMatrix();

	cout<<endl;
	cout << "* Assign values for matrix M2 *" << endl;
	M2.readMatrix();
	
	cout << "M1 size is: "<< M1.size() <<endl;
	cout << "M1 is: " << M1 << endl << endl;
	cout << "M2 size is: "<< M1.size() <<endl;
	cout << "M2 is: " << M2 << endl << endl;

	cout << "Matrix M3(M2)"<<endl;	
	Matrix M3(M2);
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M2=M1"<<endl;
	M2=M1;
	cout << "M2 is: " << M2 << endl << endl;

	cout << "M3 = M1 + M2" <<endl;
	M3 = M1 + M2;
	cout << "Now M3 is: " << M3 << endl << endl;
	
	cout << "M3 = M1 - M2" <<endl;
	M3 = M1 - M2;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 = M2 * M1" <<endl;
	M3 = M2 * M1;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 = 5 * M2" <<endl;
	M3 = 5 * M2;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 = M2 * 5" <<endl;
	M3 = M2 * 5;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 += M1" << endl;
	M3 += M1;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 -= M1" << endl;
	M3 -= M1;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 *= M1" << endl;
	M3 *= M1;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 *= 2" << endl;
	M3 *= 2;
	cout << "Now M3 is: " << M3 << endl << endl;
	
	cout << "M3 = M2 * 2 * M1" << endl;
	M3 = M2 * 2 * M1;
	cout << "Now M3 is: " << M3 << endl << endl;
	
	cout << "double d = M1(1,2)" << endl;
	double d = M1(1,2);
	cout << "Now d is: " << d << endl << endl;
	
	cout << "M2(1,1) equals to: " << M2(1,1) << endl << endl;
	

	cout << "---------- END PROGRAM ----------" << endl << endl;

	return 0;
}
