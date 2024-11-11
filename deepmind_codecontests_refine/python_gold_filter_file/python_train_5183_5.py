import sys

sys.setrecursionlimit(10 ** 9)
def solve(pick, idx):

    if pick == 0: return 0
    if idx >= n: return -float('inf')
    if (pick, idx) in dp: return dp[pick, idx]
    if n-idx+2 < pick*2: return -float('inf')
    total = max(A[idx] + solve(pick-1, idx+2), solve(pick, idx+1))

    dp[(pick, idx)] = total
    return total

n = int(input())
A = list(map(int, input().split()))
dp = {}
pick = n//2

print(solve(pick, 0))