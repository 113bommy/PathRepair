def hello():
    import math
    n,k = map(int,input().split())
    if k > math.ceil(n**2/2):
        print('NO')
        return
    else:
        arr = []
        for i in range(n):
            arr.append(["S"]*n)
        for i in range(n):
            for j in range(i%2,n,2):
                if k > 0:
                    arr[i][j] = "L"
                    k-=1
                else:
                    break
    print("YES")
    for k in arr:
        for i in k:
            print(i,end='')
        print()
hello()