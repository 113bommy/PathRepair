t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    dist = []
    for i in arr:
        if i not in dist:
            dist.append(i)
    if len(dist)>n:
        print(-1)
    else:
        while len(dist)!=n:
            dist.append(1)
        print(n*len(dist)) 
        for i in range(n):
            print(*dist, end = ' ')