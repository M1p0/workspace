
#include <iostream>
#include <math.h>
using namespace std;


#define		TRUE	1
#define		FALSE	0
#define		OK		1
#define		ERROR	0
#define		MAXSIZE	100


typedef int ElemType;

typedef struct{
	ElemType num;
	ElemType den;
}Rational;


void InitRational(Rational *a);
void RSum(Rational a,Rational b,Rational *c);
void RSub(Rational a,Rational b,Rational *c);
void RMul(Rational a,Rational b,Rational *c);
void RDiv(Rational a,Rational b,Rational *c);
void RPrint(Rational a);
void RNorm(Rational *a);

void RNorm(Rational *a)
{
	int temp=0;
	temp=a->num<a->den?a->num:a->den;
	for(;;temp--)
	{
		if(a->num%temp==0&&a->den%temp==0)
		  break;
	}
	a->num=a->num/temp;
	a->den=a->den/temp;

}

void InitRational(Rational *a)
{
	int above,blow;
	char temp;
	cin>>above>>temp>>blow;
	a->num=above;
	a->den=blow;

}

void RSum(Rational a,Rational b,Rational *c)
{

}

void RSub(Rational a,Rational b,Rational *c)
{

}

void RMul(Rational a,Rational b,Rational *c)
{

}

void RDiv(Rational a,Rational b,Rational *c)
{

}

void RPrint(Rational a)
{
	cout<<a.num<<"/"<<a.den<<endl;
}





int main(){
	Rational m,n,s;
	InitRational(&m);
	RNorm(&m);
	RPrint(m);
	InitRational(&n);
	RPrint(n);
	//RSum(m,n,&s);
/*	RSub(m,n,&s);
	RMul(m,n,&s);
	RDiv(m,n,&s);*/
	//RPrint(s);

	getchar();


}

