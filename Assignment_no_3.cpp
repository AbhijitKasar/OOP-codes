#include<iostream>
using namespace std;

class Complex
{
	private:
		float real;
		float img;

	public:
		Complex()
		{
			real=0;
			img=0;
		}
		//Parameterized constructor
		Complex(int rr,int im)
		{
			real=rr;
			img=im;
		}
		//Display function to display the result
		void display()
		{
			if(img>=0)
			{
				cout<<real<<"+"<<img<<"i"<<endl;
			}
			else
			{
				cout<<real<<img<<"i"<<endl;
			}
		}

			Complex operator +(Complex s);
			friend Complex operator -(Complex s,Complex ss);//Same as above but using friend function
			Complex operator *(Complex s);
			Complex operator /(Complex s);

}c1,c2,c3;

//Addition
Complex Complex::operator+(Complex c2)
{
	c3.real=real+c2.real;
	c3.img=img+c2.img;
	return c3;
}

//Substraction using friend function
Complex operator-(Complex c1,Complex c2)
{
	c3.real=c1.real-c2.real;
	c3.img=c1.img-c2.img;
	return c3;
}
//Multiplication
Complex Complex::operator*(Complex c2)
{
	c3.real=real*c2.real-img*c2.img;
	c3.img=img*c2.real+real*c2.img;
	return c3;
}
//Division
Complex Complex::operator/(Complex c2)
{
	c3.real=(real*c2.real+img*c2.img)/(c2.real*c2.real+c2.img*c2.img);
	c3.img=(img*c2.real-real*c2.img)/(c2.real*c2.real+c2.img*c2.img);
	return c3;
}

int main()
{
int r,i;			//These are to accept the value from user
cout<<"Enter 1st real number's real and imaginary part: ";
cin>>r>>i;
Complex c1(r,i);
cout<<"Enter 2nd real number's real and imaginary part: ";
cin>>r>>i;
Complex c2(r,i);
int ch;			//to get the  choice from user
do{
cout<<"\nMain Menu"<<endl;
cout<<"1.Addition\n2.Substraction\n3.Multiplication\n4.Division"<<endl;
cout<<"Enter your choice: ";
cin>>ch;
switch(ch)
{
case 1:c1+c2;
	c3.display();
	break;
case 2:c1-c2;
	c3.display();
	break;

case 3:c1*c2;
	c3.display();
	break;
case 4:c1/c2;
	c3.display();
	break;
default:cout<<"Invalid Choice"<<endl;
}
}while(ch!=0);

return 0;
}
