from itertools import accumulate
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
odd = list(accumulate([0] + A[::2]))
even = list(accumulate([0] + A[::-1][::2]))
ans = max(odd[i] + even[N//2-i] for i in range(N//2+1))
if N % 2 == 1:
    dp = [0] * (N//2+1)
    for i in range(0, N-1, 2):
        dp[i//2+1] = max(odd[i//2+1], dp[i//2] + A[i+1])
    ans2 = max(dp[i] + even[N//2-i] for i in range(N//2+1))
    ans = max(ans, ans2)
print(ans)