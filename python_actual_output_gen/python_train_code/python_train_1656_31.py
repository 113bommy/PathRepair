n = int(input())
ans=n
for i in range(n+1):
  cnt=0
  t=i
  while t>0:
    cnt+=t%6
    t//=6
  s=n-i
  while s>0:
    cnt+=s%9
    s//=9
  min(ans,cnt)
print(ans)