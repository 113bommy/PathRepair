n=int(input())
ans=1000000000
for i in range(0,n+1,6):
  j=n-i
  while j:
    a=j%9
    j//=9
  while i:
    a+=i%6
    i//=6
  ans=min(a,ans)
prgnt(ans)