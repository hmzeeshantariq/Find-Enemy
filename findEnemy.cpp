#include <iostream>
#include <string>
using namespace std;

int findEnemy(string* mat, int size) 
{	
	// find 2
	// if not found, then exit.
	// Here b is associated with 2.
	int len;
	bool found = false;
	int br, bc;
	for (int i = 0; i < size; i++) {
		len = mat[i].length();
		for (int j = 0; j < len && !found; j++) {
			if (mat[i][j] == '2') {
				found = true;
				br = i;
				bc = j;
			}
		}
	}
	if(!found) return 0;
	
	// find 1
	// Here a is associated with 1.	
	found = false;
	int ar, ac;
	for (int i = 0; i < size; i++) {
		len = mat[i].length();
		for (int j = 0; j < len && !found; j++) {
			if (mat[i][j] == '1') {
				found = true;
				ar = i;
				ac = j;
			}
		}
	}
	
	// dr1 = straight distance of row from 1 to 2
	// dr2 = wrap distance of row from 1 to 2

	// dc1 = straight distance of column from 1 to 2
	// dc2 = wrap distance of column from 1 to 2

	int dr1, dr2, dc1, dc2;

	len = mat[br].length();
	dc1 = abs(bc - ac);
	dc2 = abs(len - bc) + (0 + ac);

	dr1 = abs(br - ar);
	dr2 = abs(size - br) + (0 + ar);

	// find which distance is shortest 
	// for row and column
	dr1 < dr2? ar = dr1: ar = dr2;
	dc1 < dc2? ac = dc1: ac = dc2;

	// adding both rows and columns 
	// results in total steps moved

	return ac + ar;
}


int main() 
{
	string mat[] = {"000", "100", "002"};
	// Here is what matrix looks like:
	// 0 0 0
	// 1 0 0
	// 0 0 2

	cout << findEnemy(mat, mat->length());
	return 0;
}
