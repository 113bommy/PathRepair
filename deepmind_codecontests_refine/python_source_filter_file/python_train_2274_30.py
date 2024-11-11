import fractions
N,K=map(int,input().split())
A=list(map(int,input().split()))
g=A[0]
for i in range(N):
  g=fractions.gcd(g,A[i])
flag=False
for i in range(N):
  if((A[i]-K)>0 and (A[i]-K)%g==0):
    flag=True
if flag:
  print("POSSIBLE")
else:
  print("IMPOSSIBLE")