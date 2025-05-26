#include <iostream>
#include <vector>
using namespace std;
class Solution {
public: 
vector<int> asteroid(vector<int>&ast){
    int n=ast.size();
   stack<int>st;
   vector<int> ans;
   for(int i=0;i<n;i++){
     int curr=ast[i];

     if(ast[i]>0){
        st.push(curr);
     }
     else{
        while(!st.empty()&&st.top()>0&&st.top()<abs(curr)){
           st.pop();
        }
        if(!st.empty() &&st.top()==abs(curr)){
            st.pop();
        }
        else if(st.empty()||st.top()<0){
            st.push(curr);
        }
     }
   }

   while(!st.empty()){
       ans.push_back(st.top());
       st.pop();
   }
   return ans;
}

};
int main(){
    Solution sol;
   vector<int> ast={5,10,-5};
   vector<int> ans=(sol.asteroid(ast));
   reverse(ans.begin(),ans.end());
   for(int i=0;i<ans.size();i++){
       cout<<ans[i]<<" ";
   }
   cout<<endl;
// expeceted output 5,10
    
    return 0;
}
