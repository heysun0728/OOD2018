#include "Bag.h"
#include <bits/stdc++.h>
using namespace std;
int main(){
	//main_program.txt
	Bag<string> a;           //Bag constructed
	cout<<a.size()<<endl;	 //0
	cout<<a.empty()<< endl;  //1
	cout<<a.ended() << endl; //1
	a.next();                //Please initializes
	a.start();               //Please input item
	a.insert("a1");
	a.insert("a2");
	a.start();
	cout << a.currentValue() << endl; //a1
	a.next();							
	cout << a.currentValue() << endl; //a2
	cout << a.currentCount() << endl; //2
	a.next();
	cout << a.ended() <<endl;         //1
	a.next();                         //Please initializes
	cout << a.ended() <<endl;         //1
	Bag<string> a_copy = a;	          //Bag copy constructed
	cout << a_copy.size() << endl;    //2
	a.insert("a3"); 
	a.next();                         //Please initializes
	cout<<a.currentCount()<<endl;     //Please initializes
					  //0
        cout<<a.currentValue()<<endl;     //Please initializes

	cout<<a.erase("a2")<<endl;        //2
	cout<<a.erase("a4")<<endl;	  //0
	a.next();                         //Please initializes
	cout << a_copy.size() << endl;    //2
	
 
	Bag<string> a_assignment;           //Bag constructed
	a_assignment.insert("assignment1");
	a_assignment = a;                   //Bag assignment operator
	cout << a_assignment.size() << endl;//2
	a_assignment.start();
	cout << a_assignment.currentValue() << endl; //a1
	a_assignment.next();
	cout << a_assignment.currentValue() << endl; //a3
	a_assignment.next();
	cout << a_assignment.currentValue() << endl; //Please initailizes

	Bag<int> b; 		     	 //Bag constructed
	b.insert(10);
	b.insert(20);
	b.insert(20);
	b.insert(20);
	b.insert(30);
	b.insert(10);
	cout << b.size() << endl;	 //6		
	cout << b.uniqueSize() << endl;	 //3	
	cout << b.erase(10) << endl;	 //1	
	cout << b.eraseAll(20) << endl;	 //3
	cout << b.erase(20)<<endl;       //0
	cout << b.contains(20) << endl;	 //0	
	cout << b.count(10) << endl;     //1

	Bag<string> c1, c2, c_result;    //Bag constructed
					 //Bag constructed
					 //Bag constructed	
	c1.insert("duck");
	c1.insert("duck");
	c1.insert("goose");
	c1.insert("chicken");
	c1.insert("chicken");
	c2.insert("duck");
	c2.insert("goose");
	c2.insert("goose");
	c2.insert("chicken");
	c2.insert("chicken");
	c1.next();                       //Please initiallizes
	c1.start();
	c1.next();c1.next();c1.next();
	combine(c1, c2, c_result);      
	cout<<"c_result=c1+c2"<<endl;	
	c_result.printAllItem();         //print all item in result
	cout<<endl;
	cout<<"c_result=c1-c2"<<endl;	
	subtract(c1, c2, c_result);      //print all item in result
	c_result.printAllItem();
	cout<<endl;
	
	//combine subtract special case
	combine(c1,c1,c1);	
	cout<<c1.size()<<endl;    //10	
	subtract(c1,c2,c1);		
	cout<<c1.size()<<endl;    //5
	subtract(c1,c1,c1);
	cout<<c1.size()<<endl;    //0

	//different type
	Bag<char> d;                  //Bag constructed
	d.insert('a');
	cout<<d.currentValue()<<endl; //Please initializes
	
	Bag<double> e;                  //Bag constructed
	e.insert(10.8);
	e.insert(9.5);
	e.insert(7.5);
	e.start();
	cout<<e.currentValue()<<endl; //10.8
	e.insert(4.2);
	cout<<e.currentValue()<<endl; //Please initializes
				      //0
	cout<<e.erase(10.8)<<endl;    //1
	
	return 0;
}
