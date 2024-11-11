import sys
n = int(input())
a = list(map(int , input().split()))
mn = [10000000 for i in range(n+2)]

for i in range(n-1, -1,-1):
    mn[i] = min(mn[i+1],a[i])

curmax = 0
ans = 0
for i in range(n):
    curmax = max(a[i],curmax)
    if curmax  <= mn[i+1]:
        ans += 1
        curmax = 0
print(ans)