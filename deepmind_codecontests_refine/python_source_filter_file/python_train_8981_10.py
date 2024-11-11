for _ in range(int(input())):
    n,m = map(int,input().split())
    som=0
    minus = 0
    minm = 10**18
    mat = []
    for i in range(n):
        arr = list(map(int,input().split()))
        mat.append(arr)
    for i in range(n):
        for j in range(m):
            if mat[i][j]<0:
                minus+=1
            minm = min(abs(mat[i][j]),minm)
            som+=abs(mat[i][j])
    if minus%2==0:
        print(som)
    else:
        print(som-minm)