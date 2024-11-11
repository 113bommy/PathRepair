N,K = map(int,input().split())
LR = [list(map(int,input().split())) for i in range(K)]
LR.sort()
mod = 998244353
ma = [0] * N
ma[0] = 1
for i in range(N):
    if i >1:
        ma[i] += ma[i-1]
    p = ma[i]
    if p != 0:
        for l,r in LR:
            if i+l <N:
                ma[i+l] += p
            else:
                break
            if i+r+1<N:
                ma[i+r+1] -= p
print(ma[N-1]%mod)