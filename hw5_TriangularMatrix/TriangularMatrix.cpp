#include "TriangularMatrix.h"
#include <bits/stdc++.h>
using namespace std;
Matrix zeroMatrix;
Matrix::Matrix():totalNum(0),rowNum(0),IsUpper(0),element(NULL){}
Matrix::Matrix(const Matrix& m):totalNum(m.totalNum),rowNum(m.rowNum),IsUpper(m.IsUpper),element(NULL){
	element=new double[totalNum];
	int i;	
	for(i=0;i<totalNum;i++){
		element[i]=m.element[i];
	}
}
Matrix::~Matrix(){
	delete [] element;
}
const Matrix& Matrix::operator=(const Matrix & m){
	if(m.rowNum==0) return (*this);//if m=zeroMatrix
	if(rowNum!=0) delete [] element;
	totalNum=m.totalNum;
	rowNum=m.rowNum;
	IsUpper=m.IsUpper;
	element=new double[totalNum];
	int i;	
	for(i=0;i<totalNum;i++){
		element[i]=m.element[i];
	}
	return (*this);
}
void Matrix::readMatrix(){
	int i,j;
	double insertValue;	
	cout<<"<prompt> specify number of rows:"<<endl;
	cout<<"<user input>";
	cin>>rowNum;
	cout<<"<prompt> is upper or lower triangular: (upper: 1, lower:0)"<<endl;
	cout<<"<user input>";
	cin>>IsUpper;
	cout<<"<prompt> input elements of the matrix:"<<endl;
	cout<<"<user input>";
	totalNum=((rowNum+1)*rowNum)/2;
	if(rowNum!=0) delete [] element;
	element=new double[totalNum];
	for(i=0;i<totalNum;i++){
		cin>>element[i];
	}
}		
ostream& operator<<(ostream& os,const Matrix& m){
	os<<"\n";
	int i,j;	
	for(i=1;i<=m.rowNum;i++){
		for(j=1;j<=m.rowNum;j++){
			os<<m(i,j)<<"\t";	
		}
		os<<"\n";	
	}
	return os;
}
int Matrix::size() const{
	return rowNum;
}
int Matrix::IsUpperOrNot() const{
	return IsUpper;
}
int Matrix::elementIndex(int i,int j) const{
	int x,y,count=0;
	for(x=1;x<=rowNum;x++){
		for(y=1;y<=rowNum;y++){
			if(IsUpper==0&&y>x) break;
			if(IsUpper==1&&y<x) continue;
			if(i==x&&j==y) return count;			
			count++;
		}
	}
	return 0;
}
double Matrix::operator()(int i,int j) const{
	if(IsUpper==0){ 
		if(j>i) return 0;
		return element[elementIndex(i,j)];
	}
	else{
		if(j<i) return 0;
		return element[elementIndex(i,j)];
	}
}
bool CantOperate(const Matrix& l,const Matrix& r,string op){
	if(l.IsUpperOrNot()!=r.IsUpperOrNot()){
		cout<<"You cannot "<<op<<" an upper triangular matrix with a lower triangular matrix"<<endl;
		return true;
	}
	if(l.size()!=r.size()){
		cout<<"You cannot "<<op<<" two different size matrix"<<endl;
		return true;
	}
	return false;
}
Matrix Matrix::operator+=(const Matrix& m){
	string op="add";
	if(CantOperate((*this),m,op)) return zeroMatrix;
	int i;
	for(i=0;i<totalNum;i++){
		element[i]=element[i]+m.element[i];
	}
	return (*this);
}
Matrix Matrix::operator-=(const Matrix& m){
	string op="substract";
	if(CantOperate((*this),m,op)) return zeroMatrix;
	int i;
	for(i=0;i<totalNum;i++){
		element[i]=element[i]-m.element[i];
	}
	return (*this);
}
Matrix& Matrix::operator*=(double s){
	int i;
	for(i=0;i<totalNum;i++){
		element[i]=element[i]*s;
	}
	return (*this);
}

Matrix Matrix::operator*=(const Matrix& m){
	string op="multiply";
	if(CantOperate((*this),m,op)) return zeroMatrix;		
	int i,j,k,count=0;
	double sum;
	double e[totalNum];
	for(i=1;i<=rowNum;i++){
		for(j=1;j<=rowNum;j++){
			if(IsUpper==0&&j>i) continue;
			if(IsUpper==1&&j<i) continue;
			sum=0;
			for(k=1;k<=rowNum;k++){			
				sum+=(*this)(i,k)*m(k,j);			
			}
			e[count++]=sum;
		}
	}
	for(i=0;i<totalNum;i++){
		element[i]=e[i];
	}
	return (*this);
}

Matrix Matrix::operator+(const Matrix& m){
	string op="add";
	if(CantOperate((*this),m,op)) return zeroMatrix;	
	Matrix ans(*this);
	ans+=m;
	return ans;
}

Matrix Matrix::operator-(const Matrix& m){
	string op="subtract";
	if(CantOperate((*this),m,op)) return zeroMatrix;		
	Matrix ans(*this);
	ans-=m;
	return ans;
}

Matrix Matrix::operator*(double s){	
	Matrix ans(*this);
	ans*=s;
	return ans;
}

Matrix Matrix::operator*(const Matrix& m){
	string op="multiply";
	if(CantOperate((*this),m,op)) return zeroMatrix;				
	Matrix ans(*this);
	ans*=m;
	return ans;
}
Matrix operator*(double s,const Matrix& m){
	Matrix ans(m);
	ans*=s;
	return ans;
}

