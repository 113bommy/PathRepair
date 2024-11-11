n,m=map(int,input().split())
X=sorted(map(int,input().split()))
Y=sorted([X[i+1]-X[i] for i in range(m-1)])
if n>=m:
  print(0)
else:
  print(X[-1]-X[0]-sum(Y[m-n:]))