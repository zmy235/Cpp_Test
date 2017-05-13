#include <iostream>

using namespace std;
void Cij(int i, int j,vector<int> &r,int num,vector<vector<int> > & result)
{
    //排列组合公式Cij
    //cout << n << ' ' << i << ' ' << j << endl;
    if (j == 1)
    {
        for (int k = 0; k < i; k++)
        {
            vector<int> temp(num);
            r[num - 1] = k;
            for (int i = 0; i < num; i++)
            {
                temp[i]=r[i];
                //cout << r[i] << ' ';
            }
            result.push_back(temp);
            //cout << endl;
        }
    }
    else if (j == 0)
    {
        //do nothing!
    }
    else
    {
        for (int k = i; k >= j; k--)
        {
            r[j-2] = k-1;
            Cij(k - 1, j - 1,r,num,result);
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

