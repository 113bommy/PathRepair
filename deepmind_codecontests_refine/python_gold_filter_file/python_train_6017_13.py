n,m,v,p=map(int,input().split())
a=list(map(int,input().split()))
a.sort()

def f(x):
  if x>=n-p:
    return 1
  elif a[x]+m<a[n-p]:
    return 0
  else:
    ct=(p-1)*m+m+x*m
    for i in range(x+1,n-p+1):
      ct+=a[x]+m-a[i]
    if ct>=m*v:
      return 1
    else:
      return 0

L=-1;R=n
while R-L>1:
  x=(L+R)//2
  if f(x)==1:
    R=x
  else:
    L=x
print(n-L-1)