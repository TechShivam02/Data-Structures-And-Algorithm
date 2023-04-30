
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
                                                 
             
    deque<long long> dq;
    vector<long long> ans;
    
    
    
    for(long long int i=0;i<k;i++){
        
        if(arr[i] < 0){
            dq.push_back(i);
        }
        
    }
    
    
    
    if( !dq.empty() ){
        
        ans.push_back(arr[dq.front()]);
    }
    
    else{
        ans.push_back(0);
        
    }
    
    
    for(int i=k;i<n;i++){
        
        if( !dq.empty() && i-dq.front() >=k){
            dq.pop_front();
        }
        
        if(arr[i] < 0){
            dq.push_back(i);
        }
        
        
        
        if(!dq.empty()){
                ans.push_back(arr[dq.front()]);
        }
    
        else{
            ans.push_back(0);
            
        }
        
    }
        return ans;


}