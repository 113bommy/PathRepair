from heapq import *
R = lambda: list(map(int,input().split()))
n,k1,k2 = R()
a,b = R(),R()
h = []
for i in range(n): 
    a[i] = abs(a[i]-b[i])
    heappush(h,-a[i])
k1 += k2
while k1>0:
    val = heappop(h)
    heappush(h,val+1)
    k1 -= 1
ans = 0
while h:
    val = heappop(h)
    ans += val*val
print(ans)