#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

n = int(input())
ans = n
a = list(map(int, input().split()))
p = [0 for i in range(n+1)]
for i in range(n-1, -1, -1):
    p[i] = p[i-1]+a[i]
q = [0 for i in range(n+1)]
for i in range(n):
    if a[i] == 0:
        q[i] = q[i-1]+1
    else: q[i] = q[i-1]
ans = 0
for i in range(n):
    if a[i] == 0:
        ans = max(ans, q[i]+p[i+1])
    else:
        ans = max(ans, q[i-1]+p[i])
print(ans)
