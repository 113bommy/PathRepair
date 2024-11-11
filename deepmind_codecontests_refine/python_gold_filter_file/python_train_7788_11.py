n=int(input())
v=list(map(int,input().split()))
count=0
A=[[0,i] for i in range(10**5+1)]
Z=[[0,i] for i in range(10**5+1)]
for i in range(n):
  if i%2==0:
    A[v[i]][0]+=1
  else:
    Z[v[i]][0]+=1
A.sort()
Z.sort()
def wfs(x,y):
  if A[x][1]!=Z[y][1]:
    return n-A[x][0]-Z[y][0]
  else:
    return min(wfs(x,y-1),wfs(x-1,y))
print(wfs(-1,-1))