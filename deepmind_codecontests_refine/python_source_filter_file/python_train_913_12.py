N=int(input())
L=list(map(int,input().split()))
L=sorted(L)
s=(L[0]+L[1])/2
for i in range(2,N):
  s=(s+L[i])//2
print(s)