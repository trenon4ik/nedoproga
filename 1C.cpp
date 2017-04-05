#include<vector>
#include<fstream>
#include<queue>
#include<map>
#include<string>
#include<algorithm>
#include<iostream>
#include<iterator>
#include<set>
#include<queue>
using namespace std;

vector<pair<int, vector<int>>> ans;
vector<int> mas;

int main()
{
	ifstream inf("input.txt");
	ofstream ouf("output.txt");
	int n;
	inf >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		inf >> a;
		mas.push_back(a);
		vector <int> b;
		b.clear();
		ans.push_back({ 0, b });
	}
	ans[0].first = 1;
	ans[0].second.push_back(mas[0]);
	for (int i = 1; i < n; i++)
	{
		int ma = i;
		for (int q = 0; q < i; q++)
		{
			if (mas[q] < mas[i])
			{
				if (ans[q].first > ans[ma].first)
					ma = q;
			}
		}
		ans[i].first = ans[ma].first + 1;
		ans[i].second = ans[ma].second;
		ans[i].second.push_back(mas[i]);
	}
	sort(ans.begin(), ans.end());
	ouf << n - ans[0].first<<"\n";
	for (int i = 0; i < ans[0].first; i++)
		ouf << ans[0].second[i]<<" ";
	inf.close();
	ouf.close();
	return 0;
}