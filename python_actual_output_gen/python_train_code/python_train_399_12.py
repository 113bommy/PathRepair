n=int(input())
ci=[0]*8
ov=0
a=list(map(int,input().split()))
for pt in a:
  if pt>=3200:
    ov+=1
  else:
    ci[pt//400]=1
ans = sum(ci)
print(max(1,ans),min(ans+ov,8))