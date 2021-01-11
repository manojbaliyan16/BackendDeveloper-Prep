#include <iostream>
#include <vector>

using namespace std;

// space complexity O(n)  due to extra vector and Time complexity is also O(n)
vector<int> spiralPrint(vector<vector<int> > &myvec)
{    
    vector<int> result;
    int ER= myvec.size()-1;
    int EC= myvec[0].size()-1;
    int SR=0;
    int SC=0;
    while(SR < ER && SC < EC)
    {
         for(int col=SC;col<=EC;++col)
        result.push_back(myvec[SR][col]);
        
        for(int row=SR+1;row<=ER;++row)
        {
             result.push_back(myvec[row][EC]);
        }
        for(int col=EC-1;col>=SC;--col)
        {
            result.push_back(myvec[ER][col]);
        }
        for(int row=ER-1;row>SR;--row)
        {
            result.push_back(myvec[row][SC]);
        }
        SR+=1;
        ER-=1;
        SC+=1;
        EC-=1;
    }
    for(const auto elem:result)
    cout << elem << " ";
    cout << endl;
    return result;


}

int main()
{
    vector<vector<int> > myvector{{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
    cout << "row " << myvector.size() << " col " << myvector[0].size() << endl;
    vector<int> result=spiralPrint(myvector);
    /*  {},,,},
        1,2,3,11
        4,5,6,12
        7,8,9,13
    
    
    */

    return 0;


}