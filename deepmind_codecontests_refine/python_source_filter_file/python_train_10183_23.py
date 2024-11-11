from heapq import heappop, heappush
 
N, K = map(int, input().split())
td = sorted([list(map(int, input().split()))
             for _ in range(N)], key=lambda x: x[1], reverse=True)

q = []
v = set()
count = 0
for t, d in td[:K]:
    count += d
    if t in v:
        heappush(q, d)
    else:
        v.add(t)
count += len(v) ** 2
ans = count
for t, d in td[:K]:
    if t not in v and len(q) != 0:
        x = heappop(q)
        count += d + 2 * len(v) + 1 - x
        v.add(t)
        ans = max(ans, count)
        
print(ans)