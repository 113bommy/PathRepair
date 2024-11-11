#B. Road Construction
n,m = map(int,input().split())
edges = [0]*(n+1)
for _ in range(m):
    x,y = map(int,input().split())
    edges[x] = 1
    edges[y] = 1
for i in range(1,n+1):
    if edges[i] == 0:
        break
print(n-1)
for j in range(1,n+1):
    if i!=j:
        print(i,j)