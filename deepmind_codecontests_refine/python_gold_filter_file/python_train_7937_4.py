def solve(n, arr):
    temp = list.copy(arr)
    temp.sort()
    cnt = 0
    status = 0
    k = 0
    # print(arr, temp)
    for i in range(0, n):
        if arr[i] != temp[i]:
            cnt += 1
            if status == 0:
                status = 1
        else:
            if status == 1:
                status = 0
                k += 1
        if k > 1:
            print(2)
            return
    if status == 1:
        k += 1
    if k == 1:
        print(1)
    elif cnt == 0:
        print(0)
    elif cnt == n:
        print(1)
    else:
        print(2)
    pass

t = int(input())
for i in range(0, t):
    n = int(input())
    arr = list(map(int, input().split()))
    solve(n, arr)