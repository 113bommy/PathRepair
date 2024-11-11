N,K=map(int,input().split())
L=sorted(list(map(int,input().split())))
ans=sum(L[K:])
print(ans)
