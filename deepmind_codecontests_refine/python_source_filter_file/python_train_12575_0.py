n=int(input())
s=input()
r=[[0]*(n+1) for _ in range(n+1)]

#print(r)

maxV=0
for i in range(n):
  for j in  range(n-i):
    ii=n-1-i
    jj=n-1-j
    if s[ii]==s[jj]:
      r[ii][jj]=min(r[ii+1][jj+1]+1,abs(ii-jj))
      maxV=max(maxV,r[ii][jj])

print(maxV)