#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

a = list(map(int, list(input())))
b = list(map(int, list(input())))
n = len(a)
m = len(b)
a.append(0)
b = sum(b)
for i in range(1, n):
    a[i] += a[i-1]
ans = 0
for i in range(n-m+1):
    if (a[i+m-1]-a[i-1]+b)%2 == 0: ans += 1
print(ans)