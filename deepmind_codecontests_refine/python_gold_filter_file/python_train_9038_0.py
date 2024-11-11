n,k,*t=map(int,open(0).read().split())
*z,=zip(*[iter(t)]*2)
ok=10**20
ng=-1
while ok-ng>1:
  mid=(ok+ng)//2
  if sum(max(0,0--(mid-w)//d)for w,d in z)<k:ng=mid
  else:ok=mid
print(ng)