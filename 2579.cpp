#include <iostream>
#include <vector>

using namespace std;

vector<int> stair; 

long dp[301];

int max(int a, int b);

int main() {
  int n , input;
  long ans =0;
  
  cin >> n;
  

  for (int i =0; i<n; i++){
    cin >>  input;
    stair.push_back(input);
  }

  if(n==0){
    cout << stair[0] ;
    return 0;
  }
  else if (n ==1){
    ans = stair[0] +stair[1];
    cout << ans;
    return 0;
  }
  dp[0] = stair[0];
  dp[1] = stair[0] + stair[1]; 
  dp[2] = max(stair[0] + stair[2] , stair[1] + stair[2]);

  for(int i = 3; i<n;i++){
    dp[i] = stair[i] + max(stair[i-1] + dp[i-3], dp[i-2] );
  }

  cout << dp[n-1];
  return 0;


} 

int max(int a, int b){
  if (a >b){
    return a;
  }
  else{
    return b;
  }
}