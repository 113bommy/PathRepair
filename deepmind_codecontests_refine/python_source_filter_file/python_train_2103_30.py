from math import ceil 

n = int(input())
for i in range(n):
    a,b,c,d, k = map(int, input().split())

    pen = ceil(a/c)
    pencil = ceil(b//d) 

    if pen + pencil <= k:
        print(pen, pencil)
    else:
        print(-1)