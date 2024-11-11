n,c,k,*t=map(int,open(0).read().split())
t=sorted(t)
cnt,ans=0,1
x=t[0]
for i in range(n):
  cnt+=1
  if t[i]-x<k or cnt>c:
    x=t[i]
    ans+=1
    cnt=1
print(ans)