#include<bits/stdc++.h>
using namespace std;

// function to print triplets with 0 sum
vector <set < int > > Triplets(int arr[], int n)
{
bool found = false;
vector< set<int> > output;
for (int i=0; i<n-1; i++)
{
// Find all pairs with sum equals to
// "-arr[i]"

vector <int> s;
for (int j=i+1; j<n; j++)
{
int x = -(arr[i] + arr[j]);
if (find(s.begin(),s.end(), x) != s.end())
{
set<int> myset2; myset2.insert(x);myset2.insert(arr[i]);myset2.insert(arr[j]);
bool flag = true;

for (int w = 0; w < output.size(); ++w)
{
set<int> myset1 = output[w];
if(myset2 == myset1) //check duplicates
{
flag = false;
break;
}
}
if(flag == true)
{
output.push_back(myset2);
printf("Possible Triplet %d %d %d\n", x, arr[i], arr[j]);
}
found = true;
}
else
s.push_back(arr[j]);
}
}

if (found == false)
{
cout << " No Triplet with sum equal to 0 exist in this array!" << endl;
}
return output;
}

int main()
{
int arr[] = {-1, 0, 1, 2, -1, -4}; //Input array
int n = 6; //size of the array
Triplets(arr, n);
return 0;
}

/*Sample Output:

Possible Triplet 0 -1 1
Possible Triplet 2 -1 -1

Question:
return for fail cases
duplicates count?
return array?

Time complexity: O(n^2)

For each element in the input array x, we are finding a pair of other two elements which  have sum equal to -x.So, this is O(n^2).
*/
