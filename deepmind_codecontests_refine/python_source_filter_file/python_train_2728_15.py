for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))

    flag = True

    for i in range(n-1):
        if abs(arr[i] - arr[i+1]) > 1:
            print("YES")
            print(i,i+1)
            flag = False
            break

    if flag:
        print('NO')
