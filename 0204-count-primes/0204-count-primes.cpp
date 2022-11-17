class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true);
        
        for(int i=2; i<sqrt(n); i++){
            
            if(prime[i]==true){
                for(int j=i*i; j<=n; j+=i)
                    prime[j]=false;
            }
        }    
        
        int count=0;
        for(int i=2; i<n; i++){
            if(prime[i]==true)
                count++;
        }
        return count;
    }
};