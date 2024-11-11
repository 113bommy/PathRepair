import sys
input = sys.stdin.readline
from collections import *

N = int(input())
t = list(map(int, input().split()))
v = list(map(int, input().split()))
end = [-1]*N
end[-1] = 0

for i in range(N-2, -1, -1):
    end[i] = min(end[i+1]+t[i+1], v[i], v[i+1])

ans = 0
s = 0

for i in range(N):
    e = end[i]

    if s+t[i]<=e:
        ans += (s+e)*t[i]/2
        s = s+t[i]
    else:
        up = min(v[i], (s+e+t[i])/2)
        ans += (s+up)*(up-s)/2
        ans += (e+up)*(up-e)/2
        ans += up*(t[i]-(up-s)-(up-e))
        s = e

print(ans)