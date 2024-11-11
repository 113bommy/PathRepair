n,k = map(int,input().split());M = -1000000000
for _ in ' '*n:
    f,t = map(int,input().split());M = max(M,f-(t-k))if t>=k else max(M,t)
print(M)