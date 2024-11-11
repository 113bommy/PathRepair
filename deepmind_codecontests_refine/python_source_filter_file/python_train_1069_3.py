import heapq
N, K = map(int, input().split())
X = list(map(int, input().split()))
Y = [((x//2)**2 + (x//2+x%2)**2 - x**2, x**2, 1, x) for x in X]
l = []
for x in Y:
    heapq.heappush(l, x)
#print(l)
R = 0
for _ in range(K-N):
    t, x, y, s = heapq.heappop(l)
    nx = x+t
    y += 1
    k, m = divmod(s, y+1)
#    print(k,m,nx)
    nt = (y+1-m)*(k**2) + m*((k+1)**2) - nx
#    print(nt)
    heapq.heappush(l, (nt, nx, y, s))
#    print(l)
    
R = 0
for t, x, y, s in l:
    R += x
print(x)
