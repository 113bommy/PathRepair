def LI(): return list(map(int,input().split()))
N,K = LI()
a = LI()
ans = float('INF')
for i in range(2**(N-1)):
    bit = [i>>j&1 for j in range(N-1)]
    if K-1!=sum(bit):
        continue
    print("bit",bit)
    cost,kijun = 0,a[0]
    for k in range(N-1):
        if bit[k]==0:
            kijun = max(kijun,a[k+1])
            continue
        if a[k+1]>=kijun+1:
            kijun = a[k+1]
            continue
        cost += (kijun+1)-a[k+1]
        kijun += 1
    ans = min(ans,cost)
print(ans)