from heapq import *
Q, = map(int, input().split())
qs = []
c = 0
for i in range(Q):
    q = input().split()
    if len(q) == 1:
        c += 1
    else:
        a, b = int(q[1]), int(q[2])
        qs.append((a, b, c, i))
        c = 0
if c:
    qs.append((a, b, c, i))

R = [10**18]
L = [10**18]
ss = 0
for a, b, c, i in qs:
    xs = []
    if c:
        x = heappop(L)
        for _ in range(c):
            print(-x, ss)
        heappush(L, x)
    x = heappop(R)
    y = -heappop(L)
    if x < a:
        heappush(R, a)
        heappush(R, a)
        heappush(L, -x)
        heappush(L, -y)
        ss += x-a
    elif y > a:
        heappush(L, -a)
        heappush(L, -a)
        heappush(R, x)
        heappush(R, y)
        ss += y-a
    else:
        heappush(L, -a)
        heappush(R, a)
        heappush(L, -y)
        heappush(R, x)
    ss += b
