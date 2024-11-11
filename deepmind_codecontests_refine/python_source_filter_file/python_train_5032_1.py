n, m, k=input().split(" ")
n=int(n)
m=int(m)
k=int(k)
mex=0
class Obj:
  def __init__(self, index, costs, sells, lims):
    self.i=index
    self.costs=costs
    self.sells=sells
    self.limits=lims
l=[Obj(i, [], [], []) for i in range(n)]
for i in range(n):
  planet=input()
  for j in range(m):
    a, b, c=tuple(map(int, input().split(" ")))
    l[i].costs.append(a)
    l[i].sells.append(b)
    l[i].limits.append(c)
for i in range(n):
 for j in range(i+1, n):
  l1=l[i].costs
  l2=l[j].sells
  ll=[]
  for pro in range(m):
    ll.append([l2[pro]-l1[pro], pro])
  ll.sort(key=lambda x:x[0])
  quant=0
  pr=-1
  c=0
  while quant<k and pr>-len(ll)-1:
    if quant+l[i].limits[ll[pr][1]]<=k and ll[pr][0]>0:
      quant+=l[i].limits[ll[pr][1]]
      c+=l[i].limits[ll[pr][1]]*ll[pr][0]
    elif ll[pr][0]>0:
      c+=(k-quant)*ll[pr][0]
      quant=k
    else:
      break
    pr-=1
  mex=max(c, mex)
print(mex)
  