N=int(input())
V=list(map(int,input().split()))
V=sorted(V)
ans=V[0]
for i in range(1,N-1):
  ans=(ans+V[i])/2
print(ans)