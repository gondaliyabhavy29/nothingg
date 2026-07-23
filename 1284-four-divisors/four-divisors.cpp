class Solution {
public:
    int check(int n) {
        int sum = 0, cnt = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                sum += i;
                if (n / i != i) {
                    cnt++;
                    sum += n / i;
                }
            }
            if (cnt > 4)
                return 0;
        }
        if (cnt == 4)
            return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (auto c : nums) {
            sum += check(c);
        }
        return sum;
    }
};