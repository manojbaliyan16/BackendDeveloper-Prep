#include <iostream>
#include <vector>

using namespace std;
// Qu .  Find the longest Peak in an array 
// An element is the peak if its neighbors are smaller then this 
// Left Side Neighbors : from an element a[i] all elements till they decreasing will be peak(its) suitable Neighbors
// Right Side Neighbors : from an element a[i] all elements on right till they decreasing will be peak(its) suitable Neighbors
// So By this approach the first and last elemnet does not have left and right neighbors respectivley, So they can't be suitable choice for the \
// peak 

// Algo  
// find the peak element : whose both side neibours are decreasing that will be suitable peak elelment 
//                                                         ________________
// find the length of this peak: length of this peak   15 |2 3 4 10 6 1 0| 11 12: peak element is 10 and its length is 2 to 0 means 6 
// store this lenght and find the another peak and its length if another one is max update the peak length and so on 
// So here we are traversing each element at least one time and taking one auxilary element 
// So T(n)= O(n) : 
// and Space complesity is O(1) Constant time

int findLongestPeak(vector<int> &arr)
{   int longestpeakLength=0;
    int i=1; // because left boarder or index 0 element is not the right participated candidate
    
    while(i < arr.size()-1) // arr.size()-1 Because last boreder element is the not the participated candidate 
    {
        bool isPeak= ((arr[i-1] < arr[i]) && (arr[i+1] < arr[i]));
        if(!isPeak)
        {
            i++;
            continue;
        }
        int leftIndex=i-2; // Here We have taken i-2 because laready we have compare that array[i-1] < arr[i] in #27
        while((leftIndex >=0) && (arr[leftIndex] < arr[leftIndex+1]))
        {
            leftIndex -=1;
            
        }
        int rightIndex=i+2;
        while((rightIndex < arr.size()) && (arr[rightIndex] < arr[rightIndex-1]))
        {
            rightIndex+=1;
        }
        int currentPeakLength=rightIndex-leftIndex-1;
        longestpeakLength=max(currentPeakLength,longestpeakLength);
        i=rightIndex; // 
    }

    return longestpeakLength;
}

int main()
{

    vector<int> myvec{1,2,3,3,4,0,10,6,5,-1,-3,2,3};
    cout << "Longest Peak length is " << findLongestPeak(myvec) << endl;
    return 0;
}


                                                          
