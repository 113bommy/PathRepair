N,M = map(int,input().split())
K=[]
ans=0
for _ in range(N):
  K+=[input().split()]
S=set(K)
for s in S:
  if K.count(s)==N:
    ans+=1
print(ans)