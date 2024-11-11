n,m=map(int,input().split())
A=[]
for i in range(m):
  a,b=map(int,input().split())
  C=[int(i) for i in input().split()]
  x=0
  for c in C:
    x|=(1<<(c-1))
  A.append((a,x))
DP=[float("inf")]*(2**n)
DP[0]=0
for i in range(m):
  a,x=A[i]
  for j in range(2**n):

    DP[j|x]=min(DP[j|x],DP[j]+a)

print(-1 if DP[2**n-1]==float("inf") else DP[2**n-1])
