import collections 
n=int(input())
v=list(map(int,input().split()))
c1,c2,ans=collections.Counter(v[::2]),collections.Counter(v[1::2]),0
a,b=c1.most_common(),c2.most_common()
if len(a)==len(b)==1:
  print(n//2 if a==b else 0)
  exit()
ans=n+(-a[0][1]-b[0][1] if a[0][1]!=b[0][1] else (-a[0][1]-b[1][1] if b[1][1]>=a[1][1] else -a[1][1]-b[0][1]))
print(ans)