from heapq import *
N = int(input())
A = [int(a) for a in input().split()]
x, t, s, i, h = 0, 0, 0, 59, []
for a in A:
    t ^= a
for a in A:
    heappush(h, -(a&~t))
while h:
    a = -heappop(h)
    while i >= 0 and (a >> i) & 1 == 0:
        i -= 1
        x = 0
    if i < 0: break
    if x:
        heappush(h, -(a^x))
    else:
        x = a
        s = max(s, s^x)
print(s+(t^s))