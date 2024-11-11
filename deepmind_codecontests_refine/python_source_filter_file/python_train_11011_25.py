n,k,*l=map(int,open(0).read().split())
for _ in range(min(k,40)):
  s=[0]*(n+1)
  for i in range(n):
    s[max(i-l[i],0)]+=1
    s[min(i+l[i]+1,n)]-=1
  l[0]=min(s[0],n)
  for i in range(1,n):
    l[i]=min(l[i-1]+s[i],n)
print(*l)