
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumo=2*(n*(n+1)/2)-n;
        int sume=2*(n*(n+1)/2);
        return gcd(sumo,sume);
    }
};