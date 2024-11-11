import heapq as hq
n = int(input())
a = list(map(int,input().split()))
x = sum(a[:n])
y = sum(a[2*n:])
fsum = [x]
lsum = [y]
hqx = a[:n]
hqy = [-a[2*n+i] for i in range(n)]
hq.heapify(hqx)
hq.heapify(hqy)
for i in range(n):
    hq.heappush(hqx,a[n+i])
    hq.heappush(hqy,-a[2*n-i-1])
    xmin = hq.heappop(hqx)
    ymax = -hq.heappop(hqy)
    fsum.append(fsum[-1]+a[n+i]-xmin)
    lsum.append(lsum[-1]+a[2*n-i-1]-ymax)
ans = -10**18
for i in range(n):
    ans = max(ans,fsum[i]-lsum[-i-1])
print(ans)