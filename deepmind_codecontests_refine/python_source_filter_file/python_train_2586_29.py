N=int(input())
a=[int(input()) for i in range(N)]
X=1
i=1
while a[i-1]!=2 and X<=n:
    X+=1
    i=a[i-1]
if X>N:
  print(-1)
else:
  print(X)