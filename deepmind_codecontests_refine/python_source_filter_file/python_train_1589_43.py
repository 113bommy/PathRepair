import math


class Solution:
    def possible(self, a, x, y, n):
        return a * x + y <= n

    def solve(self, x, y, n):
        low, high = 0, math.ceil(n / x)

        a = 0
        while low < high:
            mid = low + (high - low) // 2
            if self.possible(mid, x, y, n):
                low = mid + 1
                a = max(a, mid)
            else:
                high = mid
        return a * x + y


for _ in range(int(input())):
    x, y, n = list(map(int, input().split()))
    ans = Solution().solve(x, y, n)
    print(ans)
