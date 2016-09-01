#include <iostream>
#include <math.h>
using namespace std;
long long int collatz(long long int);
void updateProgress(long long int, long long int);
int main() {
	long long int bestPair[] = { 0, 0 }; //[0] = num; [1] = len;
	long long int currentLen;
	for (long long int x = 1; x < 1000000; ++x) {
		currentLen = collatz(x);
		if (currentLen > bestPair[1]) {
			bestPair[0] = x;
			bestPair[1] = currentLen;
		}
		updateProgress(1000000 - 1, x);
	}
	cout << "\nBest Number: " << bestPair[0] << "\nChain Length: " << bestPair[1];
	system("pause");
	return 0;
}
long long int collatz(long long int num) {
	long long int length = 0;
	while (num != 1) {
		length++;
		if (!(num % 2)) {
			//even
			num /= 2;
		}
		else {
			num *= 3;
			num += 1;
		}
	}
	length++;
	return length;
}
void updateProgress(long long int max, long long int current) {
	cout << "\r/[[" << flush;
	//long long int lastPercentage = floor(((current - 1) / (double)max) * 100);
	long long int percentage = floor((current / (double)max) * 100);
	//if (percentage != lastPercentage) {
		for (long long int i = 0; i < percentage; ++i)
			cout << "%" << flush;
		for (long long int j = 0; j < 100 - percentage; j++)
			cout << " " << flush;
		cout << "]]\\ " << percentage << "% -- " << current << flush;
	//}
	return;
}
