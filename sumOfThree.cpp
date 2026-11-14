#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,t;
    cin >> n >> t;
    struct pairs{
        long long value;
        int id;
    };
    vector<pairs> nums;
    for(int i=0;i<n;i++){
        long long k;
        cin >>k;
        pairs k2;
        k2.value=k;
        k2.id=i+1;
        nums.push_back(k2);
    }
    sort(nums.begin(),nums.end(),[](const pairs& e1, const pairs& e2){
        return e1.value < e2.value;
    });
    long long current_sum;
    current_sum=0;
    if(n<3){
        cout << "IMPOSSIBLE";
        return 0;
    }
    else{
        for(int i =0;i<n-2;i++){
            int left,right;
            left =i+1;
            right =n-1;
            while(left<right){
                current_sum=nums[i].value+nums[left].value+nums[right].value;
                if(t<current_sum){right-=1;}
                if(t>current_sum){left+=1;};
                if(t==current_sum){
                    cout<<nums[i].id<<" "<<nums[left].id<<" "<<nums[right].id;
                    return 0;
                }
            }
            
        }
        cout << "IMPOSSIBLE";
    }
    
    return 0;
}