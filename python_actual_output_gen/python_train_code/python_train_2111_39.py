N=int(input())
L=list(map(int,input().split()))
NL=[0]*N
for i in range(N):
  NL[L[i]-1]=i+1
print(NL)