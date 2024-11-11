# maa chudaaye duniya
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    total = sum(arr)
    s = 0
    tr1 = 0
    for i in range(n-1):
        if arr[i] >= 0:
            s += arr[i]
            tr1 = max(tr1, s)
        else:
            s = 0
    tr2 = 0
    s = 0
    for i in range(1, n):
        if arr[i] >= 0:
            s += arr[i]
            tr2 = max(tr1, s)
        else:
            s = 0
    # print(tr1, tr2)
    tr = max(tr1, tr2)
    if total > tr:
        print('YES')
    else:
        print('NO')