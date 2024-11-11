N=int(input())
V=list(map(int,input().split()))
V=sorted(V)
ans=V[0]
for i in range(N):
  ans=(ans+V[i])/2
print(ans)