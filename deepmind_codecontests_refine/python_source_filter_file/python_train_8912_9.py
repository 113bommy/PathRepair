#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

n = int(input())
a = input()
dp = {-1: 0}
s = 0
ans = 0
for i in range(n):
    if a[i] == '1': s += 1
    else: s -= 1
    if s in dp: ans = max(ans, i-dp[s])
    else: dp[s] = i
print(ans)