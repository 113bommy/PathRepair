N,K,S=[int(i) for i in input().split()]
res=[10**9]*N
for i in range(K):
    res[i]=S
print(*res)
