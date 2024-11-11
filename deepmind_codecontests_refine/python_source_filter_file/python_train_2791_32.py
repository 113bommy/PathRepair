n,k=map(int,input().split())
h=list(map(int,input().split()))

l=[0]+[float("inf")]*(n-1)

for x in range(n):
    for y in range(x+1,min(n,x+k+1)):
        l[y]=min(l[y],abs(h[y]-h[x])+l[x])

print(l[-1])