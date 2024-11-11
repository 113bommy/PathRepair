
N, T = map(int, input().split())
X = []
for _ in range(N):
    a, b = map(int, input().split())
    X.append((a,b))

X.sort(key=lambda x:x[0]/(x[1]+1))
X=X[::-1]

dp = [[0]+[T+2]*29 for _ in range(N+1)]
bs = []
fi=0
for i, (a, b) in enumerate(X):
    if a==0:
        bs.append(b)
        continue
    for j in range(1, 30):
#        if j==1:
#            print(a*(dp[i][j-1]+1)+b)
        dp[i+1][j] = min(min(dp[i][j], a*(dp[i][j-1]+1)+b), T+1)
    fi = i+1

#print(dp)

bs.sort()
bbs = [0]
for i, b in enumerate(bs):
    bbs.append(bbs[-1]+bs[i]+1)
bbs.append(10**18)


#print(dp[fi], bbs)
r=0
for i in range(30):
    if dp[fi][i] > T:
        break
    nt = T-dp[fi][i]
#    print(nt)
    for j, b in enumerate(bbs):
#        print(1, b)
        if b > nt:
            break
    r=max(r, i+j-1)
print(r)
