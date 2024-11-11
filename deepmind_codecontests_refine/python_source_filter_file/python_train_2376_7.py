H, W=map(int, input().split())
a=[list(map(int, input().split())) for i in range(H)]
out=[]
n=0
for i in range(H):
  for j in range(W-1):
    if a[i][j]%2==1:
      n+=1
      a[i][j]-=1
      a[i][j+1]+=1
      out.append([i+1, j+1, i+1, j+2])
      
      
for i in range(H):
  if a[i][-1]%2==1:
    n+=1
    a[i][-1]-=1
    a[i+1][-1]+=1
    out.append([i+1, W, i+2, W])
    
print(n)
for i in range(n):
  print(' '.join(map(str, out[i])))