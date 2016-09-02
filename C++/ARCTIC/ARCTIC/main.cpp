#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct point_s {
	double x, y;
} point_t;

const int MAX_VERTEX = 100;
const double MAX_COST = 2000.0;

int N;
double adj_mat[MAX_VERTEX][MAX_VERTEX];
double mincost[MAX_VERTEX];
bool selected[MAX_VERTEX];
point_t pt[MAX_VERTEX];

double getDistance(point_t p1, point_t p2) {
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	return sqrt(x*x + y*y);
}

double prim() {
	for (int i = 0; i < N; i++) {
		mincost[i] = MAX_COST;
		selected[i] = false;
	}

	mincost[0] = 0.0;
	double ans = 0.0;

	while (true) {
		int v = -1;

		for (int u = 0; u < N; u++) {
			if (!selected[u] && (v == -1 || mincost[u] < mincost[v]))
				v = u;
		}

		if (v == -1)
			break;
		selected[v] = true;

		ans = max(mincost[v], ans);

		for (int u = 0; u < N; u++) {
			mincost[u] = min(mincost[u], adj_mat[v][u]);
		}

	}

	return ans;
}
int main()
{
	int c;

	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> pt[i].x >> pt[i].y;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				double distance = getDistance(pt[i], pt[j]);
				adj_mat[i][j] = distance;
				adj_mat[j][i] = distance;
			}
		}

		double ans = prim();

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << ans << endl;

	}

	return 0;
}