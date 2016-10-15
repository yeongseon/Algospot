#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int makeCoins(int money, int number, vector<int> &coins) {
	/*
	cout << money << endl;
	for (int i = 0; i < number; i++) {
		cout << coins[i] << " ";
	}
	*/
	vector< vector<int> > arr;
	int size = (int)(money / coins[0]);
	
	for (int i = 0; i < number; i++) {
		vector<int> row;
		for (int j = 0; j < size; j++) {
			row.push_back(0);
		}
		arr.push_back(row);
	}

	/*
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	*/
	// �ʱⰪ
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < size; j++) {
			if (i == 0 || j == 0)
				arr[i][j] = 1;
			if (j < (coins[1] / coins[0]) - 1 )
				arr[i][j] = 1;
		}
	}
#if 1
	for (int i = 1; i < number; i++) {
		for (int j = (coins[1] / coins[0] - 1); j < size; j++) {
			// arr[i][j] += arr[i-1][j];
			int money = coins[0] * (j + 1);
			int size = money / coins[i];

			for (int k = 0; k <= size; k++) {
				int remain = money - (coins[i] * k);
				// arr[i][j] = remain;
				
				if (remain == 0)
					arr[i][j] += 1;
				else {
					int index = (remain / coins[0]) - 1;
					arr[i][j] += arr[i - 1][index];
				}

				if (arr[i][j] > 1000000007)
					arr[i][j] = arr[i][j] % 1000000007;
			}
		}
	}
#endif
#if 0
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
#endif
	return arr[number-1][size-1];
}

int main() {
	int T = 0; // testcase
	int M = 0; // money
	int N = 0; // number of coin
	int ret = 0;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		vector< int > coins;
		cin >> M >> N;
		// cout << M << N;
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			coins.push_back(temp);			
		}
		ret = makeCoins(M, N, coins);		
		cout << ret << endl;
		coins.clear();
	}
	return 0;
}