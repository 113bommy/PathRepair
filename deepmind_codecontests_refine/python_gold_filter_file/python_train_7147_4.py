n,k = list(map(int,input().split()))
al  = list(map(int,input().split()))
tl  = list(map(int,input().split()))
rl  = [1-tl[i] for i in range(n)]

rs    = sum([al[i]*tl[i] for i in range(n)])  #ref sum
bl    = [0]*(n-k+1)                           #list of benefits
bl[0] = sum([al[i]*rl[i] for i in range(k)])
for i in range(1,n-k+1):
    bl[i] = bl[i-1] + al[i+k-1]*rl[i+k-1] - al[i-1]*rl[i-1]
print(max(bl)+rs)
