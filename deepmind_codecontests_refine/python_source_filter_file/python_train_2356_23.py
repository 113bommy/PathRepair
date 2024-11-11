#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

n = int(input())
ans = 0
a = list(map(int, input().split()))
for i in range(2, n-1):
    if a[i] > a[i-1]:
        if a[i] > a[i+1]:
            ans += 1
    elif a[i] < a[i-1]:
        if a[i] < a[i+1]:
            ans += 1
print(ans)