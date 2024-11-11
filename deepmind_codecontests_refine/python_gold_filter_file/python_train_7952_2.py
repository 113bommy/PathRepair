n,r = list(map(int, input().split()))

rest = [False]*1001

for i in range(r):
    u,v = list(map(int, input().split()))
    rest[u] = True
    rest[v] = True

x = 1
while rest[x]:
    x+=1
print("%d"%(n-1))
for i in range(1, x):
    print("%d %d" %(i, x))
for i in range(x+1, n+1):
    print("%d %d" %(x, i))
    
    
