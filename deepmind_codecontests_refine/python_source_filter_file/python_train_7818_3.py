n,m = map(int, input().split())
d = {}
for i in range(1,n+1):
    d[i] = set()
for i in range(m):
    x,y = map(int, input().split())
    d[x].add(y)
    d[y].add(x)
for i in range(1,n+1):
    print(len(d[i])+1)
    print(i,i)
    for k in d[i]:
        print(i,k)
