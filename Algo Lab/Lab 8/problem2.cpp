#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    string word1="bbbab";
    string word2="babbb";
    vector<vector<int>> dp(100, vector<int>(100, 0));
    if(word1[0]==word2[0]) dp[0][0]=1;
    else dp[0][0]=0;    
    for(int i=0;i<word1.size();i++){
        for(int j=0;j<word2.size();j++){
            if(i==0 && j!=0){
                if(word1[i]==word2[j]) dp[0][j]=1;
                else dp[0][j]=dp[0][j-1];
            }
            else if(i!=0 && j==0){
                if(word1[i]==word2[j]) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j];
            }
            else if(i!=0 && j!=0){
                if(word1[i]==word2[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        }

        cout<<dp[word1.size()-1][word2.size()-1]<<" ";

}