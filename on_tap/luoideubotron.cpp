#include<bits/stdc++.h>

using namespace std;

int main() {
	//khai bao cac gia tri ban dau
	const int lx = 4;
	const int ly = 4;
	const int NI = 100;
	const int NJ = 50;
	//tao mang
	float x[NI][NJ] = {};
	float y[NI][NJ] = {};
	
	const double p = 0.1; // he so nen
	const double q = 1.8;
	
	// tinh den x va denta y
	double dxi = 1.0 / (NI - 1);
	double d_eta = 1.0 / (NJ - 1);
	//cac gia tri tai bien
	for (int i = 0; i < NI; i++) {
		double xi = dxi * i;
		x[i][0] = xi * lx;
		x[i][NI - 1] = x[i][0];
		y[i][NJ-1] = ly;
		if(x[i][0]<2){
			y[i][0] = 0;
		}
		else{
			y[i][0] = x[i][0]-2;
		}
	}
	

	// nhap gia tri cac diem nut vao mang
	for (int i = 0; i < NI; i++) {
		double xi = dxi * i;
		for (int j = 0; j < NJ; j++) {		
			double eta = d_eta * j;
			//double dy = eta;
			double dy = p*eta + (1-p)*(1-tanh(q*(1-eta))/tanh(q));			
			x[i][j] = x[i][0]+(x[i][NI-1]-x[i][0])*xi;	
			y[i][j] = y[i][0]+(y[i][NJ-1]-y[i][0])*dy;
		}
	}
	int n = 0;
	//phuong phap elip
	while(n<100){
		for (int j = 1; j < NJ-1; j++){
			for (int i = 1; i < NI-1; i++){
				// cong thuc lam tron luoi
				double anpha = pow(x[i][j+1]-x[i][j-1],2)/4+pow(y[i][j+1]-y[i][j-1],2)/4;
				double beta = (x[i+1][j]-x[i-1][j])*(x[i][j+1]-x[i][j-1])/4+(y[i][j+1]-y[i][j-1])*(y[i+1][j]-y[i-1][j])/4;
				double gamar = pow(x[i+1][j]-x[i-1][j],2)/4+pow(y[i+1][j]-y[i-1][j],2)/4;
				double A = x[i+1][j-1]+x[i-1][j-1] - x[i-1][j+1]-x[i+1][j+1];
				//thu gon cong thuc
				double k = anpha*(x[i+1][j]+x[i-1][j])+gamar*(x[i][j+1]+x[i][j-1]);
				double l = anpha+gamar;
				double m = anpha*(y[i+1][j]+y[i-1][j])+gamar*(y[i][j+1]+y[i][j-1]);
				
				x[i][j] = k/(2*l) -beta*A/(4*l);
				y[i][j] = m/(2*l)-beta*A/(4*l);
			}          
		}
		n++; 
	}
	// xuat file file o trong cho luu c++
	ofstream outfile("test5.tec");
	outfile << "VARIABLES = X Y" << endl;
	outfile << "ZONE I = " << NI << ", J = " << NJ << ", F = POINT" << endl;
	for (int j = 0; j < NJ; j++)
	{
		for (int i = 0; i < NI; i++)
		{
			outfile << x[i][j] << " " << y[i][j] << endl;
			cout << x[i][j] << "\t" << y[i][j] << endl;
		}
	}
	outfile.close();

	return 0;
}
