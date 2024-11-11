n=int(input())
a=[[] for i in range(n)]
for i in range(n-1):
  b=[int(j)-1 for j in input().split()]
  a[b[0]].append(b[1])
  a[b[1]].append(b[0])

def dfs(v):
    d=[-1 for i in range(n)]
    q=[]
    d[v]=0
    q.append(v)
    while len(q):
        v=q.pop()
           
        for i in a[v]:
            if d[i]==-1:
                d[i]=d[v]+1
                q.append(i)
    return d
c1=dfs(0)
c2=dfs(n-1)
c=0
for i in range(n):
 if c1[i]>c2[i]:
    c+=1
if c>n/2:
  print("Snuke")
else:
  print("Fennec")
