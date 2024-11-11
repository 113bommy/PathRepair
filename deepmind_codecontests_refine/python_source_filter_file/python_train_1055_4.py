from heapq import heappop, heappush
n, k = map(int, input().split())
d = []
for i in range(n):
    t, b = map(int, input().split())
    d.append((t, b))

d = sorted(d, key=lambda x: (x[1], x[0]), reverse=True)
num = 0
tmp = []
tmp2 = 0
for i in range(n):
    num = max(num, (tmp2 + d[i][0]) * d[i][1])
    heappush(tmp, -d[i][0])
    tmp2 += d[i][0]
    if len(tmp) > k - 1:
        tmp2 += heappop(tmp)
print(num)