N,K = map(int,input().split())
V = list(map(int,input().split()))

Q = min(N,K)
res = 0
for a in range(Q):
    for b in range(Q-a):
        W = V[:a] + V[N-b:]
        W.sort()
        for k in range(min(K-a-b,len(W))):
            if W[k] < 0:
                W[k] = 0
            else:
                break
        res = max(res,sum(W))

print(res)