#include <iostream>
#include <vector>

using namespace std;

int D[3001] = {};
vector<int> arr;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr.push_back(input);
    }

    int max = 0;
    int ret = 1;
    D[0] = 0;
    D[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        max = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i-1] > arr[j-1] && max < D[j])
                max = D[j];
        }
        D[i] = max + 1;
        if (ret < D[i])
            ret = D[i];
    }
    cout << ret;
    return 0;
}
