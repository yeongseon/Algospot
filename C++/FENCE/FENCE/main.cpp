#include <iostream>
#include <vector>

struct fence_s {
	int height;
	int count;
};

typedef fence_s fence_t;
using namespace std;

int main() {
	int testcase = 0;
	int maxsum = 0;

	vector<int> sum;

	cin >> testcase;
	
	for (int i = 0; i < testcase; ++i) {
		int fence_size = 0;
		cin >> fence_size;

		int temp;
		for (int j = 0; j < fence_size; ++j) {
			cin >> temp;
			sum.push_back(temp);
		}
	}


	return 0;
}