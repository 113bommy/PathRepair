n, m = map(int, input().rstrip().split())
z = [0]*(n+1)
for i in range(m):
    x, y = map(int, input().rstrip().split())
    z[x]=1
    z[y]=1
print(z)
start=z[1:].index(0)+1
print(n-1)
for i in range(1,n+1):
    if i!=start:
        print(start,i)
