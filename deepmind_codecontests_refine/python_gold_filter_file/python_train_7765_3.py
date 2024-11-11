#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

n = int(input())
s = sum(map(int, input().split()))
ans = -1
for _ in range(int(input())):
    l, r = map(int, input().split())
    if s <= r:
        if ans == -1:
            ans = max(s, l)
        else:
            ans = min(ans, max(s, l))
print(ans)