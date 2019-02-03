#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

int toPerfectSqr(int n) {
	int i = n;
	long double temp = sqrt(n);
	
	if (temp - round(temp) == 0) {
		return i;
	}
	else {
		toPerfectSqr(i + 1);
	}

}




int main(int argc, char* argv[]) {

	ArgumentManager am(argc, argv);
	string inputName = am.get("input");
	string outputName = am.get("output");

	//ifstream input(inputName);
	ifstream input("testing.txt"); //for testing
	ofstream output("output2.txt"); //for testing
	//ofstream output(outputName);

	char s[1000]; // not sure about the limit of characters.
	while (!input.eof()) {
		input.getline(s, 1000);
	}

	int size = toPerfectSqr(strlen(s)-1); //dimension of the 2D array
	size = sqrt(size);
	int d = size - 1; //last index of the string, used for counting
	int lastIndex = strlen(s)-1; //last index of the string
	int flag = (size*size) - 1; // total # of cells in the 2D array
	int n = 0, x = 0, count = 0; //variables for the algorithm filling in the 2D array


	//making a 2D array of dimension {size,size}
	char **sp = new char*[size];
	for (int a = 0; a < size; a++) {
		sp[a] = new char[size];
	}

	//always filling in the first row of the 2D array
	for (int i = 0; i <= d; i++) {
		sp[n][i] = s[i];
		count++;
	}
	n++;

	while (count <= flag) {

		for (int j = x; j <= d; j++) {
			if (count <= lastIndex) {
				sp[n][j] = s[count];
				count++;
			}
			else {
				sp[n][j] = '.';
				count++;
			}
		}
		n++;

		for (int k = n; k <= d; k++) {
			if (count <= lastIndex) {
				sp[k][d] = s[count];
				count++;
			}
			else {
				sp[k][d] = '.';
				count++;
			}
		}

		for (int l = d - 1; l >= x; l--) {
			if (count <= lastIndex) {
				sp[d][l] = s[count];
				count++;
			}
			else {
				sp[d][l] = '.';
				count++;
			}
		}
		d--;

		for (int m = d; m >= n; m--) {
			if (count <= lastIndex) {
				sp[m][x] = s[count];
				count++;
			}
			else {
				sp[m][x] = '.';
				count++;
			}
		}
		x++;
	}

	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			output << sp[row][col];
		}
		output << endl;
	}

	input.close();
	output.close();
	
	system("pause");

	return 1;
}
