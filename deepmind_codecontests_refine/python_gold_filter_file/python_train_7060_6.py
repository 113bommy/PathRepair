N,*A = map(int, open(0).read().split())
a = A[0]
b = A[1]
c = A[2]
d = sum(A[3:])
x = 0
m = c
n = d
df2 = max(m,n)-min(m,n)
y = 2
for i in range(3,N-1):
  m += A[i]
  n -= A[i]
  if df2>max(m,n)-min(m,n):
    df2 = max(m,n)-min(m,n)
    c,d = m,n
    y = i
ans = max(a,b,c,d)-min(a,b,c,d)
for i in range(2,N-2):
  b += A[i]
  c -= A[i]
  df1 = max(a,b)-min(a,b)
  df2 = max(c,d)-min(c,d)
  while True:
    na = a+A[x+1]
    nb = b-A[x+1]
    if df1<max(na,nb)-min(na,nb):
      break
    df1 = max(na,nb)-min(na,nb)
    a,b = na,nb
    x += 1
  while True:
    nc = c+A[y+1]
    nd = d-A[y+1]
    if df2<max(nc,nd)-min(nc,nd):
      break
    df2 = max(nc,nd)-min(nc,nd)
    c,d = nc,nd
    y += 1
  ans = min(ans,max(a,b,c,d)-min(a,b,c,d))
print(ans)