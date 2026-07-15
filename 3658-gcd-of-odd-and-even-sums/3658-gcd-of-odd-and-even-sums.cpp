class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0,sumEven = 0;
        int count = n;
        int start = 1;
        while(count--){
            sumOdd+=start;
            start+=2;
        }
        count = n;
        start = 2;
        while(count--){
            sumEven+=start;
            start+=2;
        }
        return (int)gcd(sumOdd,sumEven);
    }
};