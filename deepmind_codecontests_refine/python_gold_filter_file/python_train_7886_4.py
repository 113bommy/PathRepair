
from collections import deque

d = deque()
n,m = map(int,input().split())

w = [[] for i in range(n)]
c = [0 for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    w[a-1].append(b-1)
    w[b-1].append(a-1)
ans =-1
for i in range(n):
    if c[i] == 0:
        c[i] = 1
        ans += 1
        d.append(i)
        while d:
            x = d.pop()
            for i in w[x]:
                if c[i] == 0:
                    c[i] = 1
                    d.append(i)

print(ans)