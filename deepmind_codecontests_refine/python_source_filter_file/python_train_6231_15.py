mport sys
N,M=map(int, input().split())
a=[]
b=[]
c=[]
for m in range (0,M):
  A,B,C=map(int, input().split() )
  a+=[A]
  b+=[B]
  c+=[C]
V=[0]+[-10**12]*(N-1)# iに到達するときの最大得点
 
for n in range(N-1):
  for m in range(M):
    u=a[m]
    v=b[m]
    if V[b[m]-1]<V[a[m]-1]+c[m]:#共に有限の時はやる
      V[b[m]-1]=V[a[m]-1]+c[m]
 
moji2=[0]*N
for n in range(N):
  for m in range(M):
    u=a[m]
    v=b[m]
    if V[b[m]-1]<V[a[m]-1]+c[m]:#共に有限の時はやる
        V[b[m]-1]=V[a[m]-1]+c[m]
        moji2[b[m]-1]=1
      if moji2[N-1]:
        print("inf")
        sys.exit()
print(V[N-1])