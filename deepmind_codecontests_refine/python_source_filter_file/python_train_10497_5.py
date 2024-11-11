N,K=map(int, input().split())
A=[[0]*(2*K) for j in range(2*K)]
for i in range(N):
  x,y,a=input().split()
  x,y=int(x),int(y)
  if a=='B':
    y+=K
  x=x%(2*K)
  y=y%(2*K)
  A[y][x]+=1
def da_generate(h,w,a):
    da = [[0]*w for j in range(h)]
    da[0][0] = a[0][0]
    for i in range(1,w):
        da[0][i] = da[0][i-1]+a[0][i]
    for i in range(1,h):
        cnt_w = 0
        for j in range(w):
            cnt_w += a[i][j]
            da[i][j] = da[i-1][j]+cnt_w
    return da

#da_calc(p,q,x,y):(p,q)~(x,y)の長方形の和
def da_calc(p,q,x,y):
    if p > x or q > y:
        return 0
    if p == 0 and q == 0:
        return da[x][y]
    if p == 0:
        return da[x][y]-da[x][q-1]
    if q == 0:
        return da[x][y]-da[p-1][y]
    return da[x][y]-da[p-1][y]-da[x][q-1]+da[p-1][q-1]
f=2*K
da=da_generate(f,f,A)
ans=0
for i in range(K+1):
  for j in range(K+1):
    a=da_calc(i,j,i+K-1,j+K-1)   
    y1,y2,x1,x2=i,i+K-1,j,i+K-1
    if x1>0 and y1>0:
      a+=da_calc(0,0,x1-1,y1-1)
    if x1>0 and y2<f:
      a+=da_calc(0,y2+1,x1-1,f-1)
    if x2<f and y1>0:
      a+=da_calc(x2+1,0,f-1,y1-1)
    if x2<f and y2<f:
      a+=da_calc(x2+1,y2+1,f-1,f-1)
    ans=max(ans,a,N-a)
print(ans)