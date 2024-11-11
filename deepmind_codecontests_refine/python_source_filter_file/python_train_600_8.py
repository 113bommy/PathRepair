def update(k,x):
  k+=N0-1
  data[k]=x
  while k>=0:
    k=~-k//2
    data[k]=min(data[2*k+1],data[2*k+2])
def query(l,r):
  L,R=l+N0,r+N0
  s=INF
  while L<R:
    if R&1:
      R-=1
      s=min(s,data[R-1])
    if L&1:
      s=min(s,data[L-1])
      L+=1
    L//=2
    R//=2
  return s
n,m,*t=map(int,open(0).read().split())
N0=2**(n).bit_length()
INF=2**31-1
data=[INF]*2*N0
update(1,0)
for l,r,c in sorted(zip(*[iter(t)]*3)):update(r,min(data[r+N0-1],query(l,r)+c))
print(data[n+N0-1]%INF or-1)