import sys
input=lambda: sys.stdin.readline().rstrip()
n,s=map(int,input().split())
A=[int(i) for i in input().split()]
mod=998244353
B=[[0]*(s+1) for _ in range(n+1)]
ans=0
for i in range(n):
  a=A[i]
  if a<s:
    B[i+1][a]+=i+1
  elif a==s:
    B[i+1][a]+=(i+1)*(n-i)
  for j in range(s+1):
    if j<=s:
      B[i+1][j]+=B[i][j]
    if 0<=j-a and j<s:
      B[i+1][j]+=B[i][j-a]
    if 0<=j-a and j==s:
      B[i+1][j]+=B[i][j-a]*(n-i)
    B[i+1][j]%=mod
print(B[n][s])