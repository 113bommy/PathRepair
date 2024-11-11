def is_ok(index):
  s=0
  for i in range(p,index):
    s+=a[index]+m-a[i]
  return s+m*(n-index+p-1)>=m*v and a[index]+m>=a[p-1]
def binary_search(a):
  ok=-1
  ng=len(a)
  while abs(ng-ok)>1:
    mid=(ng+ok)//2
    if is_ok(mid):ok=mid
    else:ng=mid
  return ok+1
n,m,v,p=map(int,input().split())
a=sorted(list(map(int,input().split())))[::-1]
print(binary_search(a))