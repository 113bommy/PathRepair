for _ in range(int(input())):
    n,k = map(int,input().split())
    if k%n==0:
        print(0)
    else:
        print(2)
    arr = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        if not k:
            break
        for j in range(n):
            if not k:
                break
            x = j
            y = (i+j)%n
            arr[x][y]=1
            k-=1
    for i in arr:
        for j in i:
            print(j,end=' ')
        print()
