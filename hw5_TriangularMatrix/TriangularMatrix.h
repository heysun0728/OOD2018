#include <iostream>
class Matrix{
	private:
		int rowNum;
		int totalNum;
		int IsUpper;
		double* element;
	public:
		Matrix();//constructor
		Matrix(const Matrix&);//copy constructor
		~Matrix();//destructor
		void readMatrix();
		int size() const;
		int elementIndex(int,int) const;
		int IsUpperOrNot() const;
		const Matrix& operator=(const Matrix&);
		friend std::ostream& operator<<(std::ostream&,const Matrix&);
		double operator()(int,int) const;
		Matrix operator+=(const Matrix&);
		Matrix operator-=(const Matrix&);
		Matrix operator*=(const Matrix&);	
		Matrix& operator*=(double);	
		Matrix operator+(const Matrix&);
		Matrix operator-(const Matrix&);
		Matrix operator*(const Matrix&);
		Matrix operator*(double);
		friend Matrix operator*(double,const Matrix&);
		void insert(int);	
};
