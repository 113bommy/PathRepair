n,m=map(int,input().split())
l=list(map(int,input().split()))
su=sum(l)
if su<m :
  print(-1)
else :
  c=(su-m)//m
  print(min(min(l),c))