from sys import stdin
from heapq import heappush,heappop
n = int(input())
arr = []
maxi = 0
for i in range(n):
    m,*tmp = list(map(int,stdin.readline().split()))
    tmp = max(tmp)
    maxi = max(maxi,tmp)
    arr.append([m,tmp])
ans = 0
for i in range(n):
    
    ans += (maxi - arr[i][1]) * arr[i][0]


print(ans)







