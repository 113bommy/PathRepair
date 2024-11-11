r,g=map(int,input().split())
X=0
for i in range(g+1):
  for j in range(g+1):
    k=g-i-j
    if k>=0 and k<=n:
      X+=1
print(X)