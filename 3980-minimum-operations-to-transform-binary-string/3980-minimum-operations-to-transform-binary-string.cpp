class Solution {
public:
    int minOperations(string a, string b) {
        int n = a.length();

        if(n == 1 && a.front() == '1' && b.front() == '0') return -1;

        int ans = 0;
        for(int i = 0;i < n;i += 1){
            if(b[i] == '1' && a[i] == '0'){
                ans += 1;
                a[i] = '1';
            }
        }

        // handle all the cases where b[i] = 0;
        // find the blocks of b[i]'s where they are all 0s


        int i = 0;
        while(i < n){
            int j = i;
            if(a[i] == b[i]){
                i += 1;
                continue;
            }

            while(j < n && b[j] == '0'){
                j += 1;
            }

            
            int k = i;
            while(k < j){
                if(a[k] == '0'){
                    k += 1;
                    continue;
                }

                int jj = k;
                while(jj < j && a[jj] == '1'){
                    jj += 1;
                }

                ans += (jj - k)/2;
                
                if((jj - k) & 1){
                    ans += 2;
                }

                k = jj;
            }

            i = j;
        }

        return ans;
    }
};