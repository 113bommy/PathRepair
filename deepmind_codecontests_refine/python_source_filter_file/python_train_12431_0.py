def prog():
    n ,m = map(int ,input().split())
    res ,anext = [0 ] *n ,[ i +1 for i in range( n +2)]
    from sys import stdin
    for _ in range(m):
        l ,r ,x = map(int ,stdin.readline().split())
        i=l
        while i<=r:
            if res[i-1]==0 and i!= x:
                res[i-1]=x
            save = anext[i]
            if i<x:
                anext[i]=x
            else:
                anext[i]=anext[r+1]
            i=save
    print(*res)
prog()