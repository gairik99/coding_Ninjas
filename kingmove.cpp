#include <bits/stdc++.h>
using namespace std;
int numberOfMoves(int kx, int ky, int rx1, int ry1, int rx2, int ry2)
{
    int cnt = 0;
    int dx[] = {1, 1, -1, -1, 0, 1, 0, -1};
    int dy[] = {1, -1, 1, -1, 1, 0, -1, 0};
    for (int i = 0; i < 8; i++)
    {
        int currentX = dx[i] + kx;
        int currentY = dy[i] + ky;
        if (currentX >= 0 && currentX <= 7 && currentY >= 0 && currentY <= 7)
        {
            if (currentX != rx1 && currentY != ry1 && currentX != rx2 && currentY != ry2)
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    int kx, ky, rx1, ry1, rx2, ry2;
    cin >> kx >> ky >> rx1 >> ry1 >> rx2 >> ry2;
    cout << numberOfMoves(kx, ky, rx1, ry1, rx2, ry2);
}
