/*
    Program: Maximum Profit from Stock Prices (Single Transaction)

    Problem:
    Given stock prices for n days,
    find the maximum profit achievable by buying once
    and selling once in the future.

    You must buy before you sell.


    Approach:
    - Keep track of the minimum price seen so far (mini).
    - For each day:
        profit = current_price - mini
    - Update maximum profit if this profit is higher.
    - Update mini if a lower price is found.


    Time Complexity: O(n)
    Space Complexity: O(1)

    Why This Works:
    - We only need one pass.
    - At each step, we compute best possible sell value
      assuming we bought at the cheapest price so far.

    Edge Cases:
    - If n <= 0 → return 0.
    - If prices are strictly decreasing → profit = 0.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no.of days:"<<endl;
    cin>>n;
    if(n<=0){
        cout<<0<<endl;
        return 0;
    }
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxprofit=0;
    int mini=arr[0];
    for(int i=1;i<n;i++){
        int cost=arr[i]-mini;
        maxprofit=max(maxprofit,cost);
        mini=min(arr[i],mini);
    }
    cout<<maxprofit<<endl;
    return 0;
}
