n,m=map(int,input().split(" "))
h=list(map(int,input().split(" ")))
g=[1]*n
for i in range(m):
  r=list(map(int,input().split(" ")))
  if h[r[0]-1]<h[r[1]-1]:
    g[r[0]-1]*=0
  elif h[r[0]-1]>h[r[1]-1]:
    g[r[1]-1]*=0
    
print(sum(g))