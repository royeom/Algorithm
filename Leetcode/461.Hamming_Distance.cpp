class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        int z = x^y;
        while(z > 0){
            if(z & 1) 
                dist++;
            z = z >> 1;
        }
        return dist;
    }
};