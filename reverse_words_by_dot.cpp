#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char arr[] = "I.like.this.program.very.much";
    int i = 0;
    int store = strlen(arr);
    int count = 0;
    for (int m = 0; m < strlen(arr); m++)
        if (arr[m] == '.') count++;
    for (int j = 0; j < count; j++) {
        for (i = store - 1; i >= 0 && arr[i] != '.'; i--);
        for (int k = i + 1; k < store; k++) {
            cout << arr[k];
        }
        if (i >= 0) cout << ".";
        store = i;
    }
    for (int k = 0; k < store; k++) cout << arr[k];
    cout << endl;
    return 0;
}

	// char arr[] = "I.like.this.program.very.much";
	// int i = 0;
	// int store = strlen(arr);
	// int count = 0;
	// for (int m = 0; m < strlen(arr); m++)
	// 	if (arr[m] == '.') count++;
	// for (int j = 0; j<count; j++) {
	// 	for (i = store; arr[i] != '.'; i--) {

	// 	}	
	// 	for (int k = i; k < store+1; k++) {
	// 		cout << arr[k];
	// 	}
	// 	store = i-1;
	// }




    	//string arr = "I.like.this.program.very.much";
	//
	//int i = 0;
	//int length = arr.length();
	//int count = 0;
	//int help;
	//string arr1;
	//for (int i = length - 1; i >= 0; i--) {
	//	if (arr[i] == '.') {
	//		help = length - 1;
	//		length = i - 1;
	//		arr1.append(arr.substr(i + 1, help));
	//		arr1.append(".");
	//	}
	//}
	//arr1.append(arr.substr(0, length + 1));
	//cout << arr1;