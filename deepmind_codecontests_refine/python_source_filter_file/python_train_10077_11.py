m,d=map(int,input().split())
ans=0
for i in range(d):
  d10=i//10
  d1=i-d10*10
  if d1!=1 and d10!=1 and d10*d1<=m and 1<=d10*d1:
    ans=ans+1
print(ans)