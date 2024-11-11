N,Q=map(int,input().split())
S=input()
a=[0]*N
for i in range(N-1):
  a[i+1]=a[i]+(1 if S[i:i+2]=="AC" else 0)
for i in range(Q):
  l,r=map(int,input().split())
  print(a[r-1]-a[l-1])
