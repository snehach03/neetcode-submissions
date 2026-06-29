class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       uint32_t a=0;
        uint32_t lastBit;
        for (int i = 0; i < 32; i++){
        lastBit = n & 1; 
        a<<=1;
        a|=lastBit; 
    n >>= 1;
        }

return a;
    }
};
