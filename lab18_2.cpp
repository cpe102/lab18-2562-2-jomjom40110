//Modify function overlap() form lab18_1.cpp by using pointers as input arguments.
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *,Rect *);

int main(){
	Rect A,B;
	cout << "Please input Rect 1 (x y w h): ";
	cin >> A.x >> A.y >> A.w >> A.h;
	cout << "Please input Rect 2 (x y w h): ";
	cin >> B.x >> B.y >> B.w >> B.h;
	cout << "Overlap area = " <<  overlap(&A,&B);	//W_overlap * H_overlap
	return 0;
}

double overlap(Rect *A,Rect *B)
{
	double W_ovlp[2];
	double H_ovlp[2];
	W_ovlp[0] = max((*A).x,(*B).x);
	W_ovlp[1] = min((*A).x+(*A).w,(*B).x+(*B).w);
	H_ovlp[0] = min((*A).y,(*B).y);
	H_ovlp[1] = max((*A).y-(*A).h,(*B).y-(*B).h);
	double X = W_ovlp[1] - W_ovlp[0];
	double Y = H_ovlp[0] - H_ovlp[1];
	if(X < 0 || Y < 0) return 0;
	else return abs(X)*abs(Y);
}