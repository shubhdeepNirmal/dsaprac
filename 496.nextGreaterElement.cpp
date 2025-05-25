#include <iostream>
#include<vector>
using namespace std;

class Solution {
    public: 
    vector<int> nextgreater(vector<int> arr){
        int n=arr.size();
        stack<int> s;
        vector<int>ans(n);
         for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(!s.empty()&&s.top()<curr){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=s.top(); 
            } 
            s.push(curr);
         }

         return ans;
        
    }

};

int main(){
    
 vector<int> arr = {4, 5, 2, 10, 8};

 Solution obj;
 vector<int> ans=obj.nextgreater(arr);
 for(int i=0;i<arr.size();i++){
     cout<<ans[i]<<" ";
 }
 cout<<endl;


 return 0;
 
}