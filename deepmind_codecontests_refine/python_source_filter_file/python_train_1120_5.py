N,K = map(int,input().split())
DP = [0]*(N+1)
DPsum=[0]*(N+1)
DP[1]=1
DPsum[1]=1
lr = []
m=998244353
for _ in range(K):
    l,r = map(int,input().split())
    lr.append([l,r])

for i in range(2,N+1):
    for l,r in lr:
        lx = i - r - 1
        rx = i - l
        lx = max(0,lx)
        rx = max(0,rx)
        DP[i]+= DPsum[rx]-DPsum[lx]
    DPsum[i]=DPsum[i-1]+DP[i]
print(DP[N]%m)
