#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

n = int(input())
a = [1]+list(map(int, input().split()))+[10**6]
ans = 10**6
for i in range(1, n+2):
    ans = min(ans, max(a[i-1]-1, 10**6-a[i]))
print(ans)