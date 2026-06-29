class Solution {
public:
    int hammingWeight(uint32_t n) {
        int digit=0;
        for(int i=0;i<32;i++){
            digit=digit+(n&1);
            n>>=1;
        }

        return digit;

    }
};
